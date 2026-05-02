bool isSelfDividing(int n) {
    int temp = n;

    while(temp!=0) {
        int ld = temp%10;

        if(ld==0 || n%ld!=0) return false;

        temp /= 10;
    }

    return true;
}






class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int>ans;

        for(int i=left;i<=right;i++) {
            if(isSelfDividing(i)) ans.push_back(i);
        }

        return ans;
    }
};