// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #6
#include "Listener.h"
#include <iostream>
#include <string>
using namespace std;


//Default constuctor which makes everything empty and 0
Listener::Listener(){
    listenerName = "";
    for (int i = 0; i< size; i++){
        playCount[i] = 0;
    }
}

//Default parameterized constructor which takes in a string for listenerName, an array of integers for playCount, and an integer with the size of the array
Listener::Listener(string listNm, int plCnt[], int siz){
    listenerName = listNm;
    //if the inputted siz is less than size, then set the array equal to all of the 
    //elements in the inputted array and set all the other elements to 0
        if (siz<size){
          
            for (int i = 0; i<siz; i++){
                playCount[i] = plCnt[i];
                
            }
            for (int k = (siz); k<size; k++){
                playCount[k] = 0;
            }
        }
        //otherwise just set the playcount array's elements equal to the plcnt array all throughotu
        else {
            for (int l = 0; l<size; l++){
                playCount[l] = plCnt[l];
            }
        }
}

//returns listenerName as a string
string Listener::getListenerName(){
    return listenerName;
}

//Assigns listenerName the value of the input string
void Listener::setListenerName(string Nm){
    listenerName = Nm;
}

//Returns the count of plays of a song (i.e the number of listens of a song) stored at the specified index. If the index is larger than the last index in the playCount array, or less than 0, returns -1.
int Listener::getPlayCountAt(int index){
    //if the index is less than 0 or greater than the size -1, return -1
    if (index <0 || index>size-1){
        return -1;
    }

    //otherwise return the element of the playCount at the index inputted
    else {
        return playCount[index];
        
    }
    

    
}

//Sets the count of number of plays of songs (i.e the number of listens of a song) to value at the specified index, if index is within the bounds of the array and value is greater than 0. Returns a boolean value, true if the number of plays was successfully updated and false otherwise. To be clear - one cannot set the playCount array equal to zero using this function.
bool Listener::setPlayCountAt(int index,int value){

    //initialize a boolean variable to true
    bool ret = 1;

    //if the inputted index is less than the size, greater than or equal to 0, and the value is not 0
    //return true for ret and set the playCount at the index to value
    if(index<size && index>=0 && value!=0){
        playCount[index] = value;
        return ret;
    }

    //otherwise just return false
    else {
        return !ret;
    }

}


//Calculates and returns the sum of all the number of plays of all songs (i.e the number of listens of all songs) , returns an int
int Listener::totalPlayCount(){
    //initialize a max variable of type int to 0 for the sum
    int max = 0;

    //go through the playCount and add each element to the max value for the total sum
    for (int i = 0; i < size; i++){
        max += playCount[i];
    }

    //return the max
    return max;
}

//Calculates and returns the number of unique songs listened to by the listener; unique here refers to songs which have at least one play (value >= 1 in the playCount array)
int Listener::getNumUniqueSongs(){
    //intialize a count variable and set it equal to 0 to count the number of unique songs
    int count = 0;

    //iterate through the songs array and if the number of plays is greater than 0, nump up the count
    for (int i = 0; i<size; i++){
        if (playCount[i]>=1){
            count++;
        }
    }

    //return the count
    return count;
}

//Returns size as an integer
int Listener::getSize(){
    return size;
}

