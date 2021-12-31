// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #6
#ifndef LISTENER.H
#define LISTENER.H
#include <iostream>
#include <string>
using namespace std;

//Made a Listener class
class Listener{
    //private data members for the name of the listener, the array playCount, and the size
    private:
        string listenerName;

        static const int size = 50;
        int playCount[size];
       
    
    //public member functions
    public:

        //Default constuctor which makes everything empty and 0
        Listener();

        //Default parameterized constructor which takes in a string for listenerName, an array of integers for playCount, and an integer with the size of the array
        Listener(string listNm, int plCnt[], int siz);
            
        
        //returns listenerName as a string
        string getListenerName();

        //Assigns listenerName the value of the input string
        void setListenerName(string listNm);

        //Returns the count of plays of a song (i.e the number of listens of a song) stored at the specified index. If the index is larger than the last index in the playCount array, or less than 0, returns -1.
        int getPlayCountAt(int index);

        //Sets the count of number of plays of songs (i.e the number of listens of a song) to value at the specified index, if index is within the bounds of the array and value is greater than 0. Returns a boolean value, true if the number of plays was successfully updated and false otherwise. To be clear - one cannot set the playCount array equal to zero using this function.
        bool setPlayCountAt(int index,int);

        //Calculates and returns the sum of all the number of plays of all songs (i.e the number of listens of all songs) , returns an int
        int totalPlayCount();

        //Calculates and returns the number of unique songs listened to by the listener; unique here refers to songs which have at least one play (value >= 1 in the playCount array)
        int getNumUniqueSongs();

        //Returns size as an integer
        int getSize();


};

#endif
