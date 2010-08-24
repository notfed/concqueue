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
  inline operator tm_t() const { return m_AbsTime; }
  inline operator time_t() const { return ToTimeT(); }
  inline operator timespec_t() const { timespec_t tmpTime = {ToTimeT(),0}; return tmpTime; }
  time_t ToTimeT() const { return timegm(&m_AbsTime); }
  DateTime operator+(const TimeSpan& addend);
  TimeSpan operator-(const DateTime& minuend);
  bool operator< (const DateTime& right);
  bool operator<= (const DateTime& right); 
  bool operator>= (const DateTime& right); 
  bool operator> (const DateTime& right); 
      
};
inline TimeSpan DateTime::operator-(const DateTime& minuend) 
{ return TimeSpan(static_cast<int>(
                        difftime(this->ToTimeT(),
                        minuend.ToTimeT())), 0); 
}
inline bool DateTime::operator< (const DateTime& right) 
{ return (difftime(*this,right) < 0); }
inline bool DateTime::operator<= (const DateTime& right) 
{ return *this==right || *this<right; }
inline bool DateTime::operator>= (const DateTime& right) 
{ return *this==right || *this>right; }
inline bool DateTime::operator> (const DateTime& right) 
{ return !(*this<right); }
#endif
