#ifndef DATETIME_H
#define DATETIME_H
#include "TimeSpan.h"
#include <ostream>
#include <time.h>
typedef struct tm tm_t;
typedef struct timespec timespec_t;
class DateTime
{
  mutable tm_t m_AbsTime;
public:
  static DateTime Now();
  inline DateTime(const tm_t& tm) { m_AbsTime = tm; }
  inline operator tm_t&() { return m_AbsTime; }
  inline operator time_t() const { return ToTimeT(); }
  inline operator timespec_t() const { timespec_t tmpTime = {ToTimeT(),0}; return tmpTime; }
  time_t ToTimeT() const { return timegm(&m_AbsTime); }
  DateTime operator+(const TimeSpan& addend);
  inline TimeSpan operator-(const DateTime& minuend) 
  { return TimeSpan(static_cast<int>(
                        difftime(this->ToTimeT(),
                        minuend.ToTimeT())), 0); 
  }
  inline friend bool operator< (DateTime& left, DateTime& right) 
  { return (difftime(left,right) < 0); }
  inline friend bool operator<= (DateTime& left, DateTime& right) 
  { return left==right || left<right; }
  inline friend bool operator>= (DateTime& left, DateTime& right) 
  { return left==right || left>right; }
  inline friend bool operator> (DateTime& left, DateTime& right) { return !(left<right); }
      
};
#endif
