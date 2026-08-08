class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=0;
        int left=0;
        int right=height.size()-1;

        while(left<right){
            int width=right-left;

            int curr=min(height[left],height[right])*width;
            ret=max(ret,curr);
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }

        return ret;
    }
};