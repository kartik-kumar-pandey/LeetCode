class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int max=0;
        int count=0;

        for(int i=1;i<skills.size();i++){
            if(skills[max]>skills[i]){
                count++;
            }else{
                max=i;
                count=1;
            }

            if(count==k) return max;
        }

        return max;
    }
};