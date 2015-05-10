#ifndef EVENT_H
#define EVENT_H
#include <list>

typedef struct Event {
  int data[4];
} Event;

typedef void (*EvtCallback)(Event);
typedef void (*MemberEvtCallback)(void*, Event);

class CallbackBase {
  protected:
    virtual void callback() = 0;
};

template<class T>
class CallbackTmpl : public virtual CallbackBase {
  private:
    int type;
  public:
    CallbackTmpl(int, void (T::*)(Event));
    void callback(Event);
};


template <typename T>
using EventCallback = void (T::*)(Event p);

typedef struct Callback {
  void* object;
  int type;
  EvtCallback evt;
} Callback;

Callback* makeCallback(void* object, int type, EvtCallback evt);

#endif


