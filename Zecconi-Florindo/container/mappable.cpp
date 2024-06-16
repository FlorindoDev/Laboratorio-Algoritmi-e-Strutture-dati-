#include "mappable.hpp"

namespace lasd {

    template<typename Data>
    inline void PreOrderMappableContainer<Data>::PreOrderMap(MapFun fun){
        Map(
            [&fun](Data & dat){
                fun(dat);
            }
        );
    }

    template<typename Data>
    inline void PostOrderMappableContainer<Data>::PostOrderMap(MapFun fun){
        Map(
            [fun](Data & dat){
                fun(dat);
            }
        );
    }

    template<typename Data>
    inline void InOrderMappableContainer<Data>::InOrderMap(MapFun fun){
        Map(
            [fun](Data & dat){
                fun(dat);
            }
        );
    }

    template<typename Data>
    inline void BreadthMappableContainer<Data>::BreadthMap(MapFun fun){
        Map(
            [fun](Data & dat){
                fun(dat);
            }
        );
    }

}
