#include <iostream>

enum Color {RED, BLACK};

template <typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;
    Color color;

    Node(T d, Color c): data(d), left(NULL), right(NULL), parent(NULL), color(c) {}
};

template <typename T>
class RedBlackTree
{
private:
    Node<T>* root;

    void rotateLeft(Node<T>* node);
    void rotateRight(Node<T>* node);
    void fixViolation(Node<T>* node);

public:
    RedBlackTree(): root(NULL) {}

    void insert(T data);
    void print();
};

template <typename T>
void RedBlackTree<T>::rotateLeft(Node<T>* node)
{
    Node<T>* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != NULL)
    {
        node->right->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == NULL)
    {
        root = rightChild;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = rightChild;
    }
    else
    {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

template <typename T>
void RedBlackTree<T>::rotateRight(Node<T>* node)
{
    Node<T>* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != NULL)
    {
        node->left->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == NULL)
    {
        root = leftChild;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = leftChild;
    }
    else
    {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

template <typename T>
void RedBlackTree<T>::fixViolation(Node<T>* node)
{
    Node<T>* parent = NULL;
    Node<T>* grandParent = NULL;

    while ((node != root) && (node->color != BLACK) && (node->parent->color == RED))
    {
        parent = node->parent;
        grandParent = node->parent->parent;

        if (parent == grandParent->left)
        {
            Node<T>* uncle = grandParent->right;

            if (uncle != NULL && uncle->color == RED)
            {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            }
            else
            {
                if (node == parent->right)
                {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandParent);
                std::swap(parent->color, grandParent->color);
                node = parent;
            }
        }
        else
        {
            Node<T>* uncle = grandParent->left;

            if ((uncle != NULL) && (uncle->color == RED))
            {
                grandParent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandParent;
            }
            else
            {
                if (node == parent->left)
                {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(grandParent);
                std::swap(parent->color, grandParent->color);
                node = parent;
            }
        }
    }
    root->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::insert(T data)
{
    Node<T>* newNode = new Node<T>(data, RED);
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        Node<T>* temp = root;
        Node<T>* parent = NULL;

        while (temp != NULL)
        {
            parent = temp;

            if (newNode->data < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        newNode->parent = parent;

        if (newNode->data < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
    fixViolation(newNode);
}
template <typename T>
void printHelper(Node<T>* root, std::string indent, bool last)
{
    if (root != NULL)
    {
        std::cout << indent;
        if (last)
        {
            std::cout << "R----";
            indent += "   ";
        }
        else
        {
            std::cout << "L----";
            indent += "|  ";
        }

    std::cout << root->data << "(" << ((root->color == RED) ? "RED" : "BLACK") << ")" << std::endl;
    printHelper(root->left, indent, false);
    printHelper(root->right, indent, true);
    }
}
template <typename T>
void RedBlackTree<T>::print()
{
    if (root != NULL)
    {
    printHelper(root, "", true);
    }
}

int main()
{
    RedBlackTree<int> rbTree;
    rbTree.insert(7);
    rbTree.insert(6);
    rbTree.insert(5);
    rbTree.insert(4);
    rbTree.insert(3);
    rbTree.insert(2);
    rbTree.insert(1);
    rbTree.print();
    return 0;
}
