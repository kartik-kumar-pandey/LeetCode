class Solution {
public:
	string reformatNumber(string number) {
		string temp; 
		string ret;  
		int n = number.size();

		for(auto ch:number){
			if(isdigit(ch)){
                temp += ch;
            }
        }

		int len = temp.size();
		int i = 0;

		while(len>0){
			if(len > 4){  
				ret += temp.substr(i,i+3);
				temp.erase(i,3);
				len = len-3;
				ret += "-";
			}else if(len == 3){  
				ret += temp.substr(i,i+3);
				temp.erase(i,3);
				len = len-3;
				ret += "-";
			}else if(len == 2){ 
				ret += temp.substr(i,i+2);
				temp.erase(i,2);
				len = len-2;
				ret += "-";
			}else if(len == 4){   
				ret += temp.substr(i,i+2);
				temp.erase(i,2);
				ret += "-";
				len = len-2;

			}
		}
		ret.pop_back();
		return ret;
	}
};