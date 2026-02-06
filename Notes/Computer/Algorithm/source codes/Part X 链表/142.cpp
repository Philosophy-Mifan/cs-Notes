#include<iostream>
#include<limits>
#include<cstdlib>
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
}Node;

ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL){
        slow = slow->next;
        if(fast->next == NULL){
            return NULL;
        }
        fast = fast->next->next;
        if(slow == fast){
            ListNode* p = head;
            while(p != slow){
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}

int main(){
    int n, x, cnt;
    cin >> n;
    ListNode* left = NULL;
    ListNode* right = NULL;
    for(int i = 1; i <= n; i++){
        cin >> x;
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = x;
        newNode->next = NULL;
        if (i == 1){
            left = newNode;
            right = newNode;
        }
        else{
            //insert at the end
            right->next = newNode;
            right = newNode;
        }
    }
    cin >> x;
    ListNode* temp = left;
    while(temp!= NULL && temp->val != x){
        temp = temp->next;
    }
    right->next = temp; //create a cycle
    ListNode* ans = detectCycle(left);
    if(ans == NULL){
        cout << "No cycle" << endl;
    }
    else{
        cout << ans->val << endl;
    }
    return 0;
}