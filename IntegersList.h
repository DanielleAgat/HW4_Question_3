////Student's Name: Danielle Agat Levi
////Student's ID: 313357329
//
//#ifndef INTEGERSLIST_H
//#define INTEGERSLIST_H
//#include <stdio.h>
//#include <stdlib.h>
//#include "ErrorsHandlings.h"
//#include "Tree.h"
//
////Linked List's declaration
//typedef struct listNode  {
//    int data;
//    struct listNode* next;
//} ListNode;
//
//typedef struct list  {
//    ListNode* head;
//    ListNode* tail;
//} List;
//
//
////TODO: Add description
//List buildListFromTree(Tree tr);
//
////TODO: Add description
//void _build_list_from_tree(List* lst,TreeNode* root);
//
////This function creates a new (empty) list.
//void makeEmptyList(List* lst);
//
////This function gets a num and creates a new node with the given number as its pointed data
////Then it inserts it to the end of the list and sets it as the new tail.
//void insertDataToEndList(List* lst,int integer);
//
////This function is an inner function, it creates a new node to list.
//void _insertNewNodeToEnd(List* lst, ListNode* newNode);
//
////This function creates a new node, containing a given integer as its pointed data.
//ListNode* createNode(int integer, ListNode* next);
//
////This function prints a given list.
//void printLeafList(Tree tr);
//
////This function is an inner function. It prints a given node.
//void _print_leaf_list(ListNode* node);
//
////This function frees a given list's memory.
//void freeList(List* lst);
//
////This function is an inner function, it frees a given node.
//void _free_list(ListNode* node);
//
//#endif
