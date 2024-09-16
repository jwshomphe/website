#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Artist {
public:
    string moniker;
    int frequency;
    vector<string> albums;
    string MBID;
};

class Album {
public:
    string title;
    int frequency;
    string artist;
    vector<string> tracks;
    string MBID;

    Album(string t, string a, string id) {
        title = t;
        frequency = 0;
        MBID = id;
        artist = a;
    }
};

class Track {
public:
    string title;
    int frequency;
    string artist;
    string MBID;

    Track(string t, string a, string id) {
        title = t;
        artist = a;
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

    Instance(string song, string album, string art, string time,
             string artistID, string trackID, string albumID) {
        songtitle = song;
        albumtitle = album;
        artist = art;
        timeoccurance = time;
        artistMBID = artistID;
        trackMBID = trackID;
        albumMBID = albumID;
    }
};

class Day {};

class Month {};

class Year {};

class Library {
public:

private:
};

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

vector<string> parseCSVLine(const string &line) {
    vector<string> result;
    stringstream ss(line);
    string field;
    bool insideQuotes = false;
    string currentField;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (c == '"') {
            insideQuotes = !insideQuotes;
        } else if (c == ',' && !insideQuotes) {
            result.push_back(currentField);
            currentField.clear();
        } else {
            currentField += c;
        }
    }
    result.push_back(currentField);

    return result;
}


int main() {
    vector<Instance> InstLST;
    string filename = "smalltest.csv";
    ifstream myfile(filename);

    if (myfile.is_open()) {
        string line;
        while (getline(myfile, line)) {
            vector<string> fields = parseCSVLine(line);

            if (fields.size() < 9) {
                cout << "Incorrect format in line: " << line << endl;
                continue;
            }
            //MBID strings are 36 long
            string timestamp = fields[1] + fields[2];

            string artistMBID = removeQuotes(fields[4]);
            replaceEmptyMBID(artistMBID);

            string albumMBID = removeQuotes(fields[6]);
            replaceEmptyMBID(albumMBID);

            string trackMBID = removeQuotes(fields[8]);
            replaceEmptyMBID(trackMBID);

            Instance instance(
                removeQuotes(fields[7]), removeQuotes(fields[5]), removeQuotes(fields[3]), removeQuotes(timestamp),
                artistMBID, trackMBID, albumMBID
            );

            InstLST.push_back(instance);
        }
        myfile.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    for (size_t i = 0; i < InstLST.size(); ++i) {
        cout << InstLST[i].trackMBID << endl;
    }
    cout << "reached end" << endl;
    return 0;
}
