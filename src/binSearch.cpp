/**
 * @file binSearch.cpp
 * @brief This is a demonstration of binary search trees.
 * @details This is a demo from CPTR 227 class
 * @author Seth McNeill
 * @date 2021 March 02
 * 
 */

#include <iostream>
#include <queue>
using namespace std;

/**
 * Binary Tree Node
 * 
 * This is from Open Data Structures in C++ by Pat Morin
 */
class BTNode {
private:
  char objName; // The object number created
  static char name;
  int payload; // Data that is stored in the node

public:
  BTNode* left;
  BTNode* right;
  BTNode* parent;

  /**
   * BTNode constructor
   */
  BTNode(int dataVal) {
      left = NULL;
      right = NULL;
      parent = NULL;
      objName = name++;
      payload = dataVal;
      cout << "name = " << name << ", payload = " << payload << endl;
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
  int nodeData() {
      return(payload);
  }

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
    cout << "newNode " << newNode->nodeName() << ":" << newNode->nodeData() << endl;
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
/*
    for(int ii = 1; ii < 7; ii++) {
        addNode(root, ii);
    }
    addNode(root, 3);
*/
    addNode(root, 7);
    addNode(root, 3);
    addNode(root, 1);
    addNode(root, 5);
    addNode(root, 11);
    addNode(root, 4);
    addNode(root, 9);
    addNode(root, 6);
    addNode(root, 8);
    addNode(root, 13);
    addNode(root, 12);
    addNode(root, 14);
    return root;
}

/**
 * Prints out a representtation of a binary search tree
 * 
 * This is particularly interesting since it requires 
 * traversing the tree in a breadth-first manner rather than
 * a depth-first manner as we have been up until now.
 * Some good references:
 * https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
 * 
 * @param rootNode is a pointer to the root node
 */
void printTree(BTNode* rootNode) {
    queue<BTNode*> todo; // queue of nodes left to visit
    BTNode* cur;   // current node
    BTNode* last;  // last node
    queue<int> depth; // keeps track of the depth of each node
    int curDepth; // depth of the previous node
    int prevDepth; // depth of the previous node
    todo.push(rootNode); // start the queue with the rootNode
    depth.push(0); // root node is at depth 0

    while(!todo.empty()) {
        cur = todo.front(); // collect the first node in the queue
        curDepth = depth.front();
        if(curDepth > prevDepth) { // next row of nodes encountered
            cout << endl;
        }
        // print the current node
        cout << curDepth << '-' << cur->nodeName() << ":" << cur->nodeData() << '\t';
        // add children to the list
        if(cur->left != NULL) {
            todo.push(cur->left);
            depth.push(curDepth + 1);
        }
        if(cur->right != NULL) {
            todo.push(cur->right);
            depth.push(curDepth + 1);
        }
        // remove the first node from the queue
        todo.pop(); 
        prevDepth = depth.front();
        depth.pop();
    }
    cout << endl;
}


/**
 * Print a binary tree
 * 
 * This example is modified from:
 * https://stackoverflow.com/a/51730733
 * 
 * @param prefix is a string of characters to start the line with
 * @param node is the current node being printed
 * @param isLeft bool true if the node is a left node
 */
void printBT(const string& prefix, BTNode* node, bool isLeft)
{
    if( node != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "--" );

        // print the value of the node
        cout << node->nodeName() << ':' << node->nodeData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

/**
 * An overload to simplify calling printBT
 * 
 * @param node is the root node of the tree to be printed
 */
void printBT(BTNode* node)
{
    printBT("", node, false);
}

int main(int, char**) {
    BTNode* rootNode = new BTNode(0); // pointer to the root node
    genExampleTree(rootNode);
    //printTree(rootNode);
    printBT(rootNode);
}
