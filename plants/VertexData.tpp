// Constructor
template<class T> VertexData<T>::VertexData() {
  buffer = new GLuint;
  data = 0;
}

// Destructor
template<class T> VertexData<T>::~VertexData() {
 if(data)
   delete data;
 if(buffer)
   delete buffer;
}

// Get vertex data
template<class T> T* VertexData<T>::getData() {
  return data;
}

// Get vertex buffer
template<class T> GLuint* VertexData<T>::getBuffer() {
  return buffer;
}

// Set vertex data
template<class T> void VertexData<T>::setData(T* data, int size) {
  this->data = new T[size];
  std::copy(data, data+size, this->data);
  this->size = size;
  refreshBuffer();
}

template<class T> int VertexData<T>::numVerts(){
  return size/3;
}

// Rebuild vertex buffer
template<class T> void VertexData<T>::refreshBuffer() {

  // Generate & bind vertex buffer
  glGenBuffers(1, buffer);
  glBindBuffer(GL_ARRAY_BUFFER, *buffer);
      
  // Pass updated vertices to OpenGL.
  glBufferData(GL_ARRAY_BUFFER, sizeof(T)*size, 
      data, GL_STATIC_DRAW);
}
