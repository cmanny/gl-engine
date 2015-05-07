#include "EventManager.h"
EventManager* EventManager::instance = 0;


#pragma warning( push )
#pragma warning( disable : 4101)

EventManager::EventManager(GLFWwindow* w) {
  window = w;
  instance = this;
  cout << "address of keyCallback " << (void*)EventManager::keyCallback << "\n";
  glfwSetKeyCallback(w, EventManager::keyCallback);
  glfwSetScrollCallback(w, &EventManager::mouseScrollCallback);
  glfwSetMouseButtonCallback(w, &EventManager::mouseButtonCallback);
  glfwSetCursorPosCallback(w, &EventManager::mouseMoveCallback);

  for(int i = 0; i < NUM_EVTS; i++)
    callbacks.insert(
        std::pair< int,list<EvtCallback>* >(i,new list<EvtCallback>)
        );
}

#pragma warning( pop ) 

EventManager* EventManager::getInstance(){
  return instance;
}

int EventManager::enableCallback(int type, EvtCallback callback){
  if(callbacks.count(type) > 0){
    callbacks[type]->push_back(callback);
    cout << "Pushed callback " << type << " at address " << (void*)callback << "\n";
  }
}

int EventManager::disableCallback(int type, EvtCallback callback){
  if(callbacks.count(type) > 0){
    list<EvtCallback>* v = callbacks[type];
    v->remove(callback);
  }
}
void EventManager::keyCallback(GLFWwindow* w,int key,int scancode,int action,int mods){
  cout << "Key callbacks" << "\n";
  for(auto it = instance->callbacks[EVT_KEY]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt;
    evt.data[0] = key;
    evt.data[1] = scancode;
    cout << "Looping key callback, evt ptr " << (void*)&evt << " with key" << key << "\n";
    (*it)(evt);
  } 
}
void EventManager::mouseMoveCallback(GLFWwindow* w,double xpos,double ypos){
  for(auto it = instance->callbacks[EVT_MOUSEMOVE]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {xpos,ypos,0,0};
    (*it)(evt);
  }
}
void EventManager::mouseButtonCallback(GLFWwindow* w,int button,int action,int mods){
  for(auto it = instance->callbacks[EVT_MOUSEBUTTON]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {button,action,mods,0};
    (*it)(evt);
  }
}
void EventManager::mouseScrollCallback(GLFWwindow* w,double xoff,double yoff){
  for(auto it = instance->callbacks[EVT_MOUSESCROLL]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {xoff, yoff, 0,0};
    (*it)(evt);
  }
}

