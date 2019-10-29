#include <iostream>

using namespace std;

class TwoWayStack{
private:
	int top1;
	int top2;
	int * a;
	int size;

public:
	TwoWayStack(int c){
		size = c;
		a = new int[size];
		top1 = -1;
		top2 = size;
	}

void push1(int data);
void push2(int data);
void pop1();
void pop2();
int Top1();
int Top2();
};

void TwoWayStack::push1(int data){
	if(top1< top2 - 1){
		a[++top1] = data;
	}
	else{
		cout << "Stack 1 overflow\n";
	}
}

int TwoWayStack::Top1(){
	cout << "Top of stack 1 is:" << a[top1];
}

int TwoWayStack::Top2(){
	cout << "Top of stack 2 is:" << a[top2];
}
void TwoWayStack::push2(int data){
	if(top2 > top1 + 1){
		a[--top2] = data;
	}
	else{
		cout << "stack 2 overflow\n";
	}
}

void TwoWayStack::pop1(){
	cout << "Top of Stack1 is:" << a[top1]<< "\n";
	top1 = top1 - 1;
}
void TwoWayStack::pop2(){
	cout << "Top of Stack2 is:" << a[top2]<< "\n";
	top2 = top2 + 1;
}
int main(){
TwoWayStack t(10);
t.push1(2);
t.push2(1);
t.push2(11);
t.push2(8);
t.push1(267);
t.push1(111);
t.push2(78);
t.push1(4);
t.push2(44);
t.push1(8967);
t.push2(24232);
t.push2(19);
t.Top1();
t.Top2();
}