#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

void output(vector<vector<string>> t){
    for(int i = 0; i < t.size(); i++){
        for(int j = 0; j < t[i].size(); j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<string>> readTable(vector<vector<string>> t){
    ifstream file("LR.csv");
    while(file){
        string line;
        vector<string>row;
        if(!getline(file,line)) break;
        istringstream ss(line);
        while(ss){
            string s;
            if(!getline(ss,s,',')) break;
            row.push_back(s);
        }
        t.push_back(row);
    }
    file.close();
    return t;
}

int main(){
    ofstream LR ("lr.txt");
    vector<vector<string>> table;
    table = readTable(table);
    if(LR.is_open()){


        for(int i = 0; i < table.size(); i++){
            LR << "{";
            for(int j = 0; j < table.at(i).size(); j++){
                LR << "\"" << table[i][j] << "\"" << ",";
            }
            LR << "},\n";
        }
        LR << "}";
    }
    LR.close();
}