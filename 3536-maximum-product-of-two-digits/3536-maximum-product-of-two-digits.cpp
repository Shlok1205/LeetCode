#include <string>
#include <algorithm>

class Solution{
public:
    int maxProduct(int n){
        std::string s=std::to_string(n);
        std::sort(s.rbegin(),s.rend());
        return (s[0]-'0')*(s[1]-'0');
    }
};