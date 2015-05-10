#include "Event.h"

Callback* makeCallback(void* object, int type, EvtCallback evt){
  Callback* c = new Callback;
  c->object = object;
  c->type = type;
  c->evt = evt;
  return c;
}

template<class T>
CallbackTmpl<T>::CallbackTmpl(int type, EventCallback<T>  callback){
}
