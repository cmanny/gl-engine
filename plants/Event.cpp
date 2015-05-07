#include "Event.h"

Callback* makeCallback(void* object, int type, EvtCallback evt){
  Callback* c = new Callback;
  c->object = object;
  c->type = type;
  c->evt = evt;
  return c;
}
