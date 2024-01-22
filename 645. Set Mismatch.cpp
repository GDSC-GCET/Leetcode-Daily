class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int total = (n * (n + 1)) / 2;
        int sum = nums[0];
        int duplicate = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                duplicate = nums[i];

            sum += nums[i];
        }

        int missing = total - (sum - duplicate);

        return {duplicate, missing};
    }
};

//The array nums is sorted in ascending order using sort(nums.begin(), nums.end()). This makes duplicate elements adjacent to each other.
//A variable duplicate is initialized to -1, and a variable sum is initialized with the value of the first element in the sorted array.
//A loop iterates through the sorted array starting from index 1. If the current element is equal to the previous element, it means a duplicate is found, and its value is stored in the duplicate variable. The sum of elements is also calculated during this process.
//The total sum of numbers from 1 to n is calculated using the formula (n * (n + 1)) / 2.
//The missing number is computed by subtracting the sum of the array (excluding the duplicate) from the total sum.
