#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// adds spaces before and after tokens
string token(string s){
    char token[8] = {',','=' ,';', ':','(',')',  '+', '*'};
    string newstr;
    int counter = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < s.size(); j++){
            //cout << s.size() << endl;
            cout << s.at(j) << endl;
            if(s.at(j) == '"')
                ++counter;
            if(s.at(j) == token[i] && counter != 1){
                
                //newstr = s.substr(0, s.find(token[i])) + "_" + token[i] + "_" + s.substr(s.find(token[i])+1, s.size());  // main one
                newstr += s.substr(0, s.find(token[i])) + "_" + token[i];
                s = s.substr(s.find(token[i])+1, s.size());
                j = 0;
            }
            if(counter == 2)
                counter = 0;
        }
    }
    newstr += s;
    return newstr;
}

// gets rid of comments
string comment(string s){
    int pos = s.find("**");
    string newstr;
    //cout << s.size() - 2 << " " << pos << endl;
    if(pos == -1){
        return s;
    }
    else if(pos >= 0 && (pos == s.size()-2)){
        newstr = "";
    }
    else{
        newstr = s.substr(0, pos);
    }
    return newstr;
}

int main(){
    string line;
    vector<string> v;
    ifstream finalp1 ("finalp1.txt");
    ofstream finalp2 ("finalp2.txt");
    if (finalp1.is_open()){
        while (getline(finalp1,line)){
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            line = comment(line);
            if(!line.empty()){
                line = token(line);
                
                v.push_back(line);
            }
        }
        finalp1.close();
    }
    else cout << "Error opening file";
    
    for(int i = 0; i < v.size(); i++){
        finalp2 << v.at(i) << endl;
    }
    finalp2.close();
}