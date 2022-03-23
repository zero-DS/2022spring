#include <bits/stdc++.h>
using namespace std;
class Unit{
    int x,y;
    public:
        Unit *p;
        Unit(int a, int b, Unit *u){
            x=a;
            y=b;
            p=u;  
        }
        void Print(){
            //if(p!=NULL)p->Print(); //execution #3
            cout<<x<<','<<y<<endl;  
            //if(p!=NULL)p->Print(); //execution #2
        }
};
class St{
    public:
        int grade;
        St(int g){
            this->grade=g;
        }
};
void swap1(int &a, int &b){
    int t;
    t=a;
    a=b;
    b=t;
};
void swap2(int *a, int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
};
int main(void){
    Unit c(5,6,NULL);
    Unit b(3,4,&c);
    Unit a(1,2,&b);

    cout<<"[Print a]"<<endl;a.Print();
    cout<<"[Print b]"<<endl;b.Print();
    cout<<"[Print c]"<<endl;c.Print();

    int *pInteger=NULL;
    pInteger=new int;
    if(!pInteger)cout<<"allocation error"<<endl;
    *pInteger=777;
    cout<<endl<<"pInteger : "<<*pInteger<<endl<<endl;
    delete pInteger;

    Unit *uArr=new Unit[2]{Unit(1,2,NULL),Unit(3,4,NULL)};
    for(int i=0;i<2;i++){
        uArr->Print();
        uArr++;
    }
    delete[] uArr;

    int l=5,m=6;
    swap1(l,m);
    cout<<endl<<l<<','<<m<<endl;
    swap2(&l,&m);
    cout<<l<<','<<m<<endl<<endl;

    St s[10]={St(90),St(88),St(85),St(55),St(47),St(92),St(87),St(30),St(89),St(65)};
    int maxGradeIndex;
    for(int i=0;i<10;i++){
        if(i==0)maxGradeIndex=0;
        else{
            if(s[maxGradeIndex].grade<s[i].grade)maxGradeIndex=i;
        }
    }
    cout<<"Best grade = "<<s[maxGradeIndex].grade<<'\n';
    cout<<"StudentID = "<<maxGradeIndex+1<<'\n'<<endl;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(s[i].grade>s[j].grade){
                swap(s[i],s[j]);
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<s[i].grade<<' ';
    }
    return 0;
}