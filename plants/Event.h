#ifndef EVENT_H
#define EVENT_H
#include <list>

typedef struct Event {
  int data[4];
} Event;

typedef void (*EvtCallback)(Event);
typedef void (*MemberEvtCallback)(void*, Event);

typedef struct Callback {
  void* object;
  int type;
  EvtCallback evt;
} Callback;

Callback* makeCallback(void* object, int type, EvtCallback evt);

#endif


