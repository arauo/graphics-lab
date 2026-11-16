#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct point{double x,y;};
struct line{struct point a,b;};
double line_length(const struct line *l){
    double dx=l->b.x-l->a.x;
    double dy=l->b.y-l->a.y;
    return sqrt(dx*dx+dy*dy);
};
struct point midpoint(const struct line *l){
    struct point m;
    m.x=(l->a.x+l->b.x)/2;
    m.y=(l->a.y+l->b.y)/2;
    return m;
};
int main(void) {
    struct line l = { {0,0}, {3,4} };
    printf("length = %.2f\n", line_length(&l));
    struct point m = midpoint(&l);
    printf("mid = (%.1f, %.1f)\n", m.x, m.y);
    printf("sizeof(point) = %zu\n", sizeof(struct point));
    printf("sizeof(line)  = %zu\n", sizeof(struct line));
    int n = 5;
    struct point *pts = malloc(n * sizeof(struct point));
    if (pts == NULL) return 1;
    for (int i = 0; i < n; i++) { pts[i].x = i; pts[i].y = i*2; }
    printf("pts = %p\n", (void*)pts);
    free(pts);
    pts = NULL;
    return 0;
}