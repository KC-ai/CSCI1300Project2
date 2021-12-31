// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #2
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//This is my split function 
void split(string splitted, char separate, string pieces[], int siz){
    int len = splitted.length();
    int numSplit = 0;
    int prev = 0;
    /*if (splitted == ""){
        return 0;
    }*/
    for (int i = 0; i<=len; i++){
        
        if (splitted[i]==separate || i == len ){
                pieces[numSplit] = splitted.substr(prev,i-prev);
                numSplit++;
                prev = i+1;
        }
    }
    /*if (numSplit>=siz){
        return -1;
    }
    else{
        return numSplit;
    }*/
}

/*
* This function fills an array of Song objects with title, artist, and genre information
* Parameters: string fileName: the name of the file to be read, array songs: array of Song objects, int numSongsStored: the number of songs currently stored in the array, and int songArrSize: the capacity of the song array, which is defaultly set to 50
* Return: the total number of songs in the system
*/
int readSongs(string fileName, Song songs[], int numSongsStored, int songArrSize = 50){

    //make an input variable of type ifstream
    ifstream in1;

    //open the txt file
    in1.open(fileName);

    //make a new string array of 50 for the songs in the file
    string arr[50]; 

    //make a new line variable for each line in the file
    string line = "";

    //if the number of songs is equal to the size of the array, return -2
    if (numSongsStored == songArrSize){
            return -2;
    }

    //if the file can't be opened, return -1
    if (in1.fail()){
        return -1;
    }
    
    //while the number of songs stored are less than the song array size and there are still lines in the txt file, run a loop
    while(getline(in1, line) && (numSongsStored < songArrSize)){

        //if the line isn't empty, then go into an if statement
        if (line != ""){

            //use the split function to store the title, artist, and genre inside the array arr 
            split(line, ',', arr, 3); 
        
            //at the index of numSongsStored, store the title, artist, and genre
            songs[numSongsStored] = Song(arr[0], arr[1], arr[2]);
          
            //if the number of songs stored is equal to the array size, then return the number of songs stored
            if (numSongsStored == songArrSize){
                return numSongsStored;
                
            }
            
            //increment the number of songs stored each time its added to the loop
            numSongsStored++;
            
        }
    }
    
    
    
    //return the number of songs stored
    return numSongsStored;
}

int main (){

    //Test case 
    Song songs[50];
    int numsongs = readSongs("songs.txt", songs, 0, 50);
}