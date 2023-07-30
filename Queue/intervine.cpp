#include <bits/stdc++.h>
using namespace std;
queue<int> fun(queue<int>& q){
    int si=q.size();
    queue<int> q1,q2;
    for(int i=0;i<si/2;i++){
        q1.push(q.front());
        q.pop();
    }
    for(int i=0;i<si/2;i++){
        q2.push(q1.front());
        q1.pop();
        q2.push(q.front());
        q.pop();
    }
    if(si&1){
        q2.push(q.front());
        q.pop();
    }
    return q2;
}
int main(){
    queue<int> q,ans;
    q.push(12);
    q.push(121);
    q.push(122);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(155);
    q.push(16);
    q.push(17);
    ans=fun(q);
    while(!ans.empty()){
        cout<<ans.front()<<endl;
        ans.pop();
    }
    return 0;
}