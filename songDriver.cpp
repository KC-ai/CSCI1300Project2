// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #1

#include <iostream>
#include "Song.h"

using namespace std;

int main(){
    // default constructor
    Song s1 = Song();
    cout << s1.getTitle() << endl;
    cout << s1.getArtist() << endl;
    cout << s1.getGenre() << endl;

    // checking setter for name 
    Song s2 = Song();
    string title = "Yesterday";
    s2.setTitle(title);
    cout << s2.getTitle() << endl;

    // checking setter for population
    Song s3 = Song();
    string artist = "The Beatles";
    s3.setArtist(artist);
    cout << s3.getArtist() << endl;

    // checking setter for genre
    Song s4 = Song();
    string genre = "Rock";
    s4.setGenre(genre);
    cout << s4.getGenre() << endl;

    // parameterized constructor
    title = "Rocket Man";
    artist = "Elton John";
    genre = "Rock";
    Song s5 = Song(title, artist, genre);
    cout << s5.getTitle() << endl;
    cout << s5.getArtist() << endl;
    cout << s5.getGenre() << endl;

}