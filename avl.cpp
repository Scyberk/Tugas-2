/*avl
ada 4 case:
	1. left left
	2. left right
	3. right right
	4. right left

*/

/*binary search tree

#*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Data{
	int value;
	char name[100];
	int height;
	Data *left, *right;
};

int getHeight(Data *root){
	if(root == NULL) return 0;
	return root->height;
}

int getMax(int a, int b){
	return(a>b) ? a:b;
}

int getBf(Data *root){
	if(root == NULL) return NULL;
	return getHeight(root->left) - getHeight(root->right);
}

Data *newNode(char name[100], int value){
	Data *node = (Data *) malloc (sizeof(Data));
	strcpy(node->name, name);
	node->value = value;
	node->height = 1;
	node->left = node->right = NULL;
	return node;
}

Data *leftRotate(Data *root){
	Data *x = root->right;
	Data *subX = x->left;
	
	x->left = root;
	root->right = subX;
	
	root->height = 1+getMax(getHeight(root->left), getHeight(root->right));
	x->height = 1+getMax(getHeight(x->left), getHeight(x->right));
	return x;
}

Data *rightRotate(Data *root){
	Data *x = root->left;
	Data *subX = x->right;
	
	x->right = root;
	root->left = subX;
	
	root->height = 1+getMax(getHeight(root->left), getHeight(root->right));
	x->height = 1+getMax(getHeight(x->left), getHeight(x->right));
	return x;
}

Data *rebalance(Data *root){
	if(root == NULL)return NULL;
	root->height = 1+getMax(getHeight(root->left), getHeight(root->right));
	int bf = getBf(root);
	
	//left left
	if(bf > 1 && getBf(root->left) >= 0){
		return rightRotate(root);
	}
	
	//left right
	else if(bf>1 && getBf(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//right right
	else if(bf< -1 && getBf(root->right) <= 0){
		return leftRotate(root);
	}
	
	//right left
	else if(bf< -1 && getBf(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

Data *insert(Data *root, char name[100], int value){
	if(root == NULL) return newNode(name, value);
	else if(value < root->value)root->left = insert(root->left, name, value);
	else root->right = insert(root->right, name, value);


	return rebalance(root);
}

Data *deleteNode(Data *root, char name[100], int value){
	if(root==NULL) return NULL;
	else if(value < root->value)root->left = deleteNode(root->left, name, value);
	else if(value > root->value)root->right = deleteNode(root->right, name, value);
	else{
		if(strcmp(root->name, name)==0){
			// ga punya anak
			if(root->left == NULL && root->right == NULL){
				free(root);
				root = NULL;
			}
			//punya 1 anak di kiri
			else if(root->left != NULL && root->right == NULL){
				Data *temp = root->left;
				*root = *temp;
				free(temp);
			}
			
			//punya 1 anak di kanan
			else if(root->left == NULL && root->right != NULL){
				Data *temp = root->right;
				*root = *temp;
				free(temp);
			}
			
			//punya 2 anak
			else{
				Data *temp = root->left;
				while(temp->right != NULL){
					temp = temp->right;
				}
				strcpy(root->name, temp->name);
				root->value = temp->value;
				root->left = deleteNode(root->left, temp->name, temp->value);
			}
		}
		else{
			root->right = deleteNode(root->right, name, value);
		}
	}
	return rebalance(root);
}

void prefix(Data *root){
	//1. print
	//2. kiri
	//3. kanan
	
	if(root != NULL){
		printf("%s %d: BF %d\n", root->name, root->value, getBf(root));
		prefix(root->left);
		prefix(root->right);
	}
}

void infix(Data *root){
	//1. kiri
	//2. print
	//3. kanan
	if(root != NULL){
		infix(root->left);
		printf("%s %d\n", root->name, root->value);
		infix(root->right);
	}
}

void postfix(Data *root){
	//1. kiri
	//2. kanan
	//3. print
	if(root != NULL){
		postfix(root->left);
		postfix(root->right);
		printf("%s %d\n", root-> name, root->value);
	}
}

int main(){
	
	Data *root = NULL;
	root = insert(root, "Davis", 50);
	root = insert(root, "Kelvin", 60);
	root = insert(root, "Victor", 70);
	root = insert(root, "Jose", 75);
	root = insert(root, "Theo", 73);
	root = insert(root, "Carney", 20);
	root = insert(root, "Garru", 10);
	root = insert(root, "Garryl", 35);
	
	prefix(root);
	printf("\n\n");
	
	//delete
	root = deleteNode(root, "Kelvin", 60);
	root = deleteNode(root, "Victor", 70);
	prefix(root);
	
	return 0;
}
