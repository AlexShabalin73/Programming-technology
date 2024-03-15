#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void insert(Node* &root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }

    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}

bool search(Node* root, int val) {
    if (root == NULL) {
        return false;
    }

    if (root->data == val) {
        return true;
    }

    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    Node* root = NULL;
    insert(root, 4);
    insert(root, 2);
    insert(root, 5);
    insert(root, 1);
    insert(root, 3);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Search for 3: " << search(root, 3) << endl;
    cout << "Search for 6: " << search(root, 6) << endl;

    return 0;
}
