//queue(FIFO - First In First Out)
//insertion and deletion from oppposite end
//implementation using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
void ensert(int n)
{
    struct node *cur;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = n;
    cur->next = NULL;
    if(f==NULL)
    {
        f = r = cur;
    }
    else
    {
        r->next = cur;
        r = cur;
    }
}
void del()
{
    if(f==NULL)
    {
        printf("queue is empty");
    }
    else
    {
        struct node *p;
        p = f;
        f = f->next;
        free(p);
        p = NULL;  
    }
}
void print()
{
    printf("ELEMENTS OF QUEUE ARE:\n");
    while(f!=NULL)
    {
        printf("%d\n",f->data);
        f = f->next;
    }
}
int main()
{
    ensert(10);
    ensert(20);
    del();
    ensert(30);
    ensert(40);
    del();
    ensert(50);
    print();
    ensert(60);
    print();
    return 0;
}