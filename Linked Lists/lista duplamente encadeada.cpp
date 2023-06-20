#include <iostream>
#include <ctime>

using namespace std;

struct double_node{
    int data;
    struct double_node * next;
    struct double_node * prev;
};
typedef struct double_node * dnodePtr;

void printList(dnodePtr *head){
    cout << "[ ";
    for(dnodePtr aux = *head; aux != NULL; aux = aux->next){
        cout << aux->data << " ";
    }
    cout << "]\n";
}

void printListAdresses(dnodePtr *head){
    cout << "----------------------------------------------------\n";
    for(dnodePtr aux = *head; aux != NULL; aux = aux->next){
        cout << aux->data << "\t" << aux->prev << "\t";
        if(aux->prev == NULL){
            cout << "\t";
        }
        cout << aux << "\t" << aux->next << endl;
    }
    cout << "----------------------------------------------------\n";
}

void push(dnodePtr *head, int value){
    dnodePtr newNode = new double_node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void pop(dnodePtr *head){
    if(*head != NULL){
        dnodePtr aux = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        delete(aux);    
    } 
}

void insert(dnodePtr *head, int value){
    dnodePtr newNode = new double_node;
    newNode->data = value;
    dnodePtr aux = *head, aux2;
    if(*head == NULL || value <= (*head)->data){
        newNode->next = *head;
        newNode->prev = NULL;
        if(*head != NULL){
            (*head)->prev = newNode;
        }
        *head = newNode;
    }
    else{
        while(aux != NULL && value > aux->data){
            aux2 = aux;
            aux = aux->next;
        }
        if(aux == NULL){
            aux = aux2;
            newNode->next = aux->next;
            newNode->prev = aux;
            aux->next = newNode;
        }
        else{
            aux = aux->prev;
            newNode->next = aux->next;
            newNode->prev = aux;
            aux->next->prev = newNode;
            aux->next = newNode;
        }
    }
}

void remove(dnodePtr *head, int value){
    if(*head != NULL){
        dnodePtr aux = *head;
        if(value == (*head)->data){
            *head = (*head)->next;
            if(*head != NULL){
                (*head)->prev = NULL;
            }
            delete(aux);
        }
        else{
            while(aux != NULL && value != aux->data){
                aux = aux->next;
            }
            if(aux != NULL){
                if(aux->next != NULL){
                    aux->next->prev = aux->prev;
                }
                if(aux->prev != NULL){
                    aux->prev->next = aux->next;
                }
                delete(aux);
            }
        }    
    } 
}

int main(){
    dnodePtr list = NULL;

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        int x = rand() % 100;
        insert(&list, x);
    }
    printListAdresses(&list);

    while(true){
        int x;
        cin >> x;
        remove(&list, x);
        printListAdresses(&list);    
    }
    

    return 0;
}