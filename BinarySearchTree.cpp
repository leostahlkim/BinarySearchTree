/*
 * BinarySearchTree.cpp
 * Name: Leo Kim
 * Date: 3/28/2022
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>
#include <algorithm> // for max function

#include "BinarySearchTree.h"

using namespace std;

/*
 * name:      BinarySearchTree default constructor
 * purpose:   initialize an empty BinarySearchTree
 * arguments: none
 * returns:   none
 * effects:   root to nullptr
 */
BinarySearchTree::BinarySearchTree()
{
        root = nullptr;
}

/*
 * name:      BinarySearchTree destructor
 * purpose:   free memory associated with the BinarySearchTree
 * arguments: none
 * returns:   none
 * effects:   call post_order_delete, root to nullptr
 */
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}

/*
 * name:      post_order_delete
 * purpose:   free memory associated with a BinarySearchTree
 * arguments: none
 * returns:   none
 * effects:   moves through tree and removes every node in post order
 */
void BinarySearchTree::post_order_delete(Node *node)
{
        if (node != nullptr) {
                post_order_delete(node->left);
                post_order_delete(node->right);
                delete node;
        }
}

/*
 * name:      BinarySearchTree copy constructor
 * purpose:   Create a BST that is a deepcopy of the given BST
 * arguments: BST being copied
 * returns:   none
 * effects:   calls pre_order_copy and sets root equal to the result
 */
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

/*
 * name:      BinarySearchTree assignment overload operator
 * purpose:   Deepcopy the righthand BST to the lefthand BST
 * arguments: BST being copied
 * returns:   The newly copied lefthand BST
 * effects:   recycles previous BST memory and copies new BST
 */
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // Check to see if the assignment operator is assigning two equivalent BSTs
        if (this == &source) {
                return *this;
        }

        post_order_delete(this->root);
        this->root = pre_order_copy(source.root);
        
        return *this;
}

/*
 * name:      pre_order_copy
 * purpose:   Move through a BST in pre order and copy every node
 * arguments: root of tree being copied
 * returns:   Root of the copied tree
 * effects:   Allocates memory for the newly copied tree
 */
BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        if (node != nullptr) {
                Node *copy = new Node;
                copy->data = node->data;
                copy->count = node->count;
                copy->left = pre_order_copy(node->left);
                copy->right = pre_order_copy(node->right);
                return copy;
        }

        return nullptr;
}

/*
 * name:      find_min (public)
 * purpose:   find the minimum value node in a BST
 * arguments: none
 * returns:   an int of the minimum value in the BST
 * effects:   calls the private find_min helper function
 */
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}

/*
 * name:      find_min (private)
 * purpose:   find the minimum value node in a BST
 * arguments: root of the BST
 * returns:   a node pointer to the minimum value node
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{
        if (node == nullptr) {
                return nullptr;
        } if (node->left == nullptr) {
                return node;
        }
        
        return find_min(node->left);
}

/*
 * name:      find_max (public)
 * purpose:   find the maximum value node in a BST
 * arguments: none
 * returns:   an int of the maximum value in the BST
 * effects:   calls the private find_max helper function
 */
int BinarySearchTree::find_max() const
{
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MIN

        return find_max(root)->data;
}

/*
 * name:      find_max (private)
 * purpose:   find the maximum value node in a BST
 * arguments: root of the BST
 * returns:   a node pointer to the maximum value node
 * effects:   none
 */
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        if (node == nullptr) {
                return nullptr;
        } if (node->right == nullptr) {
                return node;
        }

        return find_max(node->right);
}

/*
 * name:      contains (public)
 * purpose:   find if the BST contains a given value
 * arguments: int of the value
 * returns:   a boolean for if the BST contains the value
 * effects:   calls the contains private helped function
 */
bool BinarySearchTree::contains(int value) const
{
        return contains(root, value);
}

/*
 * name:      contains (private)
 * purpose:   find if the BST contains a given value
 * arguments: a node pointer and an int of the value
 * returns:   a boolean for if the BST contains the value
 * effects:   none
 */
bool BinarySearchTree::contains(Node *node, int value) const
{
        // Use the BST invariant to move through the tree
        if (node == nullptr) {
                return false;
        } if (node->data == value) {
                return true;
        } if (value < node->data) {

                return contains(node->left, value);

        }

        return contains(node->right, value);
}

/*
 * name:      insert (public)
 * purpose:   insert a given value into the BST
 * arguments: int of the value
 * returns:   none
 * effects:   calls the insert private helped function
 */
void BinarySearchTree::insert(int value)
{
        insert(root, value);
}

/*
 * name:      insert (private)
 * purpose:   insert a given value into the BST
 * arguments: a node pointer and int of the value
 * returns:   none
 * effects:   adds the given value to the BST
 */
void BinarySearchTree::insert(Node *node, int value)
{       
        if (node == nullptr) {
                root = newNode(value);
        } else if (node->data == value) {
                node->count++;
        } 
        // Move left
        else if (value < node->data) {
                if (node->left == nullptr) {
                        node->left = newNode(value);
                } else {
                        insert(node->left, value);
                }
        } 
        // Move right
        else if (value > node->data) {;
                if (node->right == nullptr) {
                        node->right = newNode(value);
                } else {
                        insert(node->right, value);
                }
        }
}

/*
 * name:      remove (public)
 * purpose:   remove the node corresponding to a given value
 * arguments: int of the value
 * returns:   none
 * effects:   calls the private remove helper function
 */
bool BinarySearchTree::remove(int value)
{
        return remove(root, nullptr, value);
}

/*
 * name:      remove (private)
 * purpose:   remove the node corresponding to a given value
 * arguments: int of the value and node pointers for node being removed and its
 *            parent
 * returns:   true if a node was removed and false if not
 * effects:   removes the node if it is in the BST
 */
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        if (node == nullptr) {
                return false;
        } if (node->data == value) {
                node->count--;
                if (node->count < 1) {
                        if (node == root) {
                                removeRoot();
                        }
                        else if (node->right == nullptr) {
                                adopt(node->left, node, parent);
                        } else if (node->left == nullptr) {
                                adopt(node->right, node, parent);
                        } else {
                                twoChildrenRemove(node, parent);
                        }

                        delete node;
                        return true;
                }
        } if (value < node->data) {
                return remove(node->left, node, value);

        } if (value > node->data) {
                return remove(node->right, node, value);
        }
        return false;
}

/*
 * name:      tree_height (public)
 * purpose:   find the height of the given tree
 * arguments: none
 * returns:   an int of the tree's height
 * effects:   calls the private tree_height helper function
 */
int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}

/*
 * name:      tree_height (private)
 * purpose:   find the height of the given tree
 * arguments: a node pointer
 * returns:   an int of the tree's height
 * effects:   none
 */
int BinarySearchTree::tree_height(Node *node) const
{
        if (node == nullptr) {
                return -1;
        } if (node->left == nullptr and node->right == nullptr) {
                return 0;
        } if (node->left == nullptr) {
                return 1 + tree_height(node->right);
        } if (node->right == nullptr) {
                return 1 + tree_height(node->left);
        } else {
                return 1 + 
                max(tree_height(node->left), tree_height(node->right));
        }
}

/*
 * name:      node_count (public)
 * purpose:   find the total number of nodes in the given tree
 * arguments: none
 * returns:   an int of the total number of nodes
 * effects:   calls the private node_count helper function
 */
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

/*
 * name:      node_count (private)
 * purpose:   find the total number of nodes in the given tree
 * arguments: a node pointer
 * returns:   an int of the total number of nodes
 * effects:   none
 */
int BinarySearchTree::node_count(Node *node) const
{
        if (node == nullptr) {
                return 0;
        } if (node->right == nullptr) {
                if (node->left == nullptr) {
                        return 1;
                }
                return 1 + node_count(node->left);
        } if (node->left == nullptr) {
                return 1 + node_count(node->right);
        }

        return 1 + node_count(node->left) + node_count(node->right);
}

/*
 * name:      count_total (public)
 * purpose:   find the value of all the numbers in the BST
 * arguments: none
 * returns:   an int of the total value
 * effects:   calls the private count_total helper function
 */
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

/*
 * name:      count_total (private)
 * purpose:   find the value of all the numbers in the BST
 * arguments: a node pointer
 * returns:   an int of the total value
 * effects:   none
 */
int BinarySearchTree::count_total(Node *node) const
{
        if (node == nullptr) {
                return 0;
        } 
        int node_total = (node->data * node->count);
        if (node->right == nullptr) {
                if (node->left == nullptr) {
                        return node_total;
                }
                return node_total + count_total(node->left);
        } if (node->left == nullptr) {
                return node_total + count_total(node->right);
        }

        return node_total + count_total(node->left) + count_total(node->right);
}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}

/*
 * name:      newNode
 * purpose:   create a new node on the heap
 * arguments: value of the node
 * returns:   pointer to the newly created node
 * effects:   creates a new node on the heap
 */BinarySearchTree::Node *BinarySearchTree::newNode(int value) {
        Node *temp = new Node;
        temp->count = 1;
        temp->data = value;
        temp->left = nullptr;
        temp->right = nullptr;
        return temp;
}

/*
 * name:      removeRoot
 * purpose:   remove the node at the root of the BST
 * arguments: none
 * returns:   none
 * effects:   removes the node at the root of the BST
 */
void BinarySearchTree::removeRoot() {
        if (node_count() == 1) {
                root = nullptr;
        } else if (root->left == nullptr) {
                root = root->right;
        } else if (root->right == nullptr) {
                root = root->left;
        } else {
                twoChildrenRemove(root, nullptr);
        }
}

/*
 * name:      twoChildrenRemove
 * purpose:   remove a node with two children
 * arguments: node pointers to the node being removed and its parent
 * returns:   none
 * effects:   removes the given node
 */
void BinarySearchTree::twoChildrenRemove(Node *node, Node *parent) {
        Node *rightMin = find_min(node->right);
        Node *rightMinParent = find_parent(node, rightMin);

        if (parent != nullptr) {
                adopt(rightMin, node, parent);
        } else {
                root = rightMin;
        }
               
        if (rightMinParent != node) {
                
                if (rightMin->right != nullptr) {
                        rightMinParent->left = rightMin->right;
                } else {
                        rightMinParent->left = nullptr;
                }

                rightMin->right = node->right;
        }

        rightMin->left = node->left;
}

/*
 * name:      adopt
 * purpose:   assign a parent node a new child
 * arguments: pointers to the parent node, new child, and old child
 * returns:   none
 * effects:   assigns the parent a new child
 */
void BinarySearchTree::adopt(Node *newChild, Node *oldChild, Node *parent) {
        if (parent->data < oldChild->data) {
                parent->right = newChild;
        } else {
                parent->left = newChild;
        }
}