#include "map.h"
#include "LinkedList.h"
//#include <math.h>
namespace Data{
/*
DataStructure::LinkedList<T> keys;
DataStructure::LinkedList<T> values;
*/

template <class T>
Map<T>::~Map(){
    //delete this->DataSet;
}

template<class T>
Map<T>::Map(DataStructure::LinkedList<T> &pDataSet){
    this->DataSet = &pDataSet;
}

template <class T>
Map<T>::Map(){
    this->DataSet = NULL;
};


template <class T>
void Map<T>::setDataSet(DataStructure::LinkedList<T> *pDataSet){
    this->DataSet = pDataSet;
}

template <class T>
void Map<T>::mapData(){
    assert(this->DataSet != NULL &&"\nWARN");
    this->DataSet->sortList();
    //Node<T> *pointer = DataSet.getHead;
    DataStructure::Node<T> *pointer = this->DataSet->head;
    int key, value;
    _whilecheck:
    while(pointer != NULL){
        key = pointer->data;
        value = 1;
        //std::cout << "Key :" << key << std::endl;

        do{
            //std::cout <<"DOHEAD "<< std::endl;
            if(pointer->next == NULL){
                goto _end;
            }else{
                pointer = pointer->next;
            }

            if(pointer->data == key){
                ++value;
            }else{
                break;
            }


        }while(true);
        keys.insertFirst(key);
        values.insertFirst(value);
        //std::cout << "VAL :" << value << "Pointer: " << pointer<< std::endl;

    }
    _end:
        keys.insertFirst(key);
        values.insertFirst(value);
        //std::cout << "";



}


template <class T>
float Map<T>::mean(){
    assert((this->keys != NULL && this->values != NULL) && "\nWARN");
    DataStructure::Node<T> *keyP = this->keys.head;
    DataStructure::Node<T> *valP = this->values.head;

    float up = 0;//, down = 0;
    while(keyP != NULL){
        up = up + keyP->data * valP->data;
        //down = down + valP->data;
        keyP = keyP->next;
        valP = valP->next;

    }
    return up / this->DataSet->getLength();

}


template <class T>
float Map<T>::median(){
    assert(this->DataSet->head != NULL && "\nWARN");
    DataStructure::Node<T> *pointer = this->DataSet->head;
    int i;
    if(this->DataSet->getLength() % 2 == 1){
        for(i = 1; i < (this->DataSet->getLength() +1)/2; ++i){
            pointer = pointer->next;
        }
        //std::cout << "\nMedian" << pointer->data;
        return (float)pointer->data;
    }else{ // even
        for(i = 1; i < this->DataSet->getLength() /2; ++i){
            pointer = pointer->next;
        }
        //std::cout << "Median"<< (float)pointer->data <<" "
        //<< (float)pointer->next->data;
        return ((float)pointer->data + (float)pointer->next->data)/2;
    }


}


// Ask Cenker
template<class T>
float Map<T>::quartileLower(){
    assert(this->DataSet != NULL&& "\nWARN");
    DataStructure::Node<T> *pointer = this->DataSet->head;
    T A, B;
    int idx;
    float quartile
    = 0.25 * (this->DataSet->getLength() +1);

    idx = quartile;
    quartile = quartile - idx;

    for(int i = 1; i < idx; ++i){
        pointer = pointer->next;
    }
    A = pointer->data;
    B = pointer->next->data;
    //std::cout << "\nA :" << A << "\nB :"<< B
    //<< "\nQuart :" << quartile << "\nB-A :" << B - A << std::endl;
    return A + quartile * (B - A);
}

template<class T>
float Map<T>::quarliteUpper(){
    assert(this->DataSet->head != NULL);
    DataStructure::Node<T> *pointer = this->DataSet->head;
    T A, B;
    int idx;
    float quartile
    = 0.75 * (this->DataSet->getLength() +1);

    idx = quartile;
    quartile = quartile - idx;

    for(int i = 1; i < idx; ++i){
        pointer = pointer->next;
    }
    A = pointer->data;
    B = pointer->next->data;
    //std::cout << "\nA :" << A << "\nB :"<< B
    //<< "\nQuart :" << quartile << "\nB-A :" << B - A << std::endl;
    return A + quartile * (B - A);

}

template <class T>
T Map<T>::range(){
    if(this->DataSet->isEmpty()){
        return NULL;
    }
    T max, min;
    DataStructure::Node<T> *pointer = this->DataSet->head;
    min = pointer->data;
    for(int i = 0; i < this->DataSet->getLength(); ++i){ // Dataset is sorted
        pointer = pointer->next;
    }
    max = pointer->data;
    return max - min;

}

template <class T>
float Map<T>::standardVariation(){
    DataStructure::Node<T> *pointer = this->DataSet->head;
    float mean = this->mean();
    float sum = 0;
    int i;
    for(i = 0; i < this->DataSet->getLength(); ++i){
        sum = sum + pow((pointer->data - mean), 2);
    }

    return sum / this->DataSet->getLength()  -1;

}


template <class T>
float Map<T>::standardDeviation(){
    return sqrt(this->standardVariation());
}


}



