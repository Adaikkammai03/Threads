#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* address;
    size_t size;
}s;

s array[100];
int c=0,n=100;

void* my_malloc(size_t size) {
    void* ptr=malloc(size);
    if (c<n) {
        array[c].address=ptr;
        array[c].size=size;
        c++;}
    else 
        ptr=NULL;
    return ptr;}

void my_free(void* ptr){
    int f=0;
    for(int i=0;i<c;i++){
        if(array[i].address==ptr){
            f=1;
            free(ptr);
            for(int j=i;j<c-1;j++) {
                array[j]=array[j+1];}
            c--;
            break;}}}

void find_memory_leaks(){
    if(c>0){
        printf("Memory leaks detected:\n");
        for(int i=0;i<c;i++){
            printf("Address:%p,Size:%zu\n",array[i].address,array[i].size);}}
    else{
        printf("No memory leaks detected.\n");}}

int main(){
    int* arr1 = (int*)my_malloc(sizeof(int) * 10);
    int* arr2 = (int*)my_malloc(sizeof(int) * 10);
    int* arr3 = (int*)my_malloc(sizeof(int) * 10);
    //find_memory_leaks();
    my_free(arr1);
    //find_memory_leaks();
    my_free(arr2);
    //find_memory_leaks();
    my_free(arr1);
    find_memory_leaks();
    return 0;
}
