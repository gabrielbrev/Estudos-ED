#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ctime>

using namespace std;

struct node{
    int data;
    struct node * link;
};
typedef struct node * nodePtr;

void printList(nodePtr *head){
    nodePtr aux = *head;
    cout << "[ ";
    while(aux != NULL){
        cout << aux->data << " ";
        aux = aux->link;
    }
    cout << "]\n";
}

void push(nodePtr *head, int value){
    nodePtr newNode = new node;
    newNode->data = value;
    newNode->link = *head;
    *head = newNode;
}

void pop(nodePtr *head){
    if(*head != NULL){
        nodePtr aux = *head;
        *head = (*head)->link;
        delete(aux);    
    }  
}

void add(nodePtr *head, int value){
    nodePtr aux = *head;
    nodePtr newNode = new node;
    newNode->data = value;
    newNode->link = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        while(aux->link != NULL){
            aux = aux->link;
        }
        aux->link = newNode;    
    }
}

void kick(nodePtr *head){
    if(*head != NULL){
        nodePtr aux = *head, aux2;
        if((*head)->link == NULL){
            *head = NULL;
        }
        else{
            while(aux->link != NULL){
                cout << "while\n";
                aux2 = aux;
                aux = aux->link;
            }
            cout << "dps\n";
            aux2->link = NULL;    
        }
        delete(aux);
    }
}

void indexInsert(nodePtr *head, int value, int index){
    if(index < 0){
        cout << "\033[31mIndex out of bounds\033[0m\n";
        return;
    }
    nodePtr newNode = new node;
    newNode->data = value;
    nodePtr aux = *head, aux2;
    for(int i = 0; i < index; i++){
        if(aux == NULL){
            cout << "\033[31mIndex out of bounds\033[0m\n";
            return;
        }
        aux2 = aux;
        aux = aux->link;
    }
    aux2->link = newNode;
    newNode->link = aux;
}

void indexRemove(nodePtr *head, int index){
    if(index < 0){
        cout << "\033[31mIndex out of bounds\033[0m\n";
        return;
    }
    nodePtr aux = *head, aux2;
    for(int i = 0; i < index; i++){
        if(aux == NULL){
            cout << "\033[31mIndex out of bounds\033[0m\n";
            return;
        }
        aux2 = aux;
        aux = aux->link;
    }
    aux2->link = aux->link;
    delete(aux);
}

void sortedInsert(nodePtr *head, int value, bool reversed = false){
    nodePtr newNode = new node;
    newNode->data = value;
    if(*head == NULL){
        newNode->link = NULL;
        *head = newNode;
    }
    else{
        nodePtr aux = *head, aux2;
        if(reversed){
            if((*head)->data <= value){
                newNode->link = *head;
                *head = newNode;
                return;
            }
            else{
                while(aux->data > value){
                    aux2 = aux;
                    aux = aux->link;
                    if(aux == NULL){
                        break;
                    }
                }
            }
        }
        else{
            if((*head)->data >= value){
                newNode->link = *head;
                *head = newNode;
                return;
            }
            else{
                while(aux->data < value){
                    aux2 = aux;
                    aux = aux->link;
                    if(aux == NULL){
                        break;
                    }
                }
            }
        }
        aux2->link = newNode;
        newNode->link = aux;        
    }
}

void sortList(nodePtr *head, bool reversed = false){
    nodePtr aux = *head;
    int size = 0;
    while(aux != NULL){
        size++;
        aux = aux->link;
    }
    int vec[size];
    aux = *head;
    for(int i = 0; aux != NULL; i++){
        vec[i] = aux->data;
        aux = aux->link;
    }
    int sortAux;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(reversed){
                if(vec[i] < vec[j]){
                    sortAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = sortAux;
                }
            }
            else{
                if(vec[i] > vec[j]){
                    sortAux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = sortAux;
                }
            }
        }
    }
    aux = *head;
    for(int i = 0; aux != NULL; i++){
        aux->data = vec[i];
        aux = aux->link;
    }
}

int main(){
    nodePtr list = NULL;
    
    int opt, num, index, reverse;
    do{
        cout << "[0] Sair\n";
        cout << "[1] Push\n";
        cout << "[2] Pop\n";
        cout << "[3] Add\n";
        cout << "[4] Kick\n";
        cout << "[5] Index Insert\n";
        cout << "[6] Index Remove\n";
        cout << "[7] Sorted Insert\n";
        cout << "[8] Sort List\n";
        cout << "Selecione a funcao: ";
        cin >> opt;
        switch(opt){
            case 0:
            cout << "\033[33mFim do programa\033[0m\n";
            break;

            case 1:
            cout << "Valor a ser inserido: ";
            cin >> num;
            push(&list, num);
            break;

            case 2:
            pop(&list);
            break;

            case 3:
            cout << "Valor a ser inserido: ";
            cin >> num;
            add(&list, num);
            break;

            case 4:
            kick(&list);
            break;

            case 5:
            cout << "Valor a ser inserido: ";
            cin >> num;
            cout << "Index: ";
            cin >> index;
            indexInsert(&list, num, index);
            break;

            case 6:
            cout << "Index: ";
            cin >> index;
            indexRemove(&list, index);
            break;

            case 7:
            cout << "Valor a ser inserido: ";
            cin >> num;
            do{
                cout << "[1] Crescente\n[2] Decrescente\nOrdem: ";
                cin >> reverse;
            }while(reverse != 1 && reverse != 2);
            if(reverse == 1){
                sortedInsert(&list, num);
            }
            else{
                sortedInsert(&list, num, true);
            }
            break;

            case 8:
            sortList(&list);
            break;
            default:
            cout << "\033[31mInvalido\033[0m\n";
        }
        if(opt < 9 && opt > 0){
            cout << endl;
            printList(&list);
            cout << endl;
        }
    }while(opt != 0);

    return 0;
}