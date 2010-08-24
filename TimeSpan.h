#ifndef TIMESPAN_H
#define TIMESPAN_H
#include <ctime>
#include <ostream>
typedef struct timespec timespec_t;
class TimeSpan
{
  timespec_t m_Timespec;
public:
  const static TimeSpan Zero;
  TimeSpan(const timespec_t& timespec);
  TimeSpan(int secs, int nsecs); 
  double Milliseconds() const; 
  double Seconds() const;
  operator const timespec_t&();
  TimeSpan operator+(const timespec_t& addend) const;
  TimeSpan operator+(const TimeSpan& addend) const;
  TimeSpan operator-() const;
  bool operator ==(const timespec_t& other) const; 
  bool operator ==(const TimeSpan& other) const; 
  bool operator <(const TimeSpan& other) const; 
  bool operator >(const TimeSpan& other) const; 
  bool operator <=(const TimeSpan& other) const; 
  bool operator >=(const TimeSpan& other) const; 
};
std::ostream& operator<<(std::ostream& out,const TimeSpan& ts);

inline TimeSpan::TimeSpan(const timespec_t& timespec) 
{ m_Timespec = timespec; }
inline TimeSpan::TimeSpan(int secs, int nsecs) 
{ 
  m_Timespec.tv_sec = secs + static_cast<int>(nsecs/1000000);  
  m_Timespec.tv_nsec = nsecs%1000000; 
}
inline double TimeSpan::Milliseconds() const 
{ 
    return static_cast<double>(m_Timespec.tv_sec)/1000 +
           static_cast<double>(m_Timespec.tv_nsec)*1000; 
}
inline double TimeSpan::Seconds() const 
{ 
    return static_cast<double>(m_Timespec.tv_sec)+
           static_cast<double>(m_Timespec.tv_nsec)*1000000; 
}
inline TimeSpan::operator const timespec_t&() 
{ return m_Timespec; }
inline TimeSpan TimeSpan::operator+(const timespec_t& addend) const { 
    TimeSpan newTime(addend);
    newTime.m_Timespec.tv_sec += addend.tv_sec + static_cast<int>(addend.tv_nsec/1000000);
    newTime.m_Timespec.tv_nsec += addend.tv_nsec + addend.tv_nsec%1000000;
    return newTime;
}
inline TimeSpan TimeSpan::operator+(const TimeSpan& addend) const { 
    TimeSpan newTime(addend.m_Timespec);
    return newTime + m_Timespec;
}
inline bool TimeSpan::operator ==(const timespec_t& other) const
{ 
    return ( m_Timespec.tv_sec == other.tv_sec &&
             m_Timespec.tv_nsec == other.tv_nsec ); 
}
inline bool TimeSpan::operator ==(const TimeSpan& other) const
{ 
    return ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec == other.m_Timespec.tv_nsec ); 
}
inline bool TimeSpan::operator <(const TimeSpan& other) const
{  
    return m_Timespec.tv_sec < other.m_Timespec.tv_sec || 
           ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec < other.m_Timespec.tv_nsec ); 
}
inline bool TimeSpan::operator >(const TimeSpan& other) const
{  
    return m_Timespec.tv_sec > other.m_Timespec.tv_sec || 
           ( m_Timespec.tv_sec == other.m_Timespec.tv_sec &&
             m_Timespec.tv_nsec > other.m_Timespec.tv_nsec ); 
}
inline bool TimeSpan::operator <=(const TimeSpan& other) const
{ return !(*this > other); }
inline bool TimeSpan::operator >=(const TimeSpan& other) const
{ return !(*this < other); }

inline TimeSpan TimeSpan::operator -() const { 
    timespec_t tmp;
    tmp.tv_sec = -m_Timespec.tv_sec;
    tmp.tv_nsec = -m_Timespec.tv_nsec;
    return tmp;
}

#endif
