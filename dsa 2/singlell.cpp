//revision 
//linked list - implementation,insertion and deletion
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
    struct node *cur= NULL;
    //implementation
    do{
        cur = (struct node*)malloc(sizeof(struct node));
        cin>>cur->data;
        cur->next = NULL;
        if(head==NULL)
        {
            head = temp = cur;
        }
        else
        {
            temp->next = cur;
            temp = temp->next;
        }
        cout<<"DO YOU WANT TO ADD ANOTHER NODE:";
        cin>>n;
    }while(n>0);
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //insertion of node at beginning
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"ENTER NODE:";
    cin>>cur->data;
    cur->next = head;
    head = cur;
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //insertion of node at end
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    cur = (struct node*)malloc(sizeof(struct node));
    cout<<"ENTER NODE:";
    cin>>cur->data;
    cur->next = NULL;
    temp->next = cur;
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //inserting a node at somewhere middle
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data==20)
        {
            cur = (struct node*)malloc(sizeof(struct node));
            cout<<"ENTER NODE:";
            cin>>cur->data;
            cur->next = temp->next;
            temp->next = cur;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //deletion of node from beginning
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //deletion of node from end
    temp = head;
    while(temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    struct node *dq,*eq;
    dq = temp->next;
    temp->next = NULL;
    free(dq);
    dq = NULL;
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    //deletion of node somewhere in middle
    temp = head;
    while(temp->data!=25)
    {
        dq = temp;
        eq = temp->next;
        temp = temp->next;
    }
    dq->next = eq->next;
    free(temp);
    temp = NULL;
    //traversal
    temp = head;
    cout<<"NODES CREATED ARE:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    return 0;
}