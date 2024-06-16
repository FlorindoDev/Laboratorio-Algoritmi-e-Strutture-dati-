#include "vector.hpp"

namespace lasd {


    //construttori della classe vector

    // A vector with a given initial dimension
    template <typename Data>
    Vector<Data>::Vector(const ulong new_size){
        size = new_size;
        elements = new Data[new_size] {};
        
    }

    // A vector obtained from a TraversableContainer
    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data> & trav): Vector(trav.Size()){       //richiamo il costuttore vecotr per creare il vettore e poi inizilizarlo
        ulong i = 0;
        trav.Traverse(
            [this, &i](const Data & dat){
                elements[i++] = dat;
            }
        );
    }

    // A vector obtained from a MappableContainer
    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data> && MapC): Vector(MapC.Size()){       //richiamo il costuttore vecotr per creare il vettore e poi inizilizarlo
        ulong i = 0;
        MapC.Map(
            [this, &i](Data & dat){
                std::swap(elements[i++], dat);
            }
        );
    }

    //Copy construcotr
    template <typename Data>
    Vector<Data>::Vector(const Vector<Data> & vec){
        size = vec.size;
        elements = new Data[size] {};
        std::copy(vec.elements, vec.elements + size, elements );        //il primo è l'indrizzo di partenza e il secondo è l'indirizzo darivo , l'ultimo è la destinazione
    }
    
    //Move construcotr
    template <typename Data>
    Vector<Data>::Vector(Vector<Data> && vec){
        std::swap(size, vec.size);              //inverto size del nuovo vettore con vec.size
        std::swap(elements, vec.elements);      //inverto l'indirizzo dei elementi del nuovo vettore con vec.elements
        
    }

    //distrutore
    template <typename Data>
    Vector<Data>::~Vector(){
        delete[] elements;
    }

    //************************************************************************************************************
    //OPERATORI
    //operatore = Copy
    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data> & vec){
        Vector<Data> *temp = new Vector(vec);
        std::swap(*temp, *this);
        delete temp;
        return *this;
    }

    //operatore = Move
    template <typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector<Data> && vec){
        std::swap(this->size, vec.size);              
        std::swap(this->elements, vec.elements); 
        return *this;
    }

    //operatore ==
    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data> & vec) const noexcept{
        if(vec.size != size) return false;
        for(ulong i = 0; i < size; i++){
            if(elements[i] != vec.elements[i]) return false;
        }
        return true;
    }

    //operatore !=
    template <typename Data>
    bool Vector<Data>::operator!=(const Vector<Data> & vec) const noexcept{
        return !(*this == vec);
    }

    template <typename Data>
    const Data& Vector<Data>::operator[](const ulong i) const {
        if(i < size){
            return elements[i];
        }
        throw std::out_of_range("sei andato troppo oltre! indice: " + std::to_string(i));
    }

    template <typename Data>
    Data& Vector<Data>::operator[](const ulong i){
        if(i < size){
            return elements[i];
        }
        throw std::out_of_range("sei andato troppo oltre! indice: " + std::to_string(i));
    }
    

    //************************************************************************************************************
    //Overriding function
    template <typename Data>
    void Vector<Data>::Clear(){
        delete [] elements;
        elements = nullptr;
        size = 0;
    }

    template <typename Data>
    void Vector<Data>::Resize(const ulong new_size){
       ulong min = new_size;
       if(min > size){
        min = size;
       }
        if(new_size  == 0){
            Clear();
            return;
        }else if(new_size != size){
            Data* new_elements = new Data[new_size] {};
        
            for(ulong i = 0; i<min; i++){
                std::swap(new_elements[i], elements[i]);
            }   
            size = new_size;
            std::swap(elements,new_elements); 
            delete[] new_elements;
            
        }
        
    }

    template <typename Data>
    const Data& Vector<Data>::Front() const{
        if(size != 0){
            return elements[0];
        }
        throw std::length_error("Errore di lunghezza");
    }

    template <typename Data>
    Data& Vector<Data>::Front(){
        if(size != 0){
            return elements[0];
        }
        throw std::length_error("Errore di lunghezza");
    }

    template <typename Data>
    const Data& Vector<Data>::Back() const{
        if(size != 0){
            return elements[size - 1];
        }
        throw std::length_error("Errore di lunghezza");
    }

    template <typename Data>
    Data& Vector<Data>::Back(){
        if(size != 0){
            return elements[size - 1];
        }
        throw std::length_error("Errore di lunghezza");
    }
    //************************************************************************
    //funzioni ausiliari
   

    //************************************************************************ 
    //Sortable Vecotr
    //construttori

    // A vector with a given initial dimension
    template <typename Data>
    SortableVector<Data>::SortableVector(const ulong new_size): Vector<Data>(new_size){}

    template <typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data> & trav): Vector<Data>(trav){}

    template <typename Data>
    SortableVector<Data>::SortableVector(MappableContainer<Data> && MapC): Vector<Data>(std::move(MapC)){}

    template <typename Data>
    SortableVector<Data>::SortableVector(const SortableVector & vec): Vector<Data>(vec){}
    
    template <typename Data>
    SortableVector<Data>::SortableVector(SortableVector && vec): Vector<Data>(std::move(vec)){}

    //************************************************************************ 
    //Operatori

    //operatore= copia
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data> & vec){
        Vector<Data>::operator=(vec);
        return *this;
    }

    //operatore= Move
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data> && vec){
        Vector<Data>::operator=(std::move(vec));
        return *this;
    }

    template <typename Data>
    bool SortableVector<Data>::operator==(const SortableVector<Data> & vec) const noexcept{
        if(vec.size != size) return false;
        for(ulong i = 0; i < size; i++){
            if(this->elements[i] != vec.elements[i]) return false;
        }
        return true;
    }

    //operatore !=
    template <typename Data>
    bool SortableVector<Data>::operator!=(const SortableVector<Data> & vec) const noexcept{
        return !(*this == vec);
    }

    //***************************************************************************
   
   

}
