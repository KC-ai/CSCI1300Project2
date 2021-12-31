// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #3
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* This function prints out the contents of your musioc library 
* Parameters: array of Song objects, and the number of songs in the array as an int
* Return: N/A, void
*/

void printAllSongs(Song songs[], int numsongs){

    //if the nunber of songs is less than or equal to 0, output No songs are stored
    if (numsongs <= 0){
        cout << "No songs are stored"<<endl;
    }

    //otherwise, output here is a list of songs, and traverse through the songs array to output the title and artist at each index of i using the getTitle and getArtist functions
    else {
        cout << "Here is a list of songs "<<endl;
        for (int i = 0; i<numsongs; i++){
            cout<<songs[i].getTitle()<<" is by "<<songs[i].getArtist()<<endl;

        }
    }
}

int main(){
    //Test Case

    // print three songs
    Song songs[3];

    // putting songs in the songs array
    songs[0].setTitle("Eleanor Rigby");
    songs[0].setArtist("The Beatles");

    songs[1].setTitle("Jive Talkin");
    songs[1].setArtist("The Bee Gees");

    songs[2].setTitle("ABC");
    songs[2].setArtist("The Jackson 5");

    printAllSongs(songs, 3);
}