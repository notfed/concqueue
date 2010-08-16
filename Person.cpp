#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(const char *name, const DateTime& deadline) 
    : m_Name(name),
      m_Deadline(deadline)
{ }

void Person::SayHi() const
{
  cout << "Hi! My name is " << m_Name << "!" << endl;
}
