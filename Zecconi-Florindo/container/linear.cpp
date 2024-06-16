#include "linear.hpp"
#include "traversable.hpp"
#include <iostream>

namespace lasd {
    
    template <typename Data>
    bool LinearContainer<Data>::operator==(const LinearContainer<Data> & other) const noexcept{
        if(this->size != other.Size()){
            return false;
        }

        for(ulong i=0; i<this->size; i++){
            if(operator[](i) != other.operator[](i)){
                return false;
            }
        }
        return true;
    }

    template <typename Data>
    bool LinearContainer<Data>::operator!=(const LinearContainer<Data> & other) const noexcept{
        return(!(*this == other));
    }

    //******************************************************************************************
    template<typename Data>
    inline const Data& LinearContainer<Data>::Front() const{
        return operator[](0);
    }

    template<typename Data>
    inline Data& LinearContainer<Data>::Front() {
        return operator[](0);
    }

    template<typename Data>
    inline const Data& LinearContainer<Data>::Back() const{
        return operator[](Container::size - 1);
    }

    template<typename Data>
    inline Data& LinearContainer<Data>::Back(){
        return operator[](Container::size - 1);
    }

   

    template<typename Data>
    inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
        for(ulong i = 0; i<Container::size; i++){
            fun(operator[](i));
        }
    }

    template<typename Data>
    inline void LinearContainer<Data>::Traverse(TraverseFun fun) const {
        PreOrderTraverse(fun);
    }

    template<typename Data>
    inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const{
        ulong i = Container::size;
        while(i>0){
            i--;
            fun(operator[](i));
        }
       
    }

    template<typename Data>
    inline void LinearContainer<Data>::PreOrderMap(MapFun fun){
        for(ulong i = 0; i<Container::size; i++){
            fun(operator[](i));
        }
    }

    template<typename Data>
    inline void LinearContainer<Data>::PostOrderMap(MapFun fun){
        ulong i = Container::size;
        while(i>0){
            i--;
            fun(operator[](i));
        }
    }

    template<typename Data>
    inline void LinearContainer<Data>::Map(MapFun fun){
        PreOrderMap(fun);
    }

    template<typename Data>
    void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r){
        if (p < r){
            ulong q = Partiziona(p, r);
            QuickSort(p,q);
            QuickSort(q+1,r);
        }
    }

    template<typename Data>
    ulong SortableLinearContainer<Data>::Partiziona(ulong p, ulong r){
        ulong i = p-1; 
        ulong j = r+1;
        Data x = this->operator[](p);

        do{
            
            do{
                j--;
            }while(x < this->operator[](j));
            
            do{
                i++;
            }while(x > this->operator[](i));
            
            if(i < j){
                std::swap(this->operator[](i), this->operator[](j));
               
            }

        }while(i < j);
        return j;
    }
}
