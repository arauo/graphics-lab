#include <stdio.h>

void swap_wrong1(int a,int b) {
    printf("  [函数内] 进来时: a=%d b=%d\n", a, b);
    int tmp=a;
    a=b;
    b=tmp;
    printf("  [函数内] 交换后: a=%d b=%d\n", a, b);
}
void swap_wrong2(int *a,int *b){
     printf("  [函数内] 交换前: a=%p b=%p\n", (void*)a, (void*)b);
    int *tmp=a;
    a=b;
    b=tmp;
     printf("  [函数内] 交换后: a=%p b=%p\n", (void*)a, (void*)b);
}
/*void swap_wrong3(int *a,int *b){ gcc16.2.0中指针转换为整数隐式是错误不是警告，无法通过编译
    int tmp=a;
    a=b;
    b=tmp;
}*/
void swap_wrong3(int *a,int *b){
    int *tmp=a;
    *tmp=*b;
    *b=*a;
}
void swap_ok(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(void) {
    int x = 1, y = 2;

    printf("--- wrong1: 值传递 ---\n");
    printf("before: x=%d y=%d\n", x, y);
    swap_wrong1(x, y);
    printf("after : x=%d y=%d\n\n", x, y);

    printf("--- wrong2: 只换指针副本 ---\n");
    printf("before: x=%d y=%d\n", x, y);
    swap_wrong2(&x, &y);
    printf("after : x=%d y=%d\n\n", x, y);
    printf("  [main]   x=%p y=%p\n", (void*)&x, (void*)&y);   

    printf("--- wrong3: 把地址当 int ---\n");
    printf("before: x=%d y=%d\n", x, y);
    swap_wrong3(&x, &y);
    printf("after : x=%d y=%d\n\n", x, y);
    x=1,y=2;

    printf("--- ok: 解引用 ----------\n");
    printf("before: x=%d y=%d\n", x, y);
    swap_ok(&x, &y);
    printf("after : x=%d y=%d\n", x, y);

    return 0;
}