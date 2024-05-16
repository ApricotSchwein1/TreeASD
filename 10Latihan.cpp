#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

struct Node {
    int data;
    Node *anakKiri;
    Node *anakKanan;
    Node(int dt);
};

struct Tree {
    Node *root;
    Tree();
    void sisipDtNode(int);
    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();
    int countNodes(); // method untuk menghitung jumlah node
    int countLeaves(); // method untuk menghitung jumlah daun
    int getHeight(); // method untuk menghitung tinggi pohon
private:
    void sisipDt(Node*, int);
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    int count(Node*); 
    int countLeafNodes(Node*);
    int height(Node*); 
};

Node::Node(int dt) : data(dt), anakKiri(nullptr), anakKanan(nullptr) {}

Tree::Tree() : root(nullptr) {}

void Tree::sisipDtNode(int dt) {
    if (root == nullptr) {
        root = new Node(dt);
    } else {
        sisipDt(root, dt);
    }
}

void Tree::sisipDt(Node* node, int dt) {
    if (dt < node->data) {
        if (node->anakKiri == nullptr) {
            node->anakKiri = new Node(dt);
        } else {
            sisipDt(node->anakKiri, dt);
        }
    } else {
        if (node->anakKanan == nullptr) {
            node->anakKanan = new Node(dt);
        } else {
            sisipDt(node->anakKanan, dt);
        }
    }
}

void Tree::preorderTraversal() {
    preorder(root);
    cout << endl;
}

void Tree::inorderTraversal() {
    inorder(root);
    cout << endl;
}

void Tree::postorderTraversal() {
    postorder(root);
    cout << endl;
}

void Tree::preorder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->anakKiri);
    preorder(node->anakKanan);
}

void Tree::inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->anakKiri);
    cout << node->data << " ";
    inorder(node->anakKanan);
}

void Tree::postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->anakKiri);
    postorder(node->anakKanan);
    cout << node->data << " ";
}

int Tree::countNodes() {
    return count(root);
}

int Tree::count(Node* node) {
    if (node == nullptr) return 0;
    return 1 + count(node->anakKiri) + count(node->anakKanan);
}

int Tree::countLeaves() {
    return countLeafNodes(root);
}

int Tree::countLeafNodes(Node* node) {
    if (node == nullptr) return 0;
    if (node->anakKiri == nullptr && node->anakKanan == nullptr) return 1;
    return countLeafNodes(node->anakKiri) + countLeafNodes(node->anakKanan);
}

int Tree::getHeight() {
    return height(root);
}

int Tree::height(Node* node) {
    if (node == nullptr) return 0;
    int leftHeight = height(node->anakKiri);
    int rightHeight = height(node->anakKanan);
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Tree *tree = new Tree();
    int nilai;
    cout << "Sisip nilai data berikut: " << endl;
    // sisip data 10 bilangan acak dari 0-99 ke dalam tree
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        nilai = rand() % 1000;
        cout << nilai << " ";
        tree->sisipDtNode(nilai);
    }
    cout << "\n\nPreorder Traversal" << endl;
    tree->preorderTraversal();
    cout << "\n\nInorder Traversal" << endl;
    tree->inorderTraversal();
    cout << "\n\nPostorder Traversal" << endl;
    tree->postorderTraversal();
    cout << "\n\nJumlah node dalam tree: " << tree->countNodes() << endl;
    cout << "Jumlah daun dalam tree: " << tree->countLeaves() << endl;
    cout << "Tinggi tree: " << tree->getHeight() << endl;
    return 0;
}
