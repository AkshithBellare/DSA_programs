//In a binary search tree the left subtree always has elements that are less than the root node and the right subtree has all elements 
//greater than the rootnode

#include <iostream>
#include <queue>
using namespace std;
struct BstNode{			//defining what our node will look like
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNode(int data){		//this function uses new operator to create a node from heap and returns the address of the node
	BstNode* nnode = new BstNode();
	nnode->data = data;
	nnode->left = NULL;
	nnode->right = NULL;
	return nnode;
}

BstNode* insert(BstNode* rootref,int data){	
	BstNode* newNode = getNode(data);
if(rootref == NULL){	//the very first node being created
	rootref= newNode;
	return rootref;//this will update the root node
}
else if(rootref->data <= data){
	rootref->right = insert(rootref->right,data);//using recursion to search for the element
}
else {
	rootref->left = insert(rootref->left,data);
}
return rootref; //this updates the root node if the node is not the first node of the binary search tree
}


BstNode* search(BstNode* rootref,int data){	
if(rootref==NULL){ //this condition becomes true only if the given key is not present in the binary search tree
	cout << "key not found!\n";
	return rootref;
}
if(rootref->data == data){
	cout << "key found!\n";
	return rootref;
}
else if(rootref->data >=data){
	return search(rootref->left,data);
}
else return search(rootref->right,data);
}

void levelOrderTraversal(BstNode* rootref){ //This function is for level order traversal of the binary search tree. It prints the elements in the logically breadthwise way.
	if(rootref==NULL){
	return;
	}
	queue<BstNode*> Q;
	Q.push(rootref);
	while(!Q.empty()){
	BstNode* current = Q.front();
	cout << current->data <<" ";
	if(current->left!=NULL){Q.push(current->left);}
	if(current->right!=NULL){Q.push(current->right);}
	Q.pop();
	}
}

void Inorder(BstNode* rootref){  //This traveral function will print elements in increasing order 
	if(rootref==NULL){
		return;
	}
	Inorder(rootref->left);
	cout << rootref->data << " ";
	Inorder(rootref->right);
}


void Preorder(BstNode* rootref){
	if(rootref==NULL){
		return;
	}
	cout << rootref->data << " ";
	Preorder(rootref->left);
	Preorder(rootref->right);
}

void Postorder(BstNode* rootref){
	if(rootref==NULL){
	   return;
	}
	Postorder(rootref->left);
	Postorder(rootref->right);
	cout << rootref->data << " ";
	}


int main(){
	BstNode* root = NULL;
	BstNode* temp = NULL;
	int op;
	int value;
	cout << "1) Enter 1 for insert\n2)Enter 2 for search\n3)Enter 3 for level-order traversal\n4)Enter 4 for Inorder-order traversal\n5)Enter 5 for Pre-order traversal\n6)Enter  6 for Post-order traversal\nEnter 7 to exit\n";
	do{
		cin >> op;
		switch(op){
		 	case 1:{
				cout << "Enter value:";
				cin >> value;
				root = insert(root,value);
				break;
			}

			case 2:{
				cout << "Enter value to be searched:";
				cin >> value;
				temp = search(root,value);
				cout << "\n" << temp->data;
				break;
		}
			case 3:{
				cout << "Level order traversal: ";
				levelOrderTraversal(root);
				break;
			
			}
			case 4:{
                                cout << "Inorder traversal: ";
                                Inorder(root);
                                 break;

                         }
			 case 5:{
			 	cout << "Preorder traversal: ";
				Preorder(root);
				break;
			 }
			 case 6:{
			 	cout << "Post-order traversal: ";
				Postorder(root);
				break;
			 }
			default:{
				cout <<"Invalid value!";
			}
		}
	}while(op!=7);
}
