#include "hashtable.hpp"


namespace lasd {

    template<>
    class Hashable<int>{

        public:
            //implemenatre in HasshKey la riduzione della grandezza _X_
            ulong operator()(const long int & key)noexcept{
                
                long int cont = key;
                int numcifre = 0;

                while(cont != 0){
                    cont /= 10;
                    ++numcifre;
                }

                return MidBit(key*key,numcifre);
            }

        protected:
            unsigned long long int power(int base, int esponente) {

                unsigned long long int result = 1;
                for (int i = 0; i < esponente; ++i) {
                    result *= base;
                }
                return result;

            }

            ulong MidBit(unsigned long long key, int MaxNumCifre){
                // Ottieni il numero di cifre del numero
                int NumeroCifre = 0;
                unsigned long long int cont = key;
                while (cont != 0) {
                    cont /= 10;
                    ++NumeroCifre;
                }
                // Calcola il numero di cifre da rimuovere dai lati
                int CifreDaCanc = (NumeroCifre - MaxNumCifre) / 2;

                // Rimuovi le cifre dal lato destro
                for (int i = 0; i < CifreDaCanc; ++i) {
                    key /= 10;
                }

                // Estrai le due cifre centrali
                int CifreCentrali = key % power(10,MaxNumCifre);

                return CifreCentrali;
            }
                
    };


    //hashing modulo primo
    template<>
    class Hashable<double>{

        public:
            ulong operator()(const double & key)noexcept{
            
                // /* uint64_t è un tipo di dato definito nell'header <cstdint> del C++ 
                // uint64_t: Questo tipo rappresenta un intero non negativo (unsigned) che utilizza esattamente 64 bit (8 byte) di memoria.
                // */
                // uint64_t bits;

                // /* prediamo 64bit poiche un double è rappresentato con 64 bit (standard IEEE)
                //     dopo aver copiato i 64bit potremmo tratarlo come intero senza segno , 
                //     quindi abbimo preso il numero e abbiamo tolo il numero
                
                // */

                // //copia i sizeof(bits) di key  e li mette in bits
                // std::memcpy(&bits, &key, sizeof(bits));

                // // Utilizziamo un numero primo grande per il modulo
                // const ulong prime = 1099511628211UL;    //primo molto grande per coprire tutti i 64bit
                // return static_cast<ulong>(bits % prime);

                /*La funzione floor() è una funzione della libreria matematica standard (<cmath> in C++) che arrotonda un numero in virgola mobile 
                verso il basso fino all'intero più vicino.*/
                //Risultato: floor(3.14) = 3
                long intgpart = floor(key) ;// floor funzione Libreria


                long francpart = pow(2, 24) * (key - intgpart); // parte frazionaria per 2 alla 24
                return (intgpart * francpart);  //parte intera per parte frazionaria
            }
            
                
    };



    template<>
    class Hashable<std::string>{

        public:
            //Hashing di DJB2
            ulong operator()(const std::string & key)noexcept{
                ulong hash = 5381;
                for(ulong i = 0; i < key.length(); i++){
                    hash = ((hash << 5) + hash) + key[i];
                }
                return hash;
            }
                
    };

}
