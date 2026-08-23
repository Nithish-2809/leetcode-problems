class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;
        
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }

        int totalGrps = 0;

        while(!mp.empty()) {

            int currGrpSize = 0;

            int curr = mp.begin()->first;

            currGrpSize++;

            mp[curr]--;

            if(mp[curr] == 0) {
                mp.erase(curr);
            }

            while(mp.find(curr + 1) != mp.end() &&
                  currGrpSize != groupSize) {

                currGrpSize++;

                mp[curr + 1]--;

                if(mp[curr + 1] == 0) {
                    mp.erase(curr + 1);
                }

                curr++;
            }

            if(currGrpSize == groupSize) {
                totalGrps++;
            }
            else {
                return false;
            }
        }

        return totalGrps * groupSize == n;
    }
};