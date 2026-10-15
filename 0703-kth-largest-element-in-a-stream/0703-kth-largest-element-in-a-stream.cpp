
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minH;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;

        for(int i = 0; i < nums.size(); i++) {
            minH.push(nums[i]);

            if(minH.size() > kth) {
                minH.pop();
            }
        }
    }
    
    int add(int val) {
        minH.push(val);

        if(minH.size() > kth) {
            minH.pop();
        }

        return minH.top();
    }
};
