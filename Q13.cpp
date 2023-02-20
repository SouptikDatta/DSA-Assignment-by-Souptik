//C++ program to implement 2 stacks in a single array

#include<iostream>
using namespace std;

class twostacks{
		int *arr;
		int top1;
		int top2;
		int size;
	public:
          twostacks(int n){
	        this -> size = n;
	        top1 = -1;
	        top2 = size;
	        arr = new int[n];
}
void push1(int element){
	if(top2 - top1 > 1){
		top1++;
		arr[top1] = element;
	}
	
}
	void push2(int element){
		if(top2 - top1 > 1){
			top2--;
			arr[top2] = element;
		}
	
	}
int pop1(){
	if (top1 >= 0){
		int pop_ele1 = arr[top1];
		top1--;
		return pop_ele1;
	}
	else{
		return -1;
	}
}
int pop2(){
	if(top2 < size){
		int pop_ele2 = arr[top2];
		top2--;
		return pop_ele2;
	}
}
};
int main(){
	twostacks st(10);
	st.push1(25);
	st.push1(46);
	st.push1(79);
	st.push1(17);
	
	st.push2(19);
	st.push2(7);
	st.push2(13);
	
	cout << "Popped element from stack 1 is " << st.pop1() << endl;
	cout << "Popped element from stack 1 is " << st.pop1() << endl;
	
	cout << "Popped element from stack 2 is " << st.pop2() << endl;

	return 0;
}