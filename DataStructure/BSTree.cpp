/*
Implementation of Binary Search tree
 Written By: Smrity Chaudhary
    Dated  : 17/04/2018
*/
#include<iostream>
#include<conio.h>
using namespace std;

template <class T>
struct tnode{
	/*
	Objective       : Structure of node of a binary Search tree
	Input Parameter : None
	Output Parameter: None
	*/
	T data;
	tnode* right;
	tnode* left;
};

template <class T>
class Bstree{
	/*
	Objective       : Create a Class of a binary Search tree
	Input Parameter : None
	Output Parameter: None
	Description     : Class definition
	Approach        : Class definition provides data member and member functions for the Binary Search Tree class
	*/
	public:
		tnode<T>* root;
		Bstree();
		tnode<T>* insertion(tnode<T>* root,T);
		void display(tnode<T>* root);
		void inorder(tnode<T>* root);
		void preorder(tnode<T>* root);
		void postorder(tnode<T>* root);
		bool search(tnode<T>* root, T);
		tnode<T>* min_node(tnode<T>* root);
		tnode<T>* deletenode(tnode<T>* root ,T element);
};
template <class T>
Bstree<T>::Bstree(){
	/*
	Objective       : Create a Constructor Class of a binary search tree
	Input Parameter : None
	Output Parameter: None
	Description     : Constructor definition
	*/
	root = NULL;
}
template <class T>
tnode<T>* Bstree<T>::insertion(tnode<T>* root,T element){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Statically inserting the elements in the binary Search tree
	*/
	tnode<T>* newnode = new tnode<T>;
	newnode->data = element;
	newnode->left = NULL;
	newnode->right = NULL;
	if (root == NULL){
		root = newnode;
		return root;
	}
	else if(root->data < element){
	root->right = insertion(root->right,element);
	}
	else if(root->data > element){
	root->left = insertion(root->left,element);
	}
	else{
		cout << "\nDuplicate element...";
	}
	return root;
}
template <class T>
void Bstree<T>::display(tnode<T>* root){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : None
	Output Parameter: None
	Description     : Member function definition
	Approach        : Call inorder member function to display the nodes of binary Search tree
	*/
	inorder(root);
	cout << "\n";
}
template <class T>
void Bstree<T>::inorder(tnode<T>* root){
	/*
	Objective       : Create a member function of Class of a binary Search tree
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
bool Bstree<T>::search(tnode<T>* root, T element){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : Root of the binary tree and the element need to be search
	Output Parameter: None
	Description     : Member function definition
	Approach        : Recursively call left subtree of root then right subtree by compairing element and root's data
	*/
	if(root == NULL){
		return false;
	}
	else if (element < root->data){
		return search(root->left,element);
	}
	else if (element > root->data){
		return search(root->right,element);
	}
	else {
		return true;
	}
}
template <class T>
void Bstree<T>::preorder(tnode<T>* root){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : Root of the binary tree
	Output Parameter: Print the nodes of binary tree
	Description     : Member function definition
	Approach        : Recursively call itself and print root first the left subtree of root and then right subtree (follow VLR approach)
	*/
	if(root==NULL){
		return;
	}
	cout << root->data <<",";
	preorder(root->left);
	preorder(root->right);
	return;
}
template <class T>
void Bstree<T>::postorder(tnode<T>* root){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : Root of the binary tree
	Output Parameter: Print the nodes of binary tree
	Description     : Member function definition
	Approach        : Recursively call itself and print left subtree of root then right subtree finally print the root(follow LRV approach)
	*/
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data <<",";
	return;
}
template <class T>
tnode<T>* Bstree<T>::min_node(tnode<T>* temp){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : Root of the binary tree
	Output Parameter: None
	Description     : Member function definition
	Approach        : Find the minimum element of the given BST
	*/
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}
template <class T>
tnode<T>* Bstree<T>::deletenode(tnode<T>* root ,T element){
	/*
	Objective       : Create a member function of Class of a binary Search tree
	Input Parameter : Root of the binary tree and the element that need to be deleted
	Output Parameter: None
	Description     : Member function definition
	Approach        : Recursively call itself and delete node by considering all cases of a node having child
	*/
	if (root == NULL){
		return root;
	}
	if (element < root->data){
		root->left = deletenode(root->left,element);
	}
	else if(element > root->data){
		root->right = deletenode(root->right,element);
	}
	else{
		if(root->left == NULL){
			tnode<T>* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			tnode<T>* temp = root->left;
			delete root;
			return temp;
		}
		tnode<T>* temp = min_node(root->right);
		root->data = temp->data;
		root->right = deletenode(root->right,temp->data);
	}
	return root;
}
int main(){
	/*
	Objective       : Create a Object of binary Search tree class and calll required member function
	Input Parameter : None
	Output Parameter: None
	Description     : Main function
	*/
	Bstree<int> object;
	int choice;
	while(1){
		cout <<"\n\n\n***********MENU*********\n1.Insertion in BST \n2.Display using inorder \n3.Search an element \n4.Post Order \n5.Pre Order \n6. Delete Node \n7.EXIT";
		cout << "\nEnter your choice: ";
	    cin >> choice;
	   switch(choice){
		    case 1: int element;
		            cout << "Enter an element: ";
		            cin >> element;
				    object.root = object.insertion(object.root,element);
				    object.display(object.root);
				    break;
			case 2: object.display(object.root);
				    break;
		    case 3: cout << "Enter an element you want to search: ";
		            cin >> element;
			        if (object.search(object.root,element)){
			        	cout << "\nElement found..";
					}
					else{
						cout << "\nElement not found...";
					}
		            break;
			case 4: object.postorder(object.root);
			        break;
			case 5: object.preorder(object.root);
			        break;
			case 6: cout << "Enter an element you want to delete: ";
		            cin >> element;
		            if (object.search(object.root,element)){
			        	object.root = object.deletenode(object.root,element);
				        object.display(object.root);
					}
					else{
						cout << "\nElement not found...";
					}
			        break;
			case 7: exit(0);
		    default: cout << "\nWrong choice..."; 
		}
	}
	getch();
	return 0;
}
