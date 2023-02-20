//C++ Program to reverse the first K elements of Queue :

#include<bits/stdc++.h>
using namespace std;

 //Function to reverse the first K elements of Queue
void reverseFirstKelements(int k, queue<int>& q) {
    
    //Value of k should be positive
    if (k <= 0)     
        return;

    // If Queue is empty or value of k is bigger than size of queue then return  
    if (q.empty() ==true || k > q.size())  
        return;

    stack<int>  s;

    //Pushing first k elements into a stack
    for (int i = 0; i < k; i++) {    
        s.push(q.front());
        q.pop();
    }
    
    //Enqueue the elements at the back of the queue
    while (s.empty()==false) {
        q.push(s.top());
        s.pop();
    }

    //Remove the remaining elements and enqueue them at the end of the queue
    for (int i = 0 ; i < q.size() - k ; i++) {
        q.push(q.front());
        q.pop();
    }

}

//Function to print the queue
void Print(queue<int>& q) {
    while (q.empty()== false) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() 
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);

    int k = 4;
    reverseFirstKelements(k, q);

    //Printing Queue

    Print(q);

    return 0;
}