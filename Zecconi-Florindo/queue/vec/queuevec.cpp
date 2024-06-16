#include "queuevec.hpp"

namespace lasd {

    //*******************************************************************************************
    //construttori


    //Move construcotr
    template <typename Data>
    QueueVec<Data>::QueueVec(QueueVec && QVec): Vector<Data>(std::move(QVec)){
        std::swap(testa, QVec.testa);
        std::swap(coda, QVec.coda);
        QVec.ResizeQ(4,0);
    }


    template <typename Data>
    QueueVec<Data>::QueueVec(const TraversableContainer<Data> & trav):  Vector<Data>(trav), coda(size) {
        if(size > 0) {Vector<Data>::Resize(size*2);}
        else {Vector<Data>::Resize(1);}
        
    } 

    template <typename Data>
    QueueVec<Data>::QueueVec(MappableContainer<Data> && MapC): Vector<Data>(std::move(MapC)), coda(size){
        if(size > 0) {Vector<Data>::Resize(size*2);}
        else {Vector<Data>::Resize(1);}
        
    } 

    template <typename Data>
    QueueVec<Data>::~QueueVec(){
        this->Clear();
    }


    //*******************************************************************************************
    //operatori
    template <typename Data>
    QueueVec<Data> & QueueVec<Data>::operator=(const QueueVec<Data> & QVec){
        Vector<Data>::operator=(QVec);
        testa = QVec.testa;
        coda = QVec.coda;
        return *this;
    }

    template <typename Data>
    QueueVec<Data> & QueueVec<Data>::operator=(QueueVec<Data> && QVec){
        Vector<Data>::operator=(std::move(QVec));
        std::swap(testa , QVec.testa);
        std::swap(coda , QVec.coda);
        return *this;
    }

    template <typename Data>
    bool QueueVec<Data>::operator==(const QueueVec<Data> & QVec) const noexcept{
        if(QVec.Size() != Size()) return false;
        
        ulong i = testa;
        
        while( i != coda){
            
            if(QVec.elements[i] != elements[i]) return false;
            if(i == size-1){
                i = 0;
                continue;
            }
            i++;
        }
        return true;
        
    }

    template <typename Data>
    bool QueueVec<Data>::operator!=(const QueueVec<Data> & QVec) const noexcept{
        return !(*this == QVec);
    }

    //*******************************************************************************************
    //specific function

    template <typename Data>
    const Data & QueueVec<Data>::Head() const{
        if(Empty()){
            throw std::length_error("la coda è vuota");
        }else{
            
            return elements[testa];
        }

    }

    template <typename Data>
    Data & QueueVec<Data>::Head(){
        if(Empty()){
            throw std::length_error("la coda è vuota");
        }else{
            
            return elements[testa];
        }
        
    }

    template <typename Data>
    void QueueVec<Data>::Dequeue(){
        if(Empty()){
            throw std::length_error("la coda è vuota");
        }else{
            Riduzione();
            
            if(testa == size-1){
                testa = 0;
            }else{
                testa++;
            }
        }
        if(Empty()) this->Clear();          //se la lista è vuota la pulisco per resetare i due indici
        
    }


    template <typename Data>
    Data QueueVec<Data>::HeadNDequeue(){
        if(Empty()){
            throw std::length_error("la coda è vuota");
        }else{
            Riduzione();
            Data datatoreturn(std::move(elements[testa]));
            Dequeue();
        
            return datatoreturn;
        }
    }

    // Copy of the value
    template <typename Data>
    void QueueVec<Data>::Enqueue(const Data & dat){
        Ingradimento();
        elements[coda] = dat;
        if(coda == size-1){
            coda = 0;
        }else{
            coda++;
        }
        
    } 

    

    template <typename Data>
    void QueueVec<Data>::Enqueue(Data && dat){
        Ingradimento();
        elements[coda] = std::move(dat);
        if(coda == size-1){
            coda = 0;
        }else{
            coda++;
        }
        
    } 

    //*****************************************************************************************
    //conteiner overide
    template <typename Data>
    ulong QueueVec<Data>::Size() const noexcept{
        return (((this->size + coda)-testa) % this->size);
    }

    template <typename Data>
    bool QueueVec<Data>::Empty() const noexcept{
        return testa == coda;
    }

    template <typename Data>
    void QueueVec<Data>::Clear(){
        delete[] elements;
        testa = 0;
        coda = 0;
        size = 4;
        elements = new Data[4]{};
    }

    //*****************************************************************************************
    // Auxiliary functions
    template <typename Data>
    void QueueVec<Data>::Riduzione(){
        //if(Size() == 0) return;
        if(Size()+1 == size / 4){
            ResizeQ(size/2, Size());
        }
        
    }

    template <typename Data>
    void QueueVec<Data>::Ingradimento(){
        //if(Size() == 0) ResizeQ(1*2, 1);
        if(Size()+1 == size){
            ResizeQ(size*2, Size());
        }
    }

    template <typename Data>
    void QueueVec<Data>::ResizeQ(const ulong new_size, ulong num_elements){
        
        ulong min = new_size;
        if(min > num_elements){
            min = num_elements;
        }
        if(new_size  == 0){
            Clear();
            return;
        }else if(new_size != size){
            Data* new_elements = new Data[new_size] {};
            ulong i = testa;
            ulong j = 0;
            while( i != coda && j<min){
                if(i == size) i = 0;
                std::swap(new_elements[j], elements[i]);
                j++;
                i++;
            }   
            size = new_size;
            std::swap(elements,new_elements); 
            delete[] new_elements;
            testa = 0;
            coda = min;
            
        }
        
    }
    
    
}


