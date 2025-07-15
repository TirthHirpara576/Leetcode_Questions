class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        stack <char> st;
        for(int i=0;i<n;i++){
            char ch=s[i];
            if((ch=='A'||ch=='a')||(ch=='E'||ch=='e')||(ch=='I'||ch=='i')||(ch=='O'||ch=='o')||(ch=='U'||ch=='u')){
                st.push(ch);
            }
        }

        string ans = "";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if((ch=='A'||ch=='a')||(ch=='E'||ch=='e')||(ch=='I'||ch=='i')||(ch=='O'||ch=='o')||(ch=='U'||ch=='u')){
                ans += st.top();
                st.pop(); 
            }
            else{
                ans += ch;
            }
        }
        return ans;
    }
};