#include "Attr.h"

Attr::Attr(int state)
{
  if(pthread_attr_init(&m_Attr)!=0)
    throw "Couldn't initialize Attr";
  if(pthread_attr_setdetachstate(&m_Attr,state)!=0)
    throw "Couldn't setdetachstate for Attr";
}
Attr::~Attr()
{
  if(pthread_attr_destroy(&m_Attr)!=0)
    throw "Couldn't destroy Attr";
}
Attr::operator const pthread_attr_t*()
{
  return &m_Attr;
}
