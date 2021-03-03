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
    int nodeData() {
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
    //int inData[] = {1,2,3,4,5,6,7};
    int inData[] = {4,6,5,7,2,1,3};
    int classData[] = {1,3,4,5,6,7,8,9,11,12,13,14};
    for(int ii = 0; ii < 7; ii++) {
        addNode(root, inData[ii]);
    }
    return root;
}

/**
 * Prints out a representtation of a binary search tree
 * 
 * @param rootNode is a pointer to the root node
 */
void printTree(BTNode* rootNode) {
    queue<BTNode*> todo; // the queue of nodes left to visit
    BTNode* cur; // current node
    BTNode* prev; // The previous node

    todo.push(rootNode);

    while(!todo.empty()) {
        cur = todo.front();
        // Print current node
        cout << cur->nodeName() << ':' << cur->nodeData() << '\t';
        // add cur->left to queue
        if(cur->left != NULL) {
            todo.push(cur->left);
        }
        // add cur->right to queue
        if(cur->right != NULL) {
            todo.push(cur->right);
        }
        // remove cur from queue
        todo.pop();
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

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        //cout << node->nodeName() << ':' << node->nodeData() << std::endl;
        cout << node->nodeData() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
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
    printBT(rootNode);
    printTree(rootNode);
}
