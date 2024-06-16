
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: public virtual Queue<Data>, public virtual List<Data> {
  // Must extend Queue<Data>,
  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;

  // ...

public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const TraversableContainer<Data> & trav): List<Data>(trav){}; // A stack obtained from a TraversableContainer

  QueueLst(MappableContainer<Data> && MapC): List<Data>(std::move(MapC)){}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst & QLst): List<Data>(QLst){};

  // Move constructor
  QueueLst( QueueLst && QLst): List<Data>(std::move(QLst)){};

  /* ************************************************************************ */

  // Destructor
  ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst & operator=( const QueueLst &);

  // Move assignment
  QueueLst & operator=(QueueLst &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const QueueLst &) const noexcept;
  bool operator!=(const QueueLst &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  const Data & Head() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  Data & Head() override; // (mutable version; concrete function must throw std::length_error when empty)
  void Dequeue() override; // (concrete function must throw std::length_error when empty)
  Data HeadNDequeue() override; // (concrete function must throw std::length_error when empty)
  void Enqueue(const Data &) override; // Copy of the value
  void Enqueue(Data &&) override; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
