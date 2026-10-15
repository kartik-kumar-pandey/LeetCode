
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();

        int sum=0;
        int ret=0;
        for(int i=n-1;i>=0;i--){
            if(sum+satisfaction[i]<=0){
                break;
            }
            sum+=satisfaction[i];
            ret+=sum;
            
        }

        return ret;
    }
};
