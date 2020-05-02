//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#include "Tree.h"

Tree BuildTreeFromArrayWithLeafList(int* arr,int size){
    Tree tr;
    tr.root = _build_tree_from_array_with_leaf_list(arr,size,tr.root);
    return tr;
}

TreeNode* _build_tree_from_array_with_leaf_list(int* arr,int size,TreeNode* root){ //TODO: Change accordingly
    int midIndex = size/2;
    if(size == 0 || arr[midIndex] == -1) return NULL;
    root = createLeaf(arr[midIndex]);
    root->left = _build_tree_from_array_with_leaf_list(arr,midIndex,root->left);
    root->right = _build_tree_from_array_with_leaf_list(arr + midIndex +1 ,size - midIndex - 1,root->right);
    return root;
}



TreeNode* createLeaf(char ch){ //TODO: Change accordingly
    TreeNode* newLeaf = (TreeNode*)malloc(sizeof(TreeNode));
    checkMemoryAllocation(newLeaf);
    newLeaf->data = ch;
    newLeaf->left = NULL;
    newLeaf->right = NULL;
    return newLeaf;
}

void printTreeInorder(Tree tr){
    _print_tree_inorder(tr.root);
}

void _print_tree_inorder(TreeNode* root){
    if(root == NULL) return;
    _print_tree_inorder(root->left);
    printf("%c ",root->data);
    _print_tree_inorder(root->right);
}

void freeTree(Tree tr){
    _free_tree(tr.root);
}

void _free_tree(TreeNode* root){
    if(root == NULL) return;
    _free_tree(root->left);
    _free_tree(root->right);
    free(root);
}