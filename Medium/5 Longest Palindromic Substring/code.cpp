class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1;
        int start = 0;
        for(int i=1;i<s.length()-1;i++){
            int front = i-1;
            int back = i+1;
            int curl = 1;
            while(front >= 0 && back < s.length() && s[front] == s[back]){
                front--;
                back++;
                curl += 2;
            }
            if(curl > length){
                start = front + 1;
                length = curl;
            }
        }
        for(int i=1;i<s.length();i++){
            if(s[i] != s[i-1])
                continue;
            int front = i-2;
            int back = i+1;
            int curl = 2;
            while(front >= 0 && back < s.length() && s[front] == s[back]){
                front--;
                back++;
                curl += 2;
            }
            if(curl > length){
                start = front + 1;
                length = curl;
            }
        }
        return s.substr(start, length);
    }
};