




Number of Sublists That Don't Contain Target List 








Number of Sublists That Don't Contain Target List ❄️
Question 3 of 4
You are given a list of integers nums and a list of unique integers target. Return the number of non-empty sublists in nums that don't contain every number in target. Mod the result by 10 ** 9 + 7.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
0 ≤ m ≤ 100,000 where m is the length of target
Example 1
Input
nums = [1, 2, 2]
target = [1, 2]
Output
4
Explanation
Since these sublists don't contain both 1 and 2: [1], [2], [2], [2, 2].

Example 2
Input
nums = [1, 2, 3]
target = []
Output
0
Explanation
Because target is empty, every sublist contains every element in target





Instead of counting the number of lists that don't contain every number in target, we'll instead count the number of lists that do contain every number in target. The total number of lists is \frac{N^2 + N}{2} 
, so we can subtract these two values to get the answer.

Note that for a given left endpoint ll, as ll moves to the right, the leftmost right endpoint rr such that all values in target are inside this list
can only move to the right. Therefore, we can maintain two pointers and for every such endpoint rr that we find, we can count the number of lists with left 
endpoint at ll that contain every number in target.



const int mod = 1000000007;
int solve(vector<int>& nums, vector<int>& target) {
        if(target.size() == 0) return 0;
        int n = nums.size();
        long long ans = n* (n + 1LL)/2;
        
        unordered_map<int, int> freq;
        unordered_set<int> required(target.begin(), target.end());
        int l = 0;
        
        for(int i = 0; i < n; i++){
                if(required.count(nums[i])) freq[nums[i]]++;
                while(freq.size() == target.size()){
                        ans -= (n - i);
                        cout << ans << " " ;
                if(required.count(nums[l]) ){
                        if(--freq[nums[l]] == 0)
                        freq.erase(nums[l]);
                         
                }
                l++;
                       
                }
        }
        
        return ans%mod;    
}












