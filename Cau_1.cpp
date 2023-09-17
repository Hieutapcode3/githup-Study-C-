#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef struct Point{
    int id;
    double x,y;
} P;

int main(int argc,char *argv[]){
    string path;
    int nodeid;
    for(int i=0;i< argc;i++){
        if(string(argv[i]) == string("-p")){
            path = argv[i+1];
        }else if(string(argv[i]) == string("-n")){
            nodeid = stoi(argv[i+1]);
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
    while (inFile >> line)
    {
        string word;
        P p;
        istringstream iss(line);
        getline(iss,word,',');
        p.id = stoi(word);
        getline(iss,word,',');
        p.x = stod(word);
        getline(iss,word,',');
        p.y = stod(word);
        waypoint.push_back(p);
    }
    //4
    double closest_point = 10e+9,furthest_point = 10e-9;
    int id_min,id_max;
    for(int i=0;i < waypoint.size();i++){
        double distance = sqrt(pow(waypoint[nodeid].x - waypoint[i].x,2) + pow(waypoint[nodeid].y-waypoint[i].y,2));
        if( distance < closest_point && i!= nodeid){
            closest_point = distance; 
            id_min = waypoint[i].id;
        }
        if( distance > furthest_point && i!= nodeid){
            furthest_point = distance;
            id_max = waypoint[i].id;
        }
    }
    ofstream outFIle("output.txt");
    outFIle <<" Diem thu : " << id_min << " co khoang cach gan nhat la :" << closest_point << endl;
    outFIle <<" Diem thu : " << id_max << " co khoang cach xa nhat la :"  << furthest_point << endl;
    outFIle.close();

    

}