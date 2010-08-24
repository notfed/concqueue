#ifndef SCHEDULEDMESSAGE_H
#define SCHEDULEDMESSAGE_H
#include "DateTime.h"
#include "ActionWithDeadline.h"
#include <string>
class ScheduledMessage : public ActionWithDeadline
{
  std::string m_Message;
public:
  ScheduledMessage(const char *msg, const DateTime& deadline);
  void operator ()();
};
#endif
