#include <bits/stdc++.h>
using namespace std;
class test{
    private:
    int num;

    public:
    test(){
        num=0;
    }
    test(int n){
        num=n;
    }
    void setData(int n){
        num=n;
    }
    void show(){
        cout<<num<<'\n';
    }
};
int main(){
    test A(5);
    A.show();
    test B=A;
    A.setData(10);
    A.show();
    B.show();
    return 0;
}