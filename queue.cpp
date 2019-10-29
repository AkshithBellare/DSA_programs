#include <iostream>
using namespace std;

class Queue{
private:
	int front;
	int rear;
	int * a;
	int size;
public:
	Queue(int n){
		front = rear = -1;
		size = n;
		a = new int[size];
	}

	void Enqueue(int);
	void Dequeue();
	int Front();
	int Rear();
	void Print();
	bool isEmpty();
	bool isFull();
};

bool Queue::isEmpty(){
	if(front == -1 && rear == -1){
		return true;
	}
	else return false;
}

bool Queue::isFull(){
	if(rear == size - 1){
		return true;
	}
	else return false;
}

void Queue::Enqueue(int n){
if(isEmpty()){
	front = 0;
	a[++rear] = n;
	cout <<"Enqueue done!\n";
	return; 
}
else if(isFull()){
	cout << "Queue is full!";
	return;
}
a[++rear] = n;
cout <<"Enqueue done!\n";
}

void Queue::Dequeue(){
//if empty not possible
	if(isEmpty()){
		cout << "Queue already empty!";
	}
	else front = front + 1;
	cout << "Dequeue done!\n";
}

int Queue::Front(){
	cout << "Front:";
	cout<< a[front]<<"\n";
}

int Queue::Rear(){
	cout <<"Rear:";
	cout<< a[rear]<<"\n";
}

void Queue::Print(){
	cout << "Printing queue...";
	for(int i = front;i<=rear;i++){
		cout << a[i] <<" ";
	}
	cout << "\n";
}
int main(){
	Queue queue(20);
	int opt,value;
	cout << "INPUT\n\t1 for enqueue\n\t2 for dequeue\n\t3 for top value\n\t4 for rear value\n\t5 to print\n\t6 to exit\n";
	while(cin){
		cin >> opt;
		switch(opt){
			case 1:{
				cout << "Enter value:";
				cin >> value;
				queue.Enqueue(value);
				break;
			}
			case 2:{
				queue.Dequeue();
				break;

			}
			case 3:{
				queue.Front();
				break;
			}
			case 4:{
				queue.Rear();
				break;
			}
			case 5:{
				queue.Print();
				break;
			}
			case 6:{
				exit(-1);
				cout << "Exiting...";
			}

		}
	}

}

