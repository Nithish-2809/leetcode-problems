#include <unordered_set>

class Solution {
private:
    int sumOfSquares(int n) {
        int sum = 0;
        while (n != 0) {
            int ld = n % 10;
            sum += ld * ld;
            n = n / 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;

        // Keep looping until n becomes 1 or we detect a duplicate
        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumOfSquares(n);
        }

        // If the loop terminated because n reached 1, it's a happy number
        return n == 1;
    }
};
