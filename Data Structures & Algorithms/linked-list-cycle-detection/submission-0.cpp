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
        std::unordered_map<int, std::vector<ListNode*>> seen;
        while (head != nullptr) {
            if (seen.find(head->val) != seen.end()) {
                std::vector<ListNode*>& nexts = seen[head->val];
                if (std::find(nexts.begin(), nexts.end(), head->next) != nexts.end()) {
                    return true;
                } 
            }
            seen[head->val].push_back(head->next);
            head = head->next;
        }
        return false;
    }
};
