#include "EventManager.h"

EventManager* EventManager::instance = 0;

EventManager::EventManager(GLFWwindow* w) {
  window = w;
  instance = this;
  glfwSetKeyCallback(w, EventManager::keyCallback);
  glfwSetScrollCallback(w, &EventManager::mouseScrollCallback);
  glfwSetMouseButtonCallback(w, &EventManager::mouseButtonCallback);
  glfwSetCursorPosCallback(w, &EventManager::mouseMoveCallback);

  for(int i = 0; i < NUM_EVTS; i++)
    callbacks.insert(
        std::pair< int,list<CallbackBase*>* >(i,new list<CallbackBase*>)
        );
}

int EventManager::enableCallback(CallbackBase* c){
  if(callbacks.count(c->getType()) > 0){
    callbacks[c->getType()]->push_back(c);
  }
}

int EventManager::disableCallback(CallbackBase* c){
  if(callbacks.count(c->getType()) > 0){
    list<CallbackBase*>* v = callbacks[c->getType()];
    v->remove(c);
  }
}
void EventManager::keyCallback(GLFWwindow* w,int key,int scancode,int action,int mods){
  cout << "Key callbacks" << "\n";
  for(auto it = instance->callbacks[EVT_KEY]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {key,scancode,action,mods};
    //Dat cast
    (*it)->callback(evt);
  } 
}
void EventManager::mouseMoveCallback(GLFWwindow* w,double xpos,double ypos){
  for(auto it = instance->callbacks[EVT_MOUSEMOVE]->begin(); it != instance->callbacks[EVT_MOUSEMOVE]->end(); ++it){
    Event evt = {xpos,ypos,0,0};
    (*it)->callback(evt);
  }
}
void EventManager::mouseButtonCallback(GLFWwindow* w,int button,int action,int mods){
  for(auto it = instance->callbacks[EVT_MOUSEBUTTON]->begin(); it != instance->callbacks[EVT_MOUSEBUTTON]->end(); ++it){
    Event evt = {button,action,mods,0};
    (*it)->callback(evt);
  }
}
void EventManager::mouseScrollCallback(GLFWwindow* w,double xoff,double yoff){
  for(auto it = instance->callbacks[EVT_MOUSESCROLL]->begin(); it != instance->callbacks[EVT_MOUSESCROLL]->end(); ++it){
    Event evt = {xoff, yoff, 0,0};
    (*it)->callback(evt);
  }
}
