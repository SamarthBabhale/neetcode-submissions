class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(int i=0;i<strs.size();i++){
            // Look at each character in the string
            for(char c : strs[i]) {
                // If it's a comma or our escape character, escape it
                if(c == ',' || c == '\\') {
                    encoded_string += '\\';
                }
                encoded_string += c;
            }
            encoded_string+=",";
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int i=0;
        while(i<s.size()){
            int j=i;
            string str="";
            
            // Your exact inner loop structure, but with escape awareness
            while(j < s.size()){
                if (s[j] == '\\') {
                    // It's an escape character! Skip it and take the next character literally
                    str += s[j+1];
                    j += 2;
                } else if (s[j] == ',') {
                    // This is an unescaped comma, meaning we hit the end of the current string
                    break;
                } else {
                    // A regular character
                    str += s[j];
                    j++;
                }
            }
            i=j+1;
            decoded_strings.push_back(str);
        }

        return decoded_strings;
    }
};
