// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #10

#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* This function prints the number of unique songs that the listener has listened to and the listeners average number of listens per song listened to
* Parameters: A string listenername which is the name of the listener, an array of Listener objects listeners, the number of listeners stored numListenersStored, and the number of songs numSongs
* Return: 0 and print the number of songs the listener has listened to and the average number of listens and 0 and -3 if the listener didnt listen to any songs and the name wasnt found
*/
int getListenerStats(string listenerName, Listener listeners[], int numListenersStored, int numSongs){
    //iterate through the listeners array
    for (int i = 0; i<numListenersStored; i++){
        //if the inputted listener name is equal to the name of the element in the listeners array then  either get the number of unique songs andprint it or if the total play count is 0 for all the songs 
        //then just return 0 and say the listener hasnt listened to any songs
        if (listeners[i].getListenerName() == listenerName){
            
            if (listeners[i].totalPlayCount() == 0){
                cout<<listenerName<<" has not listened to any songs."<<endl;
                return 0;
            }
            cout<<listenerName<<" listened to "<<listeners[i].getNumUniqueSongs()<<" songs."<<endl;

            //creat sum and average variables and intialize them to 0
            double sum = 0;
            double avg = 0;

            //iterate through the number of songs and if the playCount at each element is greater than 0, then add it to the sum
            for (int k = 0; k< numSongs; k++){
                if (listeners[i].getPlayCountAt(k) > 0) {
                    sum += listeners[i].getPlayCountAt(k);
                }
            }

            //calculate the average through taking the sum and then dividing it by the number of unique songs of the listener at that certain element
            avg = (sum)/(listeners[i].getNumUniqueSongs());

            //output the listener's average as calculated above rounded to 2 decimal places, and return 1
            cout<<fixed<<setprecision(2)<<listenerName <<"'s average number of listens was "<<avg<<endl;
            return 1;
        }


    }

    //if none of the cases above are true, then automatically assume that the listenerName doesn't exist, output that and retun -3
    cout<<listenerName<<" does not exist."<<endl;
    return -3;
}

int main(){
    //tester
    
    //Creating 3 listeners
    Listener listeners[3];

    //Setting name and listens for Person1
    listeners[0].setListenerName("Person1");
    listeners[0].setPlayCountAt(0,1);
    listeners[0].setPlayCountAt(1,4);
    listeners[0].setPlayCountAt(2,2);

    //Setting name and listens for Person 2
    listeners[1].setListenerName("Person2");

    //Setting name and listens for Person 3
    listeners[2].setListenerName("Person3");
    listeners[2].setPlayCountAt(0,0);
    listeners[2].setPlayCountAt(1,0);
    listeners[2].setPlayCountAt(2,0);

    cout << getListenerStats("Person1", listeners, 3, 3)<<endl;
    cout << getListenerStats("Person2", listeners, 3, 3)<<endl;
    cout << getListenerStats("Person4", listeners, 3, 3)<<endl;
}