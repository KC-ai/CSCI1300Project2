// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #5
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//to Lower function from previous problem

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

//countGenre function from previous problem
int countGenre(string genre, Song songs[], int numSongsStored){

    int genreCount = 0;
    if (numSongsStored <= 0 ){
        return 0;

    }
    for (int i = 0; i<numSongsStored; i++){
            string compare = "";
            string compare2 = "";
            compare = toLower(songs[i].getGenre());
            compare2 = toLower(genre);
            if (compare == compare2){
                genreCount++;
            }
    }    
    
    if (genreCount == 0){
        return 0;
    }

    return genreCount;

}

/*
* This function counts the most frequent genre's occurences
* Parameters: Song array of type song, and the number of songs stored of type int
* Return: the number of times that the genre with the most songs occurs
*/

int frequentGenreSongs (Song songs[], int numSongsStored){

    //intialize a temp variable to find the max in the songs array
    int temp = 0;

    //iterate through the songs array and count each genre using the countGenre function at each element, and store it in int variable count
    for (int i = 0; i<numSongsStored; i++){
        int count = countGenre(songs[i].getGenre(), songs, numSongsStored);

        //if the count is grater than the temp, replace the temp with that countGenre valiue
        if (count>temp){
            temp = count;
        }
    }
    //return the temp 
    return temp;

}

int main(){

    // tester
    /*int numSongsStored = readSongs("songs.txt", songs, numSongsStored, songArrSize);
    cout << frequentGenreSongs(songs, numSongsStored) << endl;*/
}