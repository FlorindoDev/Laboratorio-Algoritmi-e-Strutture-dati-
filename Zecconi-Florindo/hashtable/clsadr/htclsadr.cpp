#include "htclsadr.hpp"

namespace lasd {

    /* ********************************************************************************* */
    /*                               costruttore e distruttori                           */
    /* ********************************************************************************* */

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong & i){
        if(i > 0){
            Vec.Resize(i);
            this->capacita = i;
        }else{
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data> & trav){
        if(trav.Size() == 0){
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
        }else{
            Vec.Resize(trav.Size());
            this->capacita = trav.Size();
            trav.Traverse(
                [this](const Data & dat){
                    this->Insert(dat);
                }
            );
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong & i,const TraversableContainer<Data> & trav){
        if(i > 0){
            Vec.Resize(i);
            this->capacita = i;
            trav.Traverse(
                [this](const Data & dat){
                    this->Insert(dat);
                }
            );  
        }else{
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data> && MapC){

        if(MapC.Size() == 0){
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
        }else{
            Vec.Resize(MapC.Size());
            this->capacita = MapC.Size();
            MapC.Map(
                [this](Data & dat){
                    this->Insert(std::move(dat));
                }
            );
        }
        
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const ulong & i,MappableContainer<Data> && MapC){
        if(i > 0){
            Vec.Resize(i);
            this->capacita = i;
            MapC.Map(
                [this](Data & dat){
                    this->Insert(std::move(dat));
                }
            );  
        }else{
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
        }
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr & HT){
        if(HT.Vec.Size() > 0){
            Vec.Resize(HT.Vec.Size());
            this->size = HT.size;
            this->capacita = HT.capacita;
            ulong cont {0};
            HT.Vec.Traverse(
                [this, &cont](const BST<Data> * dat){
                    if(dat != nullptr){
                       Vec[cont] = new BST<Data>(*dat);
                       
                    }
                    ++cont;
                }
           );
        }
    
    }

    template <typename Data>
    HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr && HT){
        std::swap(HT.Vec, this->Vec);
        std::swap(HT.size, this->size);
        std::swap(HT.capacita, this->capacita);
    }

    //_X_
    template <typename Data>
    HashTableClsAdr<Data>::~HashTableClsAdr(){
        this->Clear();
        
    }

    /* ********************************************************************************* */
    /*                                      Operatori                                    */
    /* ********************************************************************************* */

    //Copy
    template <typename Data>
    HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data> & HT){
        HashTableClsAdr<Data> *tmp = new HashTableClsAdr(HT);
        std::swap(*tmp,*this);
        delete tmp;
        return *this;
    }

    //Move
    template <typename Data>
    HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data> && HT){
        std::swap(this->size, HT.size); 
        std::swap(this->Vec, HT.Vec);
        std::swap(this->capacita,HT.capacita);
        return *this;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr & HT) const noexcept{
        if(HT.size == 0 && this->size == 0 ) return true;
        if(HT.size != this->size) return false;
        bool uguali = true;
        HT.Vec.Traverse(
            [this, &uguali](const BST<Data> * alb){
                if(alb != nullptr && !(alb->Empty())){
                    alb->PreOrderTraverse(
                        [this, &uguali](const Data & dat){
                            uguali &= this->Exists(dat);
                        }
                    
                    ); 
                }
                
            }
        );
        return uguali;
       
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr & HT) const noexcept{
        return !(HT == *this);
    }

    /* ********************************************************************************* */
    /*                            Funzioni specifiche                                    */
    /* ********************************************************************************* */


    template <typename Data>
    bool HashTableClsAdr<Data>::Exists(const Data & dat) const noexcept{
        if(this->capacita > 0 && this->size > 0){
            ulong home = this->HashKey(dat);
            if(Vec[home] != nullptr){
                return Vec[home]->Exists(dat);
            }
            return false;
        }

        return false;
        
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(const Data & dat){
        bool flag = true;
        if(Exists(dat)) return false;
        if(this->capacita > 0){
            ulong home = this->HashKey(dat);
        
            if(this->Vec[home] == nullptr){
                BST<Data> *tmp = new BST<Data>{};
                flag &= tmp->Insert(dat);
                this->Vec[home] = tmp;
            }else{
                flag &= Vec[home]->Insert(dat);
            }
            
        }else{
            return false;
        }
        if(flag) this->size++;
        return flag;
    }


    template <typename Data>
    bool HashTableClsAdr<Data>::Insert(Data && dat){
        bool flag = true;
        if(Exists(dat)) return false;
        if(this->capacita > 0){    
            ulong home = this->HashKey(dat);
        
            if(this->Vec[home] == nullptr){
                BST<Data> *tmp = new BST<Data>{};
                flag &= tmp->Insert(std::move(dat));
                this->Vec[home] = tmp;
            }else{
                flag &= Vec[home]->Insert(std::move(dat));
            }
            
        }else{
            return false;
        }

        if(flag) this->size++;
        return flag;
    }

    template <typename Data>
    bool HashTableClsAdr<Data>::Remove(const Data & dat){
        bool flag = true;
        if(this->size > 0){    
            ulong home = this->HashKey(dat);
            if(this->Vec[home] != nullptr){
                flag &= Vec[home]->Remove(dat);
            }else{
                return false;
            }
            
        }else{
            return false;
        }

        if(flag) this->size--;
        return flag;
    }

    //_X_
    template <typename Data>
    void HashTableClsAdr<Data>::Resize(ulong i){
        if(i == 0){
            this->Clear();
            Vec.Resize(GRANDEZZABASE);
            this->capacita = GRANDEZZABASE;
            return;
        }else{
            HashTableClsAdr<Data> *tmp = new HashTableClsAdr(i);
            Vec.Traverse(
                [tmp](const BST<Data> * alb){
                    if(alb != nullptr && !(alb->Empty())){
                        alb->PreOrderTraverse(
                            [tmp](const Data & dat){
                                tmp->Insert(dat);
                            }
                        
                        ); 
                    }
            
                }
            );
            std::swap(*tmp,*this);
            delete tmp;
        }
        
    }

    template <typename Data>
    void HashTableClsAdr<Data>::Clear(){
        
        for(ulong i = 0; i  < Vec.Size(); i++ ){
        if(Vec[i] != nullptr){
            delete Vec[i];
            Vec[i] = nullptr;
        }
        
        }
        this->size = 0;
        //Vec.Clear();
        //this->capacita = 0
        
        
    }


    // //_X_
    // template <typename Data>
    // void HashTableClsAdr<Data>::stamp(){
    //     Vec.Traverse(
    //         [this](const BST<Data> * alb){
    //             if(alb != nullptr && !(alb->Empty())){
    //                 alb->PreOrderTraverse(
    //                     [this](const Data & dat){
    //                     std::cout<<" "<< dat <<" ";
    //                     }
                    
    //                 ); 
    //             }
                
    //         }
    //     );
    // }
}
