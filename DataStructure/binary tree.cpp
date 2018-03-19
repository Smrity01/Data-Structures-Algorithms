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
	inorder(root);
	cout << "\n";
}
template <class T>
void binarytree<T>::inorder(tnode<T>* root){
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
	binarytree<int> object;
	object.insertion();
	object.display();
	object.paths(0,object.root);
	getch();
	return 0;
}
