class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>s;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()<nums2[i]){
                int x=s.top();
                s.pop();
                mp[x]=nums2[i];
            }
            s.push(nums2[i]);
        }
        while(!s.empty()){
             int x=s.top();
                s.pop();
                mp[x]=-1;
        }
        vector<int> ret;
        for(int i=0;i<nums1.size();i++){
            ret.push_back(mp[nums1[i]]);
        }
        
        return ret;
        
    }
};