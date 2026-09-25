import java.util.*;

class Solution
{
    public List<String> braceExpansionII(String expression)
    {
        Set<String> result=solve(expression,0,expression.length());

        List<String> answer=new ArrayList<>(result);
        Collections.sort(answer);

        return answer;
    }

    private Set<String> solve(String s,int start,int end)
    {
        Set<String> result=new HashSet<>();
        Set<String> current=new HashSet<>();
        current.add("");

        int i=start;

        while(i<end)
        {
            char ch=s.charAt(i);

            if(ch=='{')
            {
                int count=1;
                int j=i+1;

                while(count>0)
                {
                    if(s.charAt(j)=='{')
                    {
                        count++;
                    }
                    else if(s.charAt(j)=='}')
                    {
                        count--;
                    }

                    j++;
                }

                Set<String> inside=solve(s,i+1,j-1);
                current=combine(current,inside);

                i=j;
            }
            else if(ch==',')
            {
                result.addAll(current);
                current=new HashSet<>();
                current.add("");

                i++;
            }
            else
            {
                Set<String> letter=new HashSet<>();
                letter.add(String.valueOf(ch));

                current=combine(current,letter);

                i++;
            }
        }

        result.addAll(current);

        return result;
    }

    private Set<String> combine(Set<String> a,Set<String> b)
    {
        Set<String> result=new HashSet<>();

        for(String x:a)
        {
            for(String y:b)
            {
                result.add(x+y);
            }
        }

        return result;
    }
}