#ifndef TIME_H
#define TIME_H
#include <time.h>
typedef struct timespec timespec_t;
class TimeSpec
{
  timespec_t m_Timespec;
public:
  inline TimeSpec(timespec_t& timespec) { m_Timespec = timespec; }
  inline operator timespec_t&() { return m_Timespec; }
};
#endif
