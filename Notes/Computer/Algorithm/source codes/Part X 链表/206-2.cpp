#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode* next;
}Node;

ListNode* reverseList(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr != NULL){
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
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
    left = reverseList(left);
    ListNode* temp = left;
    while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
    return 0;
}