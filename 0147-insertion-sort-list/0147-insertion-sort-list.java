class Solution
{
    public ListNode insertionSortList(ListNode head)
    {
        ListNode dummy=new ListNode(0);
        ListNode current=head;

        while(current!=null)
        {
            ListNode next=current.next;

            ListNode temp=dummy;

            while(temp.next!=null && temp.next.val<current.val)
            {
                temp=temp.next;
            }

            current.next=temp.next;
            temp.next=current;

            current=next;
        }

        return dummy.next;
    }
}