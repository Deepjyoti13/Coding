#include "io.h"

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() < 3)
        return ans;
    vector<int> sums;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += nums[i];
        sums.push_back(nums[i]);
    }
    if (sum == 0)
    {
        ans.push_back(sums);
    }
    for (int i = 3; i < nums.size(); i++)
    {
        sums.push_back(nums[i]);
        sums.erase(sums.begin());
        sum = sum + nums[i] - nums[i - 3];
        if (sum == 0)
            ans.push_back(sums);
    }
    return ans;
}

int main()
{
    inputOutput();
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-6);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(-4);
    vector<vector<int>> answer = threeSum(nums);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << answer[i][j]<<" ";
        }
        cout << endl;
    }
}