#ifndef MEMFUN_H
#define MEMFUN_H
template <class T, void* (T::*M)()>
void* CallMemFun(void* _this)
{
  T* t = reinterpret_cast<T*>(_this);
  return (t->*M)();
}
#endif
