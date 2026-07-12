class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);   // start node
        ListNode* current = dummy;           // pointer to build result list
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry) {
            
            int sum = carry;  // start with carry

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;  // update carry (0 or 1)
            int digit = sum % 10;

            current->next = new ListNode(digit);
            current = current->next;
        }

        return dummy->next;   // skip dummy node
    }
};