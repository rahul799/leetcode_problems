1720. Decode XORed Array
Easy

104

17

Add to List

Share
There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

 

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
Example 2:

Input: encoded = [6,2,7,3], first = 4
Output: [4,2,0,7,4]
 

Constraints:

2 <= n <= 104
encoded.length == n - 1
0 <= encoded[i] <= 105
0 <= first <= 105




ai ^ ai+1 = bi => ai ^ ai+1 ^ ai = bi ^ ai => ai+1 = bi ^ ai

It's easy to create a new array and just append the decoded numbers to it.
What if the interviewer asks you to do it in-place? (For example, you need to decode a (infinite) stream on the fly)

Imagine first is ai and n is bi, we firstly put ai in the ith slot by swapping ai and bi, then calculate ai+1 and store in first.
At the end first will be the last number.

vector<int> decode(vector<int>& encoded, int first) {
	for (int &n : encoded) {
		swap(n, first);
		first ^= n;
	}
	encoded.push_back(first);
	return encoded;
}
