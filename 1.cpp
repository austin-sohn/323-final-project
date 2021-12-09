#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

// --------------- PART 1 -----------------
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

// gets rid of comments
string comment(string s){
    int pos;
    string newstr = "";
    int counter = 0;
    while(pos >= 0){
        pos = s.find("**");
        if(counter == 0){
            if(s.at(0) != '\n')
                newstr += s.substr(0, pos);
            if(newstr.at(newstr.length() - 1) != '\n')
                newstr+='\n';
        }
        s = s.substr(pos+3, s.length());
        counter++;
        if (counter == 2){
            counter = 0;
        }
    }
    return newstr;
}

// adds space before and after token
string token(string s){
    char token[8] = {',','=',';',':','(',')','+','*'};
    string res[6] = {"program", "var", "begin", "end.", "integer", "write"};
    int len = sizeof(token)/sizeof(token[0]);
    int len2 = sizeof(res)/sizeof(res[0]);
    string newstr;
    int counter = 0;
    bool b = false;

    for(int i = 0; i < len2; i++){
        //cout << s.substr(s.find(res[i]) + res[i].length(), s.length());
        s = s.substr(0,s.find(res[i]) + res[i].length()) + " " + s.substr(s.find(res[i]) + res[i].length(), s.length());
        //s = newstr;
    }
    cout << s;
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


int main(){
    string line, newstr;
    ifstream finalp1 ("finalp1.txt");
    ofstream finalp2 ("finalp2.txt");

    if (finalp1.is_open()){
        while (getline(finalp1,line)){
            newstr += line + '\n';
            
            }
        newstr = remove_space(newstr);
        newstr = comment(newstr);
        newstr = token(newstr);
        finalp1.close();
    }

    else cout << "Error opening file";

    newstr = newstr.substr(0, newstr.find("end.") + 4);
    newstr.push_back(' ');
    finalp2 << newstr;
    finalp2.close();

}