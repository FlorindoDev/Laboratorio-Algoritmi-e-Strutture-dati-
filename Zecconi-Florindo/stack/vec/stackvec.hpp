
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */
#include <stdexcept>
#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: public virtual Stack<Data>, public virtual Vector<Data> {
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:

  ulong indice = 0;
  using Vector<Data>::size;
  using Vector<Data>::elements;

  // ...

public:

  // Default constructor
  StackVec(): Vector<Data>(1){};

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data> & trav): Vector<Data>(trav), indice(size){} // A stack obtained from a TraversableContainer

  StackVec(MappableContainer<Data> && MapC): Vector<Data>(std::move(MapC)), indice(size){} // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  inline StackVec(const StackVec<Data> & Stkvec): Vector<Data>(Stkvec), indice(Stkvec.indice){};

  // Move constructor
  inline StackVec(StackVec<Data> &&);

  /* ************************************************************************ */

  // Destructor
  ~StackVec();

  /* ************************************************************************ */

  // Copy assignment
  StackVec & operator=(const StackVec &);

  // Move assignment
  StackVec & operator=(StackVec &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec &) const;
  bool operator!=(const StackVec &) const;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data & Top() const override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data & Top() override; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data  TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data &) override; // Override Stack member (copy of the value)
  void Push(Data &&) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override ; // Override Container member

  inline ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!
  void Riduzione();
  void Ingradimento();
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
