class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        int n = A.size();
        vector<int> dp(m+1,0);
        for(int i=0;i<n;++i) {
            //滚动数组(用于减少空间复杂度,提高效率)
            for(int j = m; j>=1;--j) {//一定要倒序开始
                if(j >= A[i]) dp[j] = max(dp[j],dp[j-A[i]]+A[i]);
                else dp[j] = dp[j];
            }
        }
    }
     return dp[m];
};
