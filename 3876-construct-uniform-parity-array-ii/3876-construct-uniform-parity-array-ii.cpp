class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd=INT_MAX;
        int minEven=INT_MAX;

        for(int x:nums1) {
            if(x%2==0)
                minEven=min(minEven,x);
            else
                minOdd=min(minOdd,x);
        }

        // All elements have the same parity
        if(minOdd==INT_MAX || minEven==INT_MAX)
            return true;

        // Convert every even number to odd
        return minOdd<minEven;
    }
};