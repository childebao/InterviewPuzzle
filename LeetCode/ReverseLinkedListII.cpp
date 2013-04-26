/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // Split into 3 parts: head, tmp, ans
    ListNode *reverseList(ListNode *head, ListNode *tail) {
        if (!head->next || head->next == tail) return head;
        
        ListNode *ans = head->next;
        head->next = tail;
        
        if (!ans->next || ans->next == tail) {
            ans->next = head;
            return ans;
        }
        
        ListNode *tmp = ans;
        ans = ans->next;
        tmp->next = head;
        head = tmp;
        
        while (true) {
            tmp = ans;
            
            if (!ans->next || ans->next == tail) {
                ans->next = head;
                return ans;
            }
        
            ans = ans->next;
            tmp->next = head;
            head = tmp;
        }
        return ans;
    }
    
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *ans = new ListNode(0);
        ans->next = head;
        
        ListNode *tail = ans;
        ListNode *left = head;
        int count = 1;
        while (count < m && left) {
            tail = left;
            left = left->next;
            count ++;
        }
        
        ListNode *right = left;
        while (count < n && right) {
            right = right->next;
            count ++;
        }
        
        tail->next = reverseList(left, right->next);
        
        return ans->next;
    }
};