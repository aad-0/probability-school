#include "map.h"    // for some functions
#include "LinkedList.h"
                    // used as a function member, not
                    // class member.
#include <cassert>
namespace DataStructure{
    /*void sortList();
    void insertFirst();
    void insertLast();
    void destroyList();

    void front();
    void back();
    */


template<class T>
LinkedList<T>::~LinkedList(){
    std::cout << "LinkedList Destroyed at: " << this << std::endl;
    this->destroyList();
}

template <class T>
void LinkedList<T>::sortList(){
        this->MergeSort(&(this->head));
}

template <class T>
void LinkedList<T>::copyList(LinkedList<T> &Dest){
    Node<T> *p = this->head;
    while(p != NULL){
        Dest.insertLast(p->data);
        p = p->next;
    }
}


template <class T>
void LinkedList<T>::insertFirst(T val){
    Node<T> *newp = new Node<T>;
    newp->data = val;
    newp->next = this->head;
    this->head = newp;
    this->count = this->count +1;

}

template <class T>
void LinkedList<T>::insertAt(T Val, int indx){
    assert(indx > 0 && "\nIn insertAt\n");
    assert(indx <= this->getLength() && "\nIn insertAt\n");
    // you cannot insert theindex that does not exist, for now
    if(indx == this->getLength()){ // insert functions ++'s
        this->insertLast(Val);
        return;
    }else if(indx == 1){
        this->insertFirst(Val);
        return;
    }

    Node<T> *p = this->head;
    Node<T> *_new = new Node<T>;
    _new->data = Val;

    int i;
    for(i = 1; i < indx; ++i){
        p = p->next;
    }

    _new->next = p->next;
    p->next = _new;
    //p->next = _new;
    this->count = this->count +1;
    return;
}

template <class T>
void LinkedList<T>::destroyList(){
    Node<T> *p = this->head;
    while(this->head != NULL){
        p = this->head;
        this->head = this->head->next;
        delete p;
    }
    this->last = NULL;
    this->count = 0;
}

template <class T>
void LinkedList<T>::arrToList(T *Arr, int size){
    int i;
    for(i = 0; i < size; ++i){
        this->insertFirst(Arr[i]);
    }
    this->count = size;
}

template <class T>
void LinkedList<T>::printList(){
    Node<T> *p = this->head;
    for(int i = 1; i <=this->count; ++i ){
        std::cout << "Data at " << p << " is " << p->data << std::endl;
        p = p->next;
    }
    /* OLD SHIT, I think that count does not work properly
    Node<T> *p = this->head;
    while(p != NULL){
        std::cout << "Data at " << p << " is "<< p->data <<std::endl;
        p = p->next;
    }*/
    /* before count
    Node<T> *p = this->head;
    while(p!= NULL){
        std::cout << "Data at " << p << " is "<< p->data <<std::endl;
        p = p->next;
    }*/
}


template <class T>
bool LinkedList<T>::isEmpty(){
    return (this->getLength() == 0);
}

template <class T>
void LinkedList<T>::removeMultiple(){
    this->sortList();
    Node<T> *p = this->head;
    Node<T> *d = NULL;
    while(!(p == this->last || p == NULL) ){
        if(p->data == p->next->data){
            d = p->next;
            p->next = d->next;
            delete d;
            this->count = this->count -1;
        }
        p = p->next;

    }
    //this->sortList();
    d = NULL;
    p = NULL;


    /* OLD SHIT

    Data::Map<T> map ;//= new Data::Map<T>;
    map.setDataSet(this);
    map.mapData();
    //this->count = map.keys.getLength();

    //this->head = map.keys.head;
    map.keys.copyList(*(this));
    std::cout << "INHOLE\n";
    this->printList();
    std::cout << "ENDINHOLE\n";
    //this->copyList(map->keys)
    */
}

template <class T>
bool LinkedList<T>::searchFor(T x){
    Node<T> *p = this->head;
    while(p != NULL){
        if(p->data == x){
            return true;
        }
        p = p->next;
    }
    return false;

}

template <class T>
int LinkedList<T>::getLength(){
    return this->count;
}

template <class T>
T &LinkedList<T>::getAt(int indx){
    /*if(indx > this->count || indx < 0){
        std::err <<"\n[WARN] Out of indx || indx < 0";
        return -1;
    }*/
    //std::cout <<"INDX :" << indx << "COUNT :" << this->count << std::endl;
    //std::cout << "\n GETAT WHAT IS LEN " << this->getLength();
    assert(indx > 0  && "\n IN LinkedList<T>::getAT\n");
    assert(indx <= this->getLength() && "\n IN LinkedList<T>::getAT\n");


    int i;
    Node<T> *p = this->head;
    //std::cout << "ADDR"<<p << std::endl;
    for(i = 1; i < indx; ++i){
    //std::cout << "ADDR "<<p <<" Holds "<<p->data<< std::endl;
        p = p->next;
    }
    return (p->data);
}


template <class T>
void LinkedList<T>::insertLast(T Val){
    /*
    []  []  []  []
    */
    this->count = this->count +1;
    if(this->head == NULL){
        this->head = new Node<T>;
        this->head->data = Val;
        return;
    }
    if(this->last == NULL){
        this->last = new Node<T>;
        this->last->data = Val;
        this->head->next = this->last;
        return;
    }

    Node<T> *p = new Node<T>;
    p->data = Val;
    this->last->next = p;
    this->last = p;

}



//template <class T>
//Node<T> *LinkedList<T>::getHead(){return this->head;}


/*
template <class T>
LinkedList<T>::back()const {
    if(this->tail != NULL)
        return this->last->data;

}
template <class T>
LinkedList<T>::front() const{
    if(this->head != NULL)
        return this->head->data;
}

*/



}
