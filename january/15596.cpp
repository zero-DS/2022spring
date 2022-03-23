#include <bits/stdc++.h>
using namespace std;
long long sum(std::vector<int> &a){
    long long result=0;
    vector<int>::iterator i;
    for(i=a.begin();i!=a.end();i++){
        result+=*i;
    }
    return result;
};
