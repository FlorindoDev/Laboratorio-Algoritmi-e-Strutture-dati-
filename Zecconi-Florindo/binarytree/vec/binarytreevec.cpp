#include "binarytreevec.hpp"

namespace lasd {

/* ************************************************************************** */
/*                          Costruttori e distruttori NodoVec                 */
/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data & dat, ulong pos, Vector<struct BinaryTreeVec<Data>::NodeVec *> * ptr){
    elemento = dat;
    posizione = pos;
    ptrVec = ptr;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data && dat, ulong pos, Vector<struct BinaryTreeVec<Data>::NodeVec *> * ptr){
    std::swap(elemento,dat);
    std::swap(posizione,pos);
    std::swap(ptrVec,ptr);
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::~NodeVec(){
    ptrVec->operator[](this->posizione) = nullptr;

    if(HasLeftChild()){
       delete &LeftChild(); 
    }
    if(HasRightChild()){
        delete &RightChild();
    }
    this->ptrVec = nullptr;
    

}

/* ************************************************************************** */
/*                          Funzioni specifiche di NodoVec                    */
/* ************************************************************************** */

template <typename Data>
const Data & BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
    return elemento;

}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if((2*posizione + 1) >= ptrVec->Size()) return false;
    if(ptrVec->operator[](2*posizione + 1) == nullptr) return false;
    return true;

}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if((2*posizione + 2) >= ptrVec->Size()) return false;
    if(ptrVec->operator[](2*posizione + 2)  == nullptr) return false;
    return true;

}


template <typename Data>
const BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if((2*posizione + 1) >= ptrVec->Size()) throw std::out_of_range("non ha figlio sinistro");
    return *ptrVec->operator[](2*posizione + 1);
    

}

template <typename Data>
const BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if((2*posizione + 2) >= ptrVec->Size()) throw std::out_of_range("non ha figlio destro");
    return *ptrVec->operator[](2*posizione + 2);
    

}


template <typename Data>
Data & BinaryTreeVec<Data>::NodeVec::Element() noexcept{
    return elemento;

}

template <typename Data>
BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::LeftChild(){
    if((2*posizione + 1) >= ptrVec->Size()) throw std::out_of_range("non ha figlio sinistro");
    return *ptrVec->operator[](2*posizione + 1);
    

}

template <typename Data>
BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::NodeVec::RightChild(){
    if((2*posizione + 2) >= ptrVec->Size()) throw std::out_of_range("non ha figlio destro");
    return *ptrVec->operator[](2*posizione + 2);
    
}

/* ************************************************************************** */
/*                          Costruttore e Distrtuttore                        */
/* ************************************************************************** */


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data> & trav){
    if(trav.Size() > 0){
        Vec.Resize(trav.Size());
        ulong cont = 0;
        trav.Traverse(
            [this, &cont](const Data & dat){
                Vec[cont] = new NodeVec(dat, cont, &(this->Vec));
                cont++;
                this->size++;
            }
        );   
    }
     
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data> && MapC){
    if(MapC.Size() > 0){
        Vec.Resize(MapC.Size());
        ulong cont = 0;
        MapC.Map(
            [this, &cont](Data & dat){
                Vec[cont] = new NodeVec(dat, cont, &(this->Vec));
                cont++;
                this->size++;
            }
        );   
    }
}

//copy
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec & btv){
    if(btv.Vec.Size() > 0){
        Vec.Resize(btv.Vec.Size());
        ulong cont = 0;
        btv.Vec.Traverse(
            [this, &cont](const BinaryTreeVec<Data>::NodeVec * dat){
                Vec[cont] = new NodeVec(dat->elemento, cont, &(Vec));
                cont++;
                this->size++;
            }
        );
    }
    
}

//move
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec && btv){
    std::swap(btv.Vec, this->Vec);
    std::swap(btv.size, this->size);
    
    Vec.Traverse(
        [this, &btv](BinaryTreeVec<Data>::NodeVec * dat){
            dat->ptrVec = &(this->Vec);
        }
    );
    
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    if(size > 0) delete Vec[0];
    //delete &Vec;
}

/* ************************************************************************** */
/*                                 Operaotri                                  */
/* ************************************************************************** */

//copy
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data> & btv){
    BinaryTreeVec<Data> *tmp = new BinaryTreeVec(btv);
    std::swap(*tmp,*this);
    delete tmp;
    return *this;
    
}


//move
template <typename Data>
BinaryTreeVec<Data> & BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data> && btv){
    std::swap(this->Vec, btv.Vec);
    std::swap(this->size, btv.size);

    btv.Vec.Traverse(
        [&btv](BinaryTreeVec<Data>::NodeVec * dat){
            dat->ptrVec = &(btv.Vec);
        }
    );
    
    Vec.Traverse(
        [this](BinaryTreeVec<Data>::NodeVec * dat){
            dat->ptrVec = &(this->Vec);
        }
    );
    

    return *this;
}


template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data> & btv) const noexcept{
    return BinaryTree<Data>::operator==(btv);
}


template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data> & btv) const noexcept{
    return !(*this == btv);
}


/* ************************************************************************** */
/*                             funzioni specifiche                            */
/* ************************************************************************** */

template <typename Data>
const BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::Root() const {
    if(Vec.Size() == 0) throw std::length_error("non c'è root!");
    if(Vec[0] == nullptr) throw std::length_error("non c'è root!");
    return *Vec[0];
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec & BinaryTreeVec<Data>::Root(){
    if(Vec.Size() == 0) throw std::length_error("non c'è root!");
    if(Vec[0] == nullptr) throw std::length_error("non c'è root!");
    return *Vec[0];
}


template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    if(this->size > 0){
        delete Vec[0];
        this->size = 0;
        Vec.Clear();
    }
    
}



/* ************************************************************************** */
/*                             funzioni Ausiliari                             */
/* ************************************************************************** */


template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun) {

    for(ulong i=0; i<Vec.Size(); i++) {
        fun(Vec[i]->Element());
    }

}


template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const {
    
    for(ulong i=0; i<Vec.Size(); i++) {
        fun(Vec[i]->Element());
    }
    
}

/* ************************************************************************** */




}
