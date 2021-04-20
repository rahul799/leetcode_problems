https://binarysearch.com/room/Weekly-Contest-37-u2kU8duwTB?questionsetIndex=1


Cluster Management
Question 2 of 4
You are given two lists of integers cores and tasks. Each cores[i] represents the number of cores available in server i. And each tasks[i] represents the number of cores needed to run that task.

Each task can be run in only one server but each server can run multiple tasks. Return whether it's possible to run all the tasks with the given cores.

Constraints

n ≤ 15 where n is the length of cores
m ≤ 15 where m is the length of tasks
Example 1
Input
cores = [8, 10]
tasks = [2, 3, 3, 3, 7]
Output
true
Explanation
We can put tasks[0], tasks[1], and tasks[2] into cores[0] and the rest of the tasks into cores[1].

Example 2
Input
cores = [1, 3]
tasks = [2, 2]
Output
false
Explanation
There's no way to run the tasks on these servers.



This is a variant on the multiple knapsack problem. Since the bounds are small, we can try to brute force over all possible combinations of tasks to cores.

There are various optimizations that can be made here. One optimization that greatly speeds up the average case performance of this code is to place tasks in nonincreasing order of size.

Implementation
can will be our recursive backtracking function that tracks whether it is possible to place the tasks in from a[0] to a[idx] in the cores represented in b.

We then just brute force over all the cores and try to place them accordingly.

Time Complexity
The worst-case time complexity of this solution is still \mathcal{O}(N!)O(N!). However, the average case performance of this solution is substantially better due to the order of processing.

Space Complexity
We need \mathcal{O}(N)O(N) stack space to recursively check all the combinations.





// sort the task array, try to do the target with maximum requirement first and then keep on checking the other task



bool can(int idx, vector<int>& a, vector<int>& b) {
    if (idx == a.size()) return true;
    for (int& out : b) {
        if (out >= a[idx]) {
            out -= a[idx];
            if (can(idx + 1, a, b)) return true;
            out += a[idx];
        }
    }
    return false;
}

bool solve(vector<int>& cores, vector<int>& tasks) {
    sort(tasks.begin(), tasks.end(), greater<int>() );
    return can(0, tasks, cores);
}





