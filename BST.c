#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    int val;
    struct Node* right;
} Node;

void createBST(Node** p, int x) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->val = x;
    *p = temp;
}

void insertBST(Node** root, int x) {
    if (*root == NULL) {
        createBST(root, x);
        return;
    }
    if (x > (*root)->val) {
        insertBST(&((*root)->right), x);
    }
    else {
        insertBST(&((*root)->left), x);
    }
}

Node* getSucc(Node* root) {
    root = root->right;
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteBST(Node** root, int x) {
    if (*root == NULL) {
        return *root;
    }
    if (x > (*root)->val) {
        (*root)->right = deleteBST(&((*root)->right), x);
    }
    else if (x < (*root)->val) {
        (*root)->left = deleteBST(&((*root)->left), x);
    } else {
        if ((*root)->left == NULL) {
            Node* temp = (*root)->right;
            free((*root));
            return temp;
        } else if ((*root)->right == NULL) {
            Node* temp = (*root)->left;
            free((*root));
            return temp;
        } else {
            Node* getSuccessor = getSucc(*root);
            (*root)->val = getSuccessor->val;
            (*root)->right = deleteBST(&((*root)->right), getSuccessor->val);
        }
    }
    return *root;
}

void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->val);
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->val);
    }
}

int main() {
    Node* root = NULL;
    int ch;
    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                int x;
                scanf("%d", &x);
                insertBST(&root, x);
                break;
            }
            case 2: {
                int x;
                scanf("%d", &x);
                deleteBST(&root, x);
                break;
            }
            case 3: {
                preOrder(root);
                printf("\n");
                break;
            }
            case 4: {
                inOrder(root);
                printf("\n");
                break;
            }
            case 5: {
                postOrder(root);
                printf("\n");
                break;
            }
            default: {
                exit(0);
            }
        }
    } while (1);
}
