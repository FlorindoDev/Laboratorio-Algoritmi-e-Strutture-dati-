
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: public virtual Queue<Data>, public virtual Vector<Data>{
  // Must extend Queue<Data>,
  //             Vector<Data>

private:

  // ...

protected:
  
  ulong testa = 0;
  ulong coda = 0;
  using Vector<Data>::size;
  using Vector<Data>::elements;

  // ...

public:

  // Default constructor
  QueueVec(): Vector<Data>(4){};

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const TraversableContainer<Data> & trav); // A stack obtained from a TraversableContainer

  QueueVec(MappableContainer<Data> && MapC); // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec & QVec): Vector<Data>(QVec), testa(QVec.testa), coda(QVec.coda){}

  // Move constructor
  QueueVec(QueueVec && );

  /* ************************************************************************ */

  // Destructor
  ~QueueVec();

  /* ************************************************************************ */

  // Copy assignment
  QueueVec & operator=(const QueueVec &);

  // Move assignment
  QueueVec & operator=(QueueVec &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueVec &) const noexcept;
  bool operator!=(const QueueVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data & Head() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  Data & Head() override; // (mutable version; concrete function must throw std::length_error when empty)
  void Dequeue() override; // (concrete function must throw std::length_error when empty)
  Data HeadNDequeue() override; // (concrete function must throw std::length_error when empty)
  void Enqueue(const Data &) override; // Copy of the value
  void Enqueue(Data &&) override; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override; // Override Container member

  inline ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void Riduzione();
  void Ingradimento();
  void ResizeQ(const ulong new_size, ulong num_elements);
  

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
