#ifndef EVENT_H
#define EVENT_H
#include <list>
#include <functional>

typedef struct Event {
  int data[4];
} Event;

typedef std::function<void(Event)> EventCallback;

typedef struct Callback {
  EventCallback fn;
  int type;
} Callback;

template<typename O, typename F>
Callback* memberCallback( F evt, O obj, int type){
  Callback* c = new Callback();
  c->fn = std::bind(evt, obj, std::placeholders::_1);
  c->type = type;
  return c;
}

#endif


