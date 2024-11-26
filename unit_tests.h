/*
 *  unit_tests.h
 *  Name: Leo Kim
 *  Date: 3/28/22
 *
 *  CS 15 Hw3 Binary Search Tree
 *
 *  Purpose: Unit tests to test my program using the unit testing framework.
 */

#include "BinarySearchTree.h"
#include "cassert"
#include "algorithm"
#include "limits"

// First test to create the unit testing framework

void test(){
    assert(true);
}

// TEST GROUP BST Constructor

// Tests to make sure a BST can be created without errors
void constructor_test1() {
    BinarySearchTree tree;
}

// Tests to make sure the BST tree height is -1 when newly created
void constructor_test2() {
    BinarySearchTree tree;
    assert(tree.tree_height() == -1);
}

// Tests to make sure the contains function works on a newly created BST
void constructor_test3() {
    BinarySearchTree tree;
    assert(not tree.contains(0));
    assert(not tree.contains(5));
    assert(not tree.contains(1));
    assert(not tree.contains(29));
}

// Tests to make sure the count function works on a newly created BST
void constructor_test4() {
    BinarySearchTree tree;
    assert(tree.node_count() == 0);
    assert(tree.count_total() == 0);
}

// TEST GROUP Insert

// Tests that the insert function can be called without errors
void insert_test1() {
    BinarySearchTree tree;
    tree.insert(9);
}

// Tests that the insert function is inserting correctly for multiple nodes
void insert_test2() {
    BinarySearchTree tree;
    // insert different values and check they are added
    tree.insert(9);
    assert(tree.contains(9));
    tree.insert(12);
    assert(tree.contains(12));
    tree.insert(923);
    assert(tree.contains(923));
    tree.insert(0);
    assert(tree.contains(0));
    tree.insert(-12);
    assert(tree.contains(-12));

    // check that the tree printed in correct orientation
    tree.print_tree();
}

// Tests that the insert function inserts correctly when called many times
void insert_test3(){
    BinarySearchTree tree;
    for (int i = 0; i < 100; i++) {
        tree.insert(i);
    }

    for (int i = 0; i < 100; i++) {
        assert(tree.contains(i));
    }
}

// TEST GROUP find_min

// Test that find_min returns max possible value on empty tree
void findmin_test1() {
    BinarySearchTree tree;
    assert(tree.find_min() == std::numeric_limits<int>::max());
}

// Test that find_min works on tree with single node
void findmin_test2() {
    BinarySearchTree tree;
    tree.insert(3);
    assert(tree.find_min() == 3);
}

// Test that findmin works on populated tree (down left branch)
void findmin_test3() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(3);
    tree.insert(1);
    assert(tree.find_min() == 1);
}

// Test that findmin works on populated tree (non-straight branch)
void findmin_test4() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(-1);
    tree.insert(4);
    tree.insert(2);
    assert(tree.find_min() == -1);
}

// TEST GROUP find_max

// Test that find_max returns max possible value on empty tree
void findmax_test1() {
    BinarySearchTree tree;
    assert(tree.find_max() == std::numeric_limits<int>::min());
}

// Test that find_max works on tree with single node
void findmax_test2() {
    BinarySearchTree tree;
    tree.insert(3);
    assert(tree.find_max() == 3);
}

// Test that findmax works on populated tree (down right branch)
void findmax_test3() {
    BinarySearchTree tree;
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(2);
    tree.insert(1);
    assert(tree.find_max() == 5);
}

// Test that findmax works on populated tree (non-straight branch)
void findmax_test4() {
    BinarySearchTree tree;
    tree.insert(2);
    tree.insert(3);
    tree.insert(-1);
    tree.insert(5);
    tree.insert(4);
    assert(tree.find_max() == 5);
}

// TEST GROUP Tree Height

//test height of single leaf
void treeheight_test1() {
    BinarySearchTree tree;
    tree.insert(4);
    assert(tree.tree_height() == 0);
}

// Test height of long lefthand branch
void treeheight_test2() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    assert(tree.tree_height() == 4);
}

// Test height of long righthand branch
void treeheight_test3() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    assert(tree.tree_height() == 5);
}

// Test height of long zigzag branch
void treeheight_test4() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(7);
    tree.insert(2);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    assert(tree.tree_height() == 5);
}

// Test height of long full tree
void treeheight_test5() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    assert(tree.tree_height() == 2);
}


// TEST GROUP node count

// Tests nodecount on empty tree
void nodecount_test1() {
    BinarySearchTree tree;
    assert(tree.node_count() == 0);
}

// Tests nodecount on single leaf
void nodecount_test2() {
    BinarySearchTree tree;
    tree.insert(8);
    assert(tree.node_count() == 1);
}

// Test nodecount on long lefthand branch
void nodecount_test3() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    assert(tree.node_count() == 5);
}

// Test nodecount on long righthand branch
void nodecount_test4() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    assert(tree.node_count() == 6);
}

// Test nodecount of long zigzag branch
void nodecount_test5() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(7);
    tree.insert(2);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    assert(tree.node_count() == 6);
}

// Test nodecount of full tree
void nodecount_test6() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    assert(tree.node_count() == 7);
}

// TEST GROUP count total

// Tests counttotal on empty tree
void counttotal_test1() {
    BinarySearchTree tree;
    assert(tree.count_total() == 0);
}

// Tests counttotal on single leaf
void counttotal_test2() {
    BinarySearchTree tree;
    tree.insert(8);
    assert(tree.count_total() == 8);
}

// Test counttotal on long lefthand branch
void counttotal_test3() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(1);
    assert(tree.count_total() == 18);
}

// Test counttotal on long righthand branch
void counttotal_test4() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    assert(tree.count_total() == 21);
}

// Test counttotal of long zigzag branch
void counttotal_test5() {
    BinarySearchTree tree;
    tree.insert(1);
    tree.insert(1);
    tree.insert(2);
    tree.insert(6);
    tree.insert(3);
    tree.insert(5);
    assert(tree.count_total() == 18);
}

// Test counttotal of full tree
void counttotal_test6() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    assert(tree.count_total() == 56);
}


// TEST GROUP remove

// Tests remove on an empty tree
void remove_test0() {
    BinarySearchTree tree;
    assert(not tree.remove(3));
    assert(tree.tree_height() == -1);
}

// Tests remove on a single leaf tree
void remove_test1() {
    BinarySearchTree tree;
    tree.insert(8);
    assert(tree.contains(8));
    assert(tree.remove(8));
    assert(not tree.contains(8));
}

// Tests remove on leaves in a larger tree
void remove_test2() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(2);
    assert(tree.remove(8));
    assert(tree.remove(6));
    assert(tree.remove(4));
    assert(tree.remove(2));
    assert(tree.count_total() == 15);

}

// Tests remove on multiple count nodes in a larger tree
void remove_test3() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(7);
    tree.insert(4);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);
    tree.insert(2);
    tree.insert(2);
    tree.insert(2);
    assert(not tree.remove(5));
    assert(not tree.remove(7));
    assert(not tree.remove(4));
    assert(not tree.remove(2));
    assert(tree.count_total() == 37);

}

// Tests remove on nodes with single children
void remove_test4() {
    BinarySearchTree tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    tree.insert(9);
    tree.insert(7);
    tree.insert(8);
    tree.insert(6);
    // remove 1, which has a single right child
    assert(tree.remove(1));
    // remove 9, which has a single left child
    assert(tree.remove(9));
    assert(tree.count_total() == 35);
}

// Tests remove on nodes with two children
void remove_test5() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    // Both 2 and 6 have 2 children
    assert(tree.remove(2));
    assert(tree.remove(6));
    assert(tree.count_total() == 20);
}

// Tests remove on the root node of a tree
void remove_test6() {
    BinarySearchTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    // remove 4, which is the root node
    tree.print_tree();
    assert(tree.remove(4));
    tree.print_tree();
    assert(tree.count_total() == 24);
}

// Tests remove on every node in a full tree
void remove_test7() {
    // Make Tree
    BinarySearchTree tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(12);
    tree.insert(10);
    tree.insert(11);
    tree.insert(9);
    tree.insert(14);
    tree.insert(13);
    tree.insert(15);

    // Remove all in a random order
    assert(tree.remove(3));
    assert(tree.count_total() == 117);
    assert(tree.remove(9));
    assert(tree.count_total() == 108);
    assert(tree.remove(5));
    assert(tree.count_total() == 103);
    assert(tree.remove(8));
    assert(tree.count_total() == 95);
    assert(tree.remove(14));
    assert(tree.count_total() == 81);
    assert(tree.remove(2));
    assert(tree.count_total() == 79);
    assert(tree.remove(1));
    assert(tree.count_total() == 78);
    assert(tree.remove(4));
    assert(tree.count_total() == 74);
    assert(tree.remove(10));
    assert(tree.count_total() == 64);
    assert(tree.remove(11));
    assert(tree.count_total() == 53);
    assert(tree.remove(7));
    assert(tree.count_total() == 46);
    assert(tree.remove(6));
    assert(tree.count_total() == 40);
    assert(tree.remove(12));
    assert(tree.count_total() == 28);
    assert(tree.remove(13));
    assert(tree.count_total() == 15);
    assert(tree.remove(15));
    assert(tree.count_total() == 0);
}

// Tests remove many times on very large tree
void remove_test8() {
    BinarySearchTree tree;
    tree.insert(50);
    for (int i = 0; i < 100; i++) {
        if (i != 50) {
            tree.insert(i);
        }
    }
    //std::cerr << "added!\n";
    //tree.print_tree();
    for (int i = 99; i > -1; i--) {
        std::cerr << i << "\n";
        assert(tree.remove(i));
    }
}

// TEST GROUP copy constructor

// Tests that the copy constructor works on an empty tree
void CC_test1() {
    BinarySearchTree tree1;
    BinarySearchTree tree2 = tree1;
    assert(tree1.tree_height() == -1);
    assert(tree2.tree_height() == -1);
}

// Tests the copy constructor works with a single leaf node
void CC_test2() {
    BinarySearchTree tree1;
    tree1.insert(4);
    BinarySearchTree tree2 = tree1;
    assert(tree1.count_total() == 4);
    assert(tree2.count_total() == 4);
    tree1.remove(4);
    assert(tree1.count_total() == 0);
    assert(tree2.count_total() == 4);
}

// Tests that the copy constructor works with a larger, full tree
void CC_test3() {
    BinarySearchTree tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(12);
    tree.insert(10);
    tree.insert(11);
    tree.insert(9);
    tree.insert(14);
    tree.insert(13);
    tree.insert(15);
    BinarySearchTree tree2 = tree;
    assert(tree.count_total() == 120);
    assert(tree2.count_total() == 120);
    tree.remove(4);
    tree.remove(6);
    tree.remove(10);
    tree.remove(2);
    tree.remove(8);
    assert(tree.count_total() == 90);
    assert(tree2.count_total() == 120);
}

// Tests the copy constructor on a very large tree
void CC_test4() {
    BinarySearchTree tree;
    tree.insert(50);
    for (int i = 0; i < 100; i++) {
        if (i != 50) {
            tree.insert(i);
        }
    }
    BinarySearchTree tree2 = tree;
    assert(tree.count_total() == tree2.count_total());
    for (int i = 99; i > -1; i--) {
        assert(tree.remove(i));
    }
    assert(tree.count_total() != tree2.count_total());
}


// TEST GROUP overload assignment operator

// Tests that the copy constructor works on an empty tree
void OAO_test1() {
    BinarySearchTree tree1;
    BinarySearchTree tree2;
    tree2 = tree1;
    assert(tree1.tree_height() == -1);
    assert(tree2.tree_height() == -1);
}

// Tests the copy constructor works with a single leaf node
void OAO_test2() {
    BinarySearchTree tree1;
    tree1.insert(4);
    BinarySearchTree tree2;
    tree2 = tree1;
    assert(tree1.count_total() == 4);
    assert(tree2.count_total() == 4);
    tree1.remove(4);
    assert(tree1.count_total() == 0);
    assert(tree2.count_total() == 4);
}

// Tests that the copy constructor works with a larger, full tree
void OAO_test3() {
    BinarySearchTree tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.insert(12);
    tree.insert(10);
    tree.insert(11);
    tree.insert(9);
    tree.insert(14);
    tree.insert(13);
    tree.insert(15);
    BinarySearchTree tree2;
    tree2 = tree;
    assert(tree.count_total() == 120);
    assert(tree2.count_total() == 120);
    tree.remove(4);
    tree.remove(6);
    tree.remove(10);
    tree.remove(2);
    tree.remove(8);
    assert(tree.count_total() == 90);
    assert(tree2.count_total() == 120);
}

// Tests the copy constructor on a very large tree
void OAO_test4() {
    BinarySearchTree tree;
    tree.insert(50);
    for (int i = 0; i < 100; i++) {
        if (i != 50) {
            tree.insert(i);
        }
    }
    BinarySearchTree tree2;
    tree2 = tree;
    assert(tree.count_total() == tree2.count_total());
    for (int i = 99; i > -1; i--) {
        assert(tree.remove(i));
    }
    assert(tree.count_total() != tree2.count_total());
}
