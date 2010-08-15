#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

Person::Person(const char *name) 
    : m_Name(name)
{ }

void Person::SayHi() const
{
  cout << "Hi! My name is " << m_Name << "!" << endl;
}
