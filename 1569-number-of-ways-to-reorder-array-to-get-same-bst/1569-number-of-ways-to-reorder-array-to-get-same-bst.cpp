class Solution {
    static const int MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[0]) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }

        long long ways = C[n - 1][left.size()];
        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;
        return ways;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Pascal's triangle for nCr mod p
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};