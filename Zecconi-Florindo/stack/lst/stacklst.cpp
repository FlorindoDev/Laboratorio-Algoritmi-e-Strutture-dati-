#include "stacklst.hpp"

namespace lasd {

    template <typename Data>
    StackLst<Data> & StackLst<Data>::operator=(const StackLst<Data> & Stklist){
        List<Data>::operator=(Stklist);
        return *this;
    }

    template <typename Data>
    StackLst<Data> & StackLst<Data>::operator=(StackLst<Data> && Stklist){
        List<Data>::operator=(std::move(Stklist));
        return *this;
    }

    template <typename Data>
    bool StackLst<Data>::operator==(const StackLst & Stklist) const{
        return List<Data>::operator==(Stklist);
    }

    template <typename Data>
    bool StackLst<Data>::operator!=(const StackLst & Stklist) const{
        return List<Data>::operator!=(Stklist);
    }

    template <typename Data>
    const Data & StackLst<Data>::Top() const{
        return List<Data>::Front();
    }

    template <typename Data>
    Data & StackLst<Data>::Top(){
        return List<Data>::Front();
    }

    template <typename Data>
    void StackLst<Data>::Pop(){
        List<Data>::RemoveFromFront();
    }

    template <typename Data>
    Data StackLst<Data>::TopNPop(){
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    void StackLst<Data>::Push(const Data & dat){
        List<Data>::InsertAtFront(dat);
    }

    template <typename Data>
    void StackLst<Data>::Push(Data && dat){
        List<Data>::InsertAtFront(dat);
    }
    

}
