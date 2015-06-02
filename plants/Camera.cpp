#include "Camera.h"

// Constructor
Camera::Camera(EventManager* evtmgr){
  this->evtmgr = evtmgr;
}

// Initialise camera
void Camera::init(int x, int y, int z){
  tbb::spin_mutex::scoped_lock lock(mutex);
  evtmgr->enableCallback(make_callback(this, EVT_MOUSESCROLL, &Camera::scrollCallback));
  evtmgr->enableCallback(make_callback(this, EVT_KEY, &Camera::keyCallback));
  centreX = eyeX = x;
  centreY = eyeY = y;
  eyeZ = z;
  centreZ = 0;
  moveVelX = moveVelY = moveVelZ = 0;
  moveNorth = moveEast = moveSouth = moveWest = rotNorth = rotSouth = false;
  viewMat = glm::lookAt(
    glm::vec3(eyeX, eyeY, eyeZ),
    glm::vec3(centreX, centreY, centreZ),
    glm::vec3(0, 1, 0)
  );
}

glm::mat4* Camera::view(){
  
  /*std::cout << "view thread: " << std::this_thread::get_id() << "\n";
  tbb::spin_mutex::scoped_lock jimmers;
  if(jimmers.try_acquire(mutex))*/ 
    return &viewMat;
  //else return 0;
}

glm::vec3 Camera::getPos(){
  return glm::vec3(eyeX, eyeY, eyeZ);
}
void Camera::scrollCallback(Event evt){
  eyeZ += 5*evt.data[1];
}

void Camera::keyCallback(Event evt){
  
  int key = evt.data[0];
  int scancode = evt.data[1];
  int action = evt.data[2];
  int mods = evt.data[3];
  
  switch(action){
    case GLFW_REPEAT:
    case GLFW_PRESS:
      switch(key){
        case GLFW_KEY_A: moveWest = true; break;
        case GLFW_KEY_D: moveEast= true; break;
        case GLFW_KEY_W: moveNorth = true; break;
        case GLFW_KEY_S: moveSouth = true; break;
        case GLFW_KEY_E: rotSouth = true; break;
        case GLFW_KEY_Q: rotNorth = true; break;
      }
    break;
    
    case GLFW_RELEASE: 
      switch(key){
        case GLFW_KEY_A: moveWest = false; break;
        case GLFW_KEY_D: moveEast= false; break;
        case GLFW_KEY_W: moveNorth = false; break;
        case GLFW_KEY_E: rotSouth = false; break;
        case GLFW_KEY_Q: rotNorth = false; break;
        case GLFW_KEY_S: moveSouth = false; break;
      }
    break;
  }       
}

// Update camera
void Camera::update(double delta) {
  double factor = (double)delta*8;
  double max = factor*8;
  double slow = factor/8;

  // Increase velocity
  if(moveNorth) 
    moveVelY += factor;
  if(moveEast)
    moveVelX += factor;
  if(moveSouth)
    moveVelY -= factor;
  if(moveWest)
    moveVelX -= factor;

  // Reduce velocity
  if(!moveNorth)
    if(moveVelY > 0) {moveVelY -= slow;}
  else
  if(!moveSouth)
    if(moveVelY < 0) {moveVelY += slow;}
  
  if(!moveEast)
    if(moveVelX > 0) {moveVelX -= slow;}
  else
  if(!moveWest)
    if(moveVelX < 0) {moveVelX += slow;}

  // Ensure velocity doesn't exceed bounds
  if(moveVelX > max) 
    moveVelX = max;
  else if(moveVelX < -max)
    moveVelX = -max;

  if(moveVelY > max) 
    moveVelY = max;
  else if(moveVelY < -max)
    moveVelY = -max;

  // Update camera position
  eyeX = centreX += moveVelX;
  eyeY = centreY += moveVelY;  

   
  tbb::spin_mutex::scoped_lock lock(mutex); 
  viewMat = glm::lookAt(
    glm::vec3(eyeX, eyeY, eyeZ),
    glm::vec3(centreX, centreY, centreZ),
    glm::vec3(0, 1, 0)
  );
}



