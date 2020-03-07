/* Maya Michalik
 * November 12 2019
 */
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//this method creates a new node in the binary search tree
Node new_node(BStree bst, Key *key, Data data) {
    Node node;

    int i = bst->top;
    node.key = key;
    node.data = data;
    node.left = 0;
    node.right = 0;
    bst->tree_nodes[i] = node;
    i += 1;
    bst->free_nodes[i] = 0;
    // setting values for the node
    return node;
}

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned int array of size+1 for member free_nodes
// set member size to ’size’;
// set entry free_nodes[i] to i
// set member top to 1;
// set member root to 0;
BStree bstree_ini(int size) {
    int numSize = sizeof(BStree_struct);

    BStree tree = (BStree) malloc(numSize);
    tree->tree_nodes = (Node*) malloc((size+1) * sizeof(Node));
    tree->free_nodes = (unsigned int*) malloc((size+1) * sizeof(int));
    //allocating memory

    for(int i = 0; i <= size; i++){
       tree->free_nodes[i]= i;
    }
    tree->size = size;
    tree->top = 1;
    tree->root = 0;
    //setting values
    return(tree);
}
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, Data data, int i) {
    int var = bst->free_nodes[bst->top];

    if(bst->top == bst->size+1){
        printf("Out of bounds!");
        return;
     //catches error
    }
    if(i==0){
        bst->tree_nodes[var] = new_node(bst,key,data);
        bst->root = var;
        bst->top++;
       //inserting root
    }
    else{
        int comp = key_comp(key,bst->tree_nodes[i].key);

        if (comp < 0){
            if(bst->tree_nodes[i].left == 0){

                bst->tree_nodes[var] = new_node(bst, key, data);
                bst->tree_nodes[i].left = bst->free_nodes[bst->top];
                bst->top++;
            }
            else{
                bstree_insert(bst, key, data, i);
            }
        }
        else if(comp > 0){
            if(bst->tree_nodes[i].right==0){
                bst->tree_nodes[var]=new_node(bst, key, data);

                bst->tree_nodes[i].right = bst->free_nodes[bst->top];
                bst->top++;

            }
            else{
                bstree_insert(bst, key, data, i);
            }
        }
        //recursively inserts node into tree
    }

}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst, int i) {

    if (i < bst->size) {

        bstree_traversal(bst, 2*i);

        if (bst->free_nodes[i] == 0) {

            print_node(bst->tree_nodes[i]);

        }
        bstree_traversal(bst, 2 * i + 1);
        //recursively traverses through the tree
    }
}
// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {
    free(bst->tree_nodes);
    free(bst->free_nodes);
    free(bst);
    //frees nodes
}
