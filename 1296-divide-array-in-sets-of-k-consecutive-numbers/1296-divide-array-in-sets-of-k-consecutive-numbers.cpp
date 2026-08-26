class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        // Step 1: Count the frequency of each number
        // std::map automatically keeps the keys sorted
        map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Try to form groups starting from the smallest available number
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            int currentNum = it->first;
            int count = it->second;

            // If this number has already been completely used up in previous groups, skip it
            if (count == 0) continue;

            // We need 'count' number of groups starting with 'currentNum'
            // Check if the next k-1 consecutive numbers have enough frequency
            for (int i = 0; i < k; i++) {
                int nextNum = currentNum + i;
                
                // If the consecutive number doesn't have enough copies, it's impossible
                if (counts[nextNum] < count) {
                    return false;
                }
                
                // Deduct the used count
                counts[nextNum] -= count;
            }
        }

        return true;
    }
};
