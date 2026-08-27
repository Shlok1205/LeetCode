class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();

        vector<int> total(26,0);

        for(char c:s)
            total[c-'a']++;

        for(int i=n-1;i>=0;i--) {
            vector<int> freq=total;

            // Try to form target[0...i-1]
            bool possible=true;

            for(int j=0;j<i;j++) {
                int x=target[j]-'a';

                if(freq[x]==0) {
                    possible=false;
                    break;
                }

                freq[x]--;
            }

            if(!possible)
                continue;

            // Find the smallest character greater than target[i]
            int x=target[i]-'a';

            for(int j=x+1;j<26;j++) {
                if(freq[j]>0) {
                    freq[j]--;

                    string ans=target.substr(0,i);
                    ans+=char('a'+j);

                    // Add remaining characters in sorted order
                    for(int k=0;k<26;k++)
                        ans+=string(freq[k],char('a'+k));

                    return ans;
                }
            }
        }

        return "";
    }
};