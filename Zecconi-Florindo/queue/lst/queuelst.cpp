#include "queuelst.hpp"

namespace lasd {

    /* ************************************************************************** */
    //operatori
    template <typename Data>
    QueueLst<Data> & QueueLst<Data>::operator=( const QueueLst<Data> & QLst){
        List<Data>::operator=(QLst);
        return *this;
    }

    template <typename Data>
    QueueLst<Data> & QueueLst<Data>::operator=(QueueLst<Data> && QLst){
        List<Data>::operator=(std::move(QLst));
        return *this;
    }

    template <typename Data>
    bool QueueLst<Data>::operator==(const QueueLst<Data> & QLst) const noexcept{
        return List<Data>::operator==(QLst);
        
    }

    template <typename Data>
    bool QueueLst<Data>::operator!=(const QueueLst<Data> & QLst) const noexcept{
        return List<Data>::operator!=(QLst);
    }

    template <typename Data>
    const Data & QueueLst<Data>::Head() const{
        return List<Data>::Front();

    }

    template <typename Data>
    Data & QueueLst<Data>::Head(){
        return List<Data>::Front();
    }

    template <typename Data>
    void QueueLst<Data>::Dequeue(){
        List<Data>::RemoveFromFront();
    }

    template <typename Data>
    Data QueueLst<Data>::HeadNDequeue(){
        return List<Data>::FrontNRemove();
    }

    template <typename Data>
    void QueueLst<Data>::Enqueue(const Data & dat){
        List<Data>::InsertAtBack(dat);
    }

    template <typename Data>
    void QueueLst<Data>::Enqueue(Data && dat){
        List<Data>::InsertAtBack(std::move(dat));
    }



    /* ************************************************************************** */

}
