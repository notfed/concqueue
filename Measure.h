#ifndef MEASURE_H
#define MEASURE_H
#include "DateTime.h"
#include <string>
// Takes note of time of construction, then writes the
// result upon destruction.
class Measure
{
  DateTime m_StartTime;
  std::string m_Name;
public:
  Measure(std::string name)
    : m_StartTime(DateTime::Now()),
      m_Name(name)
  {}
  ~Measure();
};
#endif
