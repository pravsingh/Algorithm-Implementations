#include "bst.h"

static size_t bst_size = sizeof(bst_t);

int bst_init(bst_t **root, void *data, size_t data_size){
    /**
     * This function init the bst_t data type and creates a root
     * :params: root is the variable to hold the bst_t root 
     * :params: data is the holder for the data of the root's data
     * :params: data_size is size of the data passed to this function
     * :return code: When memory allocation is failed -1 is returned
     **/
    *root = (bst_t *)malloc(bst_size);
    if(root == NULL)
        return -1;
    
    (*root)->data = malloc(data_size);
    if((*root)->data == NULL)
        return -1;
    
    // memcpy needs the dest address, the src's address and the size of the src 
    memcpy((*root)->data, data, data_size);
    (*root)->left = NULL;
    (*root)->right = NULL;
    return 0; // Signal that the funtion exited properly
}


void bst_free(bst_t **tree){
    if((*tree)->right)
        bst_free(&(*tree)->right);
    
    if((*tree)->left)
        bst_free(&(*tree)->left);
    
    if((*tree)->data)
        free((*tree)->data);
    free(*tree);
    *tree = NULL;
}


int bst_insert(bst_t **tree, void *data, size_t size,  bool (*compare)(void *, void *)){
    /**
     * :param: tree is the pointer to the bst
     * :param: data is the pointer to the data for the new node
     * :param: size is the size of the data
     * :param: The compare call-back is used to decide if data is greater than current node's data
     **/
    if(*tree == NULL)
        return bst_init(tree, data, size);
    bool is_greater = compare(data, (*tree)->data);
    if(is_greater)
        bst_insert(&(*tree)->left, data, size, compare);
    else
        bst_insert(&(*tree)->right, data, size, compare);
    return 0;
}
