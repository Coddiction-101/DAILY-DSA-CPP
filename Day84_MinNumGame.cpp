class Solution {
    public int[] numberGame(int[] nums) {
        Arrays.sort(nums);

        int[] ans = new int[nums.length];
        int index = 0;

        for(int i = 0; i < nums.length; i  += 2) {
            ans[index++] = nums[i + 1];
            ans[index++] = nums[i];
        }
        return ans;
    }
}
