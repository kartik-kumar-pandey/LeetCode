class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j=0;
        int cnt=0;
        int maxi=*max_element(arr.begin(),arr.end());
        maxi+=k;
        for(int i=1;i<=maxi;i++){
            if(j<arr.size()&&arr[j]==i){
                j++;
            }else{
                cnt++;
            }

            if(cnt==k){
                return i;
            }
        }
        return -1;
    }
};