#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include <string>
template <class A>
class TimedAction
{
  A m_Action;
  DateTime m_Deadline;
public:
  const DateTime& Deadline() const { return m_Deadline; }
  TimedAction(const A& name, const DateTime& deadline);
  void Invoke();
  inline friend bool operator<(TimedAction& pa,TimedAction& pb)
  { return pa.m_Deadline < pb.m_Deadline; }
};
template <class A>
class TimedAction_ptr_cmp
{
public:
  inline bool operator()(const TimedAction<A>* pa, const TimedAction<A>* pb)
  { return pa->Deadline() >= pb->Deadline(); } 
};
#endif
