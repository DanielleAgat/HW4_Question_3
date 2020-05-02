//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "ErrorsHandlings.h"
#include "integersLists.h"

typedef int BOOL; //TODO: Remove if needed
#define FALSE 0 //TODO: Remove if needed
#define TRUE 1 //TODO: Remove if needed
#define EOS '\0' //TODO: Remove if needed
#define LEFT  0
#define RIGHT 1


//This Macro returns TRUE if a given char represents a digit; FALSE otherwise.
#define isNum(num) ((((num) >= '0') && ((num) <= '9')) ? TRUE : FALSE ) //TODO: Remove if needed
//This Macro returns True if a given char represents a valid operator ('+','-','*','/','%') ; False otherwise.
#define isOperator(char) ((char == '*') || (char == '/') || (char == '-') || (char == '+') || (char == '%')) //TODO: Remove if needed
//This Macro returns True if a given char is a valid char(num/operator/parenthesis) ; False otherwise.
#define isValidChar(char) ((isOperator(char)) || (isNum(char)) || (char == '(') || (char == ')')) //TODO: Remove if needed
//This Macro returns the given char digit as an integer.
#define parseInt(char) ((char) - '0') //TODO: Remove if needed


//Tree's declaration
typedef struct  treeNode {
    int data;
    struct treeNode* parent;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

typedef struct tree{
    TreeNode* root;
    List leafList;
} Tree;

//This function gets an array and creates a tree and a leaf list from it's values.
Tree BuildTreeFromArrayWithLeafList(int* arr,int size);

//This is an inner function. It create a tree and a leaf list from a given array.
TreeNode* _build_tree_from_array_with_leaf_list(int* arr,int size,TreeNode* root);

//TODO: Add description
Tree AddLeaf (Tree tr, TreeNode *p, int branchSelect, int data);

//This function gets a value and creates a new leaf.
TreeNode* createLeaf(char ch);

//This function prints a given root's values in LDR order
void printTreeInorder(Tree tr);

//This is an inner function. It gets a root and print its tree's values in LDR form.
void _print_tree_inorder(TreeNode* root);

//This function frees a given tree's memory
void freeTree(Tree tr);

//This is an inner function. It gets a root and frees its tree's memory.
void _free_tree(TreeNode* root);


#endif