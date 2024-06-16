#include "binarytreelnk.hpp"

namespace lasd {


    /* ************************************************************************ */
    /*                      Node Costruttori e Distruttori                           */
    /* ************************************************************************ */

    //Copy
    template<typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data & dat){
        elemento = dat;
    }

    //Move
    template<typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data && dat){
       std::swap(elemento,dat);
    }

    //Distruttore
    template<typename Data>
    BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
        delete FiglioDx;
        delete FiglioSx;
    }

    /* ************************************************************************ */
    /*                      Node funzioni specifiche                            */
    /* ************************************************************************ */

    template<typename Data>
    const Data & BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
        return (this->elemento);
    }

    template<typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept{
        return !(FiglioSx == nullptr);
    }

    template<typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept{
        return !(FiglioDx == nullptr);
    }


    //Con NodeLnk
    template<typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk  & BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
        if(FiglioSx == nullptr) throw std::out_of_range("Non ha figlio sinistro");
        return *FiglioSx;
    }

    template<typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
        if(FiglioDx == nullptr) throw std::out_of_range("Non ha figlio destro");
        return *FiglioDx;
    }
    
    
    template<typename Data>
    Data & BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
        return (this->elemento);
    }

    
    //Con NodeLnk
    template<typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk  & BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
        if(FiglioSx == nullptr) throw std::out_of_range("Non ha figlio sinistro");
        return *FiglioSx;
    }

    template<typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::NodeLnk::RightChild() {
        if(FiglioDx == nullptr) throw std::out_of_range("Non ha figlio destro");
        return *FiglioDx;
    }
    
 
    /* ************************************************************************ */
    /*                              Funzioni specifiche                         */
    /* ************************************************************************ */
    

    template<typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::Root(){
        if(root == nullptr) throw std::length_error("Sei andato troppo oltre!");
        return *root;
    }


    template<typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::Root() const {
        if(root == nullptr) throw std::length_error("Sei andato troppo oltre!");
        return *root;
    }

    template<typename Data>
    void BinaryTreeLnk<Data>::Clear(){
        delete root;
        root = nullptr;
        this->size = 0;
    }

    /* ************************************************************************ */
    /*                        Costruttori e Distruttori                         */
    /* ************************************************************************ */

    //traversable
    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data> & trav){
        trav.Traverse(
            [this](const Data & dat) {
                InsertInTree(dat);
            }
        );
    }


    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data> && MapC){
        MapC.Map(
            [this](Data & dat) {
                InsertInTree(std::move(dat));
            }
        );
    }


    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk & btl){
        if(btl.Size() > 0){
            root = CopiaAlbero(btl.root);
            this->size = btl.size;
        }
    }

    //move
    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk && btl){
        std::swap(root, btl.root);
        std::swap(this->size, btl.size);
    }

    template<typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk(){
        delete root;
        root = nullptr;
    }


    /* ************************************************************************ */
    /*                                   Operatori                              */
    /* ************************************************************************ */


    //Copy assignment
    template <typename Data>
    BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data> & btl){
        BinaryTreeLnk<Data> *tmp = new BinaryTreeLnk(btl);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move assignment
    template <typename Data>
    BinaryTreeLnk<Data> & BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data> && btl){
        std::swap(root, btl.root); 
        std::swap(this->size, btl.size);
        return *this;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk & btl) const noexcept{
        return BinaryTree<Data>::operator==(btl);
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk & btl) const noexcept{
        return !(*this == btl);
    }


    /* ************************************************************************ */
    /*                                   Ausiliari                              */
    /* ************************************************************************ */
    
    
    template<typename Data>
    BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopiaAlbero(BinaryTreeLnk<Data>::NodeLnk* node){
        
        BinaryTreeLnk<Data>::NodeLnk* nodo = nullptr;

        if(node!=nullptr){
            nodo = new NodeLnk(node->elemento);

            if(node->FiglioSx!=nullptr)
                nodo->FiglioSx = CopiaAlbero(node->FiglioSx);

            if(node->FiglioDx!=nullptr)
                nodo->FiglioDx = CopiaAlbero(node->FiglioDx);
        }

        return nodo;

    }
    
    //Con NodeLnk
    template<typename Data>
    void BinaryTreeLnk<Data>::InsertInTree(const Data & dat){

        if(root == nullptr){
            root = new NodeLnk(dat);
            this->size++;
            return;
        }

        QueueVec<struct BinaryTreeLnk<Data>::NodeLnk *> Que;
        Que.Enqueue(root);
    
        while(!(Que.Empty())){
            BinaryTreeLnk<Data>::NodeLnk * nod = Que.HeadNDequeue(); 
            if(nod->HasLeftChild()){
                Que.Enqueue(&(nod->LeftChild()));
            }else{
                nod->FiglioSx = new NodeLnk(dat);
                this->size++;
                return;
            }
        
            if(nod->HasRightChild()){
                Que.Enqueue(&(nod->RightChild()));
            }else{
                nod->FiglioDx = new NodeLnk(dat);
                this->size++;
                return;
            }
    
        }
    
    }
    

    template<typename Data>
    void BinaryTreeLnk<Data>::InsertInTree(Data && dat){

        if(root == nullptr){
            root = new NodeLnk(std::move(dat));
            this->size++;
            return;
        }

        QueueVec<NodeLnk *> Que;
        Que.Enqueue(root);
        
        while(!(Que.Empty())){
            BinaryTreeLnk<Data>::NodeLnk * nod = Que.HeadNDequeue(); 
            if(nod->HasLeftChild()){
                Que.Enqueue(&(nod->LeftChild()));
            }else{
                nod->FiglioSx = new NodeLnk(std::move(dat));
                this->size++;
                return;
            }
        
            if(nod->HasRightChild()){
                Que.Enqueue(&(nod->RightChild()));
            }else{
                nod->FiglioDx = new NodeLnk(std::move(dat));
                this->size++;
                return;
            }
    
        }
    
    }


}
