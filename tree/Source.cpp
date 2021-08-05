#include<iostream>

using namespace std;
struct node
{
	int key;
	node *left;
	node *right;
};

node* newnode(int item)
{
	node* temp = new node();
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;

}


node* insert(node *tree, int key)
{
	//node *temp=NULL;
	if (tree == NULL)
	{

		return newnode(key);

	}
	if (key > tree->key)
	{
		node *right = insert(tree->right, key);

	}
	else if (key < tree->key)
	{
		node *right = insert(tree->left, key);
	}
	return tree;
}




void preOrder(node *tree)
{
	if (tree != NULL)
	{
		cout << tree->key << endl;
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(node *tree)
{
	if (tree)
	{

		inOrder(tree->left);
		cout << tree->key << endl;
		inOrder(tree->right);
	}
}


void postOrder(node *tree)
{
	if (tree)
	{

		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->key << endl;
	}
}





node* deletenode(node *tree, int k)
{
	if (tree == NULL)
	{
		return tree;
	}
	if (tree->key > k)
	{

		tree->left = deletenode(tree->left, k);
		return tree;
	}
	else if (tree->key < k)
	{
		tree->right = deletenode(tree->right, k);
		return tree;
	}
	//if one child
	if (tree->left == NULL)
	{
		node *temp = tree->right;
		delete tree;
		return temp;

	}
	else if (tree->right == NULL)
	{

		node *temp = tree->left;
		delete tree;
		return temp;
	}
	else{
		node *succparent = tree->right;
		node *succ = tree->right;
		while (succ->left != NULL)
		{
			succparent = succ;
			succ = succ->left;
		}

		succparent->left = succ->right;
		tree->key = succ->key;
		delete succ;
		return tree;
	}



}


node* search(node **tree, int search1)
{
	if (!(*tree))   //tree not pointer elements
	{
		return NULL;
	}
	if (search1 < (*tree)->key)

	{
		search((&(*tree)->left), search1);
	}
	else if (search1 >(*tree)->key)
	{
		search(&((*tree)->right), search1);
	}
	else if (search1 == (*tree)->key)
	{
		return *tree;
	}
}


int main()
{
	node *tree = NULL;
	tree = insert(tree, 9);
	insert(tree, 4);
	insert(tree, 2);
	insert(tree, 1);
	insert(tree, 10);
	insert(tree, 11);



	preOrder(tree);
	cout << "///////" << endl;
	inOrder(tree);
	/*cout<<"//////"<<endl;
	postOrder(root);*/

	//tree =deletenode(tree,4);
	//preOrder(tree);

	/* node *temp=search(&root,3);
	if(temp!=NULL)
	{
	cout<<"found"<<endl;
	}
	else
	{
	cout<<"not found"<<endl;
	}*/






	return 0;
}
