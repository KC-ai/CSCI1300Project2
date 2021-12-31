// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #6

#include <iostream>
#include "Listener.h"

using namespace std;

int main(){
    // Checking Paramterized Constructor/ test case
    int playCount[] = {3,4,5};
    Listener listener= Listener("Al", playCount, 3);
    cout << listener.getListenerName() << endl;
    cout << "getPlayCountAt(0) = " << listener.getPlayCountAt(0) << endl;
    cout << "getPlayCountAt(1) = "<< listener.getPlayCountAt(1) << endl;
    cout << "getPlayCountAt(2) = "<< listener.getPlayCountAt(2) << endl;
    cout << "getPlayCountAt(9) = "<< listener.getPlayCountAt(9) << endl;
    cout << "getPlayCountAt(29) = "<< listener.getPlayCountAt(29) << endl;
    cout << "getPlayCountAt(49) = "<< listener.getPlayCountAt(49) << endl;
    cout << "getPlayCountAt(-9) = "<< listener.getPlayCountAt(-9) << endl;
    cout << "getPlayCountAt(-29) = "<< listener.getPlayCountAt(-29) << endl;
    cout << "getPlayCountAt(52) = "<< listener.getPlayCountAt(52) << endl;

}