#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include <string>
class Person
{
  std::string m_Name;
  DateTime m_Deadline;
public:
  Person(const char *name, const DateTime& deadline);
  void SayHi() const;
  inline friend bool operator<(Person& pa,Person& pb)
  { return pa.m_Deadline < pb.m_Deadline; }
};
#endif
