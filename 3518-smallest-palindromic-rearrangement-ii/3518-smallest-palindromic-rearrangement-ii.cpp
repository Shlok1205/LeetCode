class Solution {
public:
    static const int LIM=1000000;

    long long ways(vector<int>& cnt) {
        int total=0;
        for(int x:cnt) total+=x;

        long long res=1;
        int rem=total;

        for(int c:cnt) {
            if(c==0) continue;

            int need=c;
            long long cur=1;

            for(int i=1;i<=need;i++) {
                cur=cur*(rem-need+i)/i;
                if(cur>LIM) cur=LIM;
            }

            if(res>LIM/cur) res=LIM;
            else res*=cur;

            if(res>LIM) res=LIM;

            rem-=need;
        }

        return res;
    }

    string smallestPalindrome(string s,int k) {
        vector<int> freq(26,0);

        for(char c:s) freq[c-'a']++;

        vector<int> half(26,0);

        string mid="";

        for(int i=0;i<26;i++) {
            half[i]=freq[i]/2;
            if(freq[i]&1) mid.push_back(char('a'+i));
        }

        if(ways(half)<k) return "";

        string left="";
        int len=s.size()/2;

        for(int pos=0;pos<len;pos++) {

            for(int c=0;c<26;c++) {

                if(half[c]==0) continue;

                half[c]--;

                long long w=ways(half);

                if(w>=k) {
                    left.push_back(char('a'+c));
                    break;
                }

                k-=w;
                half[c]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        return left+mid+right;
    }
};