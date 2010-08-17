#ifndef PERSON_H
#define PERSON_H
#include "DateTime.h"
#include <string>
class Person
{
  std::string m_Name;
  DateTime m_Deadline;
public:
  const DateTime& Deadline() const { return m_Deadline; }
  Person(const char *name, const DateTime& deadline);
  void SayHi() const;
  inline friend bool operator<(Person& pa,Person& pb)
  { return pa.m_Deadline < pb.m_Deadline; }
};
class Person_ptr_cmp
{
public:
  inline bool operator()(const Person* pa, const Person* pb)
  { return pa->Deadline() >= pb->Deadline(); } 
};
#endif
