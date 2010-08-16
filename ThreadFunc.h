#ifndef THREADFUNC_H
#define THREADFUNC_H
template< class C > 
class Ptrs {
public:
  typedef void* (*FuncPtr)(void*);    // FuncPtr : Function pointer
  typedef void* (C::*MembPtr)(void*); // MembPtr : Member function pointer
};
template< class C > 
typename Ptrs<C>::MembPtr ThreadFunc(C*& _object, typename Ptrs<C>::MembPtr theMethod)
{
  C*& theObject = _object;
  return theObject->*theMethod;
}
#endif
