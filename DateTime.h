#ifndef DATETIME_H
#define DATETIME_H
#include "TimeSpan.h"
#include <ostream>
#include <ctime>
typedef struct tm tm_t;
typedef struct timespec timespec_t;
class DateTime
{
  tm_t m_AbsTime;
public:
  static DateTime Now();
  DateTime(const tm_t& tm);
  operator tm_t() const;
  operator time_t() const;
  operator timespec_t() const;
  DateTime operator+(const TimeSpan& addend) const;
  TimeSpan operator-(const DateTime& minuend) const;
  bool operator< (const DateTime& right) const;
  bool operator<= (const DateTime& right) const; 
  bool operator>= (const DateTime& right) const; 
  bool operator> (const DateTime& right) const; 
      
};
inline DateTime::DateTime(const tm_t& tm) { m_AbsTime = tm; }
inline DateTime::operator tm_t() const { return m_AbsTime; }
inline DateTime::operator time_t() const { tm_t tmp = m_AbsTime; return timegm(&tmp); }
inline DateTime::operator timespec_t() const { timespec_t tmpTime = {static_cast<time_t>(*this),0}; return tmpTime; }
inline TimeSpan DateTime::operator-(const DateTime& minuend) const
{ return TimeSpan(static_cast<int>( difftime(static_cast<time_t>(*this),
                                              static_cast<time_t>(minuend))),0); 
}
inline bool DateTime::operator< (const DateTime& right) const
{ return (difftime(*this,right) < 0); }
inline bool DateTime::operator<= (const DateTime& right) const
{ return *this==right || *this<right; }
inline bool DateTime::operator>= (const DateTime& right) const
{ return *this==right || *this>right; }
inline bool DateTime::operator> (const DateTime& right) const
{ return !(*this<right); }
#endif
