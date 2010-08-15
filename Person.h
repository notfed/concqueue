#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person
{
  std::string m_Name;
public:
  Person(const char *name);
  void SayHi() const;
};
#endif
