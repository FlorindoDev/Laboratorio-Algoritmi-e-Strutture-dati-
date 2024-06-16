
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer & operator=(const TestableContainer &) = delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  TestableContainer & operator=(TestableContainer &&) = delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(TestableContainer &) = delete; // Comparison of abstract types is not possible.
  bool operator!=(TestableContainer &&) = delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  inline virtual bool Exists(const Data&) const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
