class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int freq[26]={0};

        for(char c:tasks)
        {
            freq[c-'A']++;
        }

        sort(freq,freq+26);

        int maxFreq=freq[25];
        int idle=(maxFreq-1)*n;

        for(int i=24;i>=0 && freq[i]>0;i--)
        {
            idle-=min(maxFreq-1,freq[i]);
        }

        return tasks.size()+max(0,idle);
    }
};