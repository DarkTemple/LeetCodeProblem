# Given a string, find the length of the longest substring without repeating characters.
#
# Examples:
#
# Given "abcabcbb", the answer is "abc", which the length is 3.
#
# Given "bbbbb", the answer is "b", with the length of 1.
#
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_map = {}
        longest_len = 0
        substring_begin = 0
        for i in xrange(len(s)):
            char_idx = char_map.get(s[i], -1)
            if char_idx < substring_begin:
                longest_len = max(longest_len, i-substring_begin+1)
            else:
                substring_begin = char_idx + 1

            char_map[s[i]] = i

        return longest_len


if __name__ == "__main__":
    s = Solution()
    print s.lengthOfLongestSubstring("abcabcb")
    print s.lengthOfLongestSubstring("tmmzuxt")
    print s.lengthOfLongestSubstring("nnn")
    print s.lengthOfLongestSubstring("pwwkew")
    print s.lengthOfLongestSubstring("zbzv")