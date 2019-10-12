﻿
#pragma region 565_数组嵌套
/*
索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到并返回最大的集合S，S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

示例 1:

输入: A = [5,4,0,3,1,6,2]
输出: 4
解释:
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
注意:

N是[1, 20,000]之间的整数。
A中不含有重复的元素。
A中的元素大小在[0, N-1]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-nesting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
	// 将重复的标记即可, 不必暴力每次都重复计算
	//Runtime : 24 ms, faster than 57.15 % of C++ online submissions for Array Nesting.
	//Memory Usage : 9.8 MB, less than 81.82 % of C++ online submissions for Array Nesting.
	int arrayNesting(vector<int>& nums) {
		vector<bool> numFlags(nums.size());
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (!numFlags[i])
			{
				int count = 0;
				int nextIndex = i;
				do
				{
					++count;
					numFlags[nextIndex] = true;
					nextIndex = nums[nextIndex];
				} while (!numFlags[nextIndex]);
				res = max(res, count);
			}
		}
		return res;
	}
};

#pragma endregion
