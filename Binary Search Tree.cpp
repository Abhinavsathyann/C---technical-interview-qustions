#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else if (val > root->data)
            root->right = insert(root->right, val);
        return root;
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    Node* search(Node* root, int key) {
        if (!root || root->data == key) return root;
        if (key < root->data)
            return search(root->left, key);
        return search(root->right, key);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;
    int ch, val;
    do {
        cout << "\n1.Insert 2.Display(Inorder) 3.Search 4.Exit: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Enter value: "; cin >> val;
            root = tree.insert(root, val);
        } else if (ch == 2)
            tree.inorder(root);
        else if (ch == 3) {
            cout << "Enter key: "; cin >> val;
            Node* found = tree.search(root, val);
            cout << (found ? "Found" : "Not Found") << endl;
        }
    } while (ch != 4);
}
