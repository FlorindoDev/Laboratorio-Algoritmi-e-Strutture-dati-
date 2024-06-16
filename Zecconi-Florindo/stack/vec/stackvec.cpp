#include "stackvec.hpp"

namespace lasd {

    //Costruttori
    template <typename Data>
    StackVec<Data>::StackVec(StackVec<Data> && Stkvec): Vector<Data>(std::move(Stkvec)){
        std::swap(indice,Stkvec.indice);
    }

    template <typename Data>
    StackVec<Data>::~StackVec(){
        this->Clear();
    }

    //*****************************************************************************************
    //Operatori

    template <typename Data>
    StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data> & Stkvec){
        Vector<Data>::operator=(Stkvec);
        indice = Stkvec.indice;
        return *this;
    }

    template <typename Data>
    StackVec<Data>& StackVec<Data>::operator=(StackVec<Data> && Stkvec){
        Vector<Data>::operator=(std::move(Stkvec));
        std::swap(indice,Stkvec.indice);
        return *this;
    }

    template <typename Data>
    bool StackVec<Data>::operator==(const StackVec<Data> & Stkvec) const{
        if(Stkvec.indice != indice) return false;

        for(ulong i = 0; i<indice; i++){
            if(Stkvec.elements[i] != elements[i]) return false;
        }

        return true;
    }

    template <typename Data>
    bool StackVec<Data>::operator!=(const StackVec<Data> & Stkvec) const{
        if(Stkvec.indice != indice) return true;

        for(ulong i = 0; i<indice; i++){
            if(Stkvec.elements[i] == elements[i]) return false;
        }

        return true;
    }
    //****************************************************************************************
    //funzioni specifiche

    template <typename Data>
    const Data & StackVec<Data>::Top() const{
        if(indice == 0) {
            throw std::length_error("Stack vuoto");
        }else{
          return elements[indice-1];  
        }
        
    }

    template <typename Data>
    Data & StackVec<Data>::Top(){
        if(indice == 0) {
            throw std::length_error("Stack vuoto");
        }else{
            return elements[indice-1];
        }
        
    }

    template <typename Data>
    void  StackVec<Data>::Pop(){

        if(indice == 0) throw std::length_error("Stack vuoto");
        
        else{
            indice--;
            Riduzione();
        }
          
       
    }

    template <typename Data>
    Data StackVec<Data>::TopNPop(){
        if(indice == 0){ 
            throw std::length_error("Stack vuoto");
        }else{
            Data DatoReturn = elements[indice-1];
            indice--;
            Riduzione();
            return DatoReturn;
            
        }
        
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data & dat){
        Ingradimento();
        elements[indice++] = dat;
    }

    template <typename Data>
    void StackVec<Data>::Push(Data && dat){
        Ingradimento();
        elements[indice++] = std::move(dat);
    }

    //
    template <typename Data>
    void StackVec<Data>::Clear(){
        for(ulong i = 0; i<indice; i++){
            Pop();
        }
        indice = 0;        
    }
    //*********************************************************************************************
    template <typename Data>
    bool StackVec<Data>::Empty() const noexcept{
        if(indice == 0) return true;
        return false;
    }

    template <typename Data>
    ulong StackVec<Data>::Size() const noexcept{
        return indice;
    }
    



    //*********************************************************************************************
    //Auxiliary functions

    template <typename Data>
    void StackVec<Data>::Riduzione(){
        //if(Size() == 0){return;}
        if(indice == Size() / 4){
            Vector<Data>::Resize(Size()/2);
        }
        
    }

    template <typename Data>
    void StackVec<Data>::Ingradimento(){
        if(Size() == 0){Vector<Data>::Resize(1);}
        if(indice == Size()){
            Vector<Data>::Resize(Size()*2);
        }
    }

}
