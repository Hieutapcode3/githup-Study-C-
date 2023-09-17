#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef struct Point{
    int i,j;
    double w;
} P;

int main(int argc,char *argv[]){
    string path;
    int nodeid;
    double w;
    for(int i=0;i< argc;i++){
        if(string(argv[i]) == string("-p")){
            path = argv[i+1];
        }else if(string(argv[i]) == string("-n")){
            nodeid = stoi(argv[i+1]);
        }else if(string(argv[i]) == string("-w")){
            w = stod(argv[i+1]);
        }
    }
    ifstream inFile(path);
    if(!inFile.is_open()){
		cout << "File UnLoaded" << endl;
		exit(0);
	}
	cout << "File Loaded" << endl;
    string line;
    vector<P> waypoint;
    inFile >> line;
    int count = 0;
    while (inFile >> line)
    {
        string word;
        P p;
        istringstream iss(line);
        getline(iss,word,',');
        p.i = stoi(word);
        getline(iss,word,',');
        p.j = stoi(word);
        getline(iss,word,',');
        p.w = stod(word);
        waypoint.push_back(p);
    }
    ofstream outfile("output_2.txt");
    outfile << "Cac canh (nodeid,i) co trong so lon hon la: " << endl;
    for(int i=0;i < waypoint.size();i++){
        if(waypoint[i].i == nodeid &&  waypoint[i].w >w ){
            outfile << "(" << nodeid << "," << waypoint[i].j << ")" << " Trong so: " << waypoint[i].w << endl;
        }

    }
}