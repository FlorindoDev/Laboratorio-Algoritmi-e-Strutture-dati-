
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {
  typedef unsigned long ulong;

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  ulong size  {0};

  /* ************************************************************************ */

  // Default constructor
  Container()=default;

public:

  // Destructor
  virtual ~Container()=default;

  /* ************************************************************************ */

  // Copy assignment
  Container operator=(const Container &) = delete;

  // Move assignment
  Container operator=(Container &&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(Container &) = delete; // Comparison of abstract types is not possible.
  bool operator!=(Container &) = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual bool Empty() const noexcept{ if (size==0) return true; return false;} // (concrete function should not throw exceptions)

  inline virtual ulong Size() const noexcept{return size;} // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual  ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer & operator=(ClearableContainer &) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ClearableContainer & operator=(ClearableContainer &&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(ClearableContainer &) = delete; // Comparison of abstract types is not possible.
  bool operator!=(ClearableContainer &) = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer {
  // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer & operator=(const ResizableContainer &) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  ResizableContainer & operator=(ResizableContainer &&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(ResizableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.
  bool operator!=(ResizableContainer &) const noexcept = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  inline virtual void Resize(ulong) = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override{
    Resize(0);
  }; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#endif
