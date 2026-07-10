import java.util.*;

class Solution {

    public int[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {

        int[][] arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        int[] pos = new int[n];
        int[] comp = new int[n];

        int compId = 0;
        comp[0] = 0;
        pos[arr[0][1]] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i][0] - arr[i - 1][0] > maxDiff) {
                compId++;
            }
            comp[i] = compId;
            pos[arr[i][1]] = i;
        }

        int LOG = 18;
        int[][] up = new int[LOG][n];

        int left = 0;
        while (left < n) {

            int right = left;
            while (right + 1 < n && comp[right + 1] == comp[left]) {
                right++;
            }

            int ptr = left;
            for (int i = left; i <= right; i++) {
                while (ptr + 1 <= right &&
                        arr[ptr + 1][0] - arr[i][0] <= maxDiff) {
                    ptr++;
                }
                up[0][i] = ptr;
            }

            left = right + 1;
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        int[] ans = new int[queries.length];

        for (int q = 0; q < queries.length; q++) {

            int u = pos[queries[q][0]];
            int v = pos[queries[q][1]];

            if (u == v) {
                ans[q] = 0;
                continue;
            }

            if (comp[u] != comp[v]) {
                ans[q] = -1;
                continue;
            }

            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }

            int cur = u;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    jumps += 1 << k;
                }
            }

            ans[q] = jumps + 1;
        }

        return ans;
    }
}