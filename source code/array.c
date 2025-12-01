#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList
{
    int* list;  //array
    int maxSize;
    int count;  
}List;

List* InitList();//初始化
void insert(List* list, int key);   //在list中插入key
int find(List* list, int key);  //在list中查找key的位置
void insert_index(List* list, int key, int data);   //在list中的data前插入key
void printfList(List* list);
void delete(List* list, int key);    //在list中删除key


//test
int main(){
    List* list = InitList();
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);
    printfList(list);
    insert_index(list, 6, 5);
    delete(list, 3);
    printfList(list);
}

List* InitList(){
    List* list = (List*)malloc(sizeof(List));
    list->count = 0;
    list->maxSize = 10;
    list->list = (int*)malloc(sizeof(int) * 10);

    return list;
}

void insert(List* list, int key){
    if(list->count >= list->maxSize){
        printf("list is full can not insert");
        return; //exit the function
    }
    list->list[list->count] = key;
    list->count++;
}

int find(List* list, int key){
    for (int i = 0;i < list->count; i++){
        if(list->list[i] == key){
            return i;
        }
        else{
            printf("key %d is not in the list", key);
        }
    }
}

//在list中的data前插入key
void insert_index(List* list, int key, int data){
    if(list->count < list->maxSize){
        int index = find(list, data);
        if (index == -1){
            printf("data %d is not in the list", data);
            return;
        }
        else{
            //move the elements after index one position forward
            for (int i = list->count; i > index; i--){
                list->list[i] = list->list[i - 1];
            }
            list->list[index] = key;
            list->count++;
        }
    }
}

void printfList(List* list){
    for(int i = 0; i < list->count;i++){
        printf("%d ", list->list[i]);
    }
    printf("\n");
}

void delete(List* list, int key){
    if(list->count == 0){
        printf("list is empty can not delete");
        return;
    }
    else{
        int index=find(list,key);
        if(index == -1){
            printf("key %d is not in the list, can not delete", key);
            return;
        }
        else{
            //move the elements after index one position backward
            for (int i = index; i < list->count - 1; i++){
                list->list[i] = list->list[i + 1];
            }
            list->count--;  //这里说明数组的删除是伪删除，实际效果是输出不到最后的元素位置，但其实元素还存在，只不过count--了
        }
    }
}