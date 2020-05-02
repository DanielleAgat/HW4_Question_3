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
    BOOL flag = FALSE;
    return _find_Parent(tr.root,parentData,branchSelect,&flag);
}


TreeNode* _find_Parent(TreeNode* root,int parentData,int branchSelect,BOOL* flag){
    TreeNode* p = NULL;
    if(root == NULL) return NULL;
    p = _find_Parent(root->left,parentData,branchSelect,flag);
    if(*flag == FALSE){
        switch (branchSelect){
            case RIGHT:
                if(root->data == parentData && root->right == NULL) returnPointer(root)
                break;
            case LEFT:
                if(root->data == parentData && root->left == NULL) returnPointer(root)
                break;
            default: printf("Error: Wrong branch type was entered!");
        }
        if(*flag == FALSE)
            p = _find_Parent(root->right,parentData,branchSelect,flag);
    }
    return p;
}


Tree AddLeaf(Tree tr,TreeNode* p ,int branchSelect ,int data){
    _add_leaf_to_tree(p,branchSelect,data);
    freeList(&(tr.leafList));
    tr.leafList = buildListFromTree(tr);
    return tr;
}

void _add_leaf_to_tree(TreeNode *parent,int branch, int data){
    switch (branch){
        case RIGHT:
            parent->right = createLeaf(data,parent);
            break;
        case LEFT:
            parent->left = createLeaf(data,parent);
            break;
        default: printf("Error: Wrong branch type was entered!");
    }
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
















void makeEmptyList(List* lst){
    lst->head = lst->tail = NULL;
}

void insertDataToEndList(List* lst,int integer){
    ListNode* newNode = createNode(integer,NULL);
    _insertNewNodeToEnd(lst,newNode);
}

ListNode* createNode(int integer, ListNode* next){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    checkMemoryAllocation(newNode);
    newNode->data = integer;
    newNode->next = next;
    return newNode;
}

void _insertNewNodeToEnd(List* lst, ListNode* newNode){
    newNode->next = NULL;
    if(lst->tail == NULL) {
        lst->tail = lst->head = newNode;
    }else{
        lst->tail->next = newNode;
        lst->tail = newNode;
    }
}


List buildListFromTree(Tree tr){
    List lst;
    makeEmptyList(&lst);
    _build_list_from_tree(&lst,tr.root);
    return lst;
}

void _build_list_from_tree(List* lst,TreeNode* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) { //Means this is a leaf
        insertDataToEndList(lst,root->data);
    }else{
        _build_list_from_tree(lst,root->left);
        _build_list_from_tree(lst,root->right);
    }
}

void printLeafList(Tree tr){
    _print_leaf_list(tr.leafList.head);
}

void _print_leaf_list(ListNode* node){
    while(node != NULL){
        printf("%d ",node->data);
        node = node->next;
    }
}

void freeList(List* lst){
    _free_list(lst->head);
}

void _free_list(ListNode* node){
    ListNode* temp;
    while(node != NULL){
        temp = node;
        node = node->next;
        free(temp);
    }
}