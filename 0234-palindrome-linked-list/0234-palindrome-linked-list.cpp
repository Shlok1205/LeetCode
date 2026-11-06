class Solution
{
public:
bool isPalindrome(ListNode* head)
{
ListNode* slow=head;
ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* prev=NULL;
    ListNode* curr=slow;

    while(curr!=NULL)
    {
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    ListNode* first=head;
    ListNode* second=prev;

    while(second!=NULL)
    {
        if(first->val!=second->val)
        {
            return false;
        }

        first=first->next;
        second=second->next;
    }

    return true;
}
};
