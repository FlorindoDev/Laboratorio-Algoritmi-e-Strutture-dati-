
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include <stdexcept>
#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: public virtual  MutableBinaryTree<Data>{
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  struct NodeLnk: virtual public MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

    // ...
  
  protected:

    /*
    friend class BinaryTreeLnk<Data>;

    //aggiustare _X_
    
    struct Node * FiglioSx = nullptr;
    struct Node * FiglioDx = nullptr;
    */

  public:

    Data elemento {};
    struct NodeLnk * FiglioSx = nullptr;
    struct NodeLnk * FiglioDx = nullptr;

    //copy costruttore
    NodeLnk(const Data&);

    //Move costruttore
    NodeLnk(Data &&);

    //Distrtuttore
    ~NodeLnk();
    
    const Data & Element() const noexcept override;

    bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)
    
    const BinaryTreeLnk<Data>::NodeLnk & LeftChild() const override;
    const BinaryTreeLnk<Data>::NodeLnk & RightChild() const override;
    
    Data & Element() noexcept override; // Mutable access to the element (concrete function should not throw exceptions)
    
    BinaryTreeLnk<Data>::NodeLnk & LeftChild() override;
    BinaryTreeLnk<Data>::NodeLnk & RightChild() override;
    
  };


  struct NodeLnk * root = nullptr;

  //funzioni asuiliari
  void InsertInTree(const Data &);
  void InsertInTree(Data &&);

  BinaryTreeLnk<Data>::NodeLnk* CopiaAlbero(BinaryTreeLnk<Data>::NodeLnk*);


public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data> &); // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data> &&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk &&);

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk & operator=(const BinaryTreeLnk &);

  // Move assignment
  BinaryTreeLnk & operator=(BinaryTreeLnk &&);

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk &) const noexcept;
  bool operator!=(const BinaryTreeLnk &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  const BinaryTreeLnk<Data>::NodeLnk & Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  BinaryTreeLnk<Data>::NodeLnk & Root() override;  // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
