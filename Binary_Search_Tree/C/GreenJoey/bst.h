#include <malloc.h>
#include <memory.h>
#include <stdint.h>

typedef enum bool{
    false, true
}bool;


typedef struct bst_t{
    void *data;
    struct bst_t *right, *left;
    uint64_t height;
}bst_t;


int bst_init(bst_t **root, void *data, size_t data_size);
void bst_free(bst_t **root);
