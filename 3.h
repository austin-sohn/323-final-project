#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void output(string s){
    cout << "----------------------------------- PART 3 --------------------------------\n";
    vector<string> res = {"program", "var", "begin", "end.", "integer", "write"};
    vector<string> v;
    string read,reserve,tmp,tmpres;
    ofstream o ("output.cpp");
    bool b;
        
    while(!s.empty()){
        if(s.find(";") ==-1){
            read = s.substr(0, s.find(" "));
            s = s.substr(s.find(" ")+1, s.length());
        }
        else{
            read = s.substr(0,s.find(";")+1);
            s = s.substr(s.find(";") +2, s.length());
        }
        

        if(find(res.begin(), res.end(), read.substr(0,read.find(" "))) != res.end()){
            reserve = read.substr(0, read.find(" "));
            read = read.substr(read.find(" ")+1, read.length());
        }

        if(reserve == "program"){
            cout << "#include <iostream>\nusing namespace std;\nint main()\n{\n\t";
            o << "#include <iostream>\nusing namespace std;\nint main()\n{\n\t";
            reserve = "";
        }

        else if (reserve == "var"){
            tmp = read;
            string types = tmp.substr(tmp.find(": ")+2, tmp.length());
            if(types.find(";") != -1) types = types.substr(0,types.find(";")-1);
            tmp = tmp.substr(0, tmp.find(":")) + ";\n\t";
            if(types == "integer"){
                cout << "int ";
                o << "int ";
            }
            cout << tmp;
            o << tmp;
            read = read.substr(read.find(";"+1), read.length());

            tmpres = reserve;
        }
        else if(reserve == "begin"){
            tmpres = reserve;
            
            cout << read << "\n\t";
            o << read << "\n\t";
            read = s.substr(0, s.find(";")+1);
        }
        else if(reserve == "write"){
            read = read.substr(read.find("(")+2, read.length());
            read = read.substr(0,read.find(")"));
            
            cout << "cout << " << read.substr(0,read.find(" "));
            o << "cout << " << read.substr(0,read.find(" "));
            if(read.find(",")!= -1){
                cout << " << " << read.substr(read.find(",")+2, read.length());
                o << " << " << read.substr(read.find(",")+2, read.length());
            }
            cout << " << endl"";\n\t";
            o << " << endl"";\n\t";
            reserve = tmpres;
        }
        else if(reserve == "end."){
            cout << "return 0;\n}";
            o << "return 0;\n}";
            s = "";
        }
    }


}