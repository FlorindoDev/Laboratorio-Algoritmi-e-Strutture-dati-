#include "dictionary.hpp"
#include "traversable.hpp"
#include "mappable.hpp"

namespace lasd {

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data> & data){
        bool check = true;
        data.Traverse(
            [this, &check](const Data& dat){
                check &= Insert(dat);
            }

        );
        return check;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data> && data){
        bool check = true;
        data.Map(
            [this, &check](Data & dat){
                check &= Insert(std::move(dat));
            }

        );
        return check;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data> & data){
        bool check = false;
        data.Traverse(
            [this, &check](const Data& dat){
                check |= Insert(dat);
            }

        );
        return check;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data> && data){
        bool check = false;
        data.Map(
            [this, &check](Data& dat){
                check |= Insert(std::move(dat));
            }

        );
        return check;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data> & data){
        bool check = true;
        data.Traverse(
            [this, &check](const Data& dat){
                check &= Remove(dat);
            }

        );
        return check;
    }

    template<typename Data>
    inline bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data> & data){
        bool check = false;
        data.Traverse(
            [this, &check](const Data& dat){
                check |= Remove(dat);
            }

        );
        return check;
    }

}
