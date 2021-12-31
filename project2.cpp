// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #11(/12 on coderunner)
#include "Listener.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//this is the split function from a while ago
int split(string splitted, char separate, string pieces[], int siz){
    int len = splitted.length();
    int numSplit = 0;
    int prev = 0;
    if (splitted == ""){
        return 0;
    }
    for (int i = 0; i<=len; i++){
        
        if (splitted[i]==separate || i == len ){
                pieces[numSplit] = splitted.substr(prev,i-prev);
                numSplit++;
                prev = i+1;
        }
    }
    if (numSplit>=siz){
        return -1;
    }
    else{
        return numSplit;
    }
}

//this is the readSongs function from a while back
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

//print all songs function from a while ago
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

//this is the read listener info function from a while ago
int readListenerInfo(string filename, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol = 51){
    ifstream in1;

    in1.open(filename);

    string arr[maxCol]; 
    int arr1[50];
    string line = "";

    if (numListenersStored >= listenerArrSize){
            return -2;
    }

    if (in1.fail()){
        return -1;
    }
    
   int i = numListenersStored;
    while(getline(in1, line) && (i<listenerArrSize)){
        if (line != ""){
           // listeners[i] = Listener(); 

            int s = 0;
            s = split(line, ',', arr, 51); 
                
            string name = "";
            listeners[i].setListenerName(arr[0]);
           // int h = 1;
            for (int k = 1; k<s; k++){
               // arr1[k] = stoi(setPlayCountAt());
               listeners[i].setPlayCountAt(k-1, stoi(arr[k]));
               // h++;
            }
           // songs[numSongsStored] = Song(arr[0], arr[1], arr[2]);
            //listeners[i] = Listener(name, arr1, maxCol);
            
            
            i++;
            
        
        }
    }

    return i;
        
}

//this is the toLower function from this 
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

//this is the count Genre function from a few problems ago
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

//this is the frequent Genre songs function from a few problems ago
int frequentGenreSongs (Song songs[], int numSongsStored){
    int temp = 0;
    for (int i = 0; i<numSongsStored; i++){
        int count = countGenre(songs[i].getGenre(), songs, numSongsStored);
        if (count>temp){
            temp = count;
        }
    }
    return temp;

}

//this is the getSongPlayCount function from a few problems ago
int getSongPlayCount(string listenerName, string songName, Listener listeners[], Song songs[], int numListeners, int numSongs){
    bool listFound = 0;
    bool songFound = 0;
    int k = -1;
    int h = -1;
    for (int i = 0; i<numListeners; i++){
        if (toLower(listeners[i].getListenerName()) == toLower(listenerName)){
            listFound = 1;
            k = i;
           //cout<<listeners[i].getListenerName()<<endl;
            
        }

    }
    for (int j = 0; j<numSongs; j++){
        if (toLower(songs[j].getTitle()) == toLower(songName)){
            songFound = 1;
            h = j;
            //cout<<songs[j].getTitle()<<endl;      
    }
    }
    
    if ((numSongs <= 0  && numListeners > 0) || ((listFound)&&!(songFound))){
        return -1;
    }
    if ((numListeners <= 0 && numSongs > 0) || (!(listFound)&&(songFound))){
        return -2;
    }
    if (!(listFound)&&!(songFound)){
        return -3;
    }
    return listeners[k].getPlayCountAt(h);
}

//this is the addlistener function from a few places ago
int addListener(string listenerName, Listener listeners[], int numSongs, int numListenersStored, int listenersArrSize = 100){
    if (listenerName == ""){
        return -3;
    }
    if (numListenersStored >= listenersArrSize){
        return -1;
    }
    
    for (int i = 0; i<listenersArrSize; i++){
        if (toLower(listeners[i].getListenerName()) == toLower(listenerName)){
            return -2;
        }
            

    }
    Listener li = Listener();
    li.setListenerName(listenerName); 
    listeners[numListenersStored] = li;
    return numListenersStored+1;
    
    
}

//this is the getListenerStats function from last problem
int getListenerStats(string listenerName, Listener listeners[], int numListenersStored, int numSongs){
    for (int i = 0; i<numListenersStored; i++){
        if (listeners[i].getListenerName() == listenerName){
            
            if (listeners[i].totalPlayCount() == 0){
                cout<<listenerName<<" has not listened to any songs."<<endl;
                return 0;
            }
            cout<<listenerName<<" listened to "<<listeners[i].getNumUniqueSongs()<<" songs."<<endl;
            double sum = 0;
            double avg = 0;
    
            for (int k = 0; k< numSongs; k++){
                if (listeners[i].getPlayCountAt(k) > 0) {
                    sum += listeners[i].getPlayCountAt(k);
                }
            }
            avg = (sum)/(listeners[i].getNumUniqueSongs());

            cout<<fixed<<setprecision(2)<<listenerName <<"'s average number of listens was "<<avg<<endl;
            return 1;
        }


    }
    cout<<listenerName<<" does not exist."<<endl;
    return -3;
}


int main() {
    int option;
    Song song[50];
    Listener listeners[100];
    string file = "";

    //initialize a songs variable to store the readSongs return value 
    int songs = 0;

    //initialize the temp1 variable to restore the songs value after each return 
    int temp1 = 0;

    //intialize a genre string to store the genre
    string genre = "";

    //intialize strings for the name, the listener, and the given song
    string name = "";
    string listener = "";
    string son = "";

    //intialize a variable to store the countGenre return value 
    int c = 0;

    //initialize a variable to store the frequentGenreSongs return value 
    int f = 0;

    //initialize a variable to store the addListener return value 
    int a = 0;

    //initialize a variable to store the readListenerInfo return value 
    int r = 0;

    //initialize a variable to store the getSongPlayCount return value
    int g = 0;

    //initialize a variable to store the getListenerStats return value
    int gL = 0;

    //while the option isnt equal to a 100, keep asking the user what option they want
    while (option!=100){

        //print the menu and ask the user for input on the option 
        cout<<"Select a numerical option:"<<endl<<"======Main Menu====="<<endl<<"1. Read songs from file"<<endl<<"2. Print all songs"<<endl<<"3. Song-count by genre"<<endl
        <<"4. Songs from most common genre"<<endl<<"5. Add listener"<<endl<<"6. Read listens from file"<<endl<<"7. Get number of listens by a listener"<<endl
        <<"8. Get listener statistics"<<endl<<"9. Quit"<<endl;
        cin>>option;

        //make a switch statement for different cases based off the user inputted option 
        
        switch(option){
            
            //if the user inputs option 1 which is to read the songs, then go to case 1
            case 1:

                //Ask the user to input the name of the song file 
                cout<<"Enter a song file name: "<<endl;
                cin>>file;
                
                
                temp1 = songs;
                
                //user the readSongs function and set it equal to the songs variable
                songs = readSongs(file, song, songs, 50);
                
                
                //if the number of songs is equal to the array, then print the message below
                if (songs == 50){
                    cout << "Total songs in the database: "<<songs<<endl;  
                    cout<<"Database is full. Some songs may have not been added."<<endl;
                }

                //If the songs is = -1, then output the following
                else if (songs == -1){
                    cout<<"No songs saved to the database."<<endl;
                    songs = temp1;
                }

                //If the songs = -2, then output the following
                else if (songs == -2){
                    cout<<"Database is already full. No songs were added."<<endl;
                    songs = temp1;
                }
                

                //otherwise, output the total songs in the database with the songs variable
                else{
                    cout << "Total songs in the database: "<<songs<<endl;   
                }
                break;

            //if the user inputs option 2 which is to print songs, then go to case 2
            case 2:
            //use the printAllSongs function to print all the songs in the system 
                printAllSongs(song, songs);
                break;
            
            //if the user inputs option 3 which is to count the total number of songs in each genre, go to case 3
            case 3:
                //ask for user input for the genre
                cout<<"Genre: "<<endl;
                cin>>genre;
                

                //call on the countgenre functions using the inputted genre, the song array and the songs (number of songs) for the params and store it in c
                if (songs > 0){
                    c = countGenre(genre, song, songs);
                }
                
                //if the songs are greater than 0 then set c = 0
                else {
                    c = 0;
                }
                //print the total number of songs for that genre in the database

                cout<<"Total "<<genre<<" songs in the database: "<<c<<endl;
                break;


            //if the user inputs option 4 which is to print the total number of songs that belong to the most common genre
            case 4:
                //call on the frequentGenreSongs function and store its value in f
                if (songs>0){
                    f = frequentGenreSongs(song, songs);
                }

                //otherwise make f = 0
                else {
                    f = 0;
                }
                //print the total number of songs that belong to the most common genre
                cout<<"Number of songs in most common Genre: "<<f<<endl;
                break;

            //if the user inputs option 5 which is to add a listener to the array then go to case 5
            case 5:
                //ask the user for a listener name, and intiialize a string variable for the name
                
                cout<<"Enter a listener name:"<<endl;
                //use getline in case the listener name is multiple words
                getline(cin,name);
                getline(cin, name);
                // call on the addListener function to add the name to the listeners array, and store it in a
                a = addListener(name, listeners, 50, a, 100);
                //output messages based on what the return value for the addListener function is 
                if (a == -1){
                    cout <<"Database is already full. Listener cannot be added."<<endl;
                }
                else if (a == -2){
                    cout <<"Listener already exists."<<endl;
                }
                else if (a == -3){
                    cout <<"The listenerName is empty."<<endl;
                }
                else {
                    cout<<"Welcome, "<<name<<"!"<<endl;
                }
                break;
            
            //if the user inputs option 6 which is to print the total number of listeners in the database then go to case 6
            case 6:
                //Ask listener for file name
                cout<<"Enter the listener info file name:"<<endl;
                cin>>file;

                //pass the file name and call on the readListenerInfo function and store it in r
                
                r = readListenerInfo(file, listeners, r, 100);

                //if r is -1 then output nothing saved to the database
                if (r == -1){
                    cout<<"Nothing saved to the database."<<endl;
                }

                //if r is -2 then output that the database is already full. nothing was added
                else if (r == -2){
                    cout<<"Database is already full. Nothing was added."<<endl;
                }

                //if r is 100, then output the total listeners but also that the database is full
                else if(r == 100){
                    cout<<"Total listeners in the database: "<<r<<endl;
                    cout<<"Database is full. Some listeners may have not been added."<<endl;
                }

                //otherwise just output the total listeners in the database 
                else {
                    cout<<"Total listeners in the database: "<<r<<endl;
                }
                break;
                
            //if the user inputs option 7 which is to print the total number of times a song has been listened to then go to case 7
            case 7:
                //Ask for listener name and the song name, and initialize variables for both
                
                cout<<"Enter a listener name: "<<endl;
                cin>>listener;
                cout<<"Enter a song name: "<<endl;

                //get the entire line for the song input incase the song is more than one word
                getline(cin, son);
                getline(cin, son);

                //call on getSongPlayCount function
               
                g = getSongPlayCount(listener, son, listeners, song, r, songs);

                //if g = -1, then output the song doesnt exist
                if (g == -1){
                    cout<<son<<" does not exist."<<endl;
                }

                //if g = -2 output the listener doesnt exist
                else if (g == -2){
                    cout<<listener<<" does not exist."<<endl;
                }

                //if g = -3, then output that the lsitener and song dont exist
                else if (g== -3){
                    cout<<listener<<" and "<<son<<" do not exist."<<endl;
                }

                //other output that the inputted listener has listened to the inputted songs g amount of times
                else {
                    cout<<listener<<" has listened to "<<son<<" "<<g<<" times."<<endl;
                }
                break;

            //if the user inputs option 8 which is to display the listener stats, then go to case 8
            case 8:
                //ask for a listener name and then call on the getListenerStats function and input it there
                cout<<"Enter a listener name: "<<endl;
                cin>>listener;

                //call on the getListenerStats function 
                gL = getListenerStats(listener, listeners, r, songs);
                break;

            //if the user inputs option 9 which is to print songs, then go to case 9
            case 9:
                //output good bye
                cout<<"Good bye!"<<endl;

                //set option to 100, so that the loop can be exited since the condition will now be false
                option = 100;
                break;
                

            //If the top 9 cases aren't chosen, then print Invalid Input
            default:
                cout<<"Invalid input."<<endl;
                break;
        }
    }
}