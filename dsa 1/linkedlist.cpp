//linked list
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head, *temp,*cur,*p,*q,*r;

void reversell(struct node *p, struct node *q)
{
    if(q!=NULL)
    {
        reversell(q,q->next);
        q->next = p;
    }
    else
    {
        head = p;
    }
}

int main()
{
    //implementaion
    int choice = 1;
    while(choice)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        cout<<"enter value:";
        cin>>temp->data;
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            cur = temp;
        }
        else
        {
            cur->next = temp;
            cur = cur->next;
        }
        cin>>choice;
    }

    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //insertion of node at beginning
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"enter value:";
    cin>>temp->data;
    temp->next = head;
    head = temp;


    //display
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //insertion of node at end
    cur = head;
    while(cur->next!=NULL)
    {
        cur = cur->next;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"enter value:";
    cin>>temp->data;
    temp->next = NULL;
    cur->next = temp;

    //display
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //insertion of node at somewhere between
    cur = head;
    while(cur->data!=15)
    {
        p = cur;
        cur = cur->next;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    cout<<"enter value:";
    cin>>temp->data;
    p->next = temp;
    temp->next = cur;

    //display
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //deletion of node at beginning
    cur = head->next;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //deletion of node at end
    cur = head;
    while(cur->next->next!=NULL)
    {
        cur = cur->next;
    }
    cur->next = NULL;
    //display
    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }

    cout<<endl;
    //length of a singly linked list = nodes in a linked list
    int c2=0;
    cur = head;
    while(cur!=NULL)
    {
        c2++;
        cur = cur->next;
    }
    cout<<"length of linked list = "<<c2<<endl;

    //reverse a singly linked list  //iterative approach  
    /*r = NULL; 
    q = head;
    p = head->next;

    while(p!=NULL)
    {
        q->next = r;
        r = q;
        q = p;
        p = p->next;
    }
    q->next = r;
    head = q;

    cur = head;
    while(cur!=NULL)
    {
        cout<<cur->data<<" ";
        cur = cur->next;
    }*/

    reversell(NULL,head);   //recursive approach

    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    //middle of linked list

    cur = head;
    int c = 0;

    while(cur!=NULL)
    {
        c++;
        cur = cur->next;
    }
    
    int ans = -1;
    cur = head;
    for(int i=0;i<=c/2;i++)
    {
        ans = cur->data;
        cur = cur->next;
    }    
    cout<<"middle element = "<<ans;
    return 0;
}