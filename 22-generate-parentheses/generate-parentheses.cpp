class Solution {
public:
 void genratePar (int n , string s,int n1,int n2 ,vector<string>& res){
   if(n1==n&&n2==n)  { res.push_back(s);return;}
    if(n1<n)
    genratePar(n,s+"(",n1+1,n2,res);
    
    if(n1>n2)
    genratePar(n,s+")",n1,n2+1,res);

 }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genratePar(n,"",0,0,res);
        return res;
    }
};