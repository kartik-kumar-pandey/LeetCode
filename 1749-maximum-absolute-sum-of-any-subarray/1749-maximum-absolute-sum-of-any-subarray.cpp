class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int maxsum=0;
        int minsum=INT_MAX;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            maxsum=max(maxsum,sum);
        }
        sum=0;
        for (int i=0;i<n;i++){
            sum+=nums[i];

            minsum=min(minsum,sum);

            if(sum>0){
                sum=0;
            }
        }

        return max(abs(maxsum),abs(minsum));
        
    }
};