#include<iostream>
#include<conio.h>
using namespace std;

template <class T>
struct tnode{
	T data;
	tnode* right;
	tnode* left;
};

template <class T>
class binarytree{
	public:
		tnode<T>* root;
		binarytree();
		void insertion();
		void display();
		tnode<T> * newNode(T);
};
template <class T>
binarytree<T>::binarytree(){
	root = NULL;
}

template <class T>
void binarytree<T>::insertion(){
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
	tnode<T>* temp = new tnode<T>;
	temp->left=NULL;
	temp->right = NULL;
	temp->data = element;
	return temp;
}
template <class T>
void binarytree<T>::display(){
	if(root==NULL){
		cout << "\nTree is empty..";
		return;
	}
	
}
