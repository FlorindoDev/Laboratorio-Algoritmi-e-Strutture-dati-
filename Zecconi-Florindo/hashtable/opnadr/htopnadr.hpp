
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include <stdexcept>
#include <vector>
#include <algorithm> // Per la funzione std::shuffle
#include <random>    // Per il generatore di numeri casuali
#include "../../vector/vector.hpp"
#define EMPTY 'e'
#define FULL 'f'
#define TOMB 't'

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */


template <typename Data>
class HashTableOpnAdr: virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  //..

protected:

  using HashTable<Data>::size;  //numero elementi
  using HashTable<Data>::capacita;  //numero slot (M)
  Vector<Data> * Vec = nullptr;  //HashTable
  Vector<ulong> perm {capacita}; //permutazione dei numieri da 1 a M-1
  Vector<char> * VecStato = nullptr;  //vettore dello stato

public:

  // Default constructor
  HashTableOpnAdr(): HashTableOpnAdr(GRANDEZZABASE){};

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(const ulong &); // A hash table of a given size
  HashTableOpnAdr(const TraversableContainer<Data> &); // A hash table obtained from a TraversableContainer
  HashTableOpnAdr(const ulong & , const TraversableContainer<Data> &); // A hash table of a given size obtained from a TraversableContainer
  HashTableOpnAdr(MappableContainer<Data> &&); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(const ulong & , MappableContainer<Data> &&); // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr &);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr &&);

  /* ************************************************************************ */

  // Destructor
  ~HashTableOpnAdr();

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr & operator=(const HashTableOpnAdr &);

  // Move assignment
  HashTableOpnAdr & operator=(HashTableOpnAdr &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr &) const noexcept;
  bool operator!=(const HashTableOpnAdr &) const noexcept;

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

protected:

  // Auxiliary member functions
  void Expand();
  void Riduzione();
  ulong HashKey(const Data &)const override;
  ulong Find(const Data &) const;     //ritorna la Home del elemento se esiste altrimenti la cpacita
  ulong FindEmpty(const Data &) const;
  ulong NumeroPrimo(const ulong &);
  bool CheckPrimo(ulong);
  void PseudoVec(const ulong);
  ulong Probing(/*const Data &,*/ const ulong ) const;
  void InitVecStato();


  //ulong SecondHashing(const Data &);
  // type Remove(argument) specifiers;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
