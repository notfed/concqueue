#ifndef ACTIONWITHDEADLINE_H
#define ACTIONWITHDEADLINE_H 
#include "DateTime.h"
#include <string>
template <class A> class ActionWithDeadline_ptr_cmp;

template <class A>
class ActionWithDeadline
{
  DateTime m_Deadline;
public:
  typedef ActionWithDeadline_ptr_cmp<A> PtrCompareType;
  const DateTime& Deadline() const { return m_Deadline; }
  ActionWithDeadline(const DateTime& deadline);
  virtual void operator()() = 0;
};

template <class A>
bool operator<(ActionWithDeadline<A>& pa,ActionWithDeadline<A>& pb)
{ return pa.Deadline() < pb.Deadline(); }

template <class A>
class ActionWithDeadline_ptr_cmp
{
public:
  inline bool operator()(const ActionWithDeadline<A>* pa, const ActionWithDeadline<A>* pb)
  { return pa->Deadline() >= pb->Deadline(); } 
};

template <class A>
ActionWithDeadline<A>::ActionWithDeadline(const DateTime& deadline) 
      : m_Deadline(deadline)
{ }

#endif
