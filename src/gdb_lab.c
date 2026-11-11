#include <stdio.h>

void add_one(int n) {
    n = n + 1;
    printf("  [in func] n = %d, &n = %p\n", n, (void*)&n);
}

void add_one_ptr(int *p) {
    *p = *p + 1;
    printf("  [in func] *p = %d, p = %p\n", *p, (void*)p);
}

int main(void) {
    int x = 10;
    int y = 10;

    printf("[main] x = %d, &x = %p\n", x, (void*)&x);
    add_one(x);
    printf("[main] after add_one: x = %d\n\n", x);

    printf("[main] y = %d, &y = %p\n", y, (void*)&y);
    add_one_ptr(&y);
    printf("[main] after add_one_ptr: y = %d\n", y);

    return 0;
}