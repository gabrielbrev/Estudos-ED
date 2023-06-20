#include <iostream>
#include <ctime>

using namespace std;

void inicialize(int vec[], int vecSize){
    for(int i = 0; i < vecSize; i++){
        vec[i] = 0;
    }
}

void printvec(int vec[], int vecSize){
    for(int i = 0; i < vecSize; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
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

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void quickSort(int vec[], int start, int end, int vecSize){
    int i, j, key;
    if((end - start) < 2){
        if((end - start == 1)){
            if(vec[start] > vec[end]){
                swap(&vec[start], &vec[end]);
            }
        }
    }
    else{
        i = start;
        j = end;
        key = vec[start];
        while(j > i){
            i++;
            while(vec[i] < key){
                i++;
            }
            while(vec[j] > key){
                j--;
            }
            if(j > i){
                swap(&vec[i], &vec[j]);
            }
        }
        swap(&vec[start], &vec[j]);
        quickSort(vec, start, j - 1, vecSize);
        quickSort(vec, j + 1, end, vecSize);
    }
}

int main(){
    srand(time(NULL));
    int vec[15];
    int vecSize = sizeof(vec)/sizeof(vec[0]);

    inicialize(vec, vecSize);

    randomize(vec, vecSize);
    cout << "Vetor aleatorizado: " << "\t";
    printvec(vec, vecSize);

    quickSort(vec, 0, vecSize - 1, vecSize);
    cout << "Vetor organizado: "  << "\t";
    printvec(vec, vecSize);
}