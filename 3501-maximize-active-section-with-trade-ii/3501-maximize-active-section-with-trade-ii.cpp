#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Group {
    int start;
    int length;
};

class SparseTable {
public:
    SparseTable(const vector<int>& nums) : n(nums.size()), st(bitLength(nums.size()), vector<int>(nums.size())) {
        for (int i = 0; i < n; ++i)
            st[0][i] = nums[i];
        for (int i = 1; i < st.size(); ++i)
            for (int j = 0; j + (1 << i) <= n; ++j)
                st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }

    int query(int l, int r) const {
        if (l > r) return 0;
        const int i = bitLength(r - l + 1) - 1;
        return max(st[i][l], st[i][r - (1 << i) + 1]);
    }

private:
    int n;
    vector<vector<int>> st;
    int bitLength(int n) const {
        return n == 0 ? 0 : 32 - __builtin_clz(n);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int n = s.length();
        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        const auto [zeroGroups, zeroGroupIndex] = getZeroGroups(s);

        if (zeroGroups.empty())
            return vector<int>(queries.size(), ones);

        const vector<int> zeroMergeLengths = getZeroMergeLengths(zeroGroups);
        const SparseTable st(zeroMergeLengths);
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& query : queries) {
            const int l = query[0];
            const int r = query[1];
            const int left = zeroGroupIndex[l] == -1
                                 ? -1
                                 : (zeroGroups[zeroGroupIndex[l]].length -
                                    (l - zeroGroups[zeroGroupIndex[l]].start));
            const int right = zeroGroupIndex[r] == -1
                                  ? -1
                                  : (r - zeroGroups[zeroGroupIndex[r]].start + 1);

            const int startAdj = zeroGroupIndex[l] + 1;
            const int endAdj = (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1) - 1;

            int activeSections = ones;

            if (s[l] == '0' && s[r] == '0' && zeroGroupIndex[l] + 1 == zeroGroupIndex[r])
                activeSections = max(activeSections, ones + left + right);
            else if (startAdj <= endAdj)
                activeSections = max(activeSections, ones + st.query(startAdj, endAdj));

            if (s[l] == '0' && zeroGroupIndex[l] + 1 <= (s[r] == '1' ? zeroGroupIndex[r] : zeroGroupIndex[r] - 1))
                activeSections = max(activeSections, ones + left + zeroGroups[zeroGroupIndex[l] + 1].length);

            if (s[r] == '0' && zeroGroupIndex[l] < zeroGroupIndex[r] - 1)
                activeSections = max(activeSections, ones + right + zeroGroups[zeroGroupIndex[r] - 1].length);

            ans.push_back(activeSections);
        }

        return ans;
    }

private:
    pair<vector<Group>, vector<int>> getZeroGroups(const string& s) {
        vector<Group> zeroGroups;
        vector<int> zeroGroupIndex;
        zeroGroupIndex.reserve(s.length());

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    ++zeroGroups.back().length;
                else
                    zeroGroups.push_back({i, 1});
            }
            zeroGroupIndex.push_back(zeroGroups.empty() ? -1 : (int)zeroGroups.size() - 1);
        }
        return {zeroGroups, zeroGroupIndex};
    }

    vector<int> getZeroMergeLengths(const vector<Group>& zeroGroups) {
        if (zeroGroups.size() < 2) return {};
        vector<int> res(zeroGroups.size() - 1);
        for (size_t i = 0; i < res.size(); ++i)
            res[i] = zeroGroups[i].length + zeroGroups[i + 1].length;
        return res;
    }
};