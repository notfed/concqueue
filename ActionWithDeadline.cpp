#include "DateTime.h"
#include "ActionWithDeadline.h"

ActionWithDeadline::ActionWithDeadline(const DateTime& deadline) 
      : m_Deadline(deadline)
{ }

const DateTime& ActionWithDeadline::Deadline() const 
{ return m_Deadline; }

