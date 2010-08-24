#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include "ActionWithDeadline.h"
#include <string>
class ScheduledMessage : public ActionWithDeadline<ScheduledMessage>
{
  std::string m_Message;
public:
  ScheduledMessage(const char *msg, const DateTime& deadline);
  void operator ()();
};
#endif
