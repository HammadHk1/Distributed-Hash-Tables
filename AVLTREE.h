#pragma once
#include<iostream>
#include <string>
using namespace std;
struct AVL_Node {
    string key, value, filepath;
    int line, line_no;
    AVL_Node* left;
    AVL_Node* right;
    AVL_Node() {//Default constructor for AVL NODE....
        key = value = filepath = " ";
        line = 0;
        left = right = NULL;
    }
};
class AVL {
private:
    AVL_Node* root;
    AVL_Node* Insert_to_Tree(AVL_Node* tree, string key, string value, string filepath, int line, int line_no) {
        if (tree == NULL) {
            AVL_Node* node = new AVL_Node;
            node->key = key;
            node->filepath = filepath;
            node->value = value;
            node->line = line;
            node->line_no = line_no;
            node->left = NULL;
            node->right = NULL;
            return node;
            return tree;
        }
        else if (line < tree->line) {
            tree->left = Insert_to_Tree(tree->left, key, value, filepath, line, line_no);
            tree = balance(tree);
        }
        else if (line >= tree->line) {
            tree->right = Insert_to_Tree(tree->right, key, value, filepath, line, line_no);
            tree = balance(tree);
        }

        return tree;
    }

public:
    AVL() {
        root = NULL;
    }
    AVL_Node* getroot() {
        return root;
    }
    void Insert(string key, string value, string filepath, int line, int line_no) {//Function overloading to get root....
        root = Insert_to_Tree(root, key, value, filepath, line, line_no);
        return;
    }
    int height(AVL_Node* tree) {
        int h = 0;
        if (tree != NULL) {
            int l_height = height(tree->left);
            int r_height = height(tree->right);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }
    int balance_factor(AVL_Node* tree) {
        int l_height = height(tree->left);
        int r_height = height(tree->right);
        return l_height - r_height;
    }
    AVL_Node* Double_right_rotation(AVL_Node* temp) {
        AVL_Node* tree;
        tree = temp->right;
        temp->right = tree->left;
        tree->left = temp;
        return tree;
    }
    AVL_Node* Double_left_rotation(AVL_Node* temp) {
        AVL_Node* tree;
        tree = temp->left;
        temp->left = tree->right;
        tree->right = temp;
        return tree;
    }
    AVL_Node* Left_Right_rotation(AVL_Node* temp) {
        AVL_Node* tree;
        tree = temp->left;
        temp->left = Double_right_rotation(tree);
        return Double_left_rotation(temp);
    }
    AVL_Node* Right_Left_rotation(AVL_Node* temp) {
        AVL_Node* tree;
        tree = temp->right;
        temp->right = Double_left_rotation(tree);
        return Double_right_rotation(temp);
    }
    AVL_Node* balance(AVL_Node* tree) {
        int bf = balance_factor(tree);
        if (bf > 1) {
            if (balance_factor(tree->left) > 0)
                tree = Double_left_rotation(tree);
            else
                tree = Left_Right_rotation(tree);
        }
        else if (bf < -1) {
            if (balance_factor(tree->right) > 0)
                tree = Right_Left_rotation(tree);
            else
                tree = Double_right_rotation(tree);
        }
        return tree;
    }

    void inorder(AVL_Node* tree) {
        if (tree == NULL)
            return;
        inorder(tree->left);
        cout << "(" << tree->key << "->" << tree->value << "->" << tree->filepath << ")" << endl;
        inorder(tree->right);
    }
    void preorder(AVL_Node* tree) {
        if (tree == NULL)
            return;
        cout << tree->key << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
    void postorder(AVL_Node* tree) {
        if (tree == NULL)
            return;
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->key << " ";
    }
    AVL_Node* findMin(AVL_Node* tree) {
        if (tree == NULL) return NULL;
        else if (tree->left == NULL) return tree; // if element traverse on max left then return
        else return findMin(tree->left); // or recursively traverse max left
    }
    AVL_Node* findMax(AVL_Node* tree) {
        if (tree == NULL) return NULL;
        else if (tree->right == NULL) return tree;
        else return findMax(tree->right);
    }
    AVL_Node* Delete_Leaf(AVL_Node* tree, int x) {
        
    }
    bool FIND_KEY(AVL_Node* tree,string key) {
        if (tree == NULL)
            return false;
        if (tree->key == key) {
            return true;
        }
        bool h;
        h = FIND_KEY(tree->left,key);
        if (h == true) {
            return true;
        }
        //cout << "(" << tree->key << "->" << tree->value << "->" << tree->filepath << ")" << " ";
        h=FIND_KEY(tree->right,key);

    }
};






































