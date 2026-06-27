class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        for (auto& [base, freq] : cnt) {
            if (base == 1) {
                ans = max(ans, 2 * ((cnt[1] - 1) / 2) + 1);
                continue;
            }

            int pairs = 0;
            long long cur = base;

            while (true) {
                // Current level needs >= 2 copies to form a pair
                if (!cnt.count(cur) || cnt[cur] < 2) break;
                
                long long next = cur * cur;
                
                // Check if next level exists (either as pair or center)
                if (!cnt.count(next)) {
                    // cur can be a pair, but there's nothing beyond → cur is NOT a pair
                    // cur becomes the center instead
                    break;
                }
                
                // next exists, so cur contributes a pair
                pairs++;
                cur = next;
            }

            // cur = innermost level; add 1 if it exists at all
            int has_center = cnt.count(cur) ? 1 : 0;
            int length = 2 * pairs + has_center;
            ans = max(ans, length);
        }

        return ans;
    }
};