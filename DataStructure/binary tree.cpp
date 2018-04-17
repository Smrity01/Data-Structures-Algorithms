/*
Implementation of Binary tree
 Written By: Smrity Chaudhary
    Dated  : 20/03/2018
*/
#include<iostream>
#include<conio.h>
using namespace std;

template <class T>
struct tnode{
	/*
	Objective       : Structure of node of a binary tree
	Input Parameter : None
	Output Parameter: None
	*/
	T data;
	tnode* right;
	tnode* left;
};

template <class T>
class binarytree{
	/*
	Objective       : Create a Class of a binary tree
	Input Parameter : None
	Output Parameter: None
	Description     : Class definition
	Approach        : Class definition provides data member and member functions for the Binary class
	*/
	public:
		int * arr;
		tnode<T>* root;
		binarytree();
		void insertion();
		void display();
		void inorder(tnode<T>* root);
		void paths(int index ,tnode<T>* root);
		tnode<T> * newNode(T);
};
template <class T>
binarytree<T>::binarytree(){
	/*
	Objective       : Create a Constructor Class of a binary tree
	Input Parameter : None
	Output Parameter: None
	Description     : Constructor definition
	*/
	root = NULL;
}

template <class T>
void binarytree<T>::insertion(){
	/*
	Objective       : Create a member function of Class of a binary tree
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Statically inserting the elements in the binary tree
	*/
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
}
template <class T>
tnode<T> * binarytree<T>:: newNode(T element ) {
	/*
	Objective       : Create a member function of Class of a binary tree
	Input Parameter : Element that need to be inserted
	Output Parameter: Created node
	Description     : Member function definition
	Approach        : Create a node of binary tree and insert the element
	*/
	tnode<T>* temp = new tnode<T>;
	temp->left=NULL;
	temp->right = NULL;
	temp->data = element;
	return temp;
}
template <class T>
void binarytree<T>::display(){
	/*
	Objective       : Create a member function of Class of a binary tree
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Call inorder member function to display the nodes of binary tree
	*/
	inorder(root);
	cout << "\n";
}
template <class T>
void binarytree<T>::inorder(tnode<T>* root){
	/*
	Objective       : Create a member function of Class of a binary tree
	Input Parameter : Root of the binary tree
	Output Parameter: Print the nodes of binary tree
	Description     : Member function definition
	Approach        : Recursively call itself and print left subtree of root then right subtree (follow LVR approach)
	*/
	
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout << root->data <<",";
	inorder(root->right);
	return;
	
}

template <class T>
void binarytree<T>::paths(int index , tnode<T>* root ) {
	/*
	Objective       : Create a member function of Class of a binary tree
	Input Parameter : Index of array and root of the tree
	Output Parameter: Print all possible paths from root to leaf
	Description     : Member function definition
	Approach        : Recursively call itself and store & print left path from root to leaf in array then right subtree
	*/
	if ( root == NULL ) {
		return;
	}
	arr[index] = root->data; 
	index++;
	if(root->left == NULL && root->right ==  NULL ){
		for(int i=0;i < index - 1;i++){
			cout << arr[i] <<"->";
		}
		cout << arr[index-1];
		cout << "\n";
		return;
	}
	else {
		paths(index , root->left);
		paths(index,root->right);
	}
}

int main(){
	/*
	Objective       : Create a Object of binary tree class and calll required member function
	Input Parameter : None
	Output Parameter: None
	Description     : Main function
	*/
	binarytree<int> object;
	object.insertion();
	object.display();
	object.paths(0,object.root);
	getch();
	return 0;
}
