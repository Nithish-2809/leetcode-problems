class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        long long currMass = mass;

        for(auto it : asteroids) {
            if(currMass<it) return false;
            currMass += it;
        }

        return true;
    }
};