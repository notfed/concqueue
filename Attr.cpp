#include "Attr.h"

Attr::Attr(int state)
{
  pthread_attr_init(&m_Attr);
  pthread_attr_setdetachstate(&m_Attr,state);
}
Attr::~Attr()
{
  pthread_attr_destroy(&m_Attr);
}
Attr::operator const pthread_attr_t*()
{
  return &m_Attr;
}
