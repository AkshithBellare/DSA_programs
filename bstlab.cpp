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

BstNode* findInorderSuccessor(BstNode* rootref){
	BstNode* temp = rootref->right;
	if(temp == NULL){
		return temp;
	}
	if(temp->right == NULL){
		return temp;
	}
	temp=temp->right;
	while(temp->left!=NULL){
		temp = temp -> left;
	}
	return temp;
}

BstNode* findInorderPredecessor(BstNode* rootref){
	BstNode* temp = rootref->left;
	if(temp == NULL){
		return temp;
	}
	if(temp->left == NULL){
		return temp->par;
	}
	temp=temp->left;
	while(temp->right!=NULL){
		temp = temp -> right;
	}
	return temp;
}

BstNode* deleteNode(BstNode* rootref,int data){
	if(rootref == NULL){
		return rootref;
	}
	if(rootref->data > data){
		rootref->left = deleteNode(rootref->left,data);
	}
	else if(rootref->data < data){
		rootref->right = deleteNode(rootref->right,data);
	}
	//root is the node to be deleted and it has only one child
	else{
	if(rootref->left == NULL){
		BstNode* temp = rootref->right;
		free(rootref);
		return temp;
	}
	else if(rootref->right == NULL){
		BstNode* temp = rootref->left;
		free(rootref);
		return temp;
	}
	//if root has two children, we have to find the inorder successor of the node
	BstNode* inorderSuccessor = findInorderSuccessor(rootref);
	rootref->data = inorderSuccessor->data;
	rootref->right = deleteNode(rootref->right,inorderSuccessor->data);
}
return rootref;
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

void minimum(BstNode* rootref){
	BstNode* temp = rootref;
	while(temp->left!=NULL){
		temp = temp ->left;
	}
	cout << "Minimum:"<< temp->data <<"\n";

}

void maximum(BstNode* rootref){
	BstNode* temp = rootref;
	while(temp->right!=NULL){
		temp = temp ->right;
	}
	cout << "maximum:"<< temp->data <<"\n";

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
	cout << "1) Enter 1 for insert\n2)Enter 2 for search\n3)Enter 3 for level-order traversal\n4)Enter 4 for Inorder-order traversal\n5)Enter 5 for Pre-order traversal\n6)Enter  6 for Post-order traversal\n";
	cout << "7)Enter 7 to delete\n8)Enter 8 for maximum\n9)Enter 9 for minimum\n10)Enter 10 for inorder Successor\n11)Enter 11 for inorder predecessor\n";
	cout << "12)Enter 12 to exit\n";
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
				if(temp!=NULL){
				cout << "\n" << temp->data << "\n";
			}
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
			 case 7:{
			 	cout << "Enter the value to be deleted:";
			 	cin >> value;
			 	root = deleteNode(root,value);
			 	break;
			 }
			 case 8:{
			 	maximum(root);
			 	break;
			 }
			 case 9:{
			 	minimum(root);
			 	break;
			 }
			 case 10:{
			 		cout << "Enter key whose inorderSuccessor you want:";
			 		cin >> value;
			 		temp = search(root,value);
			 		temp = findInorderSuccessor(temp);
			 		if(temp!=NULL){
			 		cout << "The value of inorder Successor is:" <<  temp->data <<"\n";
			 	}
			 	else if(temp == NULL){
			 		cout << "No inorder successor!";
			 	}
			 		break;
			 	}
			 case 11:{
			 		cout << "Enter key whose inorder predecessor you want:";
			 		cin >> value;
			 		temp = search(root,value);
			 		temp = findInorderPredecessor(temp);
			 		if(temp!=NULL){
			 		cout << "The value of inorder predecessor is:" <<  temp->data <<"\n";
			 	}
			 	else if(temp == NULL){
			 		cout << "No inorder successor!";
			 	}
			 		break;
			 }
			 case 12:{
			 	cout << "Exiting..\n\n";
			 }
			default:{
				cout <<"Invalid value";
				break;
			}
		}
	}while(op!=12);
}
