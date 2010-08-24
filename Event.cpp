#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

int Event::Signal()
{
  return m_Cond.Signal();
}

int Event::Broadcast()
{
  return m_Cond.Broadcast();
}

int Event::Wait()
{
  return m_Cond.Wait(m_Mutex);
}

int Event::Wait(const DateTime& deadline)
{
  return m_Cond.TimedWait(m_Mutex,deadline);
}
