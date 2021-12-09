//#include <iostream>
//#include <string>
#include <fstream>
#include <stack>
//#include <vector>
#include <sstream>
//#include <algorithm>
#include "3.h"
//using namespace std;

stack<string> popmult(stack<string> st, int amt){
    string s;
    cout << "pop:";
    for(int i = 0; i < amt; i++){
        s = st.top();
        cout << s << " ";
        st.pop();
    }
    cout << endl;
    cout << "amt:" << amt << endl;
    return st;
}

int string_to_col_num(string s){
    int col;
    if(s=="("){
        col = 0;
    }
    else if(s==")"){
        col = 1;
    }
    else if(s=="*"){
        col = 2;
    }
    else if(s=="+"){
        col = 3;
    }
    else if(s==","){
        col = 4;
    }
    else if(s=="-"){
        col = 5;
    }
    else if(s=="/"){
        col = 6;
    }
    else if(s=="0"){
        col = 7;
    }
    else if(s=="1"){
        col = 8;
    }
    else if(s=="2"){
        col = 9;
    }
    else if(s=="3"){
        col = 10;
    }
    else if(s=="4"){
        col = 11;
    }
    else if(s=="5"){
        col = 12;
    }
    else if(s=="6"){
        col = 13;
    }
    else if(s=="7"){
        col = 14;
    }
    else if(s=="8"){
        col = 15;
    }
    else if(s=="9"){
        col = 16;
    }
    else if(s==":"){
        col = 17;
    }
    else if(s==";"){
        col = 18;
    }
    else if(s=="="){
        col = 19;
    }
    else if(s=="a"){
        col = 20;
    }
    else if(s=="b"){
        col = 21;
    }
    else if(s=="c"){
        col = 22;
    }
    else if(s=="d"){
        col = 23;
    }
    else if(s=="w"){
        col = 24;
    }
    else if(s=="f"){
        col = 25;
    }
    else if(s=="integer"){
        col = 26;
    }
    else if(s=="\"value=\""){
        col = 27;
    }
    else if(s=="begin"){
        col = 28;
    }
    else if(s=="end."){
        col = 29;
    }
    else if(s=="program"){
        col = 30;
    }
    else if(s=="write"){
        col = 31;
    }
    else if(s=="var"){
        col = 32;
    }
    else if(s=="$"){
        col = 33;
    }
    else if(s=="A"){
        col = 34;
    }
    else if(s=="B"){
        col = 35;
    }
    else if(s=="C"){
        col = 36;
    }
    else if(s=="D"){
        col = 37;
    }
    else if(s=="E"){
        col = 38;
    }
    else if(s=="F"){
        col = 39;
    }
    else if(s=="G"){
        col = 40;
    }
    else if(s=="H"){
        col = 41;
    }
    else if(s=="I"){
        col = 42;
    }
    else if(s=="L"){
        col = 43;
    }
    else if(s=="N"){
        col = 44;
    }
    else if(s=="P"){
        col = 45;
    }
    else if(s=="R"){
        col = 46;
    }
    else if(s=="S"){
        col = 47;
    }
    else if(s=="T"){
        col = 48;
    }
    else if(s=="W"){
        col = 49;
    }
    else if(s=="X"){
        col = 50;
    }
    else if(s=="Y"){
        col = 51;
    }
    else if(s=="Z"){
        col = 52;
    }
    return col;
}


void showStack(stack<string> st){
    if(st.empty()){
        return;
    }
    string top = st.top();
    vector<string> v;
    cout << "stack:";
    // put stack in vector
    while(!st.empty()){
        top = st.top();
        v.push_back(top);
        st.pop();
    }
    // output backwards
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}

string go(vector<vector<string>> t, int row, int col){
    string go2 = t[row][col];
    return go2;
}

bool str_digit(string s){
    bool b = false;
    for(int i = 0; i < s.length(); i++){
        if(isdigit(s.at(i))){
            b = true;
        }
        else b = false;
    }
    return b;
}

int get_count(string s){
    int count = 0;
    int num = stoi(s) - 1;
    switch(num){
        case 0: // program I ; var C begin G end.
            count = 8;
            break;
        case 1: // LX
            count = 2;
            break;
        case 2: // L
            count = 1;
            break;
        case 3: case 4: // HX
            count = 2;
            break;
        case 5: case 6: // L
            count = 1;
            break;
        case 7: // D:Y;
            count = 4;
            break;
        case 8: // I,D
            count = 3;
            break;
        case 9: case 10: case 11: // B
            count = 1;
            break;
        case 12: // BG
            count = 2;
            break;
        case 13: case 14: // A
            count = 1;
            break;
        case 15: // write(RI);
            count = 6;
            break;
        case 16: // write(I);
            count = 5;
            break;
        case 17: // "value=",
            count = 2;
            break;
        case 18: // I=E;
            count = 4;
            break;
        case 19: case 20: // E-T
            count = 3;
            break;
        case 21: // T
            count = 1;
            break;
        case 22: case 23: // T/F
            count = 3;
            break;
        case 24: case 25: case 26: // N
            count = 1;
            break;
        case 27: case 28: // SHZ
            count = 3;
            break;
        case 29: case 30: // HZ
            count = 2;
            break;
        case 31: // H
            count = 1;
            break;
        case 32: // HZ
            count = 2;
            break;
        case 33: case 34: case 35: case 36:  case 37: case 38:case 39: case 40: 
        case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: 
        case 49:  case 50: case 51:
            count = 1;
            break;
    }
    return count;
}

string get_col(string s){
    string col;
    int num = stoi(s);
    num -= 1;
    switch(num){
        case 0:
            col = "P";
            break;
        case 1: case 2:
            col = "I";
            break;
        case 3: case 4: case 5: case 6:
            col = "X";
            break;
        case 7:
            col = "C";
            break;
        case 8: case 9:
            col = "D";
            break;
        case 10:
            col = "Y";
            break;
        case 11: case 12:
            col = "G";
            break;
        case 13: case 14:
            col = "B";
            break;
        case 15: case 16:
            col = "W";
            break;
        case 17:
            col = "R";
            break;
        case 18:
            col = "A";
            break;
            case 19: case 20: case 21:
            col = "E";
            break;
        case 22: case 23: case 24: 
            col = "T";
            break;
            case 25: case 26: case 27: 
            col = "F";
            break;
        case 28: case 29: case 30: case 31:
            col = "N";
            break;
            case 32: case 33: 
            col = "Z";
            break;
        case 34: case 35: 
            col = "S";
            break;
        case 36: case 37:case 38: case 39: case 40: 
        case 41: case 42: case 43: case 44: case 45: 
            col = "H";
            break;
        case 46: case 47: case 48: case 49: case 50: case 51:
            col = "L";
            break;
    }
    return col;
}

bool trace(vector<vector<string>> t, string readWord){
    string read,go2,top = "0";
    vector<string> res = {"program", "var", "begin", "end.", "integer", "write"};
    char c = '0', temp;
    int col;
    stack<string> st;
    st.push(top);
    int counter = 0;
    cout << "push:0\n";
    string num;
    int numtop;
    bool b = true;
    while(go2 != "acc"){
        if(b == true){  
            read = readWord.substr(0, readWord.find(" "));
            if(read == "$"){
                cout << "ah\n";
            }
            if(read == "end."){
                cout << "ah\n";
            }
            if(find(res.begin(), res.end(), read) != res.end()){
                readWord = readWord.substr(readWord.find(" ")+1, readWord.length()); 
            }
            else if(readWord.at(0) == '\"'){
                readWord = readWord.substr(readWord.find(","),readWord.length());
            }
            else{
                read = readWord.at(0);
                readWord = readWord.substr(readWord.find(" ") + 1,readWord.length());
            }
            b=false;
        }

        cout << "----------------------------------------------\n";
        showStack(st);
        top = st.top();
        cout << "pop:" << top << endl;

        if(str_digit(top))
            numtop = stoi(top);
        st.pop();
    
        if(read == "\""){
            cout << "s\n";
        }
        cout << "read:" << read << endl;
        col = string_to_col_num(read);
        cout << "col:" << col << endl;
        go2 = go(t,numtop,col);
        cout << "go2:" << go2 << endl;
        num = go2.substr(1,go2.length());
        c = go2.at(0);

        if(c=='r'){
            string nt;
            st.push(top);
            cout << "in r:\n";
            if(str_digit(num)){
                int count = get_count(num) * 2;
                st = popmult(st, count);
            }
            showStack(st);
            top = st.top();
            st.pop();
            if(str_digit(top))
                numtop = stoi(top);
            cout << "pop:" << top << endl;
            nt = get_col(num);
            col = string_to_col_num(nt);
            cout << numtop << " " << col << endl;
            go2 = go(t,numtop,col);
            st.push(top);
            st.push(nt);
            st.push(go2);
            cout << "goto[" << top <<","<<nt<<"]:" << go2 << endl;
            cout << "push:" << top << " " << nt << " " << go2 << endl;
            b = false;    
        }
        if (c=='s'){
            cout << "in s:\n";
            st.push(top);
            st.push(read);
            st.push(num);
            cout << "goto[" << numtop <<","<<read<<"]:" << go2 << endl;
            cout << "push:" << top << " " << read << " " << num << endl;
            b = true;
        }
        if(c!='s' && c!='r'){
            cout << "in else:\n";
            st.push(top);
            st.push(read);
            st.push(num);
            cout << "goto[" << numtop <<","<<read<<"]:" << go2 << endl;
            cout << "push:" << top << " " << read << " " << num << endl;
            b = false;
        }
        showStack(st);
        if(go2 == "") return false;

    }

    return true;
}

int main(){
    ifstream text ("finalp2.txt");
    string s, line;
    vector<vector<string>> table = {{"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s2","","","","","","","","","","","","","","","1","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","acc","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","","","","3","4","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","s11","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r3","r3","r3","r3","r3","r3","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","r3","r3","r3","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","","","22","","23","","","","","","","24","",},
    {"","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","r47","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","r48","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","r49","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","r50","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","r52","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","r51","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s25","","","","","","","","","","","","","","","","","","","",},
    {"","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","r37","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","r38","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","r39","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","r40","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","r41","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","r42","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","r43","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","r44","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","r45","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","r46","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r6","r6","r6","r6","r6","r6","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","r6","r6","r6","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","","","22","","23","","","","","","","26","",},
    {"","r7","r7","r7","r7","r7","r7","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","r7","r7","r7","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","","","22","","23","","","","","","","27","",},
    {"","r2","r2","r2","r2","r2","r2","","","","","","","","","","","r2","r2","r2","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","28","29","","","","","30","4","","","","","","","","",},
    {"","r5","r5","r5","r5","r5","r5","","","","","","","","","","","r5","r5","r5","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r4","r4","r4","r4","r4","r4","","","","","","","","","","","r4","r4","r4","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","s31","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","s32","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","s33","","","","","","","","","","","","","r10","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","","","s39","","","34","35","","","","","36","","37","4","","","","","","38","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","s41","","","","","","","","","","","","","","","","","","","","","","","","","40",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","42","","","","","30","4","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r15","r15","r15","r15","r15","r15","","","","r15","","r15","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","r12","","s39","","","34","35","","","","","43","","37","4","","","","","","38","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","s44","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","s45","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r14","r14","r14","r14","r14","r14","","","","r14","","r14","","","","","","","","","","","","","","","","","","","","",},
    {"s46","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","s47","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","r11","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","r9","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","r13","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","r1","","","","","","","","","","","","","","","","","","",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","51","52","","53","54","4","55","","","56","57","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","s60","","","","","","","","","","","","","","","58","4","","","59","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","","","","","","","","","r8","","","","","","","","","","","","","","","","","","","","","","","",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","61","52","","53","54","4","55","","","56","57","","","",},
    {"","","","","","","","r35","r35","r35","r35","r35","r35","r35","r35","r35","r35","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","r36","r36","r36","r36","r36","r36","r36","r36","r36","r36","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","s62","","s63","","","","","","","","","","","","","s64","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r25","r25","r25","","r25","r25","","","","","","","","","","","","r25","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r32","r32","r32","","r32","r32","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","r32","","","","","","","","","","","","","","","","","","","","","","","65","","","","","","","","","","","66",},
    {"","r26","r26","r26","","r26","r26","","","","","","","","","","","","r26","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r27","r27","r27","","r27","r27","","","","","","","","","","","","r27","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","","","","","","","","","","","","","","","","","","","","","","67","","","","","","","","","","",},
    {"","r22","s68","r22","","r22","s69","","","","","","","","","","","","r22","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","s70","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","","","","71","4","","","","","","","","",},
    {"","","","","s72","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","s73","","s62","","s63","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","52","","53","54","4","55","","","56","74","","","",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","52","","53","54","4","55","","","56","75","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r19","r19","r19","r19","r19","r19","","","","r19","","r19","","","","","","","","","","","","","","","","","","","","",},
    {"","r34","r34","r34","","r34","r34","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","r34","","","","","","","","","","","","","","","","","","","","","","","65","","","","","","","","","","","76",},
    {"","r31","r31","r31","","r31","r31","","","","","","","","","","","","r31","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r30","r30","r30","","r30","r30","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","r30","","","","","","","","","","","","","","","","","","","","","","","65","","","","","","","","","","","77",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","78","","53","54","4","55","","","56","","","","",},
    {"s48","","","s49","","s50","","s12","s13","s14","s15","s16","s17","s18","s19","s20","s21","","","","s5","s6","s7","s8","s9","s10","","","","","","","","","","","","","","79","","53","54","4","55","","","56","","","","",},
    {"","","","","","","","","","","","","","","","","","","s80","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","s81","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r18","r18","r18","r18","r18","r18","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r28","r28","r28","","r28","r28","","","","","","","","","","","","r28","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r20","s68","r20","","r20","s69","","","","","","","","","","","","r20","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r21","s68","r21","","r21","s69","","","","","","","","","","","","r21","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r33","r33","r33","","r33","r33","","","","","","","","","","","","r33","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r29","r29","r29","","r29","r29","","","","","","","","","","","","r29","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r23","r23","r23","","r23","r23","","","","","","","","","","","","r23","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","r24","r24","r24","","r24","r24","","","","","","","","","","","","r24","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r17","r17","r17","r17","r17","r17","","","","r17","","r17","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","s82","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",},
    {"","","","","","","","","","","","","","","","","","","","","r16","r16","r16","r16","r16","r16","","","","r16","","r16","","","","","","","","","","","","","","","","","","","","",}};

    if (text.is_open()){
        while (getline(text,line)){
            if(line.at(line.length()-1) != ' ')
                s += ' ';
            s += line;
        }
        s += '$';
    }

    else cout << "Error opening file";
    text.close();

    bool b = trace(table, s); // change str to s later
    cout << "----------------------------------------\n";
    string str = "program f2021 ; var a1 , b2a , wc , ba12 : integer ; begin a1 = 3 ; b2a = 4 ; wc = 5 ; write ( wc ) ; ba12 = a1 * ( b2a + 2 * wc ) ; write ( \"value=\" , ba12 ) ; end. ";
    if(b==true){
        cout << "accepted\n";
        output(str);
    } 
    else cout << "rejected";
    cout << endl;

}