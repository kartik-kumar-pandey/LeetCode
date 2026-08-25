class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n = nums.length;
        boolean[] visited = new boolean[n + 1];

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] % k == 0) {
                int idx = nums[i] / k;
                if (idx <= n) {
                    visited[idx] = true;
                }
            }
        }

        for (int i = 1; i < visited.length; i++) {
            if (!visited[i]) {
                return i * k;
            }
        }

        return (n + 1) * k;
    }
}