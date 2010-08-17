#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <time.h>
typedef struct timespec timespec_t;
class TimeSpan;
class TimeSpan
{
  timespec_t m_Timespec;
public:
  const static TimeSpan Zero;
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
  inline bool operator ==(const timespec_t& other) 
  { 
    return ( m_Timespec.tv_sec == other.tv_sec &&
             m_Timespec.tv_nsec == other.tv_nsec ); 
  }
  inline bool operator ==(const TimeSpan& other) 
  { 
    return ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec == other.m_Timespec.tv_nsec ); 
  }
  inline bool operator <(const TimeSpan& other) 
  {  
    return m_Timespec.tv_sec < other.m_Timespec.tv_sec || 
           ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec < other.m_Timespec.tv_nsec ); 
  }
  inline bool operator >(const TimeSpan& other) 
  {  
    return m_Timespec.tv_sec > other.m_Timespec.tv_sec || 
           ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec > other.m_Timespec.tv_nsec ); 
  }
  inline bool operator <=(const TimeSpan& other) 
  { return !(*this > other); }
  inline bool operator >=(const TimeSpan& other) 
  { return !(*this < other); }

  inline TimeSpan operator -() { 
    timespec_t tmp;
    tmp.tv_sec = -m_Timespec.tv_sec;
    tmp.tv_nsec = -m_Timespec.tv_nsec;
    return tmp;
  }

};
#endif
