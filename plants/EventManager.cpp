#include "EventManager.h"

EventManager* EventManager::instance = 0;

EventManager::EventManager(GLFWwindow* w) {
  if(instance == 0){ 
    instance = this;
    window = w;
    glfwSetKeyCallback(w, EventManager::keyCallback);
    glfwSetScrollCallback(w, &EventManager::mouseScrollCallback);
    glfwSetMouseButtonCallback(w, &EventManager::mouseButtonCallback);
    glfwSetCursorPosCallback(w, &EventManager::mouseMoveCallback);

    for(int i = 0; i < NUM_EVTS; i++)
      callbacks.insert(
          std::pair< int,list<Callback*>* >(i,new list<Callback*>)
          );
  }else{
    std::cerr << "EventManager: Only one instance should exist!";
  }
}

bool EventManager::enableCallback(Callback* c){
  if(callbacks.count(c->type) > 0){
    callbacks[c->type]->push_back(c);
    return true;
  }
  return false;
}

bool EventManager::disableCallback(Callback* c){
  if(callbacks.count(c->type) > 0){
    list<Callback*>* v = callbacks[c->type];
    v->remove(c);
    return true;
  }
  return false;
}
void EventManager::keyCallback(GLFWwindow* w,int key,int scancode,int action,int mods){
  for(auto it = instance->callbacks[EVT_KEY]->begin(); it != instance->callbacks[EVT_KEY]->end(); ++it){
    Event evt = {key,scancode,action,mods};
    //Dat cast
    (*it)->fn(evt);
  } 
}
void EventManager::mouseMoveCallback(GLFWwindow* w,double xpos,double ypos){
  for(auto it = instance->callbacks[EVT_MOUSEMOVE]->begin(); it != instance->callbacks[EVT_MOUSEMOVE]->end(); ++it){
    Event evt = {xpos,ypos,0,0};
    (*it)->fn(evt);
  }
}
void EventManager::mouseButtonCallback(GLFWwindow* w,int button,int action,int mods){
  for(auto it = instance->callbacks[EVT_MOUSEBUTTON]->begin(); it != instance->callbacks[EVT_MOUSEBUTTON]->end(); ++it){
    Event evt = {button,action,mods,0};
    (*it)->fn(evt);
  }
}
void EventManager::mouseScrollCallback(GLFWwindow* w,double xoff,double yoff){
  for(auto it = instance->callbacks[EVT_MOUSESCROLL]->begin(); it != instance->callbacks[EVT_MOUSESCROLL]->end(); ++it){
    Event evt = {xoff, yoff, 0,0};
    (*it)->fn(evt);
  }
}
