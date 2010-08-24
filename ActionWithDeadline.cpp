#include "ActionWithDeadline.h"
#include <string>
#include <iostream>
using namespace std;

template <class A>
ActionWithDeadline<A>::ActionWithDeadline(const A& action, const DateTime& deadline) 
    : m_Action(action),
      m_Deadline(deadline)
{ }

template <class A>
void ActionWithDeadline<A>::Invoke()
{
  m_Action();
}
