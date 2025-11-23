#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Basit bir Binary Search Tree (BST) örneği */

/* Düğüm yapısı */
typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

/* Yeni düğüm oluştur */
Node *createNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Bellek ayrılamadı!\n");
        exit(1);
    }
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

/* BST'ye ekleme */
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

/* Inorder (Sıralı yazdırma) */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

/* Preorder */
void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* Postorder */
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* Arama */
bool search(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* En küçük değeri bulma */
Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

/* Silme */
Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

/* Ağacı silelim */
void freeTree(Node *root)
{
    if (!root)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* Test */
int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("40 bulundu mu? %s\n", search(root, 40) ? "Evet" : "Hayır");

    printf("\n--- 50 siliniyor ---\n");
    root = deleteNode(root, 50);

    printf("Yeni Inorder: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
