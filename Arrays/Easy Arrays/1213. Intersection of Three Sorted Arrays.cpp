Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

 

Example 1:

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.





class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
     vector<int> answer;
    int one = 0;
    int two = 0;
    int three = 0;
    
    while(one < arr1.size() && two < arr2.size() && three < arr3.size()){
        int minEle = min(arr1[one], min(arr2[two], arr3[three]));
        if(arr1[one] ==  arr2[two] && arr1[one] ==  arr3[three])
            answer.push_back(arr1[one]);
        
        if(arr1[one] == minEle)
            one++;
        if(arr2[two] == minEle)
            two++;
        if(arr3[three] == minEle)
            three++;
    }
    return answer;
}   
    
};
