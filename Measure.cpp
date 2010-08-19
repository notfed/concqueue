#include "Measure.h"
#include <iostream>
using namespace std;

Measure::~Measure()
{
  if(!m_Name.empty()) cerr << m_Name << " took ";
  else cerr << " Took ";
  cerr << TimeSpan(DateTime::Now() - m_StartTime);
}
