class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numMap = {}
        ret = []
        for idx in xrange(len(nums)):
            num = nums[idx]
            preNumIndex = numMap.get(target - num)
            if preNumIndex is not None:
                return [preNumIndex, idx]
            else:
                numMap[num] = idx

        return []

if __name__ == "__main__":
    s = Solution()
    print s.twoSum([2, 7, 11, 15], 9)