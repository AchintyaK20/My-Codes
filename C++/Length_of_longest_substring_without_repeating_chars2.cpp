class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> freq(256);
        int l=0,r=0,ans=0;
        for(r=0 ; r<s.size() ; r++)
        {
            freq[s[r]]++;
            while(freq[s[r]]==2)
            {
                freq[s[l++]]--;
            }
        ans = max(ans,r-l+1);
        }
        return ans;
        
    }
};