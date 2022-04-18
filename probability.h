#ifndef Probability_H
#define Probability_H
#include "LinkedList.h"
#include "map.h"
/*
Sample space -> all single-event outcome-tupple

tree diagram

*/
namespace Probability{ //TUple


template <class T>
class Tuple{
// A tuple implenented with LinkedList
private:
//public:
    DataStructure::LinkedList<T> *set = new DataStructure::LinkedList<T>;
public:

    Tuple(DataStructure::LinkedList<T> &p);
    Tuple();

    //template <class T>
    void insert(T val);
    int getLength();
    T &getAt(int indx);
    bool searchFor(T x);
    void printList();
    void setSet(DataStructure::LinkedList<T> &from);

    template<T>
    friend Tuple<T> &unionn(Tuple<T> &A, Tuple<T> &B);
    template<T>
    friend Tuple<T> &intersection(Tuple<T> &A, Tuple<T> &B);
    template<T>
    friend Tuple<T> &complement(Tuple<T> &A, Tuple<T> &U);
    template<T>
    friend std::ostream& operator<<(std::ostream &os, Tuple<T>  &tup);
};

}


namespace Probability{

template <class T>
    class Universe{
    public:
        DataStructure::LinkedList<Tuple<T>> *universe = new DataStructure::LinkedList<Tuple<T>>;
        //Tuple<Tuple<T>> universe;
        //int totalTuple = 0;
        bool universeLock = false;
        int universeElementCount = 0; // which holds total element count

        Universe();
        void universeLockUnlock();
        bool universeGetLockState() const;
        float getProbabilityOf(Tuple<T> &A);
        void updateUniverseElementCount();
        void setUniverseElementCount(int pCount);


    };



}



#endif // Probability_H
