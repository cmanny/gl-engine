#ifndef EVENT_H
#define EVENT_H
#include <list>

typedef struct Event {
  int data[4];
} Event;

template <typename T>
using EventCallback = void (T::*)(Event p);

class CallbackBase {
  public:
    virtual void callback(Event) = 0;
    virtual int getType() = 0;
};

template<class T>
class Callback : public virtual CallbackBase {
  private:
    int type;
    T* object;
    EventCallback<T> evtCallback;
    
  public:
    Callback(T* t, int type, EventCallback<T>  callback){
      this->object = t;
      this->type = type;
      this->evtCallback = callback;
    }
    void callback(Event evt){
      (object->*evtCallback)(evt);

    }
    int getType(){
      return type;
    }
};

#endif


