#include "DateTime.h"
DateTime DateTime::Now()
{
  time_t myTime;
  tm_t myTm;
  time(&myTime);
  gmtime_r(&myTime,&myTm);
  return DateTime(myTm);
}
DateTime DateTime::operator+(TimeSpan addend) const
{
  DateTime newDt(m_AbsTime);
  tm_t oldDt = m_AbsTime;
  time_t me = timegm(&oldDt);
  me += addend.Seconds();
  gmtime_r(&me,&newDt.m_AbsTime);
  return newDt;
}

