//object oriented programming
//class is a user defined data type
//object is an instance say of a class
//by default data members are private
//you can access private data members only inside class and using function inside class from outside
//to intialize value of data members constructor is used
//destructors are used to destroy the objects of a class
//lets create a class of 5 students
#include<bits/stdc++.h>
using namespace std;
class student{
    public:
    string name;
    int age;
    bool gender;

    student(student &s) //copy constructor
    {
        name = s.name;
        age = s.age;
        gender = s.gender;
    }

    student()   //default constructor
    {
        cout<<"Default Constructor";
    }

    student(string s,int a,bool g)  //parameterized constructor
    {
        name = s;
        age = a;
        gender = g;
    }

    void printinfo()
    {
        cout<<"NAME = "<<name<<" "<<"AGE = "<<age<<" "<<"GENDER = "<<gender<<endl;
    }

    ~student()
    {
        cout<<"Destructor Called"<<endl;
    }

    bool operator == (student &k)   //operator overloading
    {
        if(name==k.name && age==k.age && gender==k.gender)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    /*int size;
    cout<<"Enter size of class:";
    cin>>size;
    student s[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter Name:";
        cin>>s[i].name;
        cout<<"Enter Age:";
        cin>>s[i].age;
        cout<<"Enter Gender:";
        cin>>s[i].gender;
    }

    for(int i=0;i<size;i++)
    {
        s[i].printinfo();
    }*/

    student s("samar",20,0);
    s.printinfo();
    student k("aryan",19,0);
    cout<<endl;
    student p = s;
    p.printinfo();
    if(s==k)
    {
        cout<<"SAME";
    }
    else
    {
        cout<<"NOT SAME";
    }
    cout<<endl;
    return 0;
}