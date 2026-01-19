#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * left;
	Node * right;
};

Node * create(int val){
	Node * newnode = new Node();
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

Node * insert(Node * root , int val){
	if(root == NULL){
		return create(val);
	}
	else if(root->data < val){
		root->right = insert(root->right , val);
	}else if(root->data > val){
		root->left = insert(root->left , val);
	}
	
	return root;
}

int min(Node*root){
	while(root->left!=NULL){
		root = root->left;
		
	}
	return root->data;
	
}

int max(Node*root){
	while(root->right!=NULL){
		root = root->right;
	
	}
		return root->data;
}

Node pre(Node * root){
	if(root != NULL){
		cout<<root->data<<" ";
		pre(root->left);
		pre(root->right);
	}
}

Node in(Node * root){
	if(root != NULL){
		in(root->left);
		cout<<root->data<<" ";

		in(root->right);
	}
}

Node post(Node * root){
	if(root != NULL){
		post(root->right);
		post(root->left);
		cout<<root->data<<" ";
	}
}

int main(){
	Node * root = NULL;
	int val;
	cout<<"Enter 6 numbers :\n";
	
	for(int i=0;i<6;i++){
		cin>>val;
		root = insert(root,val);
	}
	
	cout<<"MIN: "<<min(root)<<"\nMAX: "<<max(root)<<endl;
	
	cout<<"PRE-ORDER: ";
	pre(root);
	cout<<"\nIN-ORDER: ";
	in(root);
	cout<<"\nPOST-ORDER: ";
	post(root);
	
}
