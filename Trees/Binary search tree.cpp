#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct tree_node{
    int data;
    struct tree_node * right;
    struct tree_node * left;
};
typedef struct tree_node * treePtr;

void print_tree(treePtr *root, int level = 0){
    if(*root != NULL){       
        print_tree(&(*root)->left, level + 1);
        cout << "level " << level << ": [" <<  (*root)->data << "]\n";
        print_tree(&(*root)->right, level + 1);
    }
}

void insert(treePtr *root, int value){
    if(*root != NULL){
        if(value < (*root)->data){
            insert(&(*root)->left, value);
        }
        else{
            insert(&(*root)->right, value);
        }
    }
    else{
        *root = new tree_node;
        (*root)->right = NULL;
        (*root)->left = NULL;
        (*root)->data = value;
    }
}

void remove(treePtr *root, int value){
    if(*root != NULL){

        // Procura o valor de forma recursiva
        if(value < (*root)->data){
            remove(&(*root)->left, value);
        }
        else if(value > (*root)->data){
            remove(&(*root)->right, value);
        }

        // Valor encontrado
        else{

            // Caso um dos filhos seja NULL, atualiza a raiz com o filho existente
            if((*root)->left == NULL){
                treePtr aux = *root;
                *root = (*root)->right;
                delete(aux);
            }
            else if((*root)->right == NULL){
                treePtr aux = *root;
                *root = (*root)->left;
                delete(aux);
            }

            // Caso os dois filhos existam
            else{
                treePtr lowestParent = *root;
                treePtr lowest = (*root)->right;

                // Encontra o menor valor a partir do FD
                while(lowest->left != NULL){
                    lowestParent = lowest;
                    lowest = lowest->left;
                }

                // Caso o pai do menor valor seja a raiz, o FD da raiz recebe o FD do menor valor
                if(lowestParent == *root){
                    lowestParent->right = lowest->right;
                }

                // Caso contrário, o FE do pai recebe o FD do menor valor
                else{
                    lowestParent->left = lowest->right;
                }

                // Troca os valores do nó removido e do nó de menor valor a direita
                (*root)->data = lowest->data;
                delete(lowest);
            }
        }
    }
}

void inorder(treePtr *root){
    if(*root != NULL){
        inorder(&(*root)->left);
        cout << (*root)->data << endl;
        inorder(&(*root)->right);
    }
}

void preorder(treePtr *root){
    if(*root != NULL){
        cout << (*root)->data << endl;
        inorder(&(*root)->left);
        inorder(&(*root)->right);
    }
}

void postorder(treePtr *root){
    if(*root != NULL){
        inorder(&(*root)->left);
        inorder(&(*root)->right);
        cout << (*root)->data << endl;
    }
}

void print_niveis(treePtr *root, int level = 0){
    if(*root != NULL){
        print_niveis(&(*root)->left, level + 1);
        print_niveis(&(*root)->right, level + 1);
        if(level == 2){
            cout << (*root)->data << endl;
        }
    }
}

int main(){
    treePtr root = NULL;

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        insert(&root, rand() % 100);
    }
    print_tree(&root);

    print_niveis(&root);
    
    return 0;
}