class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Already sorted? (O(n) adjacent check)
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] > s[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;

        // Unsorted aur length 2 -> impossible
        if (n == 2) return -1;

        // min, max aur unki counts
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        int cntMn = count(s.begin(), s.end(), mn);
        int cntMx = count(s.begin(), s.end(), mx);

        // 1 operation
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // max sirf index 0 par, min sirf last index par -> 3 operations
        if (s[0] == mx && s[n - 1] == mn && cntMn == 1 && cntMx == 1) return 3;

        return 2;
    }
};