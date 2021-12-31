// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Extra-Credit
#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//toLower function from a few problems ago
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


void smartPlaylist (string listenerName, string genre, Listener listeners[], Song songs[], int numListeners, int numSongs){
    
}