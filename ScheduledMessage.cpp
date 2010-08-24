#include "ScheduledMessage.h"
#include <string>
#include <iostream>
using namespace std;

ScheduledMessage::ScheduledMessage(const char *msg, const DateTime& deadline) 
    : ActionWithDeadline(deadline),
      m_Message(msg)
 
{ }

void ScheduledMessage::operator()() 
{
  cout << m_Message << endl;
}
