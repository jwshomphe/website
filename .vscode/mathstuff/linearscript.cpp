#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void parse(int &x, int &y, int &z){
    int a, b, c;
    a = .25*y + .10*x + .5*z;
    b = .5*y + .8*x + .1*z;
    c = .25*y + .1*x + .4*z;
    x = b;
    y = a;
    z = c;
}

int main(){
    int happy = 9500;
    int unhappy = 100;
    int knows_happy = 400;
    
    for(int i = 0; i < 13; i++){  // Fixed loop condition
        parse(knows_happy, unhappy, happy);
        cout << "Iteration #" << i 
             << " happy: " << happy 
             << " unhappy: " << unhappy 
             << " knows happy: " << knows_happy << endl;  // Fixed output
    }
    return 0;
}
