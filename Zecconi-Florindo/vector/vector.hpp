
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */
#include <stdexcept>
#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: public virtual ResizableContainer, public virtual LinearContainer<Data> {
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;      //grandezza

  Data * elements = nullptr; //puntatore che conterà l'indirizzo per i elementi del vecotr

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong); // A vector with a given initial dimension
  Vector(const TraversableContainer<Data> &); // A vector obtained from a TraversableContainer
  Vector(MappableContainer<Data> &&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector<Data> &);

  // Move constructor
  Vector(Vector<Data> &&);

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector & operator=(const Vector &);

  // Move assignment
  Vector & operator=(Vector &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector &) const noexcept;
  bool operator!=(const Vector &) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  void Resize(const ulong) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  const Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  inline const Data & Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline Data & Front() override; // // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  inline const Data & Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline Data & Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector: public virtual Vector<Data>, public virtual SortableLinearContainer<Data>{
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  // ...

public:

  // Default constructor
  SortableVector() = default;

  // ************************************************************************ 

  // Specific constructors
  SortableVector(ulong size); // A vector with a given initial dimension
  SortableVector(const TraversableContainer<Data> &); // A vector obtained from a TraversableContainer
  SortableVector(MappableContainer<Data> &&); // A vector obtained from a MappableContainer

  // ************************************************************************ 

  // Copy constructor
  SortableVector(const SortableVector &);

  // Move constructor
  SortableVector(SortableVector &&);

  //************************************************************************ 

  // Destructor
  ~SortableVector() = default;

  //************************************************************************

  // Copy assignment
  SortableVector & operator=(const SortableVector &);

  // Move assignment
  SortableVector & operator=(SortableVector &&);

  //*************************************************************************
  //operaorti di confronto
  bool operator==(const SortableVector &) const noexcept;
  bool operator!=(const SortableVector &) const noexcept;

  //***************************************************************************

  //Overide function SortableLinearContainer
  inline void Sort() override{
    this->QuickSort(0, size-1);
  }

protected:

  // Auxiliary functions, if necessary!
};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
