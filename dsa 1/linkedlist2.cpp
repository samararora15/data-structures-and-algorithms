#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node *next;
};
struct node *removeElements(struct node *head, int val) {
    if(head==nullptr) {
            return head;
        }
        while(head!=nullptr && head->val==val) {
            head = head->next;
        }
        struct node *p=head;
        struct node *q=head;
        while(p!=nullptr) {
            if(p->val==val) {
                q->next=p->next;
                p=q->next;
            }
            else {
                q=p;
                p=p->next;
            }
        }
    return head;
}
struct node *insertFront(struct node *head, int val) {
    struct node *front = new node;
    front->val = val;
    front->next = head;
    head = front;
    return head;
}
struct node *insertBack(struct node *back, int val) {
    struct node *last = new node;
    last->val = val;
    last->next=nullptr;
    while(back->next!=nullptr) {
        back=back->next;
    }
    back->next=last;
    return last;
}
void printNode(struct node *head) {
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head=head->next;
    }
}
int main()
{
    struct node *head=nullptr,*back=nullptr,*start=nullptr;
    head=insertFront(head,2);
    head=insertFront(head,1);
    back=insertBack(head,6);
    back=insertBack(back,3);
    back=insertBack(back,4);
    back=insertBack(back,5);
    back=insertBack(back,6);
    struct node *list = removeElements(head,6);
    printNode(head);
    return 0;
}