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
  int num; // The object number created
  static int count;

  /**
   * BTNode constructor
   */
  BTNode() {
      left = NULL;
      right = NULL;
      parent = NULL;
      num = count++;
  }

    /**
     * This reports the node's number
     */
  int nodeNum() {
      return(num);
  }
};


int BTNode::count = 0; // initialize static variable


/**
 * Calculates the depth (number of steps between node and root) of a node
 * 
 * @param pointer to BTNode to measure the depth of
 * @returns integer count of depth
 */
int depth(BTNode* u) {
    int d = 0; // depth counter
    while(u != NULL) {
        u = u->parent;
        d++;
    }
    return(--d);
}


/**
 * Traverses all the nodes in a binary tree.
 * 
 * @param A pointer to the root node of interest
 */
void traverse(BTNode* rootNode) {
    if(rootNode == NULL) {
        cout << "reached NULL" << endl;
        return;
    }
    cout << "Traversing node " << rootNode->nodeNum() << endl;
    traverse(rootNode->right);
    traverse(rootNode->left);
}


/**
 * Traverses all nodes in a binary tree non-recursively
 * 
 * @param A pointer to the root node of interest
 */
void nonRecursiveTraverse(BTNode* rootNode) {
    BTNode* u = rootNode; // Current node of interest
    BTNode* prev = NULL;  // Previously looked at node
    BTNode* next;         // The next node to look at

    while(u != NULL) {
        cout << "Traversing node " << u->nodeNum() << endl;
        if(prev ==  u->parent) {
            if(u->right != NULL) {
                next = u->right;
            } else if(u->left != NULL) {
                next = u->left;
            } else {
                next = u->parent;
            }
        } else if(prev == u->right) {
            if(u->left != NULL){
                next = u->left;
            } else {
                next = u->parent;
            }
        } else {
            next = u->parent;
        }
        prev = u;
        u = next;
    }
}

/**
 * This calculates the height (max number of steps until leaf node)
 * 
 * @param pointer to a BTNode
 * @returns integer count of height
 */
int height(BTNode* u) {
    if (u == NULL) {
        cout << "Reached NULL end of branch" << endl;
        return(-1);
    }
    cout << "Calculating the height of node " << u->nodeNum() << endl;
    return(1 + max(height(u->left), height(u->right)));
}

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
    cout << "root's number: " << root->nodeNum() << endl;
    cout << "one's number: " << one->nodeNum() << endl;
    cout << "two's number: " << two->nodeNum() << endl;
    cout << "three's number: " << three->nodeNum() << endl;
    cout << "four's number: " << four->nodeNum() << endl;
    cout << "five's number: " << five->nodeNum() << endl;
    cout << "six's number: " << six->nodeNum() << endl;
    cout << "six's depth is " << depth(six) << endl;
    cout << "root's height is " << height(root) << endl;
    return root;
}


int main(int, char**) {
    BTNode* rootNode = new BTNode(); // pointer to the root node
    genExampleTree(rootNode);
    cout << endl << "Traversing the binary tree" << endl;
    traverse(rootNode);
    cout << endl << "Non-recursive traversing" << endl;
    nonRecursiveTraverse(rootNode);
}
