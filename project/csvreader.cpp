#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <istream>

using namespace std;
vector<string> csv_read_row(istream&, char);
int main(){
    ifstream file("/Users/sdsmba/PS/project/cocktaildata.csv");
    if(file.fail())cout<<"error";
    while(file.good()){
        vector<string> row = csv_read_row(file, ',');
        if(!row[0].find("#")) continue; //만약 csv 파일 안에 # 문자가 있을경우 건너뛰어라
        else {
            for(int i=0, leng=row.size(); i<leng; i++) cout << "[" << row[i] << "]" << "\t"; //알맞게 출력
        }
        cout << endl;
    }
    file.close();
    return 0;
}
vector<string> csv_read_row(istream &file, char delimiter){
    stringstream ss;
    vector<string> row;
    while(file.good()){
        char c = file.get();
        if(c=='"'){
            if(file.peek()=='"')ss<<(char)file.get();
        }
        else if (c==delimiter){
            row.push_back(ss.str());
            ss.str(""); //구분자 만날 때마다 초기화
        }
        else if(c=='\r' || c=='\n'){
            if(file.peek()=='\n')file.get();
            row.push_back(ss.str());
            return row;
        }
        else ss<<c;
    }
    row.push_back(ss.str());
    int lastrowlength = row[row.size()-1].length();
    row[row.size()-1][lastrowlength-1]='\0';
    return row;
};