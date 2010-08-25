#ifndef ID_H
#define ID_H

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

#endif
