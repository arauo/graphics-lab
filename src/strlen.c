#include  <stdio.h>
int my_strlen(const char *s){
    int i=0;
    while(*s!='\0'){
        i++;
        s++;
    }
    return i;
}

char *my_strcpy(char *dst, const char *src) {
    char *ret=dst;
   for(;*src!=0;src++,dst++){
    *dst=*src;
   }
   *dst='\0';
   return ret;
}
int main(void){
    printf("%d\n",my_strlen("hello"));
    printf("%d\n", my_strlen(""));
    printf("%d\n", my_strlen("a b c"));


     char buf[32];
     my_strcpy(buf, "hello");
    printf("buf = %s\n", buf);
     my_strcpy(buf, "");
    printf("len = %d\n", my_strlen(buf));
    return 0;
}