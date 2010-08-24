#ifndef ACTIONWITHDEADLINE_H
#define ACTIONWITHDEADLINE_H 
#include "DateTime.h"
#include <string>
class ActionWithDeadline
{
  DateTime m_Deadline;
public:
  typedef struct {
    bool operator()(const ActionWithDeadline* pa, const ActionWithDeadline* pb)
    { return pa->Deadline() >= pb->Deadline(); } 
  } PtrCompareType;
  ActionWithDeadline(const DateTime& deadline);
  const DateTime& Deadline() const;
  bool operator<(const ActionWithDeadline&) const;
  virtual void operator()() = 0;
};
inline bool ActionWithDeadline::operator<(const ActionWithDeadline& other) const
{ return m_Deadline < other.m_Deadline; }

#endif
