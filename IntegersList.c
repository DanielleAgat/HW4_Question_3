////Student's Name: Danielle Agat Levi
////Student's ID: 313357329
//
//#include "IntegersList.h"
//#include "Tree.h"
//
//void makeEmptyList(List* lst){
//    lst->head = lst->tail = NULL;
//}
//
//void insertDataToEndList(List* lst,int integer){
//    ListNode* newNode = createNode(integer,NULL);
//    _insertNewNodeToEnd(lst,newNode);
//}
//
//ListNode* createNode(int integer, ListNode* next){
//    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
//    checkMemoryAllocation(newNode);
//    newNode->data = integer;
//    newNode->next = next;
//    return newNode;
//}
//
//void _insertNewNodeToEnd(List* lst, ListNode* newNode){
//    newNode->next = NULL;
//    if(lst->tail == NULL) {
//        lst->tail = lst->head = newNode;
//    }else{
//        lst->tail->next = newNode;
//        lst->tail = newNode;
//    }
//}
//
//
//List buildListFromTree(Tree tr){
//    List lst;
//    makeEmptyList(&lst);
//    _build_list_from_tree(&lst,tr.root);
//    return lst;
//}
//
//void _build_list_from_tree(List* lst,TreeNode* root){
//    if(root == NULL) return;
//    if(root->left == NULL && root->right == NULL) { //Means this is a leaf
//        insertDataToEndList(lst,root->data);
//    }else{
//        _build_list_from_tree(lst,root->left);
//        _build_list_from_tree(lst,root->right);
//    }
//}
//
//void printLeafList(Tree tr){
//    _print_leaf_list(tr.leafList->head);
//}
//
//void _print_leaf_list(ListNode* node){
//    while(node != NULL){
//        printf("%d ",node->data);
//        node = node->next;
//    }
//}
//
//void freeList(List* lst){
//    _free_list(lst->head);
//}
//
//void _free_list(ListNode* node){
//    ListNode* temp;
//    while(node != NULL){
//        temp = node;
//        node = node->next;
//        free(temp);
//    }
//}
