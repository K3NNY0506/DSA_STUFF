#include <stdio.h>
#define size 10

typedef struct{
    int elem[size];
    int count;
}List;

void display(List L){
    for(int i = 0; i < L.count; i++){
        printf("Data: %d\n",L.elem[i]);
    }
}

List insertPos(List L, int data, int position){

    for(int i = L.count; i > position; i--){
        L.elem[i] = L.elem[i - 1];
    }

    L.elem[position] = data;

    L.count++;
    
    return L;
}

List deletePos(List L, int position){

    int i = 0;
    while (i != position - 1){
        i++;
    }

    while (i < L.count ){
        L.elem[i] = L.elem[i + 1];
        i++;
    }
    L.count--;

    return L;

}

int locate(List L, int data){

    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data){
            return i + 1;
        }else{
            return 0;
        }
    }
}

List insertSorted(List L, int data){
    int i;
    for(i = L.count - 1; i>= 0 && L.elem[i] > data; i--){
        L.elem[i+1] = L.elem[i]; 
    }
    L.elem[i+1] = data;
    L.count++;

    return L;
}

int main(){

    List L;
    L.count = 0;

    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 30, 2);

    display(L);

    // printf("After Deleting position 2:\n");
    // L = deletePos(L,2);

    // display(L);
    // int locateNumber = locate(L,3);
    // if(locateNumber >0 ){
    // printf("\nNumber Found at Index: %d",locateNumber);
    // }else{
    // printf("\nNumber Not Found!");
    // }

    L = insertSorted(L, 5);

    display(L);


    return 0;
    //hello
}