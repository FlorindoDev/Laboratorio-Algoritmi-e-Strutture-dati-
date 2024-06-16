
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include <stdexcept>
#include "../../bst/bst.hpp"
#include "../../vector/vector.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data>{
  // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::size; //numero elementi 
  using HashTable<Data>::capacita;  //numero slot (M)
  Vector<BST<Data> *> Vec {};

  // ...

public:

  // Default constructor
  HashTableClsAdr(): HashTableClsAdr(GRANDEZZABASE){}

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(const ulong & ); // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data> &); // A hash table obtained from a TraversableContainer
  HashTableClsAdr(const ulong & , const TraversableContainer<Data> &); // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data> &&) ; // A hash table obtained from a MappableContainer
  HashTableClsAdr(const ulong & , MappableContainer<Data> &&) ; // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr &);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr &&);

  /* ************************************************************************ */

  // Destructor
  ~HashTableClsAdr();

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr & operator=(const HashTableClsAdr &);

  // Move assignment
  HashTableClsAdr & operator=(HashTableClsAdr &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableClsAdr &) const noexcept;
  bool operator!=(const HashTableClsAdr &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data &&) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data &) override ; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data &) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(ulong) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override; // Override Container member

  //_X_
  // void stamp();
};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
