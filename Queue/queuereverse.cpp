#include <iostream>
#include<queue>
using namespace std;
void reverse(queue<int>& q){
    if(!q.empty()){
        int a=q.front();
        q.pop();
        reverse(q);
        q.push(a);
    }
}
int main() {
  //creation
 queue<int> q;
 q.push(15);
 q.push(14);
 q.push(13);
 q.push(12);
 q.push(11);
 q.push(10);
 reverse(q);
 while(!q.empty()){
    cout<<q.front()<<endl;q.pop();
 }
  return 0;
}