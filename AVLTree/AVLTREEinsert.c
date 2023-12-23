#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

typedef struct Node AVLTREE;

AVLTREE *createNode(int data){
    AVLTREE *newNode = malloc(sizeof(AVLTREE));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->height = 1;
    }
    return newNode;
}

void inorderTraversal(AVLTREE *root){
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int height (struct Node* n) {
    if (n == NULL)
        return 0;
    return n->height;
}  

int max(int a, int b) {

    return (a > b)? a : b;

}

AVLTREE *rightRotate(AVLTREE *z) {
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;

  

    z->height = max(height(z->left),height(z->right)) + 1;
    temp->height = max(height(temp->left),height(temp->right)) + 1;
    return temp;

}

AVLTREE *leftRotate(AVLTREE *x) {
    AVLTREE *temp = x->right;
    x->right = temp->left;
    temp->left = x;

    
    x->height = max(height(x->left),height(x->right)) + 1;
    temp->height = max(height(temp->left),height(temp->right)) + 1;
    
    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z) {
    z->left = leftRotate(z->left);
    return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z) {
    z->right = rightRotate(z->right);
    return leftRotate(z);
}
 
AVLTREE *insertToAVL(AVLTREE *tree, int x) {
    if (tree != NULL) {

        if (x < tree->data)
            tree->left  = insertToAVL(tree->left, x);
        else if (x > tree->data)
            tree->right = insertToAVL(tree->right, x);
        else 
            return tree;
 
        tree->height = 1 + max(height(tree->left), height(tree->right));

        // Left - Left Rotation
        if ((height(tree->left) - height(tree->right)) > 1 && x < tree->left->data) {
            return rightRotate(tree);
        }
        
        // Right - Right Rotation
        if ((height(tree->left) - height(tree->right)) < -1 && x > tree->right->data) {
            return leftRotate(tree);
        }
        
        // Left - Right Rotation
        if ((height(tree->left) - height(tree->right)) > 1 && x > tree->left->data) {
            tree->left =  leftRotate(tree->left);
            return leftRightRotate(tree);
        }
        // Right - Left Rotation
        if ((height(tree->left) - height(tree->right)) < -1 && x < tree->right->data) {
            tree->right = rightRotate(tree->right);
            return rightLeftRotate(tree);
        }

    }
    else
        tree = createNode(x);

return tree;

}

int main () {
    AVLTREE *root = NULL;

    int value = 0;
    while (1) {
        printf("Bir deger girin : ");
        scanf("%d", &value);

        if (value == -1) {
            break;
        }
        root = insertToAVL(root, value);
    }
    printf ("Inorder Traversal : ");
    inorderTraversal(root);
    printf("Height = %d", root->height);

    return 0;
}






