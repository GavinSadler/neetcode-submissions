class Solution:

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        out = []

        nums.sort()

        def dfs(i, currentList, total):

            if total == target:
                out.append(list(currentList))
                return
            
            if i >= len(nums):
                return

            if total > target:
                return

            for j in range(i, len(nums)):
                
                if total + nums[j] > target:
                    break

                currentList.append(nums[j])
                dfs(j, currentList, total + nums[j])
                currentList.pop()


        dfs(0, [], 0)

        return out