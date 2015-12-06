// Constructor
template<class T> VertexData<T>::VertexData(int bufType) {
  buffer = new GLuint;
  bufferType = bufType;
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
template<class T> std::vector<T>* VertexData<T>::getData() {
  return data;
}

// Get vertex buffer
template<class T> GLuint* VertexData<T>::getBuffer() {
  return buffer;
}

// Set vertex data
template<class T> void VertexData<T>::setData(std::vector<T>* data) {
  this->data = data;
}

template<class T> int VertexData<T>::numVerts(){
  return data->size();
}

// Rebuild vertex buffer
template<class T> void VertexData<T>::refreshBuffer() {
  glGenBuffers(1, buffer);
  glBindBuffer(bufferType, *buffer); 
  glBufferData(bufferType, sizeof(T)*data->size(), &(*data)[0], GL_STATIC_DRAW);
}
