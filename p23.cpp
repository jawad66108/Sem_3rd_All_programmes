#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * left;
	Node * right;
};

Node* create(int val){
	Node *newnode = new Node();
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

Node* insert(Node *root,int val){
	if(root == NULL){
		return create(val);
	}
	if(val<root->data){
		root->left=insert(root->left,val);
	}
	else if(val>root->data){
		root->right=insert(root->right,val);
	}
	return root;
}

void min(Node *root){
	while(root->left!=NULL){
		root=root->left;
	}
	cout<<"\nMin: "<<root->data;
}

void max(Node *root){
	while(root->right!=NULL){
		root=root->right;
	}
	cout<<"\nmax: "<<root->data;
}

void preorder(Node * root){
	if(root!=NULL){
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
}

void inorder(Node * root){
	if(root!=NULL){
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
}

void postorder(Node * root){
	if(root!=NULL){
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
}

int nodes(Node *root){
	if(root==NULL){
		return 0;
	}
	
	return 1+ nodes(root->left) + nodes(root->right);
}



int main(){
	Node * root = NULL;
	int val;
	
	cout<<"Enter 4 numbers : ";
	for(int i=0;i<4;i++){
		cin>>val;
		root= insert(root,val);
	}
	
	cout<<"\n";
	min(root);
	max(root);
	
	cout<<endl;
	cout<<"Pre-order: ";
	preorder(root);
	cout<<"\nIn-order: ";
	inorder(root);
	cout<<"\nPost-order: ";
	postorder(root);
	
	cout<<"\nTotal nodes: "<<nodes(root);
		
}

