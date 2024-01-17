#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=NULL;
    struct node *cur,*temp,*k,*p;
    bool val = 1;
    //implementation of singly linked list
    while(val) {
        cur = (struct node*)malloc(sizeof(struct node));
        cin>>cur->data;
        cur->next=NULL;
        if(head==NULL) {
            head = temp = cur;
        }
        else {
            temp->next = cur;
            temp = temp->next;
        }
        cin>>val;
    }
    //display
    // while(head!=NULL) {
    //     cout<<head->data<<" ";
    //     head = head->next;
    // }

    cout<<endl;
    //insertion of node at beginning
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"enter beginning node:";
    cin>>temp->data;
    temp->next = head;
    head = temp;
    k = head;
    p = head;
    //display
    // while(head!=NULL) {
    //     cout<<head->data<<" ";
    //     head = head->next;
    // }

    cout<<endl;
    //insertion of node at end
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"ente ending node:";
    cin>>temp->data;
    temp->next = NULL;
    while(k->next!=NULL) {
        k = k->next;
    }
    k->next = temp;
    k = head;
    // while(head!=NULL) {
    //     cout<<head->data<<" ";
    //     head = head->next;
    // }

    cout<<endl;
    //insertion of node at middle
    // int c=0;
    // while(k!=NULL) {
    //     c++;
    //     k=k->next;
    // }
    // c=c/2;
    // temp = (struct node*)malloc(sizeof(struct node));
    // cout<<"ente middle node:";
    // cin>>temp->data;
    // while(c>0) {
    //     p = p->next;
    //     c--;
    // }
    // struct node *q;
    // q=p;
    // temp->next = p->next;
    // q->next = temp;
    while(k!=NULL) {
        cout<<k->data<<" ";
        k = k->next;
    }
    k = head;

    cout<<endl;
    //deletion of node from beginning
    head=head->next;
    //deletion of node from end
    while(k->next->next!=NULL) {
        k = k->next;
    }
    k->next = NULL;
    k = head;
    while(k!=NULL) {
        cout<<k->data<<" ";
        k=k->next;
    }
    return 0;
}