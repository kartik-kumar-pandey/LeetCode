class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<pair<string,int>>v;
        for(int i=0;i<n;i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            v.push_back({curr,i});
        }
        sort(v.begin(),v.end());
        vector<vector<string>> ret;
        vector<string>temp;
        temp.push_back(strs[v[0].second]);
        for(int i=1;i<n;i++) {

            if(v[i].first==v[i-1].first){
                temp.push_back(strs[v[i].second]);
            }
            else{
                ret.push_back(temp);
                temp.clear();
                temp.push_back(strs[v[i].second]);
            }
        }

        ret.push_back(temp);

        return ret;
    }
};