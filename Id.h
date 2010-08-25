#ifndef ID_H
#define ID_H

// 
// Id.h
//
// The Id class can be used to create a sequence of numbers.  
// This sequence is then used to generate unique id numbers for objects of a given class.
// 
template <class T>
class Id
{
  static volatile int max_id;
public:
  const int id;
  Id();
  operator int();
};

template <class T>
volatile int Id<T>::max_id = 0;

template <class T>
Id<T>::Id()
  : id(++max_id)
{
}

template <class T>
Id<T>::operator int()
{
  return id;
}

template <class T>
class HasId
{
public:
  const int id;
  HasId() : id(Id<T>()) { }
};

#endif
