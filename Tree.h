//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "ErrorsHandlings.h"

typedef int BOOL;
#define FALSE 0
#define TRUE 1
#define LEFT  0
#define RIGHT 1

//This Macro raise a flag and returns a given pointer.
#define returnPointer(root) { \
                        *flag = TRUE; \
                        return root;\
                        }



//Linked List's declaration
typedef struct listNode  {
    int data;
    struct listNode* next;
} ListNode;

typedef struct list  {
    ListNode* head;
    ListNode* tail;
} List;


//Tree's declaration
typedef struct treeNode{
    int data;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;
}TreeNode;

typedef struct tree{
    TreeNode* root;
    List leafList;
}Tree;

//This function gets an array and creates a tree and a leaf list from it's values.
Tree BuildTreeFromArrayWithLeafList(int* arr,int size);

//This is an inner function. It create a tree and a leaf list from a given array.
TreeNode* _build_tree_from_array_with_leaf_list(int* arr,int size,TreeNode* root);

//This function finds the first parent that has no child in branchSelect(RIGHT/LEFT).
TreeNode* findParent(Tree tr,int  parentData,int branchSelect);

//This is an inner function. It finds the first parent that has no child in branchSelect(RIGHT/LEFT).
TreeNode* _find_Parent(TreeNode* root,int parentData,int branchSelect,BOOL* flag);

//This function inserts a new leaf into a tree as a child of a given parent.
Tree AddLeaf (Tree tr, TreeNode *p, int branchSelect, int data);

//This in an inner function. Is adds a new leaf to a given parent.
void _add_leaf_to_tree(TreeNode *parent,int branch, int data);


//This function gets a value and creates a new leaf.
TreeNode* createLeaf(int num,TreeNode* parent);

//This function prints a given root's values in LDR order
void printTreeInorder(Tree tr);

//This is an inner function. It gets a root and print its tree's values in LDR form.
void _print_tree_inorder(TreeNode* root);

//This function frees a given tree's memory
void freeTree(Tree tr);

//This is an inner function. It gets a root and frees its tree's memory.
void _free_tree(TreeNode* root);

//This function returns a List built from a given tree's leafs.
List buildListFromTree(Tree tr);

//This is an inner function. It builds a new List from a given tree's leafs.
void _build_list_from_tree(List* lst,TreeNode* root);

//This function creates a new (empty) list.
void makeEmptyList(List* lst);

//This function gets a num and creates a new node with the given number as its pointed data
//Then it inserts it to the end of the list and sets it as the new tail.
void insertDataToEndList(List* lst,int integer);

//This function is an inner function, it creates a new node to list.
void _insertNewNodeToEnd(List* lst, ListNode* newNode);

//This function creates a new node, containing a given integer as its pointed data.
ListNode* createNode(int integer, ListNode* next);

//This function prints a given list.
void printLeafList(Tree tr);

//This function is an inner function. It prints a given node.
void _print_leaf_list(ListNode* node);

//This function frees a given list's memory.
void freeList(List* lst);

//This function is an inner function, it frees a given node.
void _free_list(ListNode* node);


#endif