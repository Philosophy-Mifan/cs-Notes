#include <stdio.h>
#include <stdlib.h>

//单个结点，包含一个数据、一个指针（指向下一个元素）
typedef struct LNode{
    int data;
    struct LNode* next;
    //如有重复可用计数器代替
    //int count;  记录重复个数，若重复则计数器+1
}LNode;

//operate list:初始化、增、删、改、查
LNode* Initlist(LNode* node);    //initial node
int find(LNode* node, int key);
void head_insert(LNode* node, int key); //头插
void tail_insert(LNode* node, int key); //尾插
void delete(LNode* node, int key);  //删除
int get_length(LNode* node);    //获取链表长度
void printList(LNode* node);

//debug
int main(){
    LNode* head = Initlist(head);
    head_insert(head, 1);
    head_insert(head, 2);
    head_insert(head, 3);
    tail_insert(head, 4);
    tail_insert(head, 8);
    int length = get_length(head);
    printf("the length of list: %d\n", length);
    printInfo(head);
    int search_key = 3;
    int temp = find(head, search_key) + 1;
    printf("the search_key is in pos:%d\n", temp);
    delete(head, 2);
    printList(head);
}

LNode* Initlist(LNode* node){
    node = (LNode*)malloc(sizeof(LNode));
    if (node == NULL){
        printf("the initial is error.\n");
    }
    else{
        node->next = NULL;  //此处可以将next指针指向自己，变成单向循环链表
        node->data = 0; //default
    }
    return node;
}

int find(LNode* node, int key){
    LNode* tmp;
    tmp = node->next;
    int i = 0;
    while(tmp != NULL){
        if(tmp->data == key){
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;  //can not find the key
}

//创建新结点，
void head_insert(LNode* node, int key){
    LNode* tmp = (LNode*)malloc(sizeof(node));
    tmp->data = key;
    tmp->next = node->next;
    node->next = tmp;
    
}

void tail_insert(LNode* node, int key){
    LNode* tmp = (LNode*)malloc(sizeof(node));
    if (tmp == NULL){
        printf("can not create new node.\n");
        return;
    }
    tmp->data = key;
    tmp->next = NULL;

    LNode* last = node;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = tmp;
}

void delete(LNode* node, int key){
    //find
    int index = find(node, key);
    if(index == -1){
        printf("can not find the %d.\n", key);
    }
    else{
        LNode* tmp;
        tmp = node;
        int i = 0;
        while(i < index){
            tmp = tmp->next;
            i++;
        }
        //release
        LNode* free_node = tmp->next;
        tmp->next = tmp->next->next;
        free(free_node);
    }
}

void printList(LNode* node){
    if(node == NULL || node->next == NULL){
        printf("this list is empty.\n");
        return;
    }
    LNode* tmp = node->next;
    printf("list:");
    while(tmp != NULL){
        printf("[%d] ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int get_length(LNode* node){
    int length = 0;
    LNode* tmp = node->next;
    while(tmp != NULL){
        length++;
        tmp = tmp->next;
    }
    return length;
}