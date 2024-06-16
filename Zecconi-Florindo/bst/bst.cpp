#include "bst.hpp"
#include <typeinfo>

namespace lasd {

    /* ********************************************************************* */
    /*                     Costruttori e Distruttori                         */
    /* ********************************************************************* */

    template <typename Data>
    BST<Data>::BST(const TraversableContainer<Data> & trav){
        trav.Traverse(
            [this](const Data & dat){
                Insert(dat);
            }
        );
    }

    template <typename Data>
    BST<Data>::BST(MappableContainer<Data> && MapC){
        MapC.Map(
            [this](const Data & dat){
                Insert(std::move(dat));
            }
        );
    }

    template <typename Data>
    BST<Data>::BST(const BST & bst){
        if(bst.size > 0){
          bst.BreadthTraverse(
                [this](const Data & dat){
                    this->Insert(dat);
                }
            );  
        }
    }

    template <typename Data>
    BST<Data>::BST(BST && bst){
        std::swap(this->root, bst.root);
        std::swap(this->size, bst.size);
    }

    template <typename Data>
    BST<Data>::~BST(){
        delete this->root;
        this->root = nullptr;
    }

    /* ********************************************************************* */
    /*                                  Operatori                            */
    /* ********************************************************************* */

    //Copy
    template <typename Data>
    BST<Data> & BST<Data>::operator=(const BST & bst){
        BST<Data> *tmp = new BST(bst);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move
    template <typename Data>
    BST<Data> & BST<Data>::operator=(BST && bst){
        std::swap(this->root, bst.root); 
        std::swap(this->size, bst.size);
        return *this;
    }


    template <typename Data>
    bool BST<Data>::operator==(const BST & bst )const noexcept{
        bool uguale = true;
        
        if(bst.Size() != this->Size()) return false;

        if(Size() > 0){
            bst.BreadthTraverse(
                [this, &uguale](const Data & dat){
                    if(Exists(dat) == false){
                        uguale = false;
                    }
                    
                }
            );
        }

        return uguale;
    }

    template <typename Data>
    bool BST<Data>::operator!=(const BST & bst)const noexcept {
        return !(bst == *this);
    }

    /* ********************************************************************* */
    /*                        Funzioni specifiche                            */
    /* ********************************************************************* */

    //MIN
    template <typename Data>
    const Data & BST<Data>::Min() const {
        if(this->Empty()) throw std::length_error("Root vuota");
        return (FindPointerToMin(this->root))->Element();

    }

    template <typename Data>
    Data BST<Data>::MinNRemove(){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToMin(this->root);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Data datReturn = nod->Element();
        Remove(datReturn);
        return datReturn;

    }

    template <typename Data>
    void BST<Data>::RemoveMin(){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToMin(this->root);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Remove(nod->Element());

    }

    //MAX
    template <typename Data>
    const Data & BST<Data>::Max() const {
        if(this->Empty()) throw std::length_error("Root vuota");
        return FindPointerToMax(this->root)->Element();

    }

    template <typename Data>
    void BST<Data>::RemoveMax(){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToMax(this->root);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Remove(nod->Element());

    }

    template <typename Data>
    Data BST<Data>::MaxNRemove(){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToMax(this->root);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Data datReturn = nod->Element();
        Remove(datReturn);
        return datReturn;

    }

    //Predecessor
    template <typename Data>
    const Data & BST<Data>::Predecessor(const Data & dat) const{
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToPredecessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        return nod->Element();

    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data & dat){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToPredecessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Data datReturn = nod->Element();
        Remove(datReturn);
        return datReturn;

    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data & dat){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToPredecessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Remove(nod->Element());
    }

    //Successor
    
    template <typename Data>
    const Data & BST<Data>::Successor(const Data & dat) const{
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToSuccessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        return nod->Element();

    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data & dat){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToSuccessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Data datReturn = nod->Element();
        Remove(datReturn);
        return datReturn;

    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data & dat){
        if(this->Empty()) throw std::length_error("Root vuota");
        typename BinaryTreeLnk<Data>::NodeLnk * nod = FindPointerToSuccessor(this->root, dat, nullptr);
        if(nod == nullptr){
            throw std::length_error("Dato non trvato!");
        }
        Remove(nod->Element());
    }
    


    /* ********************************************************************* */
    /*                        Funzioni Specifiche                            */
    /* ********************************************************************* */


    template <typename Data>
    bool BST<Data>::Remove(const Data & dat){
        if(this->root != nullptr){
            ulong oldsize = Size();
            root = Remove(this->root, dat);
            if(Size() != oldsize){
                return true;
            } 
        }
        

        return false;
        
    }


    template <typename Data>
    bool BST<Data>::Insert(const Data & dat){
        ulong oldsize = Size();
        root = Insert(this->root, dat);
        if(Size() != oldsize){
            return true;
        }

        return false;
    }

    template <typename Data>
    bool BST<Data>::Insert(Data && dat){
        ulong oldsize = Size();
        root = Insert(this->root, std::move(dat));
        if(Size() != oldsize){
            return true;
        }

        return false;
    }


    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk & BST<Data>::Root() const{
        if(this->root == nullptr) throw std::length_error("Root vuota");
        return *(this->root);
       
    }

    template <typename Data>
    void BST<Data>::Clear(){
        delete this->root;
        this->size = 0;
        this->root = nullptr;
       
    }

    template <typename Data>
    bool BST<Data>::Exists(const Data & dat) const noexcept{
        return Exists(this->root, dat);

    }


    /* ********************************************************************* */
    /*                        Funzioni ausiliari                             */
    /* ********************************************************************* */

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Skip2Left(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        typename BinaryTreeLnk<Data>::NodeLnk * y = &nod->LeftChild();
        nod->FiglioSx = nullptr;
        delete nod;
        return y;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Skip2Right(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        typename BinaryTreeLnk<Data>::NodeLnk * y = &nod->RightChild();
        nod->FiglioDx = nullptr;
        delete nod;
        return y;
    
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Skip2LeftNoDel(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        typename BinaryTreeLnk<Data>::NodeLnk * y = &nod->LeftChild();
        nod->FiglioSx = nullptr;
        return y;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Skip2RightNoDel(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        typename BinaryTreeLnk<Data>::NodeLnk * y = &nod->RightChild();
        nod->FiglioDx = nullptr;
        return y;
    
    }


    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::FindPointerToMin(typename BinaryTreeLnk<Data>::NodeLnk * nod) const {

        if(nod->FiglioSx == nullptr){ 
            return nod; 
        }else{
            return FindPointerToMin(nod->FiglioSx);
        }

    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::FindPointerToMax(typename BinaryTreeLnk<Data>::NodeLnk * nod) const {
        
        if(!nod->IsLeaf()){
            if(nod->HasRightChild()) nod = FindPointerToMax(&nod->RightChild());
        }
        
        return nod;
    }

    
    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::DetachMin(typename BinaryTreeLnk<Data>::NodeLnk * FiglioNod, typename BinaryTreeLnk<Data>::NodeLnk * PadreNod){
        
        if(!FiglioNod->IsLeaf()){
            if(FiglioNod->HasLeftChild()) {                                     
                FiglioNod = DetachMin(&FiglioNod->LeftChild(),FiglioNod);                   //ricerca del minimo , vado sempre a sinistra
            }else{ 
                if(PadreNod != nullptr){                                                    //dopo aver trovato il minimo si dovra staccare dal albero
                    if(PadreNod->HasRightChild()){
                        if(PadreNod->RightChild().Element() == FiglioNod->Element()){       //se il minimo è il figlio destro del padre allora dovro attacare il figlio destro del minimo al padre 
                            PadreNod->FiglioDx = Skip2RightNoDel(FiglioNod);

                        }else{                                                              //se il minimo non è il figlio destro allora è il sinistro quindi attacato il figlio destro del minimo al figlio sinistro del padre del minimo                                                              
                            PadreNod->FiglioSx = Skip2RightNoDel(FiglioNod);
                        }
                    }else{
                        PadreNod->FiglioSx = Skip2RightNoDel(FiglioNod);
                    }
                    
                }else{                                                                      //se il padre è null significa che la root è il minimo e quindi la nuova root sarà il figlio destro del minimo
                    this->root = &FiglioNod->RightChild();
                }
            }
        }else{
            if(PadreNod != nullptr){
                
                if(PadreNod->HasRightChild()){ 
                    if(PadreNod->RightChild().Element() == FiglioNod->Element()){               //sestessa casistica di prima ma essendo foglie impostiamo solo il puntatore a null
                        PadreNod->FiglioDx = nullptr;
                    }else{
                        PadreNod->FiglioSx = nullptr;
                    }
                }else{
                    PadreNod->FiglioSx = nullptr;
                }
            
            }else{
                this->root = nullptr;
            }
        }

        return FiglioNod;

    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::DetachMax(typename BinaryTreeLnk<Data>::NodeLnk * FiglioNod, typename BinaryTreeLnk<Data>::NodeLnk * PadreNod){
        
        if(!FiglioNod->IsLeaf()){
            if(FiglioNod->HasRightChild()) {                                                //ricerca del massimo

                FiglioNod = DetachMax(&FiglioNod->RightChild(),FiglioNod);

            }else{                                                                          //abbiamo trovato il massimo ora dobbiamo estrarlo
                if(PadreNod != nullptr){
                    if(PadreNod->HasLeftChild()){                                               
                        if(PadreNod->LeftChild().Element() == FiglioNod->Element()){
                            PadreNod->FiglioSx = Skip2LeftNoDel(FiglioNod);
                        }else{
                            PadreNod->FiglioDx = Skip2LeftNoDel(FiglioNod); 
                        }
                    }else{
                        PadreNod->FiglioDx = Skip2LeftNoDel(FiglioNod); 
                    }
                    
                }else{
                    this->root = &FiglioNod->LeftChild();
                }
            }
        }else{
            if(PadreNod != nullptr){
                if(PadreNod->HasLeftChild()){
                    if(PadreNod->LeftChild().Element() == FiglioNod->Element()){
                        PadreNod->FiglioSx = nullptr;
                    }else{
                        PadreNod->FiglioDx = nullptr;
                    }
                }else{
                    PadreNod->FiglioDx = nullptr;
                }
                
            }else{
                this->root = nullptr;
            }
        }

        return FiglioNod;

    }




    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::FindPointerToPredecessor(typename BinaryTreeLnk<Data>::NodeLnk * nod, const Data & dat, typename BinaryTreeLnk<Data>::NodeLnk * S) const {

        if(nod != nullptr){
            if(nod->Element() < dat){
                return FindPointerToPredecessor(nod->FiglioDx,dat,nod);
            }else{
                return FindPointerToPredecessor(nod->FiglioSx,dat,S);
            }

        }
        return S;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::FindPointerToSuccessor(typename BinaryTreeLnk<Data>::NodeLnk * nod, const Data & dat, typename BinaryTreeLnk<Data>::NodeLnk * S) const {

        if(nod != nullptr){
            if(nod->Element() > dat){
                return FindPointerToSuccessor(nod->FiglioSx,dat,nod);
            }else{
                return FindPointerToSuccessor(nod->FiglioDx,dat,S);
            }

        }
        return S;

    }

    template <typename Data>
    Data BST<Data>::DataNDelete(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        Data dat = nod->Element();
        nod->FiglioSx = nullptr;
        nod->FiglioDx = nullptr;
        delete nod;
        return dat;
    }

   
    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::DeleteNode(typename BinaryTreeLnk<Data>::NodeLnk * nod){
        typename BinaryTreeLnk<Data>::NodeLnk * MinNod = nullptr;
        if(nod->HasRightChild() && nod->HasLeftChild()){
            MinNod = DetachMin(&nod->RightChild(),nod);
            nod->elemento = DataNDelete(MinNod);
    
        }else if(nod->HasRightChild()){
            nod = Skip2Right(nod);
        }else{
            nod = Skip2Left(nod);
        }

        return nod;

    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Remove(typename BinaryTreeLnk<Data>::NodeLnk * nod ,const Data & dat){
        
        if(!nod->IsLeaf()){
            if(dat > nod->Element()){
                if(nod->HasRightChild()) {
                    nod->FiglioDx = Remove(&nod->RightChild(),dat);
                }
            }else if(dat < nod->Element()) {
               if(nod->HasLeftChild()) {
                    nod->FiglioSx = Remove(&nod->LeftChild(),dat);
                } 
            }else{
                nod = DeleteNode(nod);
                this->size--;
            }
        }else{
            if( dat == nod->Element()){
                delete nod;
                nod = nullptr;  
                this->size--;
            }
            
        }
        return nod;
        

    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Insert(typename BinaryTreeLnk<Data>::NodeLnk * nod ,const Data & dat){
        if(nod == nullptr){
            nod = new typename BinaryTreeLnk<Data>::NodeLnk(dat);
            this->size++;
        }else{
            if(nod->Element() > dat){
                nod->FiglioSx = Insert(nod->FiglioSx, dat);
            }else if(nod->Element() < dat){
                nod->FiglioDx = Insert(nod->FiglioDx, dat);
            }
        }
        return nod;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk * BST<Data>::Insert(typename BinaryTreeLnk<Data>::NodeLnk * nod ,Data && dat){
        if(nod == nullptr){
            nod = new typename BinaryTreeLnk<Data>::NodeLnk(std::move(dat));
            this->size++;
        }else{
            if(nod->Element() > dat){
                nod->FiglioSx = Insert(nod->FiglioSx, dat);
            }else if(nod->Element() < dat){
                nod->FiglioDx = Insert(nod->FiglioDx, dat);
            }
        }
        return nod;
    }


    template <typename Data>
    bool BST<Data>::Exists(typename BinaryTreeLnk<Data>::NodeLnk * nod, const Data & dat) const{
        
        if(nod != nullptr){
            if(nod->Element() > dat){
                return Exists(nod->FiglioSx, dat);
            }else if (nod->Element() < dat){
                return Exists(nod->FiglioDx, dat);
            }else{
                return true;
            }
        }

        return false;  
       
    }

    

}
