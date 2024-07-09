#include<iostream>
#include<conio.h>

using namespace std;
class node{
	public:
		int info;
		node *left;
		node *right;
};
class bst{
	public:
	node *root, *temp;
	
		bst(){ root=NULL;
		}
		void insertion(node *, int);
		void preorder(node *);
		void postorder(node *);
		void inorder(node *);
	};
void bst::insertion(node* temp, int item){
	node *newnode;
	newnode=new node;
	newnode->info=item;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL){
	root=newnode;
	temp=newnode;	
	}
	else if(item<temp->info){
		if(temp->left==NULL){
			temp->left=newnode;
		}
		else{
			insertion(temp->left,item);
		}
	}
	else if(item>temp->info){
		if(temp->right==NULL){
			temp->right=newnode;
		}
		else{
			insertion(temp->right,item);
		}
		
	}	
	else	
		cout<<"Duplicate value";
}

void bst::preorder(node *temp){
	if(temp!=NULL){
		cout<<temp->info<<",";
		preorder(temp->left);
		preorder(temp->right);
	}
	
}

void bst::postorder(node *temp){
	if(temp!=NULL){
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->info<<",";
	}
}

void bst::inorder(node *temp){
	if(temp!=NULL){
		inorder(temp->left);
		cout<<temp->info<<",";
		inorder(temp->right);
	}
}


void mainmenu(){
	cout<<"\nSelect Operations:\n1.Insertion\n2.Preorder\n3.postorder\n4.Inorder\n5.exit"<<endl;
}
int main(){
	bst b;
	int choice,item;
	while(1){
	mainmenu();
	cout<<"select choice(1-4)";
	cin>>choice;
			switch(choice){
				case 1: 
						cout<<"Enter item to insert in tree\n";
						cin>>item;
						b.insertion(b.root,item); break;
				case 2: b.preorder(b.root); break;
				case 3: b.postorder(b.root); break;
				case 4: b.inorder(b.root); break;
				case 5: exit(0);
				default: cout<<"invalid input";			}	
	}
	getch();
	return 0;
}

