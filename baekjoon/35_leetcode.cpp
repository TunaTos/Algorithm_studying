#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		
		if (binary_search(nums.begin(), nums.end(), target))
		{
			return std::distance(nums.begin(), find(nums.begin(), nums.end(), target));		
		}
		auto target_iter = std::upper_bound(nums.begin(), nums.end(), target);
		return std::distance(nums.begin(), target_iter);
    }
};

int main(void)
{
	Solution sol;
	vector<int> my_vec1 = vector<int>{1,3,5,6};

	cout << sol.searchInsert(my_vec1,7);


	return (0);
}