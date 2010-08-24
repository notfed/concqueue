#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include <string>
template <class A>
class ActionWithDeadline
{
  A m_Action;
  DateTime m_Deadline;
public:
  const DateTime& Deadline() const { return m_Deadline; }
  ActionWithDeadline(const A& name, const DateTime& deadline);
  void Invoke();
  inline friend bool operator<(ActionWithDeadline& pa,ActionWithDeadline& pb)
  { return pa.m_Deadline < pb.m_Deadline; }
};
template <class A>
class ActionWithDeadline_ptr_cmp
{
public:
  inline bool operator()(const ActionWithDeadline<A>* pa, const ActionWithDeadline<A>* pb)
  { return pa->Deadline() >= pb->Deadline(); } 
};
#endif
