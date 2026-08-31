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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX,maxi=INT_MIN;
        ListNode* curr=head->next;
        ListNode* prev=head;
        vector<int>vec;
        int i=1;
        while(curr->next!=NULL) {
            if(prev->val < curr->val && curr->val> curr->next->val) {
                vec.push_back(i);
            }
            if(prev->val > curr->val && curr->val < curr->next->val) {
                vec.push_back(i);
            }
            i++;
            curr=curr->next;
            prev=prev->next;
        }
        i=1;
        while(i<vec.size()) {
            mini=min(mini,vec[i]-vec[i-1]);
            i++;
        }
        if(vec.size()>=2) maxi=vec.back()-vec[0];
        else {
            mini=-1,maxi=-1;
        }
        return {mini,maxi};
    }
};