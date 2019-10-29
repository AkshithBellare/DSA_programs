#include <iostream>
#include <vector>
using namespace std;

class BinaryHeap{
private:
	int *heap;
	int capacity;
	int heap_size;
	void heapify(int index);
	 int leftchild(int index);
	 int rightchild(int index);
	 int parent(int index);
public:
	BinaryHeap(int cap){
		heap_size = 0;
		capacity = cap;
		heap = new int[cap];
	}
	void insert(int data);
	int maximum();
	void extract_max();
};

int BinaryHeap::leftchild(int index){
	return 2 * index + 1;
}

int BinaryHeap::rightchild(int index){
	return 2 * index + 2;
}

int BinaryHeap::parent(int index){
	return (index - 1)/2;
}

void BinaryHeap::insert(int data){
	if(heap_size == capacity){
		cout << "No more elements can be inserted\n";
		return;
	}
	heap[heap_size] = data;
	heap_size++;

}

int BinaryHeap::maximum(){
	return heap[0];
}

void BinaryHeap::heapify(int index){
	if(index >=0 && parent(index)>=0 && heap[parent(index)] < heap[index]){
		int temp;
		temp = heap[parent(index)];
		heap[parent(index)] = heap[index];
		heap[index] = temp;
		heapify(parent(index));
	}
}

void BinaryHeap::extract_max(){
	int last_element = heap[heap_size - 1];
	cout << heap_size << "\n";
	heap[0] = last_element;
	heap_size--;
	heapify(heap_size - 1);
}
int main(){
	BinaryHeap binaryHeap(7);
	binaryHeap.insert(2);
	binaryHeap.insert(8);
	binaryHeap.insert(3);
	binaryHeap.insert(11);
	binaryHeap.insert(9);
	binaryHeap.insert(1123);
	cout << binaryHeap.maximum() << "\n";

}