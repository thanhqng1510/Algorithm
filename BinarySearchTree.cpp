#include <iostream>
#include <algorithm>


struct node {
    int data;
    node* left, * right;
};

void free(node*& root) {
    if (!root)
        return;
    
    free(root->left);
    free(root->right);
    delete root;
    root = nullptr;
}

void insert(node*& root, int data) {
    if (!root) {
        root = new node();
        root->data = data;
        root->left = root->right = nullptr;
    }
    else if (root->data == data)
        return;
    else if (data < root->data)
        insert(root->left, data);
    else
        insert(root->right, data);
}

node* search(node* root, int data) {
    if (!root)
        return nullptr;
    
    if (root->data == data)
        return root;
    else if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void preorder(node* root) {
    if (!root)
        return;
    
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root) {
    if (!root)
        return;
    
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(node* root) {
    if (!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

node* leftMostNode(node* root) {
    while (root->left)
        root = root->left;
    return root;
}

node* remove(node*& root, int data) {
    if (!root)
        return nullptr;
    
    if (data < root->data) {
        root->left = remove(root->left, data);
        return root;
    }
    else if (data > root->data) {
        root->right = remove(root->right, data);
        return root;
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
            return root;
        }
        else if (!root->right) {
            node* new_root = root->left;
            delete root;
            return new_root;
        }
        else if (!root->left) {
            node* new_root = root->right;
            delete root;
            return new_root;
        }
        else {
            root->data = leftMostNode(root->right)->data;
            root->right = remove(root->right, root->data);
            return root;
        }
    }
}


int main() {
    node* root = nullptr;
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);

    inorder(root);
    std::cout << "\n";
    
    remove(root, 2);
    inorder(root);
    std::cout << "\n";
    
    remove(root, 3);
    inorder(root);
    std::cout << "\n";
    
    remove(root, 7);
    inorder(root);
    std::cout << "\n";

    free(root);
}
