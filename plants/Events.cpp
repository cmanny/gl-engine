#include "Events.h"

Events::Events(GLFWwindow* w) {
  window = w;
  instance = this;
  glfwSetKeyCallback(w, keyCallback);
  glfwSetScrollCallback(w, mouseScrollCallback);
  glfwSetMouseButtonCallback(w, mouseButtonCallback);
  glfwSetCursorPosCallback(w, mouseMoveCallback);

  for(int i = 0; i < NUM_EVTS; i++)
    callbacks.insert(
        std::pair<int,list<void*>>(i,new list<void*>())
        );
}

Events::getInstance(){
  return instance;
}

int Events::enableCallback(int type, void* func){
  if(callbacks.count(type) > 0){
    callbacks[type]->push_back(func);
  }
}

int Events::disableCallback(int type, void* func){
  if(callbacks.count(type) > 0){
    list<void*>* v = callbacks[type];
    v->remove(func);
  }
}
void Events::keyCallback(GLFWwindow* w,int key,int scancode,int action,int mods){
  for(auto it = callbacks[EVT_KEY]->begin(); it != callbacks[EVT_KEY]->end()){
    (KeyCallback)(*it)(key,scancode,action,mods);
  } 
}
void Events::mouseMoveCallback(GLFWwindow* w,double xpos,double ypos){

}
void Events::mouseButtonCallback(GLFWwindow* w,int button,int action,int action){

}
void Events::mouseScrollCallback(GLFWwindow* w,double xoff,double yoff){

}

