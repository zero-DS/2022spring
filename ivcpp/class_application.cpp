#include <bits/stdc++.h>
using namespace std;
class Unit {
    char* str;
    public:
        Unit() {
            str=NULL;
        }
        Unit(char* agStr) {
            str = new char[strlen(agStr) + 1];
            strcpy(str, agStr);
        }
        Unit(Unit &agStr){//복사 생성자 <- 얘가 없다면 얕은 복사를 한다.
            cout<<"copy constructor\n";
            //this->str=agStr.str; //얕은 복사

            this->str=new char[strlen(agStr.str)+1];
            strcpy(this->str,agStr.str);//깊은 복사
        }
        void set(char* agStr) {
            strcpy(str, agStr);
        }
        void show(){
            cout<<str<<"\n";
        }
        void copyFrom(Unit &agStr){
            //this->str=agStr.str;
            this->str=new char[strlen(agStr.str)+1];
            strcpy(this->str,agStr.str);
        }
        void copyTo(Unit &agStr){
            //agStr.str=this->str;
            agStr.str=new char[strlen(this->str)+1];
            strcpy(agStr.str,this->str);
        }
};
class Square{
    private:
    int h,w;
    public:
    Square(int x,int y){
        h=x;
        w=y;
    }
    friend void addSquare(Square, Square);
    void substractSquare(Square);
};
void addSquare(Square one,Square two){
    cout<<"Sum of Areas : "<<one.h*one.w+two.h*two.w<<'\n';
}
void Square::substractSquare(Square one){
    cout<<"Substraction of Areas : "<<one.h*one.w-this->h*this->w<<'\n';
}
int main(){
    Unit A("TEST1");
    Unit B=A;
    A.set("TEST2");
    A.show();
    B.show();
    cout<<endl;
    Unit C("Unit C"),D("Unit D"),E("Unit E");
    C.show();D.show();E.show();
    cout<<endl;
    C.copyFrom(D);E.copyTo(D);
    C.show();D.show();E.show();
    cout<<endl;
    D.set("Unit D");
    C.show();D.show();E.show();
    cout<<endl;

    Square s1(5,3),s2(4,4);//15,16
    addSquare(s1,s2);
    s1.substractSquare(s2);
    return 0;
}