#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleList{
    struct DoubleList* front;   //前指针
    int data;
    struct DoubleList* next;    //后指针
}List;
List* head;  //头指针

void InitList(){
    head = (List*)malloc(sizeof(List));
    //让头指针的两个指针指向自己
    head->front = head;
    head->next = head;
    //头指针的元素可用于计数或其他用途
}

void head_insert(int key){
    List* new_node = (List*)malloc(sizeof(List));
    new_node->data = key;           //赋数据域内的值为key
    new_node->next = head->next;    //将新结点的后指针指向头指针的后指针
    new_node->front = head;         //将新结点的前指针指向头指针
    head->next->front = new_node;   //将头指针的后指针（下一个元素）的前指针指向新结点
    head->next = new_node;          //就爱那个头指针的后指针指向新结点
}

int find(int key){
    List* tmp = head->next;
    int i = 0;
    while(tmp != head){
        if(tmp->data == key){
            return i;
        }
        i++;
        tmp = tmp->next;
    }
    return -1;
}

void delete_note(int key){
        
    if(head == NULL){
        printf("无法删除元素，因为想要删除列表里的元素为null");
    }
    else{
        int index = find(key);
        if(index == -1){
            printf("can not find the delete key %d\n", key);
        }
        else{
            List* tmp = head;
            int i = 0;
            while(i < index){
                tmp = tmp->next;
                i++;
            }
            List* free_node = tmp->next;
            tmp->next->next->front = tmp;
            tmp->next = tmp->next->next;
            free(free_node);
        }
    }
}