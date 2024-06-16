
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>
#include <string>
#include <stdexcept>
#include <cstring>
#include <cmath>

/* ************************************************************************** */

#include "../container/dictionary.hpp"
#define GRANDEZZABASE 16

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  virtual ulong operator()(const Data &) noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable:  virtual public ResizableContainer, virtual public DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  ulong capacita {};

  // ...

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable & operator=(const HashTable &) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable & operator=(HashTable &&) = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  virtual ulong HashKey(const Data & key) const{
    Hashable<Data> h {}; 
    return h.operator()(key) % capacita;
  };

  // //_X_
  // virtual void stamp() = 0;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
