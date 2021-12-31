// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #1
#ifndef SONG.H
#define SONG.H
#include <iostream>
#include <string>
using namespace std;

//made a Song class
class Song{
    //private data members for the title, artist, and genre of the song
    private:
        string title;
        string artist;
        string genre;

    //public member functions
    public:

        //Default constructor which makes everything empty
        Song(){
            title = "";
            artist = "";
            genre = "";

        }

        //Defult parameterized constructor which takes in 3 strings and initializes the title, artist, and genre
        Song(string titl, string art, string gen){
            title = titl;
            artist = art;
            genre = gen;
        }

        //Returns title as a string
        string getTitle();

        //Assigns title the value of the input string
        void setTitle(string str);

        //Returns artist as a string
        string getArtist();

        //Assigns artist the value of the input string
        void setArtist(string inp);

        //Returns genre as a string
        string getGenre();

        //Assigns genre the value of the input string
        void setGenre(string s);
};

#endif