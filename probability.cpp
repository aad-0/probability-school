#include "probability.h"
#include "map.h"
#include <cassert>


namespace Probability{ //Tuple Functions
/*

template <class T>
class Tuple{
// A tuple implenented with LinkedList
public:
    DataStructure::LinkedList<T> set;

    Tuple(DataStructure::LinkedList<T> &p);


    friend Tuple<T> &unionn(Tuple<T> &A, Tuple<T> &B);
    friend Tuple<T> &intersection(Tuple<T> &A, Tuple<T> &B);
    friend Tuple<T> &complement(Tuple<T> &A);


*/

template<class T>
Tuple<T>::Tuple(){}
template<class T>
Tuple<T>::Tuple(DataStructure::LinkedList<T> &p){

    p.copyList(*this->set);
    //std::cout << "wtffff";

    this->set->removeMultiple();


    //this->set.sortList();

    //std::cout << "TUPLE CONST\n";
    //this->set.printList();
    //this->printList();
    //std::cout << "ENDTUPLE CONST\n";

    //this->set.removeMultiple();
    //this->setset = p;
}

template<class T>
void Tuple<T>::setSet(DataStructure::LinkedList<T> &from){
    //this->set = new DataStructure::LinkedList<T>;
    from.copyList(this->set);

}

template <class T>
int Tuple<T>::getLength(){
    return this->set->getLength();
}

    template <class T>
    T &Tuple<T>::getAt(int indx){
        return this->set->getAt(indx);
    }

    template <class T>
    bool Tuple<T>::searchFor(T x){
        return this->set->searchFor(x);
    }

    template <class T>
    void Tuple<T>::printList(){

        this->set->printList();
    }



template <class T>
void Tuple<T>::insert(T Val){
    //std::cout << "\nHEAD";
    if(this->set->isEmpty()){
        this->set->insertLast(Val);
        return;
    }

    if(this->set->searchFor(Val)){
        std::cerr << "\nTuple has this element already\n";
        return;
    }


    if(this->set->getAt((this->set->getLength())) <= Val){
        this->set->insertLast(Val);
        return;
    }

    if(this->set->getAt(1) >= Val){
        this->set->insertFirst(Val);
        return;
    }
    int i;
    for(i = 1; i <= this->set->getLength(); ++i){
        if(this->set->getAt(i) > Val){
            this->set->insertAt(Val, i -1);
            return;
        }
    }

}

// OLD SHIT

template <class T>
Tuple<T> &unionn(Tuple<T> &A, Tuple<T> &B){
    Tuple<T> *ret = new Tuple<T>;
    int i;
    // Stupid one // will be improvised
    for(i = 1; i <= A.getLength(); ++i){
        //ret->set.insertLast(A.set.getAt(i));
        //std::cout <<"A debug " << i << std::endl;
        //std::cout << " -> getat " << A.getAt(i) << std::endl;
        ret->insert(A.getAt(i));
    }
    for(i = 1; i <= B.getLength(); ++i){
        std::cout << "\nWHAT I HAVE\n";
        ret->printList();
        //std::cout << "\nEND WHAT I HAVE\n";
        //std::cout <<"B debug " << i << std::endl;
        //std::cout << " -> getat " << B.getAt(i) << std::endl;
        ret->insert(B.getAt(i));
    }
    //ret->set.removeMultiple();

    return (*ret);


}

template <class T>
Tuple<T> &intersection(Tuple<T> &A, Tuple<T> &B){
    Tuple<T> *ret = new Tuple<T>;
    int i;
    T x;
    std::cout << "\nLIM " << B.getLength();
    for(i = 1; i <= B.getLength(); ++i){
        x = B.getAt(i);
        //std::cout << "\n Looking For x : " << x <<  " i : " << i<<std::endl;
        if(A.searchFor(x)){
            //std::cout << "\n FOUND ONE : X " << x <<" END" ;
            //ret->set.insertLast(x);
            ret->insert(x);
        }
    }
    return (*ret);

}

template <class T>
Tuple<T> &complement(Tuple<T> &A, Tuple<T> &U){
    // Not know what I 'm doing side
    Tuple<T> *ret = new Tuple<T>;
    int i;
    T x;
    for(i = 1; i <= U.getLength(); ++i){ // Universe / A
        //x = U.set.getAt(i);
        x = U.getAt(i);
        if(!A.searchFor(x)){
            //std::cout <<"INserted ";
            ret->insert(x);
            //ret->set.insertLast(x);
        }
        //std::cout << "I :" << i << "X :" << x <<std::endl;
    }

    /*
    EASY WAYY
    */
    return (*ret);
}





template <class T>
std::ostream& operator<<(std::ostream &os, Tuple<T> &tup){
    tup.printList();
    return os;
}

}



namespace Probability{ // Universe

    /*

        Universe();
        void lockUnlock();
        float getProbabilityOf(Tuple<T> &A);
        void updateUniverseElementCount();
        void setUniverseElementCount();



    */

    template<class T>
    Universe<T>::Universe(){}

    template<class T>
    bool Universe<T>::universeGetLockState()const{
        return this->universeLock;
    }

    template<class T>
    void Universe<T>::setUniverseElementCount(int pCount){
        assert(pCount > 0 &&"\nInSetUniverseELementCount-pCount\n");
        assert(this->universeLock &&"InSetUniverseELementCount-universeLock\n");
        this->universeElementCount = pCount;
    }

    template <class T>
    void Universe<T>::universeLockUnlock(){
        this->universeLock = !(this->universeLock);
    }

    template<class T>
    void Universe<T>::updateUniverseElementCount(){
        assert(this->universeLock && "\nInupdateUniverseElementCount-universeLock\n");
        /*int i;
        for(i = 0; i < this->universe.getLength(); ++i){
            this->universeElementCount =this->universeElementCount +
            this->universe.getAt(i).set.getLength();
        }*/

        int i,elementcount = 0;
        for(i = 1; i <= this->universe->getLength(); ++i){
            elementcount = this->universe->getAt(i).getLength();
        }
        this->universeElementCount = elementcount;
        /* OLD SHIT

        Probability::Tuple<T> raw;
        int i, j;
        for(i = 1; i <= this->universe.getLength(); ++i){
            std::cout << "\nELEM ADDR " << this->universe.getAt(i) << std::endl;
            for(j = 1; j <= this->universe.getAt(i).getLength(); ++j){
                //std::cout << "\n Iserting " << this->universe.getAt(i).getAt(j);
                raw.insert(this->universe.getAt(i).getAt(j));
            }
        }
        this->universeElementCount = raw.getLength();
        */

        /*
        // ISSY WAY can be improved later
        int i ,j;
        DataStructure::LinkedList<T> raw;
        for(i = 1; i <= this->universe.getLength(); ++i){
            for(j = 1; j <= this->universe.getAt(i).getLength(); ++j){
                raw.insertLast(this->universe.getAt(i).getAt(j));
            }
        }
        raw.removeMultiple();
        this->universeElementCount = raw.getLength();
        */


    }

    template<class T>
    float Universe<T>::getProbabilityOf(Tuple<T> &A){
        assert(this->universeLock && "\nInGetProbabilityOf-lock\n");
        assert(this->universeElementCount > 0 && "\nInGetProbabilityOf-count\n");
        return (float)(A.getLength()) / (float)(this->universeElementCount);
    }



}

















