#include "bits/stdc++.h"
using namespace std;

class Queue{
    public:
    int front;
    int rear;
    int size;
    int *arr;
    Queue(int size){
        this->size=size;
        arr = new int[size];
        this->front=0;
        this->rear=0;
    }
    
    void push(int n){  
        if(rear==size){
            cout<<"Queue overflow"<<endl;return;
        }
        arr[rear]=n;
        rear++;
    }
    void pop(){
        if(front<rear){
            front++;
            if(front==rear){
            front=0;
            rear=0;
        }
        }
        
        else{
            cout<<"Queue underflow"<<endl;
        }
    }
    int top(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;return -1;
        }
        return arr[front];
    }
    bool isempty(){
        return (front==rear?true:false);
    }
    int getsize(){
        return rear-front;
    }

};
int main(){
    Queue q(5);
    cout<<q.isempty()<<endl;
    q.push(5);
    q.pop();
    q.push(15);
    q.push(51);
    cout<<q.top()<<endl;
    q.push(31);
    q.push(5);
    q.push(52);
    q.pop();
    cout<<q.getsize()<<endl;
    cout<<q.isempty()<<endl;


    return 0;
}