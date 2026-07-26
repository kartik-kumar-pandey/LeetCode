class Solution {
public:
    vector<int> getlmax(vector<int>h,int n){
        vector<int> ret(n);
        ret[0] = h[0];
        for (int i = 1; i < n; i++) {
            ret[i] = max(ret[i - 1], h[i]);
        }
        return ret;

    }
    vector<int> getrmax(vector<int>h,int n){
        vector<int>ret(n,0);
        ret[n-1]=h[n-1];
        for(int i=n-2;i>=0;i--){
            ret[i]=max(ret[i+1],h[i]);
        }

        return ret;
    }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left_max=getlmax(height,n);
        vector<int>right_max=getrmax(height,n);
        int ret=0;
        for(int i=0;i<n;i++){
            int curr_h=min(left_max[i],right_max[i])-height[i];
            ret+=curr_h;
        }
        return ret;
    }
};