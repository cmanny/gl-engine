#include "Engine.h"

using namespace glm;
using namespace std;

// Game engine constructor
Engine::Engine(int _width, int _height, int _frameRate, string _title) {
  width = _width;
  height = _height;
  frameRate = _frameRate;
  title = _title;
  fullscreen = false;
  running = true; 

  cout << "Starting Engine.\n";

  // ---- Initialise the window manager, GLFW ----
  // GLFW is setup in the main thread since the window event
  // function requires the main thread, which also suits us.
  if(!glfwInit()) {
    cerr << "Error initializing GLFW.\n";
    exit(-1);
  }
  // Set OpenGL Window hints
  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
  // Open a window and create its OpenGL context 
  window = glfwCreateWindow( width, height, title.c_str(), NULL, NULL);
  if( window == NULL ){
      cerr << "Error creating GLFW window.\n";
      glfwTerminate();
      exit(-1);
  }
  const GLFWvidmode* desktopMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
  desktopHeight = desktopMode->height;
  desktopWidth = desktopMode->width;
  // Ensure capture of escape key
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
  // ---- GLFW initialisation finished. ----

  // Additional setup of other components
  evtmgr = new EventManager(window);
  camera = new Camera(evtmgr);
  renderer = new Renderer(window, camera, width, height, &running);
}

void Engine::callback(Event evt){
  if(evt.data[0] == GLFW_KEY_F11){
    int w = !fullscreen ? desktopWidth : width;
    int h = !fullscreen ? desktopHeight : height;
    fullscreen = !fullscreen;

    glfwSetWindowSize(window,w, h);
    glfwSetWindowPos(window,0, 0); 
  }else if(evt.data[0] == GLFW_KEY_ESCAPE){
    this->running = false;
  }

} 


// Start game engine
void Engine::start() {
  // Define start time
  double lastTime = glfwGetTime(); 
  evtmgr->enableCallback(make_callback(this, EVT_KEY, &Engine::callback));
  std::thread renderThread(std::ref(*renderer));
  // Main game loop
  do {
     double currentTime = glfwGetTime();
     double delta = currentTime - lastTime;
     update(delta);
     glfwPollEvents();
  } 
  while(running);

  renderThread.join();


}

