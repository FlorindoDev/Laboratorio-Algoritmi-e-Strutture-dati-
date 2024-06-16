
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue: public virtual ClearableContainer{
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  Queue & operator=(const Queue &) noexcept = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  Queue & operator=(Queue &&) noexcept = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Queue &) = delete; // Comparison of abstract types is not possible.
  bool operator!=(Queue &&) = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data & Head() const = 0; // (non-mutable version; concrete function must throw std::length_error when empty)
  virtual Data & Head() = 0; // (mutable version; concrete function must throw std::length_error when empty)
  virtual void Dequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual Data HeadNDequeue() = 0; // (concrete function must throw std::length_error when empty)
  virtual void Enqueue(const Data &) = 0; // Copy of the value
  virtual void Enqueue(Data &&) = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
