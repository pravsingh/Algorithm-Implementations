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
    else{
        if((*tree)->data)
            free((*tree)->data);
        free(*tree);
        *tree = NULL;
    }
}
