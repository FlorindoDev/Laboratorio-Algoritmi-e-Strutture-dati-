
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: public virtual Stack<Data>, public virtual List<Data> {
  // Must extend Stack<Data>,
  //             List<Data>

private:

  // ...

protected:


  using List<Data>::size;

  // ...

public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const TraversableContainer<Data> & con): List<Data>(con){}; // A stack obtained from a TraversableContainer
  StackLst(MappableContainer<Data> && con): List<Data>(std::move(con)){}; // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst & Stklist): List<Data>(Stklist){};

  // Move constructor
  StackLst(StackLst && Stklist): List<Data>(std::move(Stklist)){};

  /* ************************************************************************ */

  // Destructor
  ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst & operator=(const StackLst &);

  // Move assignment
  StackLst & operator=(StackLst &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackLst &) const;
  bool operator!=(const StackLst &) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data & Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data & Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data &) override; // Override Stack member (copy of the value)
  void Push(Data &&) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
