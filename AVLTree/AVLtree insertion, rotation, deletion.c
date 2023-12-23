#include<stdio.h>
#include<stdlib.h>

// AVL Tree düğüm yapısı: 
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;

};

// Max değer fonksiyonu:
int max (int a, int b) {
    return (a>b) ? a : b;
}

// Yükseklik hesaplama fonksiyonu: 
int getHeight(struct Node* n) {
    if(n==NULL) {
        return 0;
    }
    return n->height;
}

// AVL Tree düğüm oluşturma:
struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node != NULL) {
        node->key = key; 
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
    }
    return node;
}

// Denge faktörünü hesaplama: 
int getBalanceFactor(struct Node* n) {
    if(n==NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right); 
}

// Sağa döndürme işlemi:
struct Node* rightRotate(struct Node* x) {
    struct Node *temp = x->left;
    x->left = temp->right;
    temp->right = x;
    
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

    return temp;

}

// Sola döndürme işlemi:
struct Node* leftRotate(struct Node* y) {
    struct Node *temp = y->right;
    y->right = temp->left;
    temp->left = y;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    temp->height = max(getHeight(temp->right), getHeight(temp->left)) + 1;

    return temp;
}

// AVL Tree'ye düğüm ekleme:
struct Node* insert(struct Node* node, int key) {
    if(node == NULL) 
        return createNode(key);
        

    if(key < node->key) 
        node->left = insert(node->left, key);
    
    else if(key > node->key) 
        node->right = insert(node->right, key);
    else
        return node;

    // yüksekliği güncelledik:
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // denge kontrolü yaptık:
    int bf = getBalanceFactor(node);

    // Left - Left Case
    if(bf > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    // Left - Right Case 
    if(bf > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right - Right Case
    if(bf < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    // Right - Left Case
    if(bf < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
    
}

// AVL Tree'den düğüm silme:
struct Node* deleteNode(struct Node* node, int key) {
    if(node == NULL)
        return node;

    if(key < node->key)
        node->left = deleteNode(node->left, key);
    else if(key > node->key)
        node->right = deleteNode(node->right, key);
    else {
        if((node->left == NULL) || (node->right == NULL)) {

            struct Node* temp = node->left ? node->left : node->right;

            if(temp == NULL) {
                temp = node;
                node = NULL;
            }
            else 
                *node = *temp;

            free(temp);
        }
        else {
            struct Node* temp = node->right;
            while(temp->left != NULL) 
                temp = temp->left;
            
            node->key = temp->key;
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (node == NULL)
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // denge kontrolü yaptık:
    int bf = getBalanceFactor(node);

    // denge kaybına göre rotasyon yapılır: 
    if (bf > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    if (bf > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (bf < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    if (bf < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node* root) {
    if(root != NULL) {
        preOrder(root->left);
        printf("%d ", root->key);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
                                               
    root = insert(root, 10);                      
    root = insert(root, 30);                      
    root = insert(root, 20);                      
    root = insert(root, 40);
    root = insert(root, 50);

    printf("AVL Tree: ");
    preOrder(root);
    root = deleteNode(root, 40);
    printf("\nPreorder after deletion: ");
    preOrder(root);
    printf("\nHeight = %d", root->height);
    return 0;
}