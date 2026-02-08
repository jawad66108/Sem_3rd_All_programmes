#include<iostream>
using namespace std;
struct Node{
	Node * left;
	Node * right;
	int data;
};

Node * create(int val){
	Node *newnode = new Node();
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data=val;
	return newnode;
}

Node* insert(int val,Node * root){
	if(root == NULL){
		return create(val);
	}
	
	if(val<root->data){
		root->left = insert(val,root->left);
	}
	
	if(val>root->data){
		root->right = insert(val,root->right);
	}
	
	return root;
}

void min(Node* root){
	while(root->left != NULL){
		root = root->left;
	}
	cout<<"MIN: "<<root->data;
}

void max(Node * root){
	while(root->right != NULL){
		root = root->right;
	}
	cout<<" max: "<<root->data;
}

void inorder(Node * root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}


int main(){
Node * root = NULL;
	int val;
	
	cout<<"Enter 4 numbers : ";
	for(int i=0;i<4;i++){
		cin>>val;
		root= insert(val,root);
	}
	
	cout<<"\n";
	min(root);
	max(root);
	
	cout<<endl;
//	cout<<"Pre-order: ";
//	preorder(root);
	cout<<"\nIn-order: ";
	inorder(root);
//	cout<<"\nPost-order: ";
//	postorder(root);
	
//	cout<<"\nTotal nodes: "<<nodes(root);
		
}
