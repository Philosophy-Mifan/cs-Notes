#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode* next;
}Node;

ListNode* reverseList(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = nullptr;
    ListNode* temp = nullptr;
    while (prev != nullptr){
        temp = prev->next;
        prev->next = curr;
        curr = prev;
        prev = temp;
    }
    return curr;    
}

int main(){
    int n, x;
    cin >> n;
    ListNode* left = NULL;
    ListNode* right = NULL;
    for(int i = 1; i <= n; i++){
        cin >> x;
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = x;
        newNode->next = NULL;
        if(i == 1){
            left = newNode;
            right = newNode;
        }
        else{
            //insert at the end
            right->next = newNode;
            right = newNode;

        }
    }
    return 0;
}