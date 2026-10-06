class Solution
{
    public int minAddToMakeValid(String s)
    {
        int balance=0;
        int moves=0;

        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)=='(')
            {
                balance++;
            }
            else
            {
                if(balance>0)
                {
                    balance--;
                }
                else
                {
                    moves++;
                }
            }
        }

        return moves+balance;
    }
}