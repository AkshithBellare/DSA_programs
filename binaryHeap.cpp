#include <iostream>
#include <list>
class BinaryHeap{
private:
		int* heap;
public:
		BinaryHeap(int n){
			heap = new int[n];
		}
		void insert(int data);
		void heapify();
}

void BinaryHeap::insert(int data,int index){
	heap[index] = data;	
	heapify(index);
}

void BinaryHeap::heapify(){
	int size = heap.size();

}
int main(){
	int op;
	int value;
	int count = 0;
	BinaryHeap binaryHeap(1000);
	cout << "1)Enter 1 for insert\n2)Enter 2 for maximum\n3)Enter 3 for extract_max\n4)Enter 4 to exit\n"
		do{
		switch(op){
		   case 1:
		    {cout << "Enter value to be inserted:";
			cin >> value;
			binaryHeap.insert(value,count);
			count++;
		}
		}
		}while(op!=9)
}