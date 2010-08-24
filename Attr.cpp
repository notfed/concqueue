#include "Attr.h"
#include <stdexcept>

Attr::Attr(int state)
{
  if(pthread_attr_init(&m_Attr)!=0)
    throw std::runtime_error("pthread_attr_init failed");
  if(pthread_attr_setdetachstate(&m_Attr,state)!=0)
    throw std::runtime_error("pthread_attr_setdetachstate failed");
}
Attr::~Attr()
{
  if(pthread_attr_destroy(&m_Attr)!=0)
    throw std::runtime_error("pthread_attr_destroy failed");
}
Attr::operator const pthread_attr_t*()
{
  return &m_Attr;
}
