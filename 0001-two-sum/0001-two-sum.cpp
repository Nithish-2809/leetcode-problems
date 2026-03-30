class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>indexMap;

        for(int i=0;i<n;i++) {
            int complement = target-nums[i];

            if(indexMap.find(complement)!=indexMap.end()) {
                return {i,indexMap[complement]};
            }

            indexMap[nums[i]] = i;
        }

        return {};
    }

};