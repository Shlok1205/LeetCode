class Solution {
    static constexpr long long MOD = 1e9 + 7;
    vector<long long> sum, sq, lz;

    void apply(int o, int len, long long v) {
        sq[o] = (sq[o] + 2 * v % MOD * sum[o] + v * v % MOD * len) % MOD;
        sum[o] = (sum[o] + v * len) % MOD;
        lz[o] += v;
    }

    void push(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            apply(2 * o, m - l + 1, lz[o]);
            apply(2 * o + 1, r - m, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(o, r - l + 1, 1);
            return;
        }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(2 * o, l, m, ql, qr);
        if (qr > m) update(2 * o + 1, m + 1, r, ql, qr);
        sum[o] = (sum[2 * o] + sum[2 * o + 1]) % MOD;
        sq[o] = (sq[2 * o] + sq[2 * o + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        vector<int> last(100001, -1);
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            update(1, 0, n - 1, last[nums[j]] + 1, j);
            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};