#include "list.hpp"

namespace lasd {

/* ************************************************************************** */

//Specific member functions (Node)

// Specific constructors
template<typename Data>
List<Data>::Node::Node(Data && dat) noexcept{
    std::swap(valore, dat);
}

// Move constructors
template<typename Data>
List<Data>::Node::Node(Node && nod) noexcept{
    std::swap(valore, nod.valore);
    std::swap(NextNode, nod.NextNode);
}

//Destructor
template<typename Data>
List<Data>::Node::~Node() {
    delete NextNode;
}

//Comparison operators (Node)

template<typename Data>
bool List<Data>::Node::operator==(const Node & nod) const noexcept {
    return (this->valore==nod.valore && ((this->NextNode==nullptr && nod.NextNode==nullptr) || ((NextNode != nullptr && nod.NextNode != nullptr) && (*NextNode == *(nod.NextNode)))));
}

template<typename Data>
inline bool List<Data>::Node::operator!=(const Node & nod) const noexcept {
    return !(*this==nod);
}


//******************************************************************************************
//funzioni specifiche Node

//******************************************************************************************
template<typename Data>
List<Data>::List(const TraversableContainer<Data> & con){
    con.Traverse(
        [this](const Data & dat) {
            InsertAtBack(dat);
        }
    );
}

template<typename Data>
List<Data>::List(MappableContainer<Data> && con){
    con.Map(
        [this](Data & dat) {
            InsertAtBack(std::move(dat));
        }
    );
}


//Copy constructor List
template<typename Data>
List<Data>::List(const List & lst){
   
    Node* corrente = lst.testa;
    while(corrente != nullptr){
        this->InsertAtBack(corrente->valore);
        corrente = corrente->NextNode;
    }
   
}

//Move constructor List
template<typename Data>
List<Data>::List(List && lst) noexcept{
    std::swap(testa, lst.testa);
    std::swap(coda, lst.coda);
    std::swap(size, lst.size);
}

// Destructor
template<typename Data>
List<Data>::~List(){
    delete testa;
}


// Copy assignment
template<typename Data>
List<Data>& List<Data>::operator=(const List& lst){
    List<Data> * tmp = new List<Data>(lst);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

// Move assignment
template<typename Data>
List<Data>& List<Data>::operator=(List && lst) noexcept{
    std::swap(testa, lst.testa);
    std::swap(coda, lst.coda);
    std::swap(size, lst.size);

    return *this;
    
}

//*****************************************************************************************
//operatori specifici

template<typename Data>
inline bool List<Data>::operator==(const List & lis) const noexcept {
    
    if(lis.size != size) return false;
    
    if(testa != nullptr){
        return *testa == *(lis.testa);
    }

    return true;
    
}

template<typename Data>
inline bool List<Data>::operator!=(const List & lst) const noexcept{
    return !(*this==lst);
}


template<typename Data>
const Data& List<Data>::operator[](const ulong i) const {

    if(i < size)
    {
        Node* cursor = testa;
        ulong j=0;

        while(cursor!=nullptr)
        {
            if(j==i)
                return cursor->valore;

            cursor = cursor->NextNode;
            j++;
        }

        return cursor->valore;
    }
    else
        throw std::out_of_range("Lista vuota ");

}

template<typename Data>
Data& List<Data>::operator[](const ulong i) {

    if(i < size)
    {
        Node* cursor = testa;
        ulong j {0};

        while(cursor != nullptr)
        {
            if(j==i)
                return cursor->valore;

            cursor = cursor->NextNode;
            j++;
        }

        return cursor->valore;
    }
    else
        throw std::out_of_range("Lista vuota");

}


//***************************************************************************************
//funzioni specifiche

template<typename Data>
void List<Data>::InsertAtFront(const Data& dat){
    Node* new_node = new Node(dat);
    new_node->NextNode = testa;
    testa = new_node;
    size++;
    if(coda==nullptr) coda=new_node;

    
}

template<typename Data>
void List<Data>::InsertAtFront(Data && dat){
    Node* new_node = new Node(std::move(dat));
    new_node->NextNode = testa;
    testa = new_node;
    size++;
    if(coda==nullptr) coda=new_node;
}

template<typename Data>
void List<Data>::RemoveFromFront(){

    if(testa!=nullptr && coda!=nullptr)
    {
        if(testa==coda)
            coda=nullptr;

        Node * delete_element = testa;
        testa = testa->NextNode;
        delete_element->NextNode = nullptr;
        delete delete_element;
        size--;
    }
    else
        throw std::length_error("List is empty");

}

template<typename Data>
Data List<Data>::FrontNRemove(){ 
    if(testa != nullptr){     
        Node Nodo_ritorno (*(this->testa));
        this->RemoveFromFront();
        return Nodo_ritorno.valore;
    }
    
    throw std::length_error("non c'è la testa");

}



template<typename Data>
void List<Data>::InsertAtBack(const Data & dat){

    Node* new_node = new Node(dat);
    if(coda==nullptr){
        coda=new_node;
        testa=new_node;
    }else{
        coda->NextNode = new_node;
        coda = new_node;
    }
    size++;
    
}


template<typename Data>
void List<Data>::InsertAtBack(Data && dat){

    Node* new_node = new Node(std::move(dat));
    if(coda==nullptr){
        coda=new_node;
        testa=new_node;
    }else{
        coda->NextNode = new_node;
        coda = new_node;
    }
    size++;

}

//*******************************************************************************************
//Override ClearableContainer member

template<typename Data>
void List<Data>::Clear() {
    delete testa;
    testa=nullptr;
    coda=nullptr;
    size=0;
}

//*******************************************************************************************

template<typename Data>
bool List<Data>::Insert(const Data& dat) {
    
    Node* prossimo = testa;
    while(prossimo != nullptr && prossimo->valore!=dat){
        prossimo = prossimo->NextNode;
    }
    if(prossimo != nullptr) return false;
    InsertAtFront(dat);
    return true;
}

template<typename Data>
bool List<Data>::Insert(Data && dat) {

    Node* prossimo = testa;
    while(prossimo != nullptr && prossimo->valore!=dat){
        prossimo = prossimo->NextNode;
    }
    if(prossimo != nullptr) return false;
    InsertAtFront(std::move(dat));
    return true;

}

template<typename Data>
bool List<Data>::Remove(const Data& dat) {
    
    Node* precedente = nullptr;
    Node* corrente = testa;

    while(corrente != nullptr){

        if(corrente->valore == dat){
            if(precedente == nullptr){
                RemoveFromFront();
                return true;
            }else{
                precedente->NextNode = corrente->NextNode;
                corrente->NextNode = nullptr;
                size--;
                delete corrente;
                return true;
            }  
        }

        precedente = corrente;
        corrente = corrente->NextNode;
    }

    return false;
}

template<typename Data>
const Data& List<Data>::Front() const {
    
    if(testa!=nullptr)
        return testa->valore;
    else
        throw std::length_error("List is empty");
}

template<typename Data>
Data& List<Data>::Front() {
    if(testa!=nullptr)
        return testa->valore;
    else
        throw std::length_error("List is empty");
}

template<typename Data>
const Data& List<Data>::Back() const {
    if(coda!=nullptr)
        return coda->valore;
    else
        throw std::length_error("List is empty");
}

template<typename Data>
Data& List<Data>::Back() {
    if(coda!=nullptr)
        return coda->valore;
    else
        throw std::length_error("List is empty");
}

//*******************************************************************************************
//Override metodi TraversableContainer e sotto classi

template <typename Data>
void List<Data>::Traverse(TraverseFun fun) const{
    this->PreOrderTraverse(fun, this->testa);
}

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun) const{
    this->PreOrderTraverse(fun, this->testa);
}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun) const{
    this->PostOrderTraverse(fun, this->testa);
}

template <typename Data>
void List<Data>::Map(MapFun fun){
    PreOrderMap(fun, this->testa);
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun fun){
    PreOrderMap(fun, this->testa);
}

template <typename Data>
void List<Data>::PostOrderMap(MapFun fun){
    PostOrderMap(fun, this->testa);
}

//*******************************************************************************************
//Auxiliary functions implementazione 

template <typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, const Node* node) const{

    Node* prossimo = testa;
    while(prossimo != nullptr){
        fun(prossimo->valore);
        prossimo = prossimo->NextNode;
    }

}

template <typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, const Node* node) const{
    if(node != nullptr){
        PostOrderTraverse(fun, node->NextNode);
        fun(node->valore);
    }
}

template <typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node* node){
    Node* prossimo = testa;
    while(prossimo != nullptr){
        fun(prossimo->valore);
        prossimo = prossimo->NextNode;
    }

}

template <typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node* node){
    if(node != nullptr){
        PostOrderMap(fun, node->NextNode);
        fun(node->valore);
    }
}







/* ************************************************************************** */

}
