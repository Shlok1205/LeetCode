class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n && ok; start += k) {
                int descents = 0;
                int mn = INT_MAX, mx = INT_MIN;

                for (int i = 0; i < k; i++) {
                    int cur = nums[start + i];
                    int nxt = nums[start + (i + 1) % k];
                    if (cur > nxt) descents++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }

                // block rotation of sorted hona chahiye
                if (descents > 1) { ok = false; break; }

                // pichhle block ka max <= is block ka min
                if (prevMax > mn) { ok = false; break; }
                prevMax = mx;
            }

            if (ok) total += k;
        }
        return total;
    }
};