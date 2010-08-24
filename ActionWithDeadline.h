#ifndef ACTIONWITHDEADLINE_H
#define ACTIONWITHDEADLINE_H 
#include "DateTime.h"
#include <string>
template <class A>
class ActionWithDeadline_ptr_cmp;
template <class A>
class ActionWithDeadline
{
  const A& m_Action;
  DateTime m_Deadline;
public:
  typedef ActionWithDeadline_ptr_cmp<A> PtrCompareType;
  const DateTime& Deadline() const { return m_Deadline; }
  ActionWithDeadline(const A& action, const DateTime& deadline);
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

template <class A>
ActionWithDeadline<A>::ActionWithDeadline(const A& action, const DateTime& deadline) 
    : m_Action(action),
      m_Deadline(deadline)
{ }

#endif
