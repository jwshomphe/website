#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;



int mode_set(int curr, string line){
    char current = line[curr];
    char next = line[curr+1];
    if( current == NULL){
        return 0;
    }
    if(current = '"' && curr == 0){
        return 4;
    }
    if(current== '"' && next == NULL){
        return 1;
    }
    if (current == '"'&& next == ','){
        if(line[curr-1] !='"' && next +1 != '"'){
            return 2;
        }else{
            return 3;
        }
    }
    
    






};
/*
mode 0 is for if the string is null
mode 1 is for if the parser has hit the end of the line
mode 2 is to advance the cell of the array and indicates that the parser has hit the end of an item
mode 3 FIND OUT WHAT THE FUCK MODE 3 DOES
mode 4 is when the first value is reached



*/

//"1716752166","26 May 2024, 19:36","Mike Will Made-It","","The,Mantra","3999e151-268d-4020-976f-62b72f85a8a9","The Mantra - From ""Creed II: The Album""",""


// use switch statements for the catches
int main(){



    return 0;
}