#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
    int height;
}Node;

Node* makeEmpty(Node* tree){
	if(tree != NULL){
		makeEmpty(tree->leftChild);
		makeEmpty(tree->rightChild);
		free(tree);
	}
	return NULL;
}

int max(int a, int b);

int height(Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

Node* newNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data   = value;
    node->leftChild   = NULL;
    node->rightChild  = NULL;
    node->height = 1;
    return(node);
}

Node *rightChildRotate(Node *y){
    Node *x = y->leftChild;
    Node *T2 = x->rightChild;

    x->rightChild = y;
    y->leftChild = T2;

    y->height = max(height(y->leftChild), height(y->rightChild))+1;
    x->height = max(height(x->leftChild), height(x->rightChild))+1;

    return x;
}

Node *leftChildRotate(Node *x){
    Node *y = x->rightChild;
    Node *T2 = y->leftChild;

    y->leftChild = x;
    x->rightChild = T2;

    x->height = max(height(x->leftChild), height(x->rightChild))+1;
    y->height = max(height(y->leftChild), height(y->rightChild))+1;

    return y;
}

int getBalance(Node *N){
    if (N == NULL)
        return 0;
    return height(N->leftChild) - height(N->rightChild);
}
 
Node* insert(Node* node, int value){
    if (node == NULL)
        return(newNode(value));
    if (value < node->data)
        node->leftChild  = insert(node->leftChild, value);
    else if (value > node->data)
        node->rightChild = insert(node->rightChild, value);
    else 
        return node;

    node->height = 1 + max(height(node->leftChild), height(node->rightChild));
 
    int balance = getBalance(node);

    if (balance > 1 && value < node->leftChild->data)
        return rightChildRotate(node);
    if (balance < -1 && value > node->rightChild->data)
        return leftChildRotate(node);
    if (balance > 1 && value > node->leftChild->data){
        node->leftChild =  leftChildRotate(node->leftChild);
        return rightChildRotate(node);
    }
    if (balance < -1 && value < node->rightChild->data){
        node->rightChild = rightChildRotate(node->rightChild);
        return leftChildRotate(node);
    }

    return node;
}

Node * minValueNode(Node* node){
    Node* current = node;

    while (current->leftChild != NULL)
        current = current->leftChild;
 
    return current;
}

Node* deleteNode(Node* root, int value){
    if (root == NULL)
        return root;
    if (value < root->data)
        root->leftChild = deleteNode(root->leftChild, value);
    else if(value > root->data)
        root->rightChild = deleteNode(root->rightChild, value);
    else{
        if((root->leftChild == NULL) || (root->rightChild == NULL)){
            Node *temp = root->leftChild ? root->leftChild : root->rightChild;
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else{
            Node* temp = minValueNode(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteNode(root->rightChild, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->leftChild), height(root->rightChild));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rightChildRotate(root);

    if (balance > 1 && getBalance(root->leftChild) < 0){
        root->leftChild =  leftChildRotate(root->leftChild);
        return rightChildRotate(root);
    }
    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return leftChildRotate(root);

    if (balance < -1 && getBalance(root->rightChild) > 0){
        root->rightChild = rightChildRotate(root->rightChild);
        return leftChildRotate(root);
    }
 
    return root;
}

void preOrder(Node *root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

int main(void){
    Node *root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 
    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
 
    root = deleteNode(root, 10);
 
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 
    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);

    makeEmpty(root);
 
    return 0;
}
