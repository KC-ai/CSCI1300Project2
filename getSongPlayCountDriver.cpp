// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #8

#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//toLower function from previous problem
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
* This function returns the total number of plays of a certain song played by a listener
* Parameters: string listenerName, the name of the song, the listener array, the song array, the number of listeners, and the number of songs
* Return: the total number of plays of a certain song as an int
*/
int getSongPlayCount(string listenerName, string songName, Listener listeners[], Song songs[], int numListeners, int numSongs){

    //intiialize 2 booleans to false and change them if the listener is found or if the song is found
    bool listFound = 0;
    bool songFound = 0;

    //initialize two index place holders to -1, which hold the indexes of where the inputted listenerName and the songName match the song names and listener names inside their respective arrays
    int k = -1;
    int h = -1;

    //iterate through the listeners array and call on the lowercase function to make both the inputted listenerName and the listener name in the listener array lowercase and if their equal to each other, 
    //then make the listFound boolean true and set k equal to the index value where they're equal
    for (int i = 0; i<numListeners; i++){
        if (toLower(listeners[i].getListenerName()) == toLower(listenerName)){
            listFound = 1;
            k = i;
           
        }

    }

    //iterate through the songs array and call on the lowercase function and compare the lowercase versions of the song title at the index of j in the songs array to the songName, and if their equal to each other, 
    //then make the songFound boolean true, and set h equal to that index where they both are equal to each other
    for (int j = 0; j<numSongs; j++){
        if (toLower(songs[j].getTitle()) == toLower(songName)){
            songFound = 1;
            h = j;
        }
    }
    
    //if the number of songs is less than or equal to 0, or the listener name is found and the song name is not found, return -1
    if ((numSongs <= 0) || ((listFound)&&!(songFound))){
        return -1;
    }

    //if the number of listeners is less than or equal to 0, or the song name is found and the listener name is not found, return -2
    if ((numListeners <= 0) || (!(listFound)&&(songFound))){
        return -2;
    }

    //if the listener name and the song name can't be found then return -3
    if (!(listFound)&&!(songFound)){
        return -3;
    }

    //return the playcount at song index h of the listener at index k
    return listeners[k].getPlayCountAt(h);
}


int main(){

    //tester

    Song songs[50];
    songs[0] = Song("Goodbye Yellow Brick Road", "Elton John", "Pop");
    songs[1] = Song("Turn Back the Hands of Time", "Tyrone Davis", "Rhythm and Blues");
    
    songs[2] = Song("I Want to Hold Your Hand", "The Beatles", "Rock");

    Listener listeners[50];
    listeners[0].setListenerName("Al");
    listeners[0].setPlayCountAt(0, 0);
    listeners[0].setPlayCountAt(1, 0);
    listeners[0].setPlayCountAt(2, 1);
    listeners[1].setListenerName("John");
    listeners[1].setPlayCountAt(0, 5);
    listeners[1].setPlayCountAt(1, 0);
    listeners[1].setPlayCountAt(2, 2);
    listeners[2].setListenerName("Sleve");
    listeners[2].setPlayCountAt(0, 1);
    listeners[2].setPlayCountAt(1, 0);
    listeners[2].setPlayCountAt(2, 1);
    listeners[3].setListenerName("Onson");
    listeners[3].setPlayCountAt(0, 2);
    listeners[3].setPlayCountAt(1, 1);
    listeners[3].setPlayCountAt(2, 0);
    int numSongsStored = 3;
    int numListenersStored = 4;
    cout<<getSongPlayCount("John", "Goodbye Yellow Brick Road", listeners, songs, numListenersStored, numSongsStored)<<endl;
    /*int listenerArrSize = 50;
    Listener listener[listenerArrSize];
    numListenersStored =
    readListenerInfo("listenerInfo.txt", listener,
    numListenersStored, listenerArrSize, 50);
    cout<<getSongPlayCount("John", "Goodbye Yellow Brick
    Road", listener, songs, numListenersStored,
    numSongsStored)<<endl;*/
}