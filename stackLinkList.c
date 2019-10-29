//implement stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};

struct Node * top = NULL;

void push(int data){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	if(top == NULL){
		top = temp;
	}
	else {
		temp -> next = top;
		top = temp;
	}
}

void pop(){
	if(top == NULL){
		printf("Stack empty!");
	}
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = top;
	top = top->next;
	free(temp);
}

void Top(){
printf("Top is: %d\n",top->data);
}

int main(){
	int opt,value;
	printf("Enter 1 for push,2 for pop,3 for top\n");
	while(1){
		scanf("%d",&opt);
		switch(opt){
			case 1: {
				  	printf("Enter value:");
				  	scanf("%d",&value);
				  	push(value);
				  	break;
		}
		   case 2:{
		   	pop();
		   	break;
		   }
		   case 3:{
		   	Top();
		   	break;
		   }
		   default: {printf("Invalid\n");}
	}
}
}
