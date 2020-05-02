//Student's name: Danielle Agat Levi
//Student's ID: 313357329

/*
 * This program gets an array and turns it into a tree and list of leafs.
 * Then it gets a new data and a parent from the user and inserts a new leaf as the given parent's child
 * It also update the leaf's list accordingly and then print both the updated tree and list.
 */


#include <stdio.h>
#include "Tree.h"
#define SIZE 100

void main() {
    int size, i;
    int arr[SIZE];
    Tree tr;
    TreeNode *p;
    int parentData, data, branchSelect;

    printf("Please enter the number of items: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    scanf("%d%d%d", &parentData, &data, &branchSelect);
    tr = BuildTreeFromArrayWithLeafList(arr, size);//the array is given as described in question 1
    //scan the tree inorder (LDR) and find the first parent (a node with parentData as data) that has no child in branchSelect
    p = findParent(tr, parentData, branchSelect);
    tr = AddLeaf(tr, p, branchSelect, data);
    printTreeInorder(tr); //Print the tree in-order (LDR)
    printLeafList(tr); //Print the leaves from left to right
    freeTree(tr);
}