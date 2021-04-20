295. Find Median from Data Stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?




class MedianFinder {
public:
    /*
    using 2 heaps
    one min heap
    one max heap
    min heap gets larger number 
    max heap gets smaller number 
    if(minh.size() + maxh.size() is odd) return max_heap's top
    else return (maxtop+mintop)/2
    */
    /** initialize your data structure here. */
    priority_queue<int> max_h;//to keep smaller half
    priority_queue<int, vector<int>, greater<int>> min_h;//to keep larger half
    MedianFinder() {
        max_h =  priority_queue<int>();
        min_h = priority_queue<int, vector<int>, greater<int>>();   
    }
    
    
    // if the number lies on right bucket
    
    // remove top of right bucket, add it into left bicket
    void addNum(int num) {
        if(max_h.size() == min_h.size()) {
            if(min_h.size()!=0 && num > min_h.top()) {
                max_h.push(min_h.top());
                min_h.pop();
                min_h.push(num);
            }
            else max_h.push(num);//keep mid in max_h as max_h->top() 
        }
        else if(max_h.size() > min_h.size()) {
            if(max_h.top() > num) {
                min_h.push(max_h.top());
                max_h.pop();
                max_h.push(num);
            }
            else {
                min_h.push(num);
            }
        }
        else {
            if(min_h.top() < num) {
                max_h.push(min_h.top());
                min_h.pop();
                min_h.push(num);
            }
            else max_h.push(num);
        }
    }
    
    double findMedian() {
        int count = min_h.size() + max_h.size();
        double mid = 0;
        if(count%2 == 1) {
            mid = double(max_h.top());
        }
        else {
            mid = ((double)min_h.top() + (double)max_h.top())/2;
        }
        
        return mid;
    }
};
