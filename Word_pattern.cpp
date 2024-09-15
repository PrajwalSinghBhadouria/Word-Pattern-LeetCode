class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string st = "";
        if(s.size()==1 && pattern.size()==1){
            if(pattern == s){
                return true;
            }
        }
        if(s==pattern){
            return false;
        }
        bool flag = false;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                flag = true;
                break;
            }
        }
        if(flag){
        vector<string> v;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=' '){
                st = st+s[i];
            }
            else{
                v.push_back(st);
                st = "";
            }
        }
        v.push_back(st);
        if(v.size()>pattern.size()){
            return false;
        }
        map<char,string> mp;
        for(int j=0; j<pattern.size(); j++){
            if(mp.find(pattern[j])==mp.end()){
                mp[pattern[j]] = v[j];
            }
            else{

                if(mp[pattern[j]]!=v[j]){
                    return false;
                }
            }
        }
        map<string,char> smp;
        for(int j=0; j<v.size(); j++){

            if(smp.find(v[j])==smp.end()){
                smp[v[j]] = pattern[j];
            }
            else{

                if(smp[v[j]]!=pattern[j]){
                    return false;
                }
            }
        }
        }
        else{
            if(s.size()>pattern.size()){
                if(pattern.size()==1){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
