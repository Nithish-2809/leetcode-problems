class Solution {
public:

    bool solve(vector<int>& arr, int idx, vector<bool>& visited) {
        int n = arr.size();
        if (idx < 0 || idx >= n) return false;
        if (visited[idx]) return false;
        if (arr[idx] == 0) return true;
        visited[idx] = true;
        int jump = arr[idx];
        return solve(arr, idx + jump, visited) ||
               solve(arr, idx - jump, visited);
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);

        return solve(arr, start, visited);
    }
};