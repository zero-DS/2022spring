#include <bits/stdc++.h>
using namespace std;

class Student{
    private:
      int year;
      int ID;
      int grade;
    public:
      int age;
      void setData(int y, int i, int g){
        year=y;
        ID=i;
        grade=g;
      }
      void showData(){
        cout<<"(Year: "<<year<<" ID: "<<ID<<" Grade: "<<grade<<")";
      }
};
class animal{
  public:
    int age;
    char sex;
    animal(){
      age=0;
      sex='m';
      cout<<"animal생성됨\n";
    }
    void animalInfo(int a, char s){
      age=a;
      sex=s;
    }
};
class people{
  private:
    int num;
  public:
    people(int n):num(n){}
    void printPeople(){
      cout<<"peopleNum: "<<num<<'\n';
    }
};
class Base{
  public:
    Base();
    ~Base();
};
Base::Base(){
  cout<<"base 생성"<<endl;
}
Base::~Base(){
  cout<<"base 소멸"<<endl;
}
class Derived:public Base{
  public:
    Derived();
    ~Derived();
};
Derived::Derived(){
  cout<<"derived 생성"<<endl;
}
Derived::~Derived(){
  cout<<"derived 소멸"<<endl;
}
int main(void) {
    Student s;
    s.setData(2017, 100100, 1);
    s.showData();
    s.age=15;
    cout<<'\n'<<s.age<<"\n\n";
    animal a;
    cout<<a.age<<" "<<a.sex<<'\n';
    a.animalInfo(5,'f');
    cout<<a.age<<" "<<a.sex<<"\n\n";
    people p(100);
    p.printPeople();
    cout<<'\n';
    Derived object;
}