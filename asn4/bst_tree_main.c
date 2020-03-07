/* Maya Michalik
 * November12 2019
 */
#include "bst.h"
int main(void) {
    BStree bst;
    bst = bstree_ini(256);
    bstree_insert(bst, key_construct("Once", 1), 11, 0);
    bstree_insert(bst, key_construct("Upon", 22), 2, 1);
    bstree_insert(bst, key_construct("a", 3), 33, 2);
    bstree_insert(bst, key_construct("Time", 4), 44, 3);
    bstree_insert(bst, key_construct("is", 5), 55,4);
    bstree_insert(bst, key_construct("filmed", 6), 66,5);
    bstree_insert(bst, key_construct("in", 7), 77,6);
    bstree_insert(bst, key_construct("Vancouver", 8), 88,7);
    bstree_insert(bst, key_construct("!", 99), 9,8);
    bstree_insert(bst, key_construct("Once", 5), 50,9);
    bstree_insert(bst, key_construct("Once", 1), 10, 10);
    bstree_traversal(bst, 10);
    bstree_free(bst);
}

