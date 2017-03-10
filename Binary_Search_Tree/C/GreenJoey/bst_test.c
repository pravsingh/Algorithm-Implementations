#include <stdio.h>
#include "bst.h"


bool compare(void *num1, void *num2){
    return *(int *)num1 > *(int *)num2 ? true: false;
}

int main(){
    bst_t *tree;
    int tmp_data;
    tmp_data = 1010;
    if(bst_init(&tree, &tmp_data, sizeof(tmp_data)) == -1)
        printf("Memory can't be allocated");
    tmp_data = 100;
    bst_insert(&tree, &tmp_data, sizeof(tmp_data), compare);
    tmp_data = 2020;
    bst_insert(&tree, &tmp_data, sizeof(tmp_data), compare);
    printf("Right Node %d Root Node %d Left Node %d\n", *(int *)tree->right->data, *(int *)tree->data, *(int *)tree->left->data);
    bst_free(&tree);
    if(tree != NULL)
        printf("Memory deallocation failed\n");
}
