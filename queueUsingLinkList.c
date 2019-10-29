#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node * next;  
};

struct Node * front = NULL;
struct Node * rear = NULL;

void Enqueue(int x){
	printf("Enqueuing..\n");
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
	    rear = temp;
	}
}
void Dequeue(){
	printf("Dequeuing..\n");
	if(front == NULL && rear == NULL){
		printf("Queue empty!");
	}
	else {
		struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
		temp = front;
		front = front -> next;
		free(temp);
	}
}
void Front(){
	printf("Front is:%d\n",front->data);  
}
void Rear(){
	printf("Rear is:%d\n",rear->data);
}
int main(){
	printf("1)Enter 1 for enqueuing\n2)Enter 2 for Dequeuing\n3)Enter 3 for front\n4)Enter 4 for rear\n5)Enter 5 to exit\n");
	int ch;
	int value;
	do{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: {
						printf("Enter value:");
						scanf("%d",&value);
						Enqueue(value);
						break;
			}
			case 2:{
						Dequeue();
						break;
			}
			case 3:{
						Front();
						break;
			}
			case 4: {
						Rear();
						break;
			}
		}
	}while(ch!=5);
}
