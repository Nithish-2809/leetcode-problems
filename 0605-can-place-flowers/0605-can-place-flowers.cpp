class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int sz = flowerbed.size();

        if(sz == 1) {
            if(flowerbed[0] == 0) n--;
            return n <= 0;
        }

        if(flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }

        for(int i = 1; i < sz - 1; i++) {
            if(flowerbed[i] == 0 &&
               flowerbed[i-1] == 0 &&
               flowerbed[i+1] == 0) {

                flowerbed[i] = 1;
                n--;
            }
        }

        if(flowerbed[sz-1] == 0 &&
           flowerbed[sz-2] == 0) {

            flowerbed[sz-1] = 1;
            n--;
        }

        return n <= 0;
    }
};