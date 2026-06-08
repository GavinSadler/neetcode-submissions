class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        
        out = []
        
        nums.sort()

        for i, a in enumerate(nums):

            # Skip duplicates for first pointer
            if i > 0 and a == nums[i - 1]:
                continue

            l = i + 1
            r = len(nums) - 1

            while l < r:
                ts = a + nums[l] + nums[r]

                if ts < 0:
                    l += 1
                elif ts > 0:
                    r -= 1
                else:
                    out.append([a, nums[l], nums[r]])
                    l += 1

                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
        
        return out
