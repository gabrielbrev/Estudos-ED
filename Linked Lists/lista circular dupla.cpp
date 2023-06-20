#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

struct double_node{
    int data;
    struct double_node *next;
    struct double_node *prev;
};
typedef struct double_node * dnodePtr;

void printList(dnodePtr *head){
    dnodePtr aux = *head;
    cout << "[ ";
    if(*head != NULL){
        do{
            cout << aux->data << " ";
            aux = aux->next;
        }while(aux != *head);
    }
    cout << "]\n";
}

void printListAdresses(dnodePtr *head){
    cout << "----------------------------------------------------\n";
    if(*head != NULL){
        dnodePtr aux = *head;
        do{
            cout << aux->data << "\t" << aux->prev << "\t";
            if(aux->prev == NULL){
                cout << "\t";
            }
            cout << aux << "\t" << aux->next << endl;
            aux = aux->next;
        }while(aux != *head);    
    }
    cout << "----------------------------------------------------\n";
}

void push(dnodePtr *head, int value){
    dnodePtr newNode = new double_node;
    newNode->data = value;
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
    }
    else{
        dnodePtr aux = *head;
        while(aux->next != *head){
            aux = aux->next;
        }
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = aux;
        aux->next = newNode;
        *head = newNode;
    }
}

void pop(dnodePtr *head){
    if(*head != NULL){
        dnodePtr aux = *head;
        if(*head == (*head)->next){
            *head = NULL;
            delete(aux);
        }
        else{
            dnodePtr aux2 = *head;
            while(aux->next != *head){
                aux = aux->next;
            }
            *head = (*head)->next;
            (*head)->prev = aux;
            aux->next = *head;
            delete(aux2);    
        }    
    }
}

void insert(dnodePtr *head, int value){
    dnodePtr newNode = new double_node;
    newNode->data = value;
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
    }
    else{
        dnodePtr aux = *head;
        if((*head)->data >= value){
            aux = aux->prev;
            newNode->next = *head;
            (*head)->prev = newNode;
            newNode->prev = aux;
            aux->next = newNode;
            *head = newNode;
        }
        else{
            do{
                aux = aux->next;
            }while(aux != *head && aux->data < value);
            aux = aux->prev;
            newNode->next = aux->next;
            newNode->prev = aux;
            aux->next->prev = newNode;
            aux->next = newNode;    
        }
    } 
}

bool remove(dnodePtr *head, int value){
    if(*head != NULL){
        dnodePtr aux = *head;

        //Caso a lista tenha somente um valor
        if(*head == (*head)->next){
            *head = NULL;
            delete(aux);
        }
        else{
            //Caso o valor seja o primeiro da lista
            if((*head)->data == value){
                dnodePtr aux2 = *head;
                aux = aux->prev;

                //Conecta o anterior com o próximo e deleta o atual
                *head = (*head)->next;
                (*head)->prev = aux;
                aux->next = *head;
                delete(aux2);
            }
            else{
                //Procura o valor desejado na lista
                do{
                    aux = aux->next;
                }while(aux != *head && aux->data != value);

                //Caso o valor seja encontrado
                if(aux->data == value){
                    
                    //Conecta o anterior com o próximo e deleta o atual
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete(aux);  
                }
                else{
                    return false;
                }
            }  
        }
        return true;   
    }
    return false;
}

void removenotbool(dnodePtr *head, int value){
    if(*head != NULL){
        dnodePtr aux = *head;
        if(*head == (*head)->next){
            *head = NULL;
            delete(aux);
        }
        else{
            if((*head)->data == value){
                dnodePtr aux2 = *head;
                aux = aux->prev;
                *head = (*head)->next;
                (*head)->prev = aux;
                aux->next = *head;
                delete(aux2);
            }
            else{
                do{
                    aux = aux->next;
                }while(aux != *head && aux->data != value);
                if(aux->data == value){
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    delete(aux);  
                }
            }  
        }
    }
}

int main(){
    dnodePtr list = NULL;
    srand(time(NULL));

    for(int i = 0; i < 150; i++){
        int x = rand() % 100 + 1;
        insert(&list, x);
    }

    printListAdresses(&list);

    while(true){
        int x;
        cin >> x;
        if(!remove(&list, x)){
            cout << "\033[31mVALOR NAO ENCONTRADO\033[0m\n";
        }
        printListAdresses(&list);
    }
    
    return 0;
}