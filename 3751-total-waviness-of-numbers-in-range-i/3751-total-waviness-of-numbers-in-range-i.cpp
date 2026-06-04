int calculateWaviness(int n) {
    int ans = 0;
    vector<int>arr;

    while(n>0) {
        int ld = n%10;
        arr.push_back(ld);
        n = n/10;
    }

    for(int i=0;i<arr.size();i++) {
        if(i==0 || i==arr.size()-1) continue;

        if((arr[i]>arr[i-1] && arr[i]>arr[i+1]) ||
           (arr[i] < arr[i-1] && arr[i] < arr[i+1])) ans+=1;
    }
    

    return ans;
    
}







class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        int ans = 0;

        for(int i=num1;i<=num2;i++) {
            int sum = calculateWaviness(i);
            ans += sum;
        }


        return ans;
    }
};