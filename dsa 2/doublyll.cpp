#include<bits/stdc++.h>
using namespace std;
struct node{
    struct node *prev;
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
        cout<<"ENTER DATA:";
        cin>>cur->data;
        if(head==NULL)
        {
            cur->prev = NULL;
            cur->next = NULL;
            head = temp = cur;
        }
        else
        {
            temp->next = cur;
            cur->prev = temp;
            cur->next = NULL;
            temp = temp->next;
        }
        cout<<"DO YOU WANT TO ADD ANOTHER NODE:";
        cin>>n;
    }while(n>0);
    //traversal
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    //insertion of node at beginning
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"ENTER DATA:";
    cin>>cur->data;
    cur->prev = NULL;
    cur->next = head;
    head = cur;
    //traversal
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    //insertion of node at end
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"ENTER DATA:";
    cin>>cur->data;
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = cur;
    cur->prev = temp;
    cur->next = NULL;
    //traversal
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return 0;
}