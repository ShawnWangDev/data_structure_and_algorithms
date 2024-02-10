// https://leetcode.cn/problems/merge-strings-alternately/solutions/1913930/jiao-ti-he-bing-zi-fu-chuan-by-leetcode-ac4ih/
#include <iostream>

using namespace std;

class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		string ans;
		// reserve() enough memory to hold m + n characters. 
		// This optimization aims to improve performance 
		// by avoiding unnecessary dynamic memory allocations that occur when 
		// adding characters to a string that hasn't pre-allocated sufficient space.
		// The reserve() method is not mandatory, 
		// but it's a good practice to pre-allocate memory 
		// for frequently modified strings to avoid performance overhead 
		// caused by frequent reallocations.
		// ref: https://cplusplus.com/reference/string/string/reserve/
		ans.reserve(m + n);
		for (int i = 0, j = 0; i < m || j < n; i++, j++) {
			if (i < m) {
				ans.push_back(word1[i]);
			}
			if (j < n) {
				ans.push_back(word2[j]);
			}
		}
		return ans;
	}

	// this function didn't planned capacity of the result of the string
	// `int mergedLength = word1Length;` is arbitrary
	// this whole part is gabble and not elegant
	string mergeAlternately_mine(string word1, string word2) {
		int word1Length = word1.length();
		int word2Length = word2.length();
		int mergedLength = word1Length;
		string mergedStr = "";
		string tailStr = "";
		if (word1Length > word2Length) {
			tailStr = word1.substr(word2Length, word1Length - word2Length);
			mergedLength = word2Length;
		}
		else if (word1Length < word2Length) {
			tailStr = word2.substr(word1Length, word1Length - word1Length);
			mergedLength = word1Length;
		}
		for (int i = 0; i < mergedLength; i++) {
			mergedStr += word1.at(i);
			mergedStr += word2.at(i);
		}
		mergedStr += tailStr;
		return mergedStr;
	}
};

int main()
{
	/* Knowledge Summary
	* string.reserve(int n)
	  Requests that the string capacity be adapted to a planned change
	  in size to a length of up to n characters.
	* string.length() and string.size() are same in functionality
	* string.at(int n)
	  Returns a reference to the character at position pos in the string.
	* string.substr(int pos,int len)
	*/
	Solution solution;
	// std::cout << solution.mergeAlternately_mine("abcdefg", "12345");
	std::cout << solution.mergeAlternately("abcdefg", "12345") << std::endl
		<< solution.mergeAlternately("123456789", "xyz") << std::endl;
}
