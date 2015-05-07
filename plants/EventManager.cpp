#include "EventManager.h"
EventManager* EventManager::instance = 0;


#pragma warning( push )
#pragma warning( disable : 4101)

EventManager::EventManager(GLFWwindow* w) {
  window = w;
  instance = this;
  glfwSetKeyCallback(w, EventManager::keyCallback);
  glfwSetScrollCallback(w, &EventManager::mouseScrollCallback);
  glfwSetMouseButtonCallback(w, &EventManager::mouseButtonCallback);
  glfwSetCursorPosCallback(w, &EventManager::mouseMoveCallback);

  for(int i = 0; i < NUM_EVTS; i++)
    callbacks.insert(
        std::pair< int,list<Callback*>* >(i,new list<Callback*>)
        );
}

#pragma warning( pop ) 

EventManager* EventManager::getInstance(){
  return instance;
}

int EventManager::enableCallback(Callback* c){
  if(callbacks.count(c->type) > 0){
    callbacks[c->type]->push_back(c);
  }
}

int EventManager::disableCallback(Callback* c){
  if(callbacks.count(c->type) > 0){
    list<Callback*>* v = callbacks[c->type];
    v->remove(c);
  }
}
void EventManager::keyCallback(GLFWwindow* w,int key,int scancode,int action,int mods){
  cout << "Key callbacks" << "\n";
  for(auto it = instance->callbacks[EVT_KEY]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {key,scancode,action,mods};
    //Dat cast
    ( (MemberEvtCallback)((void*)((*it)->evt)) )((*it)->object, evt);
  } 
}
void EventManager::mouseMoveCallback(GLFWwindow* w,double xpos,double ypos){
  for(auto it = instance->callbacks[EVT_MOUSEMOVE]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {xpos,ypos,0,0};
    //(*it)(evt);
  }
}
void EventManager::mouseButtonCallback(GLFWwindow* w,int button,int action,int mods){
  for(auto it = instance->callbacks[EVT_MOUSEBUTTON]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {button,action,mods,0};
    //(*it)(evt);
  }
}
void EventManager::mouseScrollCallback(GLFWwindow* w,double xoff,double yoff){
  for(auto it = instance->callbacks[EVT_MOUSESCROLL]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {xoff, yoff, 0,0};
    //(*it)(evt);
  }
}

