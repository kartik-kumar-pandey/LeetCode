class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ret="";
        int n=sentence.size();
        unordered_set<string>st(dictionary.begin(),dictionary.end());

        string curr="";

        for(int i=0;i<n;i++){

            if(sentence[i]!=' '){
                curr+=sentence[i];

                if(st.count(curr)){
                    while(i<n && sentence[i]!=' ') i++;
                    ret+=curr+" ";
                    curr="";
                }
            }else{
                ret+=curr+" ";
                curr="";
            }
        }

        if(curr!=""){
            ret+=curr;
        }

        if(!ret.empty() && ret.back()==' '){
            ret.pop_back();
        }

        return ret;
    }
};