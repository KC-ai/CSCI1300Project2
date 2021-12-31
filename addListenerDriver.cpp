// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #9

#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//toLower function from a few problems ago
string toLower(string gen){
    string low = "";
    for (int i = 0; i<gen.length(); i++){
        if (gen[i]<97){
            low += gen[i]+32;
        }

        else {
            low += gen[i];
        }
    }
    return low;
}

/*
* This function adds a listener to the listeners array
* Parameters: string listenerName, the listener array, the number of songs whihc is 50, the number of listeners, and the array size of the listeners which is 100
* Return: the number of listeners + 1
*/
int addListener(string listenerName, Listener listeners[], int numSongs = 50, int numListenersStored, int listenersArrSize = 100){
    //if the listener Name is empty return -2
    if (listenerName == ""){
        return -3;
    }

    //if the number of listeners stored is greater than or equal to the listeners array size return -1
    if (numListenersStored >= listenersArrSize){
        return -1;
    }

    //iterate through the listeners array and make the inputted lister Name and the listener Name element in the listeners lowercase and if their equal, return -2
    for (int i = 0; i<listenersArrSize; i++){
        if (toLower(listeners[i].getListenerName()) == toLower(listenerName)){
            return -2;
        }
    }
    //make a new listener object called li using the default constuctor with no parameters
    Listener li = Listener();

    //set the listener name of the empty listener object li to the inputted listenerName
    li.setListenerName(listenerName); 
    
    //set the listener element at the number of listeners stored to the li object we made and modified sine this is the next index
    listeners[numListenersStored] = li;

    //return the number of listeners stored +1 since if we can add a listener and passed the other edge cases, then we just need to add 1 more listener
    return numListenersStored+1;
}

int main(){
    //tester
    Listener listeners[2];
    int listenerArrSize = 2;
    int numSongs  = 5;

    listeners[0].setListenerName("Ninja");

    // Add 5 listens by the user "Ninja"
    for(int i=0; i<numSongs; i++) {
        listeners[0].setPlayCountAt(i, i);
    }

    int numListenersStored = 1;

    cout<<addListener("Knuth", listeners, numSongs, numListenersStored, listenerArrSize)<<endl;
}