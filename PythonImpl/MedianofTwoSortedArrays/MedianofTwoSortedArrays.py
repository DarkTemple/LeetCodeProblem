# There are two sorted arrays nums1 and nums2 of size m and n respectively.
#
# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#
# Example 1:
# nums1 = [1, 3]
# nums2 = [2]
#
# The median is 2.0
# Example 2:
# nums1 = [1, 2]
# nums2 = [3, 4]
#
# The median is (2 + 3)/2 = 2.5
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        ret = 0
        m, n = len(nums1), len(nums2)
        odd = ((m + n) % 2) == 1
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        if m == 0:
            return nums2[n/2] if odd else (nums2[n/2-1] + nums2[n/2]) / 2.0

        left, right = 0, m
        while left <= right:
            i = (left + right) / 2
            j = (m + n - 2 * i) / 2
            if i > 0 and nums1[i-1] > nums2[j]:
                right = i - 1
            elif i < m and nums1[i] < nums2[j-1]:
                left = i + 1
            else:
                if i == 0:
                    if odd:
                        return min(nums1[0], nums2[j])
                    else:
                        max_left = nums2[j-1]
                        min_right = nums1[i] if m == n else min(nums1[i], nums2[j])
                        return (max_left + min_right) / 2.0

                if i == m:
                    if odd:
                        return nums2[j]
                    else:
                        max_left = nums1[i-1] if m == n else max(nums1[i-1], nums2[j-1])
                        min_right = nums2[j]
                        return (max_left + min_right) / 2.0

                max_left = max(nums1[i-1], nums2[j-1])
                min_right = min(nums1[i], nums2[j])
                return min_right if odd else (max_left + min_right) / 2.0

        return 0

if __name__ == "__main__":
    s = Solution()
    # print s.findMedianSortedArrays([1], [1, 2, 3])
    # print s.findMedianSortedArrays([1, 3], [3, 5])
    # print s.findMedianSortedArrays([3, 5], [1, 4, 7])
    # print s.findMedianSortedArrays([1, 4, 7], [3, 5, 6, 8])
    # print s.findMedianSortedArrays([], [3, 6, 8])
    # print s.findMedianSortedArrays([1,2], [3,4])
    print s.findMedianSortedArrays([1], [2,3,4])
