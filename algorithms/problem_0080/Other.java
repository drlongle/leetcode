public int removeDuplicates(int[] nums) {
    int i = 0, j = -1, curCnt = 0;
    for (; i < nums.length; i++) {
        if (j < 0 || nums[i] != nums[j]) {
            nums[++j] = nums[i];
            curCnt = 1;
        } else if (curCnt < 2) {
            nums[++j] = nums[i];
            curCnt++;
        }
    }
    return j + 1;
}

