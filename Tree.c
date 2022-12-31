#include <stdlib.h>
#include <stdio.h>

typedef struct arbre{
    int data;
    struct arbre *right,*left;
}arbre;

//allocates memory for new node and returns it
arbre* initnewnode(arbre *root,int value){
    arbre *newnode=(arbre *)malloc(sizeof(arbre));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}
//inserts node to the tree
void insertNode(arbre **root,int value){
    if((*root)==NULL){
        *root = initnewnode(*root,value);
    }
    else if((*root)->data >= value ){
        insertNode(&(*root)->left,value);
    }
    else if((*root)->data < value){
        insertNode(&(*root)->right,value);
    }
}
//prints the tree (prefixe)
void print(arbre *root){
    if(root !=NULL) {
        printf("%d ->", root->data);
        print(root->left);
        print(root->right);
    }
    printf(" NULL");
}


int main(){
    int value;
    arbre *root=NULL;
    printf("Initiate your tree with value:\n");
    scanf("%d",&value);
    root =initnewnode(root,value);
    insertNode(&root,3);
    insertNode(&root,6);
    insertNode(&root,12);
    insertNode(&root,10);
    print(root);

    return 0;
}