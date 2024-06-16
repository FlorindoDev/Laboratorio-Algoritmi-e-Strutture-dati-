
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  struct NodeVec: virtual public MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    //friend class BinaryTreeVec<Data>;

  public:

    Data elemento {};
    ulong posizione {};
    Vector<struct BinaryTreeVec<Data>::NodeVec *> * ptrVec = nullptr;

    //copy costruttore
    NodeVec(const Data &, ulong, Vector<struct BinaryTreeVec<Data>::NodeVec *> *);

    //Move costruttore
    NodeVec(Data &&, ulong, Vector<struct BinaryTreeVec<Data>::NodeVec *> *);

    //Distrtuttore
    ~NodeVec();
    
    const Data & Element() const noexcept override;

    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)
    
    const BinaryTreeVec<Data>::NodeVec & LeftChild() const override;
    const BinaryTreeVec<Data>::NodeVec & RightChild() const override;
    
    Data & Element() noexcept override; // Mutable access to the element (concrete function should not throw exceptions)
    
    BinaryTreeVec<Data>::NodeVec & LeftChild() override;
    BinaryTreeVec<Data>::NodeVec & RightChild() override;

  };


  Vector<struct BinaryTreeVec<Data>::NodeVec *> Vec {};

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data> &); // A binary tree obtained from a TraversableContainer
  
  BinaryTreeVec(MappableContainer<Data> &&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec &);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec &&);

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec & operator=(const BinaryTreeVec &);

  // Move assignment
  BinaryTreeVec & operator=(BinaryTreeVec &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec &) const noexcept;
  bool operator!=(const BinaryTreeVec &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const BinaryTreeVec<Data>::NodeVec & Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  BinaryTreeVec<Data>::NodeVec & Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  using typename TraversableContainer<Data>::TraverseFun;
  void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  using typename MappableContainer<Data>::MapFun;
  void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:
  //...

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
