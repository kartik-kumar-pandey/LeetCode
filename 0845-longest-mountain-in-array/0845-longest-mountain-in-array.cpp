class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ret=0;
        for (int i=0;i<n;i++){
            int left=i;
            int right=i;

            while(left>0&&arr[left-1]<arr[left])
                left--;

            while(right+1<n&&arr[right]>arr[right+1])
                right++;
            if (left == i || right == i)
                continue;

            ret = max(ret, right - left + 1);
        }

        return ret;
    }
};