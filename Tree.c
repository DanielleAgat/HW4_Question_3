//Student's Name: Danielle Agat Levi
//Student's ID: 313357329

#include "Tree.h"

Tree BuildTreeFromArrayWithLeafList(int* arr,int size){
    Tree tr;
    tr.root = NULL;
    tr.root = _build_tree_from_array_with_leaf_list(arr,size,tr.root);
    tr.leafList = buildListFromTree(tr);
    return tr;
}

TreeNode* _build_tree_from_array_with_leaf_list(int* arr,int size,TreeNode* root){
    int midIndex = size/2;
    if(size == 0 || arr[midIndex] == -1) return NULL;
    root = createLeaf(arr[midIndex],root);
    root->left = _build_tree_from_array_with_leaf_list(arr,midIndex,root->left);
    root->right = _build_tree_from_array_with_leaf_list(arr + midIndex +1 ,size - midIndex - 1,root->right);
    return root;
}


TreeNode* findParent(Tree tr,int parentData,int branchSelect){
    return _find_Parent(tr.root,parentData,branchSelect);
}


TreeNode* _find_Parent(TreeNode* root,int parentData,int branchSelect){
    if(root == NULL) return NULL;
    switch (branchSelect){
        case RIGHT:
            if(root->data == parentData && root->right == NULL)
                return root;
            break;
        case LEFT:
            if(root->data == parentData && root->left == NULL)
                return root;
            break;
        default: printf("Error: Wrong branch type was entered!");
    }
    _find_Parent(root->left,parentData,branchSelect);
    _find_Parent(root->right,parentData,branchSelect);
}


TreeNode* createLeaf(int num,TreeNode* parent){
    TreeNode* newLeaf = (TreeNode*)malloc(sizeof(TreeNode));
    checkMemoryAllocation(newLeaf);
    newLeaf->data = num;
    newLeaf->parent = parent;
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
    printf("%d ",root->data);
    _print_tree_inorder(root->right);
}

void freeTree(Tree tr){
    _free_tree(tr.root);
    freeList(&(tr.leafList));
}

void _free_tree(TreeNode* root){
    if(root == NULL) return;
    _free_tree(root->left);
    _free_tree(root->right);
    free(root);
}