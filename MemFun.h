#ifndef MEMFUN_H
#define MEMFUN_H
template <class T>
void CallMemFun(T* _this, void (T::*_memfun)())
{
  (_this->*_memfun)();
}

template <class T, class M = void (T::*)()>
class MemFun
{
  T* m_This;
  M m_Memfun;
public:
  MemFun(T* _this, M _memfun)
    : m_This(_this),
      m_Memfun(_memfun)
  { }
  void operator()()
  {
    (m_This->*m_Memfun)();
  }
};
#endif
