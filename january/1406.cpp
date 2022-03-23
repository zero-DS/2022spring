#include <bits/stdc++.h>
using namespace std;
list<char> List;
list<char>::iterator iter=List.end();
string s;
void Lfunc();
void Dfunc();
void Bfunc();
void Pfunc(char c);
int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin>>s;
    for(char c : s){
        List.push_back(c);
    }
    int M;
    char temp,temp1;
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>temp;
        if(temp=='P'){
            cin>>temp1;
            Pfunc(temp1);
        }
        else{
            if(temp=='L')Lfunc();
            else if(temp=='D')Dfunc();
            else if(temp=='B')Bfunc();
        }
    }
    for(char c : List){
        cout<<c;
    }
    cout<<'\n';
    return 0;
}
void Lfunc(){
    if(iter!=List.begin())iter--;
}
void Dfunc(){
    if(iter!=List.end())iter++;
}
void Bfunc(){
    list<char>::iterator temp;
    if(iter!=List.begin()){
        temp=iter;
        List.erase(--temp);
    }
}
void Pfunc(char c){
    List.insert(iter,c);
}