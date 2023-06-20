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

void intercalate(int vec[], int start, int end, int mid, int vecSize){
    int i, aux[vecSize], freePos = start, start1 = start, start2 = mid + 1;
    while(start1 <= mid && start2 <= end){
        if(vec[start1] > vec[start2]){
            aux[freePos] = vec[start2];
            start2++;
        }
        else{
            aux[freePos] = vec[start1];
            start1++;
        }
        freePos++;
    }
    for(i = start1; i <= mid; i++){
        aux[freePos] = vec[i];
        freePos++;
    }
    for(i = start2; i <= end; i++){
        aux[freePos] = vec[i];
        freePos++;
    }
    for(i = start; i <= end; i++){
        vec[i] = aux[i];
    }
}

void mergeSort(int vec[], int start, int end, int vecSize){
    int mid;
    if(start < end){
        mid = (start + end)/2;
        mergeSort(vec, start, mid, vecSize);
        mergeSort(vec, mid + 1, end, vecSize);
        intercalate(vec, start, end, mid, vecSize);
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

    mergeSort(vec, 0, vecSize - 1, vecSize);
    cout << "Vetor organizado: "  << "\t";
    printvec(vec, vecSize);
}