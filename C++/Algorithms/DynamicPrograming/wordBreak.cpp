
/*
 *	Title: Segment a given string into space-separated sequence of the dictionary words.
 *	Input: string and araay of dictionary words
 */
	
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if(wordDict.size()==0) //if no word in dictionary return false.
        return false;
        
	unordered_set<string> dict;  // remove duplicate words from the dictionary
    for (int i = 0; i <wordDict.size(); i++) {
        dict.insert(wordDict[i]);
    }
        
    unordered_set<int> intSet; 
    intSet.insert(0);
        
    vector<bool> dp(s.size()+1,false);
    dp[0]=true;
    int i, j, prev = 0;
    
    for(i=1;i<=s.size();i++)
    {
        unordered_set<int> :: iterator itr; 
        for (itr = intSet.begin(); itr != intSet.end(); itr++) 
        {
            string word = s.substr(*itr, i - *itr);
            if(dict.find(word)!= dict.end())
            {
                dp[i]=true;
                intSet.insert(i);
                break;
            }       
        }
    }   
    
    return dp[s.size()];
}

int main() {
	string str1 = "newtonsappletreecambridge";
	string str2 = "einsteinsappletreecambridge"; //einste is not possible to generate
	vector<string> wordDict{"app", "tee", "tree", "cambridge", "camera", "apple", "new", "newtons", "ton"};
	
	wordBreak(str1, wordDict) ? cout<<str1<<": is possible to generate\n" : cout<<str1<<": is not possible to generate\n";
	wordBreak(str2, wordDict) ? cout<<str2<<": is possible to generate\n" : cout<<str2<<": is not possible to generate\n";
	   
	return 0;
}
	