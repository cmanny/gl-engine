#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include <glfw3.h>
#include <map>
#include <list>
#include <iostream>

#include "Event.h"



#define EVT_MOUSEMOVE 0
#define EVT_MOUSESCROLL 1
#define EVT_MOUSEBUTTON 2
#define EVT_KEY 3
#define NUM_EVTS 4

using namespace std;

//Wrapper around the glfw input methods
class EventManager {
  

  private:
    map< int,list<CallbackBase*>* > callbacks ;
    GLFWwindow *window;
    static EventManager* instance;    
    // The default callbacks for the GLFW function calls
    // They need to be static to use them as callbacks
    
    static void keyCallback(GLFWwindow* w,int,int,int,int);
    static void mouseMoveCallback(GLFWwindow* w,double,double);
    static void mouseButtonCallback(GLFWwindow* w,int,int,int);
    static void mouseScrollCallback(GLFWwindow* w,double,double);

  public:
    EventManager(GLFWwindow* w);

    bool enableCallback(CallbackBase*);
    bool disableCallback(CallbackBase*); 

};

#endif /* EVENT_MANAGER_H */
