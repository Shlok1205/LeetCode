class Solution {
    static final int MOD = 1_000_000_007;

    public int[] sumAndMultiply(String s, int[][] queries) {
        int n = s.length();

        int[] prefCount = new int[n + 1];
        int[] prefSum = new int[n + 1];

        StringBuilder nz = new StringBuilder();

        for (int i = 0; i < n; i++) {
            int d = s.charAt(i) - '0';
            prefCount[i + 1] = prefCount[i];
            prefSum[i + 1] = prefSum[i];

            if (d != 0) {
                prefCount[i + 1]++;
                prefSum[i + 1] += d;
                nz.append(s.charAt(i));
            }
        }

        int k = nz.length();

        long[] pow10 = new long[k + 1];
        pow10[0] = 1;
        for (int i = 1; i <= k; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        long[] hash = new long[k + 1];
        for (int i = 0; i < k; i++) {
            int d = nz.charAt(i) - '0';
            hash[i + 1] = (hash[i] * 10 + d) % MOD;
        }

        int[] ans = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            int a = prefCount[l];
            int b = prefCount[r + 1];
            int len = b - a;

            long x = 0;
            if (len > 0) {
                x = (hash[b] - hash[a] * pow10[len]) % MOD;
                if (x < 0) x += MOD;
            }

            long sum = prefSum[r + 1] - prefSum[l];
            ans[i] = (int) ((x * sum) % MOD);
        }

        return ans;
    }
}