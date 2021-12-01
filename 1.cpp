#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// adds spaces before and after tokens
string remove_space(string s){
    string newstr = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            newstr.push_back(s[i]);
        }
    }
    return newstr;
}
string token(string s){
    char token[8] = {',','=',';',':','(',')','+','*'};
    int len = sizeof(token)/sizeof(token[0]);
    string newstr, temp;
    int counter = 0;
    bool b = false;

    for(int i = 0; i < s.size()+1; i++){
        if(b == true){
            newstr.push_back(' ');
            b = false;
        }
        if(s[i] == '"'){
            counter++;
        }
        for(int j = 0; j < len; j++){
            if(s[i] == token[j] && counter!= 1){
                b = true;
                if(newstr[newstr.size()-1] == ' '){
                    break;
                }
                else{
                    newstr.push_back(' ');
                }    
            }
        }
        if(counter == 2){
            counter = 0;
        }
        newstr.push_back(s[i]);
    }
    return newstr;
}

// gets rid of comments
string comment(string s){
    int pos = s.find("**");
    string newstr;
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

bool check_error(){

    return false;
}

int main(){
    string line;
    vector<string> v;
    ifstream finalp1 ("finalp1.txt");
    ofstream finalp2 ("finalp2.txt");

    string res[6] = {"program", "var", "begin", "end.", "integer", "write"};
    bool error = true;

    if (finalp1.is_open()){
        while (getline(finalp1,line)){
            line = remove_space(line);
            line = comment(line);
            if(line != ""){
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
    error = check_error();
    if(error == false){
        cout << "#include <iostream>\n";
        cout << "using namespace std;\n";
        cout << "int main()\n";
        cout << "{\n";
        for(int i = 0; i < v.size(); i++){
            cout << "\t" << v.at(i) << endl;
        }
        cout << "\treturn 0;\n";
        cout << "}\n";
    }
    else{
        cout << "There was an error\n";
    }
    
}