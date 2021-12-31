// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #4
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Split function from a while back
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

//read songs function from a bit ago
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

/*
* This function makes the inputted string lowercase
* Parameters: string that is to be made lowercase
* Return: lowercase string 
*/

string toLower(string gen){

    //initialized a new string variable, made it empty to add the new lowercase characters to it.
    string low = "";

    //iterate through the inputted string, and if the character is less that 97 (ASCII value for lowercase a), add 32 to it to get its capital ASCII value
    //then add that character to the string 
    //if the character is lowercase alreayd just add it to the string 
    for (int i = 0; i<gen.length(); i++){
        if (gen[i]<97){
            low += gen[i]+32;
        }

        else {
            low += gen[i];
        }
    }
    //return the new lowercase string 
    return low;
}

/*
* This function counts the number of songs that are a certain genre
* Parameters: the genre to compare to of type string, an array of songs of type songs, and the number of songs stored as an int
* Return: the count of the songs that match the genre inputted
*/

int countGenre(string genre, Song songs[], int numSongsStored){
    //initialize the genreCount variable to 0
    int genreCount = 0;

    //if the numSongsStored is 0 or invalid, just return 0
    if (numSongsStored <= 0 ){
        return 0;

    }

    //Otherwise iterate through the songs array and create 2 strings to store the lowercase value of the genre at a certain string and the inputted genre string
    for (int i = 0; i<numSongsStored; i++){
            string compare = "";
            string compare2 = "";
            compare = toLower(songs[i].getGenre());
            compare2 = toLower(genre);

            //if the genre in the array is equal to the inputted genre then bump up the counter value
            if (compare == compare2){
                genreCount++;
            }
    }    
    
    //if the genreCount is 0, then return 0
    if (genreCount == 0){
        return 0;
    }

    //return the genre count
    return genreCount;

}

int main(){

    //Tester
    Song song[50];
    int numSongsStored = 0;
    int songArrSize = 50;
    int i = readSongs("songs.txt",song, numSongsStored, songArrSize);
    cout << countGenre("Metal", song, numSongsStored);
}

