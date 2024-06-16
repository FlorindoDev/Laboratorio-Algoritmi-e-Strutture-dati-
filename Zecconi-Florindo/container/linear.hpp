
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderMappableContainer<Data>, virtual public PostOrderMappableContainer<Data>{
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer &) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer &&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const LinearContainer &) const noexcept; // Comparison of abstract types is possible.
  inline bool operator!=(const LinearContainer &) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data & operator[](const ulong) const = 0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data & operator[](const ulong) = 0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  inline virtual const Data & Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Front(); // (mutable version; concrete function must throw std::length_error when empty)

  inline virtual const Data & Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data & Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  inline void Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer: virtual public LinearContainer<Data>{
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator=(const SortableLinearContainer &) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  SortableLinearContainer& operator=(SortableLinearContainer &&) = delete; // Move assignment of abstract types is not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(SortableLinearContainer &) const noexcept; // Comparison of abstract types is possible.
  bool operator!=(SortableLinearContainer &) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() = 0;

protected:

  // Auxiliary member functions
  void QuickSort(ulong p, ulong r);
  ulong Partiziona(ulong p, ulong r);
  

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
