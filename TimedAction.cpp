#include "TimedAction.h"
#include <string>
#include <iostream>
using namespace std;

template <class A>
TimedAction<A>::TimedAction(const A& action, const DateTime& deadline) 
    : m_Action(action),
      m_Deadline(deadline)
{ }

template <class A>
void TimedAction<A>::Invoke()
{
  m_Action();
}
