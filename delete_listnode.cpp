#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        while(curr)
        {
            if (head->val == val)
            {
                head = head ->next;
            }
            else if(curr ->next->val == val)
            {
                curr->next = curr->next->next;
                continue;
            }
            curr = curr->next;
        }
        return head;

    }
};
int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode* ans = s.removeElements(head, 6);
    while(ans)
    {
        cout<<ans->val<<" ";
        
        ans = ans->next;
    }
    system("pause");

    return 0;
}