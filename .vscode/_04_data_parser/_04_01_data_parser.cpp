
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
// add support for a find first instance of artist, song, and  album fn 
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

string removeQuotes(const string &str) {
    if (str.size() >= 2 && str.front() == '"' && str.back() == '"') {
        return str.substr(1, str.size() - 2);
    }
    return str;
}
void MBIDFIX(string &x) {
    if (x == "") {
        x = "NO MBID PRESENT";
    }
}
int main() {
    vector<Instance> InstLST;
    string filename = "SCROBBLESALLTIME.csv";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            stringstream ss(line);
            string uts, timestamp, artist, artistMBID, albumtitle, albumMBID, songtitle, trackMBID;
            string trash;
            getline(ss, trash, ',');



            getline(ss, uts, ',');
            getline(ss, timestamp, ',');
            getline(ss, artist, ',');
            getline(ss, artistMBID, ',');
            getline(ss, albumtitle, ',');
            getline(ss, albumMBID, ',');
            getline(ss, songtitle, ',');
            getline(ss, trackMBID, ',');
             
            MBIDFIX(artistMBID);
            MBIDFIX(albumMBID);
            MBIDFIX(trackMBID);

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
