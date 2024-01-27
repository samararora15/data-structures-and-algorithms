#include<bits/stdc++.h>
using namespace std;
int calPoints(vector<string> &v){
    if(v.size()==0)
        return 0;
        stack<int> s;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int k=a+b;
                s.push(b);
                s.push(a);
                s.push(k);
            }
            else if(v[i]=="D"){
                int k=2*s.top();
                s.push(k);
            }
            else if(v[i]=="C"){
                s.pop();
            }
            else{
                s.push(stoi(v[i]));
            }
        }
        while(!s.empty()){
            ans=ans+s.top();
            s.pop();
        }
    return ans;
}
int maxDepth(string s){
    //although it can also be solved using stack but will be overkill
    if(s.empty())   return 0;
    int i=0,c=0,ans=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(')
        c++;
        if(s[i]==')')
        c--;
        if(c>ans)
        ans=c;
    }
    return ans;
}
int main(){
    // string s="(1+(2*3)+((8)/4))+1";
    // cout<<maxDepth(s);
    vector<string> v = {"5","2","C","D","+"};
    cout<<calPoints(v);
    return 0;
}