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

void insertionSort(int vec[], int vecSize){
    int aux, j;
    for(int i = 0; i < vecSize - 1; i++){
        j = i + 1;
        while(vec[j] < vec[j - 1] && j > 0){
            aux = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = aux;
            j--;
        }
    }
}

int main(){
    srand(time(NULL));
    int vec[15];
    int size = sizeof(vec)/sizeof(vec[0]);

    inicialize(vec, size);

    randomize(vec, size);
    cout << "Vetor aleatorizado: " << "\t";
    printvec(vec, size);

    insertionSort(vec, size);
    cout << "Vetor organizado: "  << "\t";
    printvec(vec, size);
    
    return 0;
}