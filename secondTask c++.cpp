// secondTask c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iostream>
#include<list>
#include <algorithm>
#include "Number.h"
#include <random>
using namespace std;
Number add(Number num1, Number num2) {
    return num1+num2;
}
Number& addByreference(Number & num1, Number &num2) {

    return num1+num2;
}
void print(Number n1) {
    std::cout <<n1.getNumberValue() << " " << n1.getNumberName() << std::endl;

}
void print2(Number *n1) {
    std::cout << n1->getNumberValue() << " " << n1->getNumberName() << std::endl;

}
void procesVector(std::vector<Number> numbers, int len) {
    if (len > 10 || len < 5) return;
    for (int i = 0; i < len; i++) {
        int a;
        std::cin >> a ;
        Number num = Number(a);

        numbers.push_back(num);
    }
    for (Number num : numbers) {
        print(num);

    }

}
void procesList(std::list<Number> numbers, int len) {
    if (len > 10 || len < 5) return;
    for (int i = 0; i < len; i++) {
        int a;
        std::cin >> a ;
        Number num = Number(a);
        numbers.push_back(num);
    }
    for (Number num : numbers) {
        print(num);

    }

}
int createRandom(int low, int high) {
    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd());  // Seed the generator
    uniform_int_distribution<> distr(low, high);
    return  distr(gen);
}
auto comparator = [&](const Number& low, const Number& high) {
    return low.getNumberValue() < high.getNumberValue();
    };
vector<Number> createV1() {

    int size = createRandom(500, 1000);
    vector<Number> myNumber;
    for (int i = 0; i < size; i++) {
        myNumber.push_back(createRandom(1, 1000));

    }
    cout << "#1 size of v1 is :" << size << endl;
    return myNumber;
}
vector<Number> createV2(vector<Number> &v1) {
    int b = createRandom(1, 199);
    int e = createRandom(b, 200);
    int size2 = e-b;
    std::vector<Number> v2(v1.begin() + b, v1.begin()+e);
    std::cout << "#2 Vector v2 created to begin at " << b << " and end at "<< e<<" size "<<size2 << "  of the original v1." << std::endl;
    return v2;
}
vector <Number > createList1(vector<Number> &v1) {
    
    int sizeList1 = createRandom(20, 50);
    vector<Number> List1(sizeList1);
    sort(v1.begin(), v1.end(), comparator);
    copy(v1.begin(), v1.begin() + sizeList1, List1.begin());
    cout << "#3 list 1 is created with " << sizeList1 << " elements\n";
    return List1;
}
vector <Number> createList2(vector<Number> &list1) {
    int sizeList2 = createRandom(1, list1.size() - 1);
    vector<Number> list2(sizeList2);
    copy(list1.end() - sizeList2, list1.end(), list2.begin());
    cout << "#4 list 2 is created with " << sizeList2 << " elements\n";

    return list2;
}
void RemoveOdd(vector<Number> &list1) {
    cout << "#7 size of list 1 with odd elements: " << list1.size()<<endl;
    auto is_odd = [](Number num) {
        return num.getNumberValue() & 1; // Return true for even numbers
        };

    // Use std::remove_if to move the even numbers to the end
    auto new_end = std::remove_if(list1.begin(), list1.end(), is_odd);

    // Erase the "removed" elements from the vector
    list1.erase(new_end, list1.end());
    cout << "size of list 1 after removing odd elements: " << list1.size()<<endl;

}
vector<Number> createV3(vector<Number> &v1, vector<Number>&v2) {
    sort(v2.begin(), v2.end(), [&](const Number& a, const Number& b) { return a.getNumberValue() < b.getNumberValue(); }); 
    vector<Number> v3;
    cout << "#8 from v1 of size " << v1.size() << " and v2 of size " << v2.size();
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
        back_inserter(v3),
        comparator);
    cout << ", v3 created of size " << v3.size()<<endl;
    return v3;
}
vector<pair<Number, Number>> createList3(vector<Number>& list1, vector<Number>& list2) {
    cout << "#9 before errase size of list1 " << list1.size() << " and of list2 " << list2.size()<<endl;
    int n1 = (list1.size() > list2.size()) ? list1.size() - list2.size() : 0;
    int n2 = (list2.size() > list1.size()) ? list2.size() - list1.size() : 0;
    list1.erase(list1.begin(), list1.begin() + n1);
    list2.erase(list2.begin(), list2.begin() + n2);
    vector<pair<Number, Number>> list3;

    //// Populate list3 using a lambda function
    transform(list1.begin(), list1.begin() + list1.size(), list2.begin(), back_inserter(list3), [&](const Number& num1, const Number& num2) {
        return make_pair(num1,num2);
        });
    cout << " after errase size of list1 " << list1.size() << " and of list2 " << list2.size() << endl;
    cout << " and size of the created list3 " << list3.size()<<endl;

    return list3;
}
vector<pair<Number, Number>> createV4(vector<Number>&v1,vector<Number>& v2) {
    cout << "#10 before creating v4 size of v1 " << v1.size() << " and of v2 " << v2.size() << endl;
    int n = min(v1.size(), v2.size());
    vector<pair<Number, Number>> v4;
    //// Populate list3 using a lambda function
    transform(v1.begin(), v1.begin() + n, v2.begin(), back_inserter(v4), [&](const Number& num1, const Number& num2) {
        return make_pair(num1, num2);
        });
    cout << " after creating v4 size of v1 " << v1.size() << " and of v2 " << v2.size() << endl;
    cout << " and size of the created v4 " << v4.size() << endl;

    return v4;
}
int main()
{
    // #1 Create a vector of size [500-1000] with random values of class Number 
    vector<Number> v1 = createV1();
    // #2 create a vector v2 of the  [b,e] elements of v1
    vector<Number> v2=createV2(v1);
    // #3 create list1 with the top [20-50] elemenets of v1
    vector<Number> list1 = createList1(v1);
    // #4 create list2 with the bottom [20-50] elements of list1
    vector<Number> list2 = createList2(v2);
    // #5 remove all the elements that has been copied from the original vectors
    cout << "#5 v1 size before the erase " << v1.size()<<endl;
    v1.erase(v1.begin(), v1.begin() + list1.size());
    cout << "v1 size after the erase " << v1.size() << endl;
  
    cout << "v2 size before the erase " << v2.size() << endl;
    v2.erase(v2.end()-list2.size(), v2.end());
    cout << "v2 size after the erase " << v2.size() << endl;
    // #6 rearrane the list1 so that the Number elements with values less than the avarage are below it and the ones with larger values are above it in the order
    sort(list1.begin(), list1.end(), [](const Number& low, const Number& high) {
        return low.getNumberValue() < high.getNumberValue();
        });
    cout << "#6 rearranged\n";
    // #7 remove the odd numbers from list1
    RemoveOdd(list1);

    // #8 create v3 of all the elements of v1 and v2
    vector<Number> v3 = createV3(v1, v2);
    // #9 remove n elements from the larger of {list1, list2} and create list3 of consecutive pairs from {list1, list2}
    vector<pair<Number, Number>> list3 = createList3(list1, list2);
    // #10 creating a vector of pairs for v1 and v2 without making them of the same size first
    vector<pair<Number, Number>>v4 = createV4(v1, v2);
    /*for (Number num : myNumber) {
        print(num);
    }*/
    //// static class instance 
    //Number n1(1);
    //Number n2(2);
    //n1 = n2;
    //print(add(n1,n2));
    //// dynamci class instance 
    //Number* n3 = new Number(2);
    //print(n1);
    //print2(n3);
    //delete n3;
    //int vector_length;
    //std::cin >> vector_length;
    //std::vector<Number> number_vector;
    //procesVector(number_vector, vector_length);


    
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
