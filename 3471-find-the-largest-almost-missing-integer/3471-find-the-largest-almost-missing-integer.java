import java.util.*;

class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> count = new HashMap<>();
        
        for (int s = 0; s <= n - k; s++) {
            Set<Integer> window = new HashSet<>();
            for (int i = s; i < s + k; i++) {
                window.add(nums[i]);
            }
            for (int v : window) {
                count.put(v, count.getOrDefault(v, 0) + 1);
            }
        }
        
        int best = -1;
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            if (e.getValue() == 1 && e.getKey() > best) {
                best = e.getKey();
            }
        }
        
        return best;
    }
}