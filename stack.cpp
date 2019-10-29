#include <iostream>
using namespace std;
class Stack{
	private:
		int top;
		int *a;
		int size;
	public:
		Stack(int n){
	    top = -1;
	    size = n;
	    a = new int[size];
		}

		void Push(int);
		void Pop();
		int Top();
		bool isEmpty();
		void print();
};

bool Stack::isEmpty(){
	if(top == -1){
		return true;
	}
	else return false;
}

void Stack::Push(int x){
if(top == size - 1){
	cout << "Stack overflow";
	return;
}
else a[++top] = x;
cout << "pushed\n";
}

void Stack::Pop(){
	if(isEmpty()){
		cout << "Stack underflow!";
		return;
	}
	else top--;
	cout << "Pop done!\n";
}

void Stack::print(){
	cout << "printing stack...";
	for(int i = 0;i <=top;i++){
		cout << a[i] << " ";
	}
	cout << "\n";
}
int Stack::Top(){
	return a[top];
}
int main(){
	Stack stack(20);
	int opt,value;
	cout << "Enter 1 for Push\n\t2 for Pop\n\t3 to print\n\t4 to exit\n";
	while(cin){
		cin >> opt;
		switch(opt){
			case 1: {
				cout << "Enter value:";
				cin >> value;
				stack.Push(value);
				break;
			}

			case 2: {
				stack.Pop();
				break;
			}
			case 3: {
				stack.print();
				break;
			}
			case 4: {
				cout << "Exiting...";
				exit(-1);
			}
			default: cout << "invalid";
					 break;
		}
	}
}
