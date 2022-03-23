#include <stdio.h>
#include <stdlib.h>
void swap(int*,int*);
int main(void){
    double f=2.5;
    printf("%lf, %g",f,f);
    int* a=(int*)malloc(sizeof(int));
    printf("\n%d",*a);

}
void swap(int* a, int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
