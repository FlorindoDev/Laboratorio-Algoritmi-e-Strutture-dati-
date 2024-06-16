#include "htopnadr.hpp"

namespace lasd {

/* **************************************************************************** */
/*                     Costruttori e distruttori                                */
/* **************************************************************************** */


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong & i){
    if(i > 0){
        ulong nextprime = NumeroPrimo(i);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }else{
        ulong nextprime = NumeroPrimo(GRANDEZZABASE);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data> & trav){
    if(trav.Size() > 0){

        ulong nextprime = NumeroPrimo(trav.Size());         //per utilizzare tutti i slot possibili
        this->capacita = nextprime;

        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        InitVecStato();
        PseudoVec(nextprime);
        trav.Traverse(
            [this](const Data & dat){
                this->Insert(dat);
            }
        );
    }else{
        ulong nextprime = NumeroPrimo(GRANDEZZABASE);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong & i,const TraversableContainer<Data> & trav){
    if(i > 0){
        ulong nextprime = NumeroPrimo(i);
        this->capacita = nextprime;

        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};
        
        InitVecStato();
        PseudoVec(nextprime);
    
        trav.Traverse(
            [this](const Data & dat){
                this->Insert(dat);
            }
        );  

    }else{
        ulong nextprime = NumeroPrimo(GRANDEZZABASE);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data> && MapC){
    if(MapC.Size() > 0){
        ulong nextprime = NumeroPrimo(MapC.Size());
        this->capacita = nextprime;

        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};
        
        InitVecStato();
        PseudoVec(nextprime);

        MapC.Map(
            [this](Data & dat){
                this->Insert(std::move(dat));
            }
        );
    }else{
        ulong nextprime = NumeroPrimo(GRANDEZZABASE);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const ulong & i,MappableContainer<Data> && MapC){
    if(i > 0){
        ulong nextprime = NumeroPrimo(i);
        this->capacita = nextprime;

        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};
        
        InitVecStato();
        PseudoVec(nextprime);
        
        MapC.Map(
            [this](Data & dat){
                this->Insert(std::move(dat));
            }
        );
    }else{
        ulong nextprime = NumeroPrimo(GRANDEZZABASE);   //per utilizzare tutti i slot possibili
        
        Vec = new Vector<Data>{nextprime};
        VecStato = new Vector<char>{nextprime};

        this->capacita = nextprime;

        InitVecStato();
        PseudoVec(nextprime);
    }
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr & HT){
    if(HT.capacita > 0){
        Vec = new Vector<Data>{HT.Vec->Size()};
        this->VecStato  = new Vector<char>{HT.VecStato->Size()};

        this->size = HT.size;
        this->capacita = HT.capacita;
        this->perm = HT.perm;
        ulong cont {0};

        HT.Vec->Traverse(
            [this, &cont, &HT](const Data & dat){
                this->Vec->operator[](cont) = dat;
                this->VecStato->operator[](cont) = HT.VecStato->operator[](cont);
                ++cont;
            }
       );
    }
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr && HT){
    std::swap(HT.Vec, this->Vec);
    std::swap(HT.size, this->size);
    std::swap(HT.capacita, this->capacita);
    std::swap(HT.perm, this->perm);
    std::swap(HT.VecStato, this->VecStato);
}

template <typename Data>
HashTableOpnAdr<Data>::~HashTableOpnAdr(){
    if(this->capacita > 0){
        this->Clear();
        delete Vec;
        delete VecStato;
    }
}

/* **************************************************************************** */
/*                                      Operatori                               */
/* **************************************************************************** */

template <typename Data>
HashTableOpnAdr<Data> & HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data> & HT){
    HashTableOpnAdr<Data> *tmp = new HashTableOpnAdr(HT);
    std::swap(*tmp,*this);
    delete tmp;
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data> & HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data> && HT){
    std::swap(this->size, HT.size); 
    std::swap(this->Vec, HT.Vec);
    std::swap(this->capacita,HT.capacita);
    std::swap(HT.perm, this->perm);
    std::swap(HT.VecStato, this->VecStato);
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr & HT) const noexcept{
    if(HT.size == 0 && this->size == 0 ) return true;
    if(HT.size != this->size) return false;
    bool uguali = true;
    for(ulong i = 0; i<HT.Vec->Size();i++){
        if(HT.VecStato->operator[](i) == FULL){
            uguali &= this->Exists(HT.Vec->operator[](i));  
        }

    }
    
    return uguali;
   
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr & HT) const noexcept{
    return !(HT == *this);
}

/* ********************************************************************************* */
/*                            Funzioni specifiche                                    */
/* ********************************************************************************* */

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data & dat) const noexcept{
    if(this->size == 0) return false;
    if(Find(dat) == this->capacita) return false;

    return true;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data & dat){
    if(this->size > 0){
        ulong HomeDel = Find(dat);
        if( HomeDel != this->capacita){
            (*VecStato)[HomeDel] = TOMB;
            this->size--;
            Riduzione();
            return true;
        }
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data & dat){
    if(this->capacita > 0){
        if(Exists(dat)) return false;
        Expand();
        ulong HomeIns = FindEmpty(dat);
        if(HomeIns != this->capacita){
            (*Vec)[HomeIns] = dat;
            (*VecStato)[HomeIns] = FULL;
            this->size++;
            return true;
        }
        
        
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data && dat){
    if(this->capacita > 0){
        if(Exists(dat)) return false;
        Expand();
        ulong HomeIns = FindEmpty(dat);
        if(HomeIns != this->capacita){
            (*Vec)[HomeIns] = std::move(dat);
            (*VecStato)[HomeIns] = FULL;
            this->size++;
            return true;
        }
        
    }
    return false;
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong i){
    if(i <= this->size && i != 0) return;
    if(i == 0){
            this->Clear();
        }else{
            HashTableOpnAdr<Data> *tmp = new HashTableOpnAdr(i);
            if(this->capacita > 0){
                ulong cont {0};
                Vec->Traverse(
                    [this,tmp,&cont](const Data dat){
                        if(this->VecStato->operator[](cont) == FULL){
                            tmp->Insert(dat);
                        }
                        ++cont;
                    }
                );
            }
            std::swap(*tmp,*this);
            delete tmp;
            
        }
}


template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    if(this->size > 0){
        this->size = 0;
        for(ulong i = 0; i<this->capacita; ++i){
            (*VecStato)[i] = EMPTY;
        }
    }
}


/* **************************************************************************** */
/*                            Funzioni ausiliari                                */
/* **************************************************************************** */


template <typename Data>
void HashTableOpnAdr<Data>::Riduzione(){
    if(this->Size()+1 == this->capacita / 4){
        Resize(this->size/2);
    }
    
}
    
template <typename Data>
void HashTableOpnAdr<Data>::Expand(){
    if(this->Size()+1 == this->capacita){
        Resize(this->capacita*2);
    }
}

template <typename Data>
void HashTableOpnAdr<Data>::InitVecStato(){
    if(this->capacita > 0){
        for(ulong i = 0; i<VecStato->Size(); i++){
            (*VecStato)[i] = EMPTY;
        }
    }
}


template <typename Data>
ulong HashTableOpnAdr<Data>::Find(const Data & key) const{

    if(this->size <= 0) return this->capacita;
    ulong home = this->HashKey(key) % this->capacita;
    ulong pos = home;

    for(ulong i = 0; i<this->capacita; i++){

        if((*VecStato)[pos] == EMPTY) return this->capacita;

        else if((*Vec)[pos] == key && (*VecStato)[pos] == FULL) return pos;

        pos = (home + Probing(i)) % this->capacita;
    }

    return this->capacita;
    
}

template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data & key) const{

    if(this->capacita <= 0) return this->capacita;
    ulong home = this->HashKey(key) % this->capacita;
    ulong pos = home;

    for(ulong i = 0; i<this->capacita; i++){

        if((*VecStato)[pos] == EMPTY || (*VecStato)[pos] == TOMB) return pos;

        pos = (home + Probing(i)) % this->capacita;
    }

    return this->capacita;

    
}

template <typename Data>
bool HashTableOpnAdr<Data>::CheckPrimo(ulong num) {
    if (num <= 1) return false; // I numeri <= 1 non sono primi
    if (num <= 3) return true; // 2 e 3 sono primi
    if (num % 2 == 0 || num % 3 == 0) return false; // Escludi i multipli di 2 e 3

    // Verifica i numeri della forma 6k ± 1 fino alla radice quadrata di num
    for (ulong i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}


template <typename Data>
ulong HashTableOpnAdr<Data>::NumeroPrimo(const ulong & n) {
    //Inizia dal numero successivo a n
    ulong candidate = n + 1;

    // Continua a incrementare fino a trovare un numero primo
    while (!CheckPrimo(candidate)) {
        candidate++;
    }

    return candidate;
    //return n;
}



template <typename Data>
void HashTableOpnAdr<Data>::PseudoVec(const ulong i) {
    if(i > 0){
        perm.Resize(i);
        std::vector<ulong> vettore(i);

        // Riempimento del vettore con numeri da 1 a m
        for (ulong j = 0; j < i; ++j) {
            vettore[j] = j + 1;
        }

        // Inizializzazione del generatore di numeri casuali

        /*random_device genera il numero casuali a aprtire dal hardwere e rumori nel segnale eltrico , 
        pero questa operazione è dispondiosa*/
        std::random_device rd;  //generatore di si numeri pesudo casuali che generera un seme

        /*  un algoritmo per la generazione di numeri pseudo-casuali */
        std::mt19937 gen(rd()); //un generaotre di numeri pesudo-casuali che ha bisogno di un seme poichè il seme determinera la sequnza di numeri pesudo-casuali

        /* prende l'intervalo in cui deve agire e rimescola i elementi in posizone diversa
        le posizioni casuli venegono generati con gen*/
        // Mescolamento del vettore per ottenere ordine casuale
        std::shuffle(vettore.begin(), vettore.end(), gen);

        for(ulong j = 0; j < i; ++j){
            perm[j] = vettore[j];
        }
    }
    
}

template <typename Data>
ulong HashTableOpnAdr<Data>::Probing(/*const Data & key,*/ const ulong i) const{
    return perm[i]; // * SecondHashing(key); 
}

// template <typename Data>
// ulong HashTableOpnAdr<Data>::SecondHashing(const Data & key) {

//     return key % this->capacita; 
// }

template <typename Data>
ulong HashTableOpnAdr<Data>::HashKey(const Data & key) const{
    Hashable<Data> h {};
    return h.operator()(key);
}

// //_X_
// template <typename Data>
// void HashTableOpnAdr<Data>::stamp(){};

}
