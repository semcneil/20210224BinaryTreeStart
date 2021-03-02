/**
 * @file binSearch.cpp
 * @brief This is a demonstration of binary search trees.
 * @details This is a demo from CPTR 227 class
 * @author Seth McNeill
 * @date 2021 March 02
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
  BTNode(int dataVal) {
      cout << "name = " << name << endl;
      left = NULL;
      right = NULL;
      parent = NULL;
      objName = name++;
      data = dataVal;
  }

    /**
     * This reports the node's name
     */
  char nodeName() {
      return(objName);
  }

    /**
     * This reports the node's data
     */
  char nodeData() {
      return(data);
  }

private:
  char objName; // The object number created
  static char name;
  int data; // Data that is stored in the node
};


char BTNode::name = 'A'; // initialize static variable

/**
 * This function adds a node to a binary search tree.
 * 
 * @param rootNode is the pointer to the tree's root node
 * @param n is the node to add
 * @returns pointer to rootNode if successful, NULL otherwise
 */
BTNode* addNode(BTNode* rootNode, BTNode* n) {
    BTNode* prev = NULL;
    BTNode* w = rootNode;
    if(rootNode == NULL) { // starting an empty tree
        rootNode = n;
    } else {
        // Find the node n belongs under, prev, n's new parent
        while(w != NULL) {
            prev = w;
            if(n->nodeData() < w->nodeData()){
                w = w->left;
            } else if(n->nodeData() > w->nodeData()) {
                w = w->right;
            } else { // data already in the tree
                return(NULL);
            }
        }
        // now prev should contain the node that should be n's parent
        // Add n to prev
        if(n->nodeData() < prev->nodeData()) {
            prev->left = n;
        } else {
            prev->right = n;
        }
    }
    return(rootNode);
}


/**
 * Adds a new node with the passed data value
 * 
 * @param rootNode pointer to root node
 * @param dataval an integer for the new node's data
 * @returns pointer to root node or NULL if not successful
 */
BTNode* addNode(BTNode* rootNode, int dataval) {
    BTNode* newNode = new BTNode(dataval);
    if(addNode(rootNode, newNode) == NULL) {
        cout << dataval << " already in tree" << endl;
    } else {
        cout << dataval << " succesfully added" << endl;
    }
    return(rootNode);
}

/**
 * This generates a simple tree to play with
 * 
 * It is a bit of a hack.
 */
BTNode* genExampleTree(BTNode* root) {
/*    BTNode* one = new BTNode(1);
    BTNode* two = new BTNode(2);
    BTNode* three = new BTNode(3);
    BTNode* four = new BTNode(4);
    BTNode* five = new BTNode(5);
    BTNode* six = new BTNode(6);
    cout << "Created the nodes" << endl;
    addNode(root, one);
    addNode(root, two);
    addNode(root, three);
    addNode(root, four);
    addNode(root, five);
    addNode(root, six);
    */
    for(int ii = 1; ii < 7; ii++) {
        addNode(root, ii);
    }
    addNode(root, 3);
    return root;
}

/**
 * Prints out a representtation of a binary search tree
 * 
 * @param rootNode is a pointer to the root node
 */
void printTree(BTNode* rootNode) {

}


int main(int, char**) {
    BTNode* rootNode = new BTNode(0); // pointer to the root node
    genExampleTree(rootNode);
}
