#include <iostream>
#include <ctime>

using namespace std;

void inicialize(int vec[], int vecSize){
    for(int i = 0; i < vecSize; i++){
        vec[i] = 0;
    }
}

void randomize(int vec[], int vecSize){
    int num;
    bool invec;
    for(int i = 0; i < vecSize; i++){
        do{
            invec = false;
            num = rand() % 100;
            for(int j = 0; j < vecSize; j++){
                if(vec[j] == num){
                    invec = true;
                }
            }
        }while(invec == true);
        vec[i] = num;
    }
}

void printvec(int vec[], int vecSize){
    for(int i = 0; i < vecSize; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int vec[], int vecSize){
    int aux;
    for(int i = 0; i < vecSize; i++){
        for(int j = i; j < vecSize; j++){
            if(vec[i] > vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int vec[15];
    int size = sizeof(vec)/sizeof(vec[0]);

    inicialize(vec, size);

    randomize(vec, size);
    cout << "Vetor aleatorizado: ";
    printvec(vec, size);

    bubbleSort(vec, size);
    cout << "Vetor organizado: ";
    printvec(vec, size);
    
    return 0;
}