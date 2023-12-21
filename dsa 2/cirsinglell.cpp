#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
int main()
{
    int n;
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *cur = NULL;
    //implementation
    do{
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter Data:";
    cin>>cur->data;
    cur->next = head;
        if(head==NULL)
        {
            head = temp = cur;
            cur->next = cur;
        }
        else
        {
            temp->next = cur;
            temp = temp->next;
        }
        cout<<"Do You Want to Add Another Node:";
        cin>>n;
    }while(n>0);
    //traversal
    temp = head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    //insertion at beginning
    temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter Data:";
    cin>>cur->data;
    cur->next = head;
    temp->next = cur;
    head = cur;
    //traversal
    temp = head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    //insertion at end
    temp = head;
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter Data:";
    cin>>cur->data;
    temp->next = cur;
    cur->next = head;
    //traversal
    temp = head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<endl;
    return 0;
}