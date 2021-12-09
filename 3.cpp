#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
#include  <iostream>
using namespace  std;
int main()
{
    int a1 , b2a , wc, ba12 ;    
    a1 = 3 ;
    b2a = 4 ;
    wc = 5 ;
    cou<<wc ;  
    ba12 = a1 * (b2a + 2 * wc ) ;
    cout<< “value=” <<ba12<<endl;
    return 0;
}
*/

void output(string s){
    vector<string> res = {"program", "var", "begin", "end.", "integer", "write"};
    vector<string> v;
    string read,reserve,tmp;
    bool b;
        
    while(!s.empty()){
        read = s.substr(0,s.find(";")+1);
        s = s.substr(s.find(";") +2, s.length());
        /*
        if(find(res.begin(), res.end(), read) != res.end()){
            reserve = read;
        }*/
        for(int i = 0; i < res.size(); i++){
            if(read.find(res.at(i)) != -1){
                reserve = res.at(i);
                break;
            }
        }
        if(reserve == "program"){
            cout << "#include <iostream>\nusing namespace std;\nint main()\n{\n\t";
            reserve = "";
        }

        else if (reserve == "var"){
            //read = s.substr(0, s.find(";")+1);
            tmp = read.substr(read.find(" ")+1, read.length());
            string types = tmp.substr(tmp.find(": ")+2, tmp.length());
            if(types.find(";") != -1) types = types.substr(0,types.find(";")-1);
            tmp = tmp.substr(0, tmp.find(":"));
            if(types == "integer"){
                cout << "int ";
            }
            /*
            while (!tmp.empty()){
                if(tmp.at(0) != ',')
                    v.push_back(tmp.substr(0, tmp.find(" ")));
                tmp = tmp.substr(tmp.find(" ")+1, tmp.length());
            }*/
            cout << tmp << ";\n\t";
            read = read.substr(read.find(";"+1), read.length());
            //s = s.substr(s.find(read) + read.length() + 1, s.length());
 
        }
        else if(reserve == "begin"){
            read = s.substr(0, s.find(";")+1);
            s = s.substr(s.find(";")+2, s.length());
            cout << read << endl;

        }
        else if(reserve == "write"){

        }
        else if(reserve == "end."){

        }
    }
}

int main(){
    //ifstream text ("finalp2.txt");
    string s,line;
    string str = "program f2021 ; var a1 , b2a , wc , ba12 : integer ; begin a1 = 3 ; b2a = 4 ; wc = 5 ; write ( wc ) ; ba12 = a1 * ( b2a + 2 * wc ) ; write ( \"value=\" , ba12 ) ; end. ";
    /*
    if (text.is_open()){
        while (getline(text,line)){
            if(line.at(line.length()-1) != ' ')
                s += ' ';
            s += line;
        }
    }
    else cout << "Error opening file";
    text.close();
    */
    output(str);
}