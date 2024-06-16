
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
class BST:  virtual public ClearableContainer , virtual public DictionaryContainer<Data> ,virtual public BinaryTree<Data>, virtual public BinaryTreeLnk<Data> {
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  // ...

public:

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data> &); // A bst obtained from a TraversableContainer
  BST(MappableContainer<Data> &&); // A bst obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST &);

  // Move constructor
  BST(BST &&);

  /* ************************************************************************ */

  // Destructor
  ~BST();

  /* ************************************************************************ */

  // Copy assignment
  BST & operator=(const BST &);

  // Move assignment
  BST & operator=(BST &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST &) const noexcept;
  bool operator!=(const BST &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  const Data & Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  const Data & Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  const Data & Predecessor(const Data &) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data &); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data &); // (concrete function must throw std::length_error when not found)

  const Data & Successor(const Data &) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data &); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data &); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  const typename BinaryTreeLnk<Data>::NodeLnk & Root() const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data &) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data &&) override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data &) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data &) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary functions, if necessary!

  
  Data DataNDelete(typename BinaryTreeLnk<Data>::NodeLnk *);

  typename BinaryTreeLnk<Data>::NodeLnk * DeleteNode(typename BinaryTreeLnk<Data>::NodeLnk *);


  typename BinaryTreeLnk<Data>::NodeLnk * DetachMin(typename BinaryTreeLnk<Data>::NodeLnk *, typename BinaryTreeLnk<Data>::NodeLnk *);
  typename BinaryTreeLnk<Data>::NodeLnk * DetachMax(typename BinaryTreeLnk<Data>::NodeLnk *, typename BinaryTreeLnk<Data>::NodeLnk *);

  typename BinaryTreeLnk<Data>::NodeLnk * Skip2Left(typename BinaryTreeLnk<Data>::NodeLnk *);
  typename BinaryTreeLnk<Data>::NodeLnk * Skip2Right(typename BinaryTreeLnk<Data>::NodeLnk *);

  typename BinaryTreeLnk<Data>::NodeLnk * Skip2LeftNoDel(typename BinaryTreeLnk<Data>::NodeLnk *);
  typename BinaryTreeLnk<Data>::NodeLnk * Skip2RightNoDel(typename BinaryTreeLnk<Data>::NodeLnk *);


  //const typename BinaryTreeLnk<Data>::NodeLnk * FindPointerToMin(const typename BinaryTreeLnk<Data>::NodeLnk *) const; // Both mutable & unmutable versions
  
  typename BinaryTreeLnk<Data>::NodeLnk * FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk *) const; // Both mutable & unmutable versions
  typename BinaryTreeLnk<Data>::NodeLnk * FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk *) const; // Both mutable & unmutable versions


  typename BinaryTreeLnk<Data>::NodeLnk * FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk *,const Data &, typename BinaryTreeLnk<Data>::NodeLnk *) const; // Both mutable & unmutable versions
  typename BinaryTreeLnk<Data>::NodeLnk * FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk *,const Data &, typename BinaryTreeLnk<Data>::NodeLnk *) const; // Both mutable & unmutable versions

  typename BinaryTreeLnk<Data>::NodeLnk * Remove(typename BinaryTreeLnk<Data>::NodeLnk *,const Data &);

  typename BinaryTreeLnk<Data>::NodeLnk * Insert(typename BinaryTreeLnk<Data>::NodeLnk *,const Data &);
  typename BinaryTreeLnk<Data>::NodeLnk * Insert(typename BinaryTreeLnk<Data>::NodeLnk *, Data &&);

  bool Exists(typename BinaryTreeLnk<Data>::NodeLnk *, const Data &) const;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
