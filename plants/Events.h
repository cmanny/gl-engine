#ifndef EVENTS_H
#define EVENTS_H
#include <glfw3.h>
#include <map>
#include <list>

typedef void (*KeyCallback)(GLFWwindow* w,int key, int scancode, int action, int mods);
typedef void (*MouseMoveCallback)(GLFWwindow* w, double xpos, double ypos);
typedef void (*MouseButtonCallback)(GLFWwindow* w, int button, int action, int mods);
typedef void (*MouseScrollCallback)(GLFWwindow* w, double xoff, double off);


#define EVT_MOUSEMOVE 0
#define EVT_MOUSESCROLL 1
#define EVT_MOUSEBUTTON 2
#define EVT_KEY 3
#define NUM_EVTS 4

using namespace std;

//Wrapper around the glfw input methods
class Events {
  

  private:
    map< int,list<void*>* > callbacks ;
    GLFWwindow *window;
    static Events* instance;
    
    // The default callbacks for the glfw functions
    void keyCallback(GLFWwindow* w,int,int,int,int);
    void mouseMoveCallback(GLFWwindow* w,double,double);
    void mouseButtonCallback(GLFWwindow* w,int,int,int);
    void mouseScrollCallback(GLFWwindow* w,double,double);

  public:
    Events(GLFWwindow* w);
    static Events* getInstance();

    int enableCallback(int, void*);
    int disableCallback(int, void*); 

    // The default callbacks for the glfw functions
    //
};

#endif /* EVENTS_H */
