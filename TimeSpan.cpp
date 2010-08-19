#include "TimeSpan.h"
const TimeSpan TimeSpan::Zero = TimeSpan(0,0);

std::ostream& operator<<(std::ostream& out,const TimeSpan& ts)
{
  if(ts.Seconds()<1)
    out << ts.Milliseconds() << "ms";
  else
    out << ts.Seconds() << "sec";
  return out;
}

