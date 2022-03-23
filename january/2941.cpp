#include <bits/stdc++.h>
using namespace std;
int checkCA(char c, char c1, char c2);
int main(void){
    string word;
    cin>>word;
    int wsize=word.size();
    int cnt=0;
    if(wsize==1){
        cnt=1;
    }
    else{
        int i;
        for(i=0;i<wsize-2;i++){
            i+=checkCA(word[i],word[i+1],word[i+2]);
            cnt++;
        }
        if(i==wsize-2){
            if(checkCA(word[wsize-2],word[wsize-1],'\0')==1)cnt++;
            else cnt+=2;
        }
        else {
            if(!(word[wsize-1]=='='&&word[wsize-2]=='z'&&word[wsize-3]=='d')){
                if(wsize>3)cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
int checkCA(char c, char c1, char c2){
    if(c=='c' && (c1=='=' || c1=='-'))return 1;
    else if(c=='d' && c1=='-')return 1;
    else if(c=='d' && c1=='z' && c2=='=')return 2;
    else if((c=='l' || c=='n') && c1=='j')return 1;
    else if((c=='s' || c=='z') && c1=='=')return 1;
    else return 0;
}