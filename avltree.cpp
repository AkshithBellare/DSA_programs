#include <iostream>
using namespace std;

class AVLNode{
public:
		int data;
		int height;
		AVLNode* left;
		AVLNode* right;
		AVLNode* parent;
};

int getheight(AVLNode* node){
	if(node == NULL){return 0;}
	return node->height;
}

AVLNode* createNode(int key){
	AVLNode* newNode = new AVLNode();
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->parent = NULL;
	newNode->data = key;
	newNode->height = 1;
	return newNode;
}

int getbalance(AVLNode* node){
	return (getheight(node->left) - getheight(node->right));
}

int max(int a,int b){
	return (a>b)?a:b;
}

void updateHeight(AVLNode* node){
	node->height = max(getheight(node->left),getheight(node->right)) + 1;
}

AVLNode* leftrotate(AVLNode* x){
	AVLNode* y = x->right;
	AVLNode* T2 = y->left;

	//perform rotation
	y->left = x;
	x->right = T2;

	updateHeight(x);
	updateHeight(y);

	return y;//return new node
    
}

AVLNode* rightrotate(AVLNode* y){
	AVLNode* x = y->left;
	AVLNode* T2 = x->right;

	//perform rotation
	x->right = y;
	y->left = T2;

	//update height
	updateHeight(x);
	updateHeight(y);


	return x;//returning new node
}

void preorder(AVLNode* root){
	if(root == NULL ){return;}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

AVLNode* insert(AVLNode* root, int key){
	
	if(root == NULL){
		AVLNode* newNode = createNode(key);
		return newNode;
	}
	else if(key < root->data){
		root->left = insert(root->left,key);
	}
	else if(key > root->data){
		root->right = insert(root->right,key);
	}
	else return root;

	updateHeight(root);

	int balance = getbalance(root);    

    //four cases
	
	if(balance > 1 && key < root->left->data){//left-left case
		return  rightrotate(root);
	}
	else if(balance < -1 && key > root->right->data){
		return leftrotate(root);
	}
	else if(balance > 1 && key > root->left->data){
		root->left = leftrotate(root->left);
		return rightrotate(root);
	}
	else if(balance < -1 && key < root->right->data){
		root->right = rightrotate(root->right);
		return leftrotate(root);
	}
	return root;
}

AVLNode* deleteNode(AVLNode* root, int key)  
{  
      
    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if ( key < root->data )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if( key > root->data )  
        root->right = deleteNode(root->right, key);  
  
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            AVLNode *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            AVLNode* temp = inorderSuccessor(root->data);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->data = temp->data;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,  
                                     temp->data);  
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(getheight(root->left),  
                           getheight(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getbalance(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        getbalance(root->left) >= 0)  
        return rightrotate(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        getbalance(root->left) < 0)  
    {  
        root->left = leftrotate(root->left);  
        return rightrotate(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
        getbalance(root->right) <= 0)  
        return leftrotate(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        getbalance(root->right) > 0)  
    {  
        root->right = rightrotate(root->right);  
        return leftrotate(root);  
    }  
  
    return root;  
}  
AVLNode*  search(AVLNode* root,int key){
	AVLNode* result;
	if(root == NULL){
		result = root;
	}
	if(root->data == key){
		result = root;
	}
	else if(key < root -> data){
		result = search(root->left, key);
	}
	else if(key > root->data){
		result = search(root->right,key);
	}
	return result;
}

int minimum(AVLNode* root){
	while(root->left!=NULL){
		root = root -> left;
	}
	return root->data;
}

int maximum(AVLNode* root){
	while(root->right!=NULL){
		root = root -> right;
	}
	return root->data;
}

int inorderSuccessor(AVLNode* root, int key){
	AVLNode* temp;
	AVLNode* node = search(root,key);
	if(node == NULL){
		cout <<"The key doesnt exist!\n\n";
	}
	if(node->right == NULL){
		temp = node->left;
		if(temp == NULL){
			cout << "no inorderSuccessor\n\n";
			return -1;
		}
		while(temp->right!=NULL){
			temp = temp -> right;
		}
		return temp->data;
	}
	else if(node->right->left == NULL){
		return node->right->data;
	}
	else {
		temp = node->right;
		while(temp->left!=NULL){
			temp = temp->left;
		}
		return temp->data;
	}
	return 0;
}

int inorderPredecessor(AVLNode* root, int key){
	AVLNode* temp;
	AVLNode* node = search(root,key);
	if(node == NULL){
		cout <<"The key doesnt exist!\n\n";
	}
	if(node->left == NULL){
		temp = node->right;
		if(temp == NULL){
			cout << "no inorderPredecessor\n\n";
			return -1;
		}
		while(temp->left!=NULL){
			temp = temp -> left;
		}
		return temp->data;
	}
	else if(node->left->right == NULL){
		return node->left->data;
	}
	else {
		temp = node->left;
		while(temp->right!=NULL){
			temp = temp->right;
		}
		return temp->data;
	}
	return 0;
}


int main(){
	AVLNode* root = NULL;
	
		int opt;
		int value;
		cout << "Enter 1 for insert:\n";
		cout << "Enter 2 for maximum:\n";
		cout << "Enter 3 for minimum:\n";
		cout << "Enter 4 for preorder traversal:\n";
		cout << "Enter 5 for search:\n";
		cout << "Enter 6 for inorderSuccessor:\n";
		cout << "Enter 7 or inorderPredecessor:\n";
		cout << "Enter 8 for delete:\n";
	while(1){
		cin >> opt;
		switch(opt){
			case 1: {
				cout << "Enter element:";
				cin >> value;
				root = insert(root,value);
				break;
			}
			case 2:{
				cout << "maximum is:" << maximum(root) << "\n";
				break;
			}
			case 3:{
				cout << "minimum is:" << minimum(root) << "\n";
				break;
			}
			case 4:{
				cout << "preorder traversal:";
				preorder(root);
				break;
			}
			case 5:{
				cout << "Enter the element you want to search for:\n";
				cin >> value;
				search(root,value);
			}
			case 6:{
				cout << "Enter element:\n";
				cin >> value;
				cout <<"inorderSuccessor is:";
				cout << inorderSuccessor(root, value) << "\n";
				break;
			}
			case 7:{
				cout << "Enter element:\n";
				cin >> value;
				cout <<"inorderSuccessor is:";
				cout << inorderPredecessor(root, value) << "\n";
				break;
			}
			case 8:{
				cout << "Enter value to be deleted:";
				cin >> value;
				deleteNode(root,value);
				break;
			}
		}
	}


}
