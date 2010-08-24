#ifndef ACTIONWITHDEADLINE_H
#define ACTIONWITHDEADLINE_H 
#include "DateTime.h"
#include <string>
class ActionWithDeadline
{
  DateTime m_Deadline;
public:
  typedef struct {
    inline bool operator()(const ActionWithDeadline* pa, const ActionWithDeadline* pb)
    { return pa->Deadline() >= pb->Deadline(); } 
  } PtrCompareType;
  inline friend bool operator<(const ActionWithDeadline& pa, const ActionWithDeadline& pb)
  { return pa.m_Deadline < pb.m_Deadline; }
  const DateTime& Deadline() const;
  ActionWithDeadline(const DateTime& deadline);
  virtual void operator()() = 0;
};


#endif
