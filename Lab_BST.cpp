#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node * right;
};

Node * create(int val){
	Node * newnode = new Node();
	newnode->data= val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
	
}



Node * insert(Node * root ,int val){
	if(root == NULL ){
		return create(val);
	}
	if(val<root->data){
		root->left = insert(root->left,val);
	}
	else if(val>root->data){
		root -> right = insert(root->right , val);
	}
	
	return root;
}


Node pre(Node * root){
	if(root !=NULL){
		cout<<root->data<<" ";
		pre(root->left);
		pre(root->right);
	}
}


Node post(Node * root){
	if(root !=NULL){
		pre(root->left);
		pre(root->right);
		cout<<root->data<<" ";

	}
}
int findMin(Node* root) {
		while (root->left != NULL)
			root = root->left;
			return root->data;
	}
	
int findMax(Node* root) {
		while (root->right != NULL)
			root = root->right;
			return root->data;
	}
	
int countNodes(Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main(){
	
	Node* root = NULL;
	int val;
	cout<<"Enter ten numbers : ";
	for(int i=0;i<7;i++){
		
		cin>> val;
		root = insert(root, val);
	}

	cout << "pre-order Traversal: ";
	pre(root);
	
	cout<<" \nPost-order Traveral: ";
	post(root);
	
	cout<<"Min: "<<findMin(root)<<"\nMax : "<<findMax(root)<<"\nTotal Number of nodes are: "<<countNodes(root);
	

}


