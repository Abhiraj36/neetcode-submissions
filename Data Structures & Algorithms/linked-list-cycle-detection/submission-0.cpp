/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == nullptr) {
            return false;
        }
         ListNode* turtle = head;
         ListNode* rabbit = head;
        
while (rabbit != nullptr && rabbit->next != nullptr)
 {
     turtle = turtle->next;
     rabbit = rabbit->next->next;
     if(turtle == rabbit){
    return true;
}
}
return false;
    }
};
