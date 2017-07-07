#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if( dict.empty() ) return 0;
        queue<string> words;
        dict.insert(end);
        int len = 2;
        addNextWord(start, words, dict);
        while( !words.empty() ){
            int num = words.size();
            for(int i=0; i<num; ++i){
                string queWord = words.front();
                words.pop();
                if( queWord == end )
                     return len;
                addNextWord(queWord, words, dict);
            }
            ++len;
        }
        return 0;
    }
    private:
    void addNextWord(string word, queue<string>& words, unordered_set<string>& dict){
        dict.erase(word);
        int wordLen = word.size();
        for(int i=0; i<wordLen; ++i){
            char letter = word[i];
            for(int j=0; j<26; ++j){
                word[i] = 'a'+j;
                if( dict.find(word) != dict.end() ){
                    words.push(word);
                }
            }
            word[i] = letter;
        }
    }
};



int main()
{
	string start = "hit";
	string end = "dob";
	string dict[] = {"hot","dot","dog","lot","log"};
	unordered_set<string> d(dict,dict+1);
	Solution s;
	cout<<s.ladderLength(start,end,d)<<endl;
}