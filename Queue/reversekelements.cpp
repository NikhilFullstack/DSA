#include<bits/stdc++.h>
#include<queue>
using namespace std;
void reversek(queue<int>& q,int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        q.push(st.top());
        st.pop();
    }
    for(int i=n;i<q.size();i++)
    {
        int a=q.front();
        q.pop();
        q.push(a);
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(19);
    q.push(18);
    q.push(17);
    q.push(16);
    reversek(q,5);
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
}