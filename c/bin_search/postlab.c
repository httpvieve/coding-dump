#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef max
    #define max(a,b) ((a) > (b) ? (a) : (b))
#endif


// a recursive subroutine to display the BST in tree mode
void showTreeHelper(BST_NODE* node, int tabs){

	if(!node) return; // node is null, do nothing
	showTreeHelper(node->right, tabs + 1);
	for(int i=0; i<tabs; i++) printf("\t");
	printf("%d(%d)\n", node->key, node->height);
	showTreeHelper(node->left, tabs + 1);

}


void showTree(BST* B){
	showTreeHelper(B->root, 0);
}

BST_NODE* createBSTNode(int key, BST_NODE* L, BST_NODE* R, BST_NODE* P){
	BST_NODE* new = (BST_NODE *) malloc (sizeof(BST_NODE));
	new->key = key;
	new->left = L;
	new->right = R;
	new->parent = P;
	new->height = 0;

	return new;
}

BST* createBST(int max){
	BST* new = (BST *) malloc (sizeof(BST)); // initializes the BST
	new->root = NULL;
	new->maxSize = max;
	new->size = 0;

	return new;
}

int isEmpty(BST* B){
	if (B == NULL){
		printf("No BST Initialized.\n");
		return 0;
	}

	if (B->root == NULL) return 1; // returns 1 if empty/no root node
	return 0;
}

int isFull(BST* B){
	if (B == NULL){
		printf("No BST Initialized.\n");
		return 0;
	}

	if (B->size == B->maxSize) return 1; // returns 1 if BST is full
	return 0;
}

void insert(BST* B, BST_NODE* node){
	if (B == NULL){
		printf("No BST Initialized.\n");
		free(node); // frees the created node in the function call in main
		return;
	}

	if (isFull(B)){
		printf("BST is full.\n");
		free(node); // frees the created node in the function call in main
		return;
	}

	if (isEmpty(B)){
		B->root = node; // node is new root node if BST is empty
		return;
	}


	BST_NODE* temp = B->root;
	while (temp != NULL){ 

		// if key < current
		if (node->key < temp->key){
			if (temp->left == NULL) {
				temp->left = node;
				node->parent = temp;
				break;
			}
			if (temp->left != NULL){
				temp = temp->left;
			}
		}
		
		// if key > current
		if (node->key > temp->key){
			if (temp->right == NULL) {
				temp->right = node;
				node->parent = temp;
				break;
			}
			if (temp->right != NULL){
				temp = temp->right;
			}
		}
	} // end of while

	// B->size update
	B->size = (B->size) + 1;

	// height update
	// temp = node; // commented out since temp is already at the parent node of the inserted node
	while (temp != NULL){
		if (temp->left != NULL && temp->right == NULL){
			temp->height = temp->left->height + 1;
		}else if (temp->left == NULL && temp->right != NULL){
			temp->height = temp->right->height + 1;
		}else{
			temp->height = max(temp->left->height, temp->right->height) + 1;
		}

		temp = temp->parent;
	} // end of height update while loop
}

BST_NODE* search(BST* B, int key){
	if (B == NULL || isEmpty(B)){
		return NULL;
	}

	BST_NODE* temp = B->root;
	while(temp != NULL){
		if (key == temp->key){
			// printf("(key = %d) ", temp->key); // checker
			return temp;
		}

		if (key < temp->key) temp = temp->left;
		else temp = temp->right;
	}
	// printf("(key not found) "); // checker
	return temp; // should return NULL if not key not found in BST
}

void inorderWalk(BST* B){
	if (B == NULL){
		printf("No BST Initialized.\n");
		return;
	}

	BST_NODE* temp = B->root;
	while (temp != NULL){
		if (temp->left == NULL){
			printf("%d ", temp->key);
			temp = temp->right;
		}else{

		}
	}

}


// main function
int main(){

	char command;
	int key, result;

	BST *B = createBST(100);
	BST_NODE* node;
	while(1){
		scanf(" %c", &command);

		switch(command){
			case '+':
				scanf("%d", &key);
				printf("Inserting key: %d\n", key);
				insert(B, createBSTNode(key, NULL, NULL, NULL));
				break;
			case '?':
				scanf(" %d", &key);
				printf("Searching node with key: %d. Location: %p\n", key, search(B, key));
				// (nil) means NULL pointer
				break;
			case 'p':
				printf("Tree (rotated +90 degrees): \n");
				showTree(B);
				printf("\n");
				break;
			case 'E':
				printf("BST %s empty.\n", isEmpty(B)?"is":"is not");
				break;
			case 'F':
				printf("BST %s full.\n", isFull(B)?"is":"is not");
				break;
			/* for the postlab, uncomment this
			case '<':
				printf("Pre-order Traversal: ");
				preorderWalk(B);
				printf("\n");
				break;
			case '>':
				printf("Post-order Traversal: ");
				postorderWalk(B);
				printf("\n");
				break;
			case '/':
				printf("In-order Traversal: ");
				inorderWalk(B);
				printf("\n");
				break;
			*/
			case 'Q':
				return 0;
			default:
				printf("Unknown command: %c\n", command);
		}
	}

	return 0;
}