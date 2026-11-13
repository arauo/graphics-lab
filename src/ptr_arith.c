#include <stdio.h>
int main(void){
    int     a[5] = {10, 20, 30, 40, 50};
    int    *pi   = a;
    char    cs[] = "hello";
    char   *pc   = cs;
    double  d[3] = {1.5, 2.5, 3.5};
    double *pd   = d;
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(double) = %zu\n", sizeof(double));
    
    printf("pc+1-pc=%td\n",(char*)(pc+1)-(char*)pc);
    printf("pi+1-pi=%td\n",(char*)(pi+1)-(char*)pi);
    printf("pd+1-pd=%td\n",(char*)(pd+1)-(char*)pd);
    
    printf("sizeof(int*) = %zu\n", sizeof(int*));
    printf("sizeof(char*) = %zu\n", sizeof(char*));
    printf("sizeof(double*) = %zu\n", sizeof(double*));
    
    printf("sizeof(a)=%zu\n",sizeof(a));
    printf("sizeof(pi)=%zu\n",sizeof(pi));
    printf("a=%p\n",a);
    printf("&a[0]=%p\n",&a[0]);
    printf("a+1=%p\n",a+1);
    printf("&a[1]=%p\n",&a[1]);
}