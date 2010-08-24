#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include "ActionWithDeadline.h"
#include <string>
class Person : public ActionWithDeadline<Person>
{
  std::string m_Name;
public:
  Person(const char *name, const DateTime& deadline);
  void operator ()();
};
#endif
