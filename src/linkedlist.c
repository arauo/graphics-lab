#include <stdio.h>
#include <stdlib.h>
struct node {
    int  id;
    char name[20];
    struct node *next;  
};
char * my_strcpy(const char *string,char *cpy){
    char *ret=cpy;
    while((*cpy++=*string++))
        ;
    return ret;     
}


struct node *create_node(int id,const char *name){
   struct node *a=malloc(sizeof(struct node));
   if(!a)return NULL;
   a->id=id;
   my_strcpy(name,a->name);
   a->next=NULL;
   return a;
}
void print_list(const struct node *head){
    const struct node *p=head;
    while(p){
        printf("id=%d\tname=%s\n",p->id,p->name);
        p=p->next;
    }
    printf("the end\n");
}
/*struct node *push_front(struct node *head,int id,const char *name){  头插
    struct node *q=create_node(id, name);
    if (q == NULL) return head; 
    q->next=head;
    return q;
}*/
struct node *push_back(struct node *head, int id, const char *name){  //尾插
    struct node *q=create_node(id,name);
    if(!q)
        return head;
    if (!head)
        return q;    
    struct node *p=head;
    while(p->next)
        p=p->next;
    p->next=q;
    return head;
}
struct node *find(struct node *head, int id){
    struct node *t=head;
    while(t!=NULL&&t->id!=id){
        t=t->next;  
    }
    if(!t)
        return NULL; 
    else
        return t;
}
struct node *remove_node(struct node *head, int id){
    struct node *cur=head,*prev=NULL;
    while (cur != NULL && cur->id != id) {
        prev=cur;
        cur=cur->next;
       
    }
    if (cur == NULL) return head; 
    if (prev == NULL)
        head=cur->next;
    else
        prev->next = cur->next;
    free(cur);
    return head;

}

struct node *reverse(struct node *head){
    struct node *p = head, *q = NULL, *j;
    while (p){            
        j = p->next;     
        p->next = q;   
        q = p;             
        p = j;            
    }
    return q;          
}
struct node *middle(struct node *head){
    struct node *p=head,*q=head;
    while(p&&p->next){
        p=p->next->next;
        q=q->next;
    }
    return q;
}
int has_cycle(struct node *head){
    struct node *p=head,*q=head;
    while(p&&p->next){
        p=p->next->next;
        q=q->next;
        if(q==p)return 1;
    }
    return 0;
}



void free_list(struct node *head){
    struct node *p=head;
    while(p){
        struct node *next=p->next;
        free(p);
        p=next;
    }
}
int main(void) {
    struct node *head = NULL;               

    /*head = push_front(head, 1, "Alice");
    head = push_front(head, 2, "Bob");
    head = push_front(head, 3, "Cindy");*/

    head = push_back(head, 1, "Alice");
    head = push_back(head, 2, "Bob");
    head = push_back(head, 3, "Cindy");

    head = remove_node(head, 2);
    print_list(head);

    head = reverse(head);
    print_list(head);

    free_list(head);
    return 0;
}