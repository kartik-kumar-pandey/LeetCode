class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        int temp[n];
        int median=0;
      

        if (nums1.size()>nums2.size()){
            for (int i=0;i<nums1.size();i++){
                temp[i]=nums1[i];
            }
            for (int i=nums1.size();i<n;i++){
                temp[i]=nums2[i-nums1.size()];
            }
        } else{
            for (int i=0;i<nums2.size();i++){
                temp[i]=nums2[i];
            }
            for (int i=nums2.size();i<n;i++){
                temp[i]=nums1[i-nums2.size()];
            }
        }

        sort(temp,temp+n);
        if (n%2!=0){
            return temp[n/2];
        } else {
            return (temp[n/2] +temp[n/2-1])/2.0;
        }
    }
};