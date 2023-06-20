#include <iostream>
#include <ctime>

using namespace std;

struct node{
    int data;
    struct node *link;
};
typedef struct node * nodePtr;

void printList(nodePtr *head){
    nodePtr aux = *head;
    cout << "[ ";
    if(*head != NULL){
        do{
            cout << aux->data << " ";
            aux = aux->link;
        }while(aux != *head);
    }
    cout << "]\n\n";
}

void printListAdresses(nodePtr *head){
    cout << "-----------------------------------------\n";
    if(*head != NULL){
        nodePtr aux = *head;
        do{
            cout << aux->data << "\t" << aux << "\t" << aux->link << endl;
            aux = aux->link;
        }while(aux != *head);    
    }
    cout << "-----------------------------------------\n";
}


void push(nodePtr *head, int value){
    nodePtr newNode = new node;
    newNode->data = value;
    if(*head == NULL){
        *head = newNode;
        newNode->link = *head;
    }
    else{
        nodePtr aux = *head;
        while(aux->link != *head){
            aux = aux->link;
        }
        newNode->link = *head;
        *head = newNode;
        aux->link = *head;
    }
}

void pop(nodePtr *head){
    if(*head != NULL){
        nodePtr aux = *head, aux2 = *head;
        while(aux->link != *head){
            aux = aux->link;
        }
        *head = (*head)->link;
        aux->link = *head;
        delete(aux2);    
    }
}

void insert(nodePtr *head, int value){
    nodePtr newNode = new node;
    newNode->data = value;
    if(*head == NULL){
        *head = newNode;
        newNode->link = *head;
    }
    else{
        nodePtr aux = *head, aux2;
        if((*head)->data >= value){
            while(aux->link != *head){
                aux = aux->link;
            }
            newNode->link = *head;
            aux->link = newNode;
            *head = newNode;
        }
        else{
            do{
                aux2 = aux;
                aux = aux->link;
            }while(aux != *head && aux->data < value);
            aux = aux2;
            newNode->link = aux->link;
            aux->link = newNode;    
        }
    } 
}

void remove(nodePtr *head, int value){
    if(*head != NULL){
        bool found = false;
        nodePtr aux = *head, aux2;
        do{
            aux2 = aux;
            aux = aux->link;
        }while(aux != *head);
        do{
            if(aux->data == value){
                found = true;
                break;
            }
            aux2 = aux;
            aux = aux->link;
        }while(aux != *head);
        if(found){
            aux2->link = aux->link;    
            if(aux == *head){
                *head = aux2->link;
            }
            delete(aux);
        }    
    }
    
}

int main(){
    nodePtr list = NULL;

    srand(time(NULL));
    for(int i = 10; i < 50; i++){
        int x = rand() % 100 + 1;
        cout << x << endl;
        insert(&list, x);
        printListAdresses(&list);
    }
    printList(&list);

    int x;
    cin >> x;
    remove(&list, 2);
    printList(&list);



    
    return 0;
}