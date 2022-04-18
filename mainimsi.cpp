#include <iostream>
#include "LinkedList.cpp"
#include "map.cpp"
#include "probability.cpp"

/*

TODO
fix geldi
olasýlýkta aðýrlýk sistemi gelecek
week 7-8 gelecek
hadi uyudum ben


/TODO

*/



int main(void){
    //int arr[] = {40,60,65,65,65,68,68,70,70,70,70,70,70,74,75,75,90,95};
    int arr[] = {260,290,300,320,330,340,340,520,520};
    int arr2[] = {260,290,300,320,330,340,340,520,520,566};
    //int *arr = new int[150];
    //int *arr2 = new int[150];

    /*
    //DataStructure::LinkedList<int> *b, *a = new DataStructure::LinkedList<int>;

    DataStructure::LinkedList<int> a;

    DataStructure::LinkedList<int> b;



    a.arrToList(arr, sizeof(arr) / sizeof(*arr));
    b.arrToList(arr2,sizeof(arr2) / sizeof(*arr2));
    std::cout <<"Initial Conditions" << std::endl;
    a.printList();
    std::cout << "_____" << std::endl;
    b.printList();
    std::cout << "End Of Initial Conditions"<<std::endl;

    //a.printList();
    //b.printList();


    std::cout << "Before tuples" << std::endl;
    a.sortList();
    Probability::Tuple<int> x(a);
    //int x = -99;
    b.sortList();
    Probability::Tuple<int> y(a);//(b);
    Probability::Tuple<int> z;
    std::cout << "After Tuples" << std::endl;

    Probability::Universe<int> Uni;
    std::cout << "X " << std::endl; // 1,2,3,4
    std::cout << "X sorted" << std::endl;
    y.printList();
    x.printList();
    std::cout << "BAAAAAAAAAAAAAAAAAAS" << std::endl;
    std::cout << "Ýnserting : "<< x << std::endl;
    //return 0;

    //Uni.universe->insertAt(x,1);
    Uni.universe->insertFirst(x);
    std::cout << "ORTAAAAAAAAAAAAAAAAA"<<std::endl;
    std::cout << "Ýnserting : "<< y << std::endl;
    Uni.universe->insertAt(y,1);
    std::cout << "SOOOOOOOOOOOOOOOOOOON" << std::endl;
    Uni.universe->printList();
    z = Probability::unionn(Uni.universe->getAt(1),Uni.universe->getAt(2));


    std::cout <<"\nLockStatement :" <<Uni.universeGetLockState() << std::endl;
    Uni.universeLockUnlock();
    std::cout << "AGA";
    std::cout <<"\nAfterChange: " <<Uni.universeGetLockState() << std::endl;
    //Uni.updateUniverseElementCount();
    Uni.updateUniverseElementCount();
    std::cout << "AGA";
    std::cout << "\nUpdatedElement Count :" << Uni.universeElementCount<<std::endl;
    float h;
    h = Uni.getProbabilityOf(x);
    std::cout << "\nProbabilty of X :" << h << std::endl;
    h = Uni.getProbabilityOf(y);
    std::cout << "\nProbabilty of Y :" << h << std::endl;
    h = Uni.getProbabilityOf(Probability::intersection(x,y));
    std::cout << "\nProbabilty of X^Y :" << h << std::endl;
    Probability::intersection(x,y).printList();



    std::cout << "Before" << std::endl;
    //a.printList();
    x.printList();
    std::cout << "_____________" << std::endl;
    y.printList();
    std::cout << "After" << std::endl;
    //a.removeMultiple();
    //z = Probability::unionn(x,y);//Probability::complement(x,y);
    //z = Probability::complement(x,y);
    //z = Probability::intersection(x,y);

    //z.printList();
    a.printList();
    //a.sortList();
    std::cout << "MAP DECLARE" << std::endl;
    a.printList();
    Data::Map<int> m(a);
    std::cout << "SHIIIT" << std::endl;
    m.mapData();
    std::cout << "Keys" << std::endl;
    m.keys.printList();
    std::cout << "Vals" << std::endl;
    m.values.printList();
    float xx;
    xx = m.median();
    std::cout << "Mean :" << xx << std::endl;
    xx = m.quartileLower();
    std::cout <<"Q1 : "<< xx <<std::endl;
    xx = m.quarliteUpper();
    std::cout <<"Q3 : "<< xx <<std::endl;

    */





    return 0;
}





