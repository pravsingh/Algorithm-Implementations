#include <stdio.h>
#include "bst.h"

int main(){
    bst_t *tree;
    int tmp_data;
    tmp_data = 1010;
    if(bst_init(&tree, &tmp_data, sizeof(tmp_data)) == -1)
        printf("Memory can't be allocated");
    printf("%d\n", *(int *)tree->data);
}
