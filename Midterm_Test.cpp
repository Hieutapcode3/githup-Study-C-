#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

// Cau1
typedef struct Company{
    int id;
    string companyname;
    string country;
    double sales;
    double profit;
    double assets;
    double market_value;
} CPN;

double getnumber(string &s){
    int unit =1;
    for(int i=0;i< s.size();i++){
        if(s[s.size() -1] == 'B' || s[s.size() -2] == 'B')
            unit = 1000;
    }
    string num_only;
    for(int i=0;i < s.size();i++){
        if(isdigit(s[i]) || s[i] == '.')
        num_only += s[i];
    }
    return stod(num_only)* unit;
}

void remove_commas(string& input) {
    bool insideQuotes = false;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] == '"') {
            insideQuotes = !insideQuotes; 
        }
        if (insideQuotes && input[i] == ',') {
            input.erase(i, 1); 
            --i; 
        }
    }
    for(int i=0;i< input.size();i++){
        if(input[i] == '"')
            input.erase(i,1);
    }
}

//Cau3
void outFile(string &path,string &countryName){
    ifstream inFile(path);
    ofstream ouFile(countryName + ".csv");
    string line;
    getline(inFile,line,'\n');
 	while(getline(inFile,line,'\n')){
 	    string words;
        istringstream iss(line);
        getline(iss,words,',');
        getline(iss,words,',');
        getline(iss,words,',');
        if(words == countryName){
            ouFile << line <<endl;
        }
 	}
 	inFile.close();
 	ouFile.close();
}

//Cau4
void readFile(string &path,vector<CPN> &v){
    ifstream inFile(path);
    string line;
    getline(inFile,line,'\n');
 	while(getline(inFile,line,'\n')){
 	    string words;
 	    remove_commas(line);
        istringstream iss(line);
        CPN c;
        getline(iss,words,',');
        c.id = stoi(words);
        getline(iss,words,',');
        string companyname = words;
        getline(iss,words,',');
        string country = words;
        getline(iss,words,',');
        string sales = words;
        getline(iss,words,',');
        string profit = words;
        getline(iss,words,',');
        string assets = words;
        getline(iss,words,',');
        string market_value = words;
        c= {c.id,companyname,country,getnumber(sales),getnumber(profit),getnumber(assets),getnumber(market_value)};
        v.push_back(c);
    }
    // for(int i=0;i < v.size();i++){
    //     cout <<v[i].id <<" " << v[i].companyname <<" " << v[i].country << " " << v[i].sales << " " << v[i].profit << " " << v[i].assets << " " << v[i].market_value <<endl;
    // }
}
//Cau5
void Check(vector<CPN> &v,double &value){
    int count =0;
    for(int i=0;i < v.size();i++){
        if(v[i].profit > value){
            count++;
            cout << v[i].companyname <<endl;
        }
    }
    cout <<"Co tong cong :" << count << " cong ty co profit lon hon" <<endl;
}
//Cau6
void Check_2(vector<CPN> &v,double &value){
    int count =0;
    for(int i=0;i < v.size();i++){
        if(v[i].profit < 0){
            count++;
            cout << v[i].companyname <<endl;
        }
    }
    cout <<"Co tong cong :" << count << " cong ty co profit nho hon 0" <<endl;
}
int main(int argc, char * argv[]) {
    if(argc != 7){
        cout << "Input not correct" << endl;
        exit(0);
    }
    string path;
    string countryName;
    vector<CPN> cpn;
    double value; // million $
    for(int i=0;i< argc;i++){
        if(string(argv[i]) == string("-p")){
            path = argv[i+1];
        }else if(string(argv[i]) == string("-cn")){
            countryName = argv[i+1];
        }else if(string(argv[i]) == string("-v")){
            value = stod(argv[i+1]);
        }
    }
	ifstream inFile(path);
	if(!inFile.is_open()){
		cout << "File UnLoaded" << endl;
		exit(0);
	}
	cout << "File Loaded" << endl;
	//outFile(path,countryName);
	readFile(path,cpn);
	Check(cpn,value);
	//Check_2(cpn,value);
}	