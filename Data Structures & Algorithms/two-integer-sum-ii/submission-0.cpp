class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i_1 = 0;
        int i_2 = numbers.size() - 1;
        
        while(numbers[i_1] + numbers[i_2] != target) {
            if (numbers[i_1] + numbers[i_2] > target) {
                i_2--;
            } else if (numbers[i_1] + numbers[i_2] < target) {
                i_1++;
            }
        }

        return {i_1 + 1, i_2 + 1};
    }
};