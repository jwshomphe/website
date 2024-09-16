#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

string mode_set(int curr, string line){
    //cout<<"modeset"<<curr<<endl;
    int next = curr+1;
    //checks if first and starts collecting (edge case)     -- current = " net = ,
    if(curr == 0 && line[curr]== '"'){
        return "first item";
    }
    //checks to see if at end of string(line) should break in main function
    //
    else if(curr == line.length()){
        return "hit end";
    }
    else if(line[next] == ',' && line[curr] != '"' && line[curr] != ','){
        return 6;
    }
    //checks if empty fix
    else if (line[curr] == '"' && line[next]== '"'){
        if (line[curr-1]== ',' && line[next + 1]==','){
            return "empty item";
        }else{
            cout<<"3 returned"<<endl;
            return 3;
        }}
    //this should start collecting data
    else if(line[curr]== ',' && line[next]== '"'&& line[next+1] != '"'){
        return "start collecting data";
    }
    //ends collection make sure to itterate args num when this is true
    else if(line[curr]== '"' && line[next]== ',' && line[curr-1]!='"' && line[next+1] != '"'){
        return "end collection and incrament";
    }

    else if(line[curr]== '"' && line[next]== ','){
        return "increment";
    }
    else if(line[curr] == '"' && line[next] == ',' && line[next+1] =='"'){
        if(line[curr -1] != '"' && line[next +2 != ',']){
            return "increment";
        }else{
            //über special case 
            return "im actually entireley unsure";
        }
    }

    
    return "base case";
}

void parse (string line){
int argnum=0;
string args[10];
int curr = 0;
int next = 1;
int numsinc =0;
//char targ;

/*modes
mode 0 = not collecting, starts on 0
mode 1 = collecting
mode 2 = empty quotes
mode 3 = something else
mode 4 = possible seperation ie comma
mode 5 = ending current collection
*/


//"1716752166","26 May 2024, 19:36","Mike Will Made-It","","The,Mantra","3999e151-268d-4020-976f-62b72f85a8a9","The Mantra - From ""Creed II: The Album""",""

for(int i = 0; i<= line.length(); i++){
    string mode=mode_set(curr, line);
    if(mode == "hit end"){
        break;
    }
    else if((mode=="first item" || mode == "base case" || mode == "start collecting data") && line[next] != '"'){
        args[argnum].push_back(line[next]);
    }
    else if(mode == "empty item"){
        args[argnum] = "EMPTY";
        numsinc++;
        cout<<"mode 2 incremented"<< numsinc << "times"<< endl;
        argnum++;
    }
    else if(mode == "end collection and incrament"){
        
    }
    else if(mode == "increment"){
        numsinc++;
        cout<<"mode 5 incremented"<< numsinc << "times"<< endl;
        argnum++;
    }
    // else if(mode == 10){
    //     cout<<"big error"<<endl;
    // }



curr = next;
next++;

}
for (int i=0; i<10; i++){
    cout<< args[i]<<endl;
}
}


int main(){
string eviltest= "\"1716752166\",\"26 May 2024, 19:36\",\"Mike Will Made-It\",\"\",\"The,Mantra\",\"3999e151-268d-4020-976f-62b72f85a8a9\",\"The Mantra - From \"\"Creed II: The Album\"\"\",\"\" ";
parse(eviltest);
/*
for(int i =0; i>args->length(); i++){
    cout<<args[i]<<endl;
}*/
return 0;

}