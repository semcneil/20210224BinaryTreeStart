/**
 * @file main.cpp
 * @brief This is a demonstration of simple binary trees
 * @details This is a demo from CPTR 227 class
 * @author Seth McNeill
 * @date 2021 February 24
 * 
 */

#include <iostream>
using namespace std;

/**
 * Binary Tree Node
 * 
 * This is from Open Data Structures in C++ by Pat Morin
 */
class BTNode {
public:
  BTNode* left;
  BTNode* right;
  BTNode* parent;

  /**
   * BTNode constructor
   */
  BTNode() {
      left = NULL;
      right = NULL;
      parent = NULL;
  }
};

/**
 * This generates a simple tree to play with
 * 
 * It is a bit of a hack.
 */
BTNode* genExampleTree(BTNode* root) {
    BTNode* one = new BTNode();
    BTNode* two = new BTNode();
    BTNode* three = new BTNode();
    BTNode* four = new BTNode();
    BTNode* five = new BTNode();
    BTNode* six = new BTNode();
    cout << "Created the nodes" << endl;
    root->left = one;
    cout << "Added root->left" << endl;
    one->parent = root;
    root->right = two;
    two->parent = root;
    two->left = three;
    three->parent = two;
    two->right = four;
    four->parent = two;
    one->left = five;
    five->parent = one;
    five->left = six;
    six->parent = five;
    return root;
}

int main(int, char**) {
    BTNode* rootNode; // pointer to the root node
    genExampleTree(rootNode);
    cout << "Hello, world! Binary Trees\n";
}
