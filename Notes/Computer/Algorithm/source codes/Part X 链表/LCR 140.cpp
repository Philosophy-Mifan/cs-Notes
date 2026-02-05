#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode* next;
}Node;

ListNode* trainingPlan(ListNode* head, int cnt) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next != NULL){
        if (cnt > 1){
            fast = fast->next;
            cnt--;
            continue;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main(){
    int n, x, cnt;
    cin >> n >> cnt;
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
    ListNode* ans = trainingPlan(left, cnt);
    cout << ans->val << endl;
    return 0;
}