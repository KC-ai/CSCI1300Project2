// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #1
#include "Song.h"
#include <iostream>
#include <string>
using namespace std;

//Returns title as a string
string Song::getTitle(){
    return title;
}

//Assigns title the value of the input string
void Song::setTitle(string str){
    title = str;
}

//Returns artist as a string
string Song::getArtist(){
    return artist;
}

//Assigns artist the value of the input string
void Song::setArtist(string inp){
    artist = inp;
}

//Returns genre as a string
string Song::getGenre(){
    return genre;
}

//Assigns genre the value of the input string
void Song::setGenre(string s){
    genre = s;
}