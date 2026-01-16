class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> valuesToRemove(nums.begin(), nums.end());

        while (head != nullptr && valuesToRemove.count(head->val) > 0) {
            head = head->next;
        }

        if (head == nullptr) {
            return nullptr;
        }

        ListNode* current = head;
        while (current->next != nullptr) {
            if (valuesToRemove.contains(current->next->val)) {
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }

        return head;
    }
};
