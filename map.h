#ifndef Map_H
#define Map_H
#include "LinkedList.h"
namespace Data{
    template <class T>
    class Map{ // a actually hashmap?
    public:
    DataStructure::LinkedList<T> *DataSet;
    DataStructure::LinkedList<T> keys;
    DataStructure::LinkedList<T> values;


    public:
    Map(DataStructure::LinkedList<T> &DataSet);
    Map();
    ~Map();


    void setDataSet(DataStructure::LinkedList<T> *pDataSet);

    void mapData();

    float mean();

    float median();

    T* mode(); // will be implemented later

    float quartileLower();
    float quarliteUpper();

    T range();

    float standardVariation();
    float standardDeviation();


    };


}

#endif // Map_H
