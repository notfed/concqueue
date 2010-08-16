#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <time.h>
typedef struct timespec timespec_t;
class TimeSpan
{
  timespec_t m_Timespec;
public:
  inline TimeSpan(timespec_t& timespec) { m_Timespec = timespec; }
  inline TimeSpan(int secs, int nsecs) 
    { m_Timespec.tv_sec = secs;  m_Timespec.tv_nsec = nsecs; }
  inline time_t Seconds() const { return m_Timespec.tv_sec; }
  inline operator timespec_t&() { return m_Timespec; }
  inline TimeSpan operator+(TimeSpan& addend) { 
    timespec_t tmp = addend.m_Timespec;
    m_Timespec.tv_sec += tmp.tv_sec;
    m_Timespec.tv_nsec += tmp.tv_nsec;
    return TimeSpan(tmp);
  }
};
#endif
