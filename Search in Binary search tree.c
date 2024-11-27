#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *left, *right;
};
struct Node* newnode(int value)
{
struct Node* temp= (struct Node*)malloc(sizeof(struct Node));
temp->data = value;
temp->left = temp->right = NULL;
return temp;
}
struct Node* insertNode(struct Node* node, int value)
{
if (node == NULL) {
return newnode(value);
}
if (value < node->data)
{
node->left = insertNode(node->left, value);
}
else if (value > node->data)
{
node->right = insertNode(node->right, value);
}

return node;
}

struct Node* searchBST(struct Node* root, int val)
{
    if (root == NULL || root->data == val) {
            return root;
        }
        if (val < root->data) {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
}
int main(){
struct Node* root = NULL;
root = insertNode(root, 50);
insertNode(root, 30);
insertNode(root, 20);
insertNode(root, 40);
insertNode(root, 70);
insertNode(root, 60);
insertNode(root, 80);
int value = 100
;
struct Node* result = searchBST(root, value);

if (result != NULL) {
        printf("Found node with value: %d\n", result->data);
    } else {
        printf("Node with value %d not found in the BST.\n", value);
    }
}
