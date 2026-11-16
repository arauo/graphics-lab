#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void){
    
      int x = 1, y = 2, z = 3;
    int *a[3] = { &x, &y, &z };      
    int arr[3] = { 10, 20, 30 };
    int (*p)[3] = &arr;              

    printf("sizeof(a)  = %zu\n", sizeof(a));
    printf("sizeof(p)  = %zu\n", sizeof(p));
    printf("sizeof(*a) = %zu\n", sizeof(*a));
    printf("sizeof(*p) = %zu\n", sizeof(*p));

    printf("*a[1]      = %d\n", *a[1]);
    printf("(*p)[1]    = %d\n", (*p)[1]);

    (*p)[1] = 99;                    
    printf("arr[1]     = %d\n", arr[1]);

    int (*f)(int, int) = add;     
    printf("f(2,3)      = %d\n", f(2, 3));
    printf("sizeof(f)   = %zu\n", sizeof(f));
    printf("f == add ?  %d\n", f == add);

    int nums[] = { 3, 1, 4, 1, 5 };
    int n = sizeof(nums) / sizeof(nums[0]);
    qsort(nums, n, sizeof(int), cmp_int);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}