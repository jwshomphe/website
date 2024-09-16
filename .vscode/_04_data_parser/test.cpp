



#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

class Artist{
    
    private:


    public:
    string moniker;
    int frequencey;
    vector<string> albums;
    string MBID;


    


};
class Album{
    private:

    public:
    string title;
    int frequencey;
    string artist;
    vector<string> tracks;
    string MBID;
    Album(string t, string a, string id){
        title=t;
        frequencey=0;
        MBID= id;
        artist=a;
    }


};

class Track {
public:
    string title;
    int frequency;
    string artist;
    string MBID;

    Track(string t, string a, string id){

    title=t;
    artist=a;
    MBID = id;
    frequency = 0;
    }

    void incrementFrequency() {
        frequency++;
    }
};


class Instance {
public:
     string songtitle;
     string albumtitle;
     string artist;
     string timeoccurance;
     string artistMBID;
     string trackMBID;
     string albumMBID;

    Instance( string song,  string album,  string art,  string time,
              string artistID,  string trackID,  string albumID) {
        songtitle = song;
        albumtitle = album;
        artist = art;
        timeoccurance = time;
        artistMBID = artistID;
        trackMBID = trackID;
        albumMBID = albumID;
    }
};

class Day{


};
class Month{

};
class Year{

};
class Library{
    public:

    private:
    



};

Instance Parse(string line){
    string args[6];
    int mode = 1;
    int argsnum =0;
    int curr = 11;
    int next= 12;
    /*
    if(line == NULL){
        return NULL;
    }
    
    */
    for(int i = 0; i>= line.length(); i++){
        if(&line == NULL){
            break;
        }else if(next = line.length()){
            return Instance(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
        //for only the first item UTS
        }else if (mode = 1){
             cout<< line;
        }
        
    

    curr = next;
    next++;
}}

bool isMBID(string &MBID){
    if(&MBID == NULL){
        return false;
    }
    else if(MBID.length() == 36 && MBID[8] == '-' && MBID[13] == '-' && MBID [18] == '-' && MBID[23] == '-'){
        return true;

    }else if (MBID.empty())
    {
        MBID = "no MBID present";
    }else{
        return false;
    }
}



string removeQuotes(const string &str) {
    if (str.size() >= 2 && str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.size() - 2);
    }
    return str;
}
void replaceEmptyMBID(string &x) {
    if (x.empty()) {
        x = "no MBID present";
    }
}
int main() {
    vector<Instance> InstLST;
    string filename = "smalltest.csv";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            //some issues are popping up when items in the csv file include a comma ie. a song title with a comma in it, how to resolve?
            //MBID strings are 36 long
            
            stringstream ss(line);
            string uts, timestamp, artist, artistMBID, albumtitle, albumMBID, songtitle, trackMBID;
            string date, time;
            string trash,trash2,trash3,trash4;
            string temp1,temp2,temp3, temp4, temp5,temp6,temp7,temp8,temp9;
            getline(ss, trash, ',');

            getline(ss, trash, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, artist, ',');
            getline(ss, artistMBID, ',');
            getline(ss, albumtitle, ',');
            getline(ss, albumMBID, ',');
            getline(ss, songtitle, ',');
            getline(ss, trackMBID, ',');

            timestamp = date + time;

            // Remove quotes and replace empty MBIDs
            artistMBID = removeQuotes(artistMBID);
            replaceEmptyMBID(artistMBID);

            albumMBID = removeQuotes(albumMBID);
            replaceEmptyMBID(albumMBID);

            trackMBID = removeQuotes(trackMBID);
            replaceEmptyMBID(trackMBID);

            Instance test(
                removeQuotes(songtitle), removeQuotes(albumtitle), removeQuotes(artist), removeQuotes(timestamp),
                removeQuotes(artistMBID), removeQuotes(trackMBID), removeQuotes(albumMBID)
            );

            InstLST.push_back(test);
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    for (int i = 0; i < InstLST.size(); i++) {
        cout << InstLST[i].trackMBID << endl;
    }
    cout << "reached end" << endl;
    return 0;
}
