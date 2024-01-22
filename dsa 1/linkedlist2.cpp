#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    struct node *next;
};
struct node *mergeTwoLists(struct node *list1, struct node *list2) {
    if(list1==nullptr)  return list2;
    if(list2==nullptr)  return list1;
    struct node *head=list2;
    if(list1->val<list2->val) {
        head=list1;
        list1=list1->next;
    }
    else{
        list2=list2->next;
    }
    struct node *cur=head;
    while(list1!=nullptr && list2!=nullptr) {
        if(list1->val<list2->val) {
            cur->next=list1;
            list1=list1->next;
        }
        else{
            cur->next=list2;
            list2=list2->next;
        }
        cur=cur->next;
    }
    while(list1!=nullptr){
        cur->next=list1;
        list1=list1->next;
        cur=cur->next;
    }
    while(list2!=nullptr){
        cur->next=list2;
        list2=list2->next;
        cur=cur->next;
    }
    return head;
}
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
struct node *reverseList(struct node *head) {
    if(head==nullptr || head->next==nullptr) {
        return head;
    }
    struct node *p=nullptr,*q=head,*r=head->next;
    while(r!=nullptr) {
        q->next = p;
        p = q;
        q = r;
        r=r->next;
    }
    q->next = p;
    head = q;
    return head;
}
struct node *middleNode(struct node *head) {
    struct node *p = head;
    int c=0;
    while(p!=nullptr) {
        c++;
        p=p->next;
    }
    c=c/2;
    while(c>0) {
        head=head->next;
        c--;
    }
    return head;
}
bool hasCycle(struct node *head) {
    if(head==nullptr || head->next==nullptr) {
        return false;
    }
    struct node *p,*q;
    p=head;
    q=head;
    while(q!=nullptr && q->next!=nullptr) {
        p=p->next;
        q=q->next->next;  
        if(p==q)
        return true;
    }
    return false;
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
    back=insertBack(head,3);
    back=insertBack(back,4);
    back=insertBack(back,5);
    back=insertBack(back,6);
    // struct node *list = removeElements(head,6);
    // printNode(head);
    // cout<<hasCycle(head);
    // struct node *middle=middleNode(head);
    reverseList(head);
    // head1=mergeTwoLists(head,head1);
    return 0;
}