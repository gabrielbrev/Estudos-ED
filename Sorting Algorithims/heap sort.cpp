#include <iostream>
#include <ctime>

void printVec(int vec[], int size){
    std::cout << "[ ";
    for(int i = 0; i < size; i++){
        std::cout << vec[i] << " ";
    }
    std::cout << "]\n";
}

void randomize(int vec[], int size){
    for(int i = 0; i < size; i++){
        vec[i] = rand() % 300 + 1;
    }
}

void swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

/*
void heapify(int vec[], int size){
    for(int i = 1; i <= size; i++){
        int j, k;
        j = i;
        k = j/2;
        while(j > 0){
            if(vec[k] < vec[j]){
                swap(&vec[k], &vec[j]);
                printVec(vec, size);
            }
            j = k;
            k = j/2;
            
        }
    }
    stop = false;
}

void heapsort(int vec[], int size){
    for(int end = size - 1; end > 1; end--){
        heapify(vec, end);
        swap(&vec[0], &vec[end]);
        printVec(vec, size);
        stop = false;
    }
}
*/

void heapify(int vec[], int start, int end){
    int right = 2 * start + 2;
    int left = 2 * start + 1;
    int greater = start;
    if(right <= end && vec[right] > vec[start]){
        greater = right;
    }
    if(left <= end && vec[left] > vec[greater]){
        greater = left;
    }
    if(greater != start){
        swap(&vec[start], &vec[greater]);
        heapify(vec, greater, end);
    }
}

void heapsort(int vec[], int size){
    for(int i = size/2; i >= 0; i--){
        heapify(vec, i, size - 1);
    }
    for(int end = size - 1; end >= 1; end--){
        swap(&vec[0], &vec[end]);
        heapify(vec, 0, end - 1);
    }
}


int main(){
    srand(time(NULL));
    int size = 10;
    int vec[size];

    randomize(vec, size);
    printVec(vec, size);

    heapsort(vec, size);
    printVec(vec, size);

    return 0;
}