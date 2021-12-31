// CSCI 1300 Fall 2021
// Author: Kash Challapalli
// Recitation: 213 - Jerry Gammie
// Project 2 - Problem #7
#include "Listener.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//split function from a while back
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

/*
* This function returns the total number of listeners in the array as an integer
* Parameters: string filename, an array of listeners of Listener objects, the number of listeners stored, the size of the listener array, and the maxCol
* Return: the total number of listeners in the array
*/
int readListenerInfo(string filename, Listener listeners[], int numListenersStored, int listenerArrSize, int maxCol = 51){
    //create an isftream variable named in1
    ifstream in1;

    //open the file
    in1.open(filename);

    //make an array called arr of size 51 of type string for the names
    string arr[maxCol]; 

    //make a variable called line thats empty
    string line = "";

    //if the number of listeners stored is greater than or equal to the size of the listener array then return -2
    if (numListenersStored >= listenerArrSize){
            return -2;
    }

    //if the file cant be opened return -1
    if (in1.fail()){
        return -1;
    }
    
   int i = numListenersStored;

   //as long as there is another (non empty) line and the numListeners is less than the listenerArrSize keep going
    while(getline(in1, line) && (i<listenerArrSize)){


        if (line != ""){
           
            //create a variable to store the value the split functionr returns called s
            int s = 0;
            //input the line, the delimeter as a comma, the string array arr for the array to be stored into, and 51 as the size
            s = split(line, ',', arr, 51); 
                
            //create a string variable for the name and make it empty
            string name = "";

            //set the listener name of each listeners element to arr[0]
            listeners[i].setListenerName(arr[0]);

            //iterate through the listeners array and start the counter at 1 and bound it at the split functin return value  and iterate through each line
            for (int j = 1; j<s; j++){
              
               //set the playcount at each listeners element to j-1 and the integer converted string as the parameters
               listeners[i].setPlayCountAt(j-1, stoi(arr[j]));
               
            }
            
            //bump up the i value 
            i++;
            
        
        }
    }

    //return the i which is the number of listeners
    return i;
        
}

int main(){
    //tester
    int numListenersStored = 0;
    int listenerArrSize = 50;
    int maxColumns = 51;
    Listener listener[50];
    numListenersStored = readListenerInfo("listeners.txt", listener, numListenersStored, listenerArrSize, maxColumns);
    cout<<numListenersStored<<endl;
}