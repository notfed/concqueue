#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(const char *name, const DateTime& deadline) 
    : ActionWithDeadline<Person>(*this,deadline),
      m_Name(name)
 
{ }

void Person::operator()() 
{
  cout << "Hi! My name is " << m_Name << "!" << endl;
}
