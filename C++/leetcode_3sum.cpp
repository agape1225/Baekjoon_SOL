#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    //brute force -> O(n^3) -> No
    //two pointer -> n * O(n^2) -> Yes....?
    //binary_search -> log(n)
    //set, find -> log(n)
    //two pointer -> log(n^2)
     vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> answers;
        sort(nums.begin(), nums.end());

        int nums_size = nums.size();
        int target = -987654321;

        for (int i = 0; i < nums_size; i++) {
            if (target == -nums[i])
                continue;

            target = -nums[i];
            int left = i + 1;
            int right = nums_size - 1;
            while (left < right) {
                int tmp = nums[left] + nums[right];

                if (tmp == target) {
                    int left_num = nums[left];
                    int right_num = nums[right];

                    answers.push_back({ nums[i], nums[left], nums[right] });

                    while (left < nums_size && nums[left] == left_num)
                        left++;

                    while (right >= 0 && nums[right] == right_num)
                        right--;
                }
                else if (tmp < target)
                    left++;
                else
                    right--;
            }
        }
        return answers;
    }
};