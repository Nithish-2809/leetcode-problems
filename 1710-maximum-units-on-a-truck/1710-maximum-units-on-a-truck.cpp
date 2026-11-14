class Solution {
public:

    static bool cmp(vector<int>a,vector<int>b) {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int ans = 0;

        for(auto it : boxTypes) {
            int boxes = it[0];
            int units = it[1];

            if(boxes<=truckSize) {
                ans += boxes*units;
                truckSize -= boxes;
            }
            else {
                ans += truckSize*units;
                break;
            }
        }

    return ans;
    }
};