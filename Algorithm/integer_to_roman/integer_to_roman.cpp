#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string thous[] = {"", "M", "MM", "MMM"};
        string hundr[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ten[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string one[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return thous[num/1000]+hundr[(num%1000)/100]+ten[(num%100)/10]+one[num%10];
        
        
    }
};

int main()
{
	Solution s;
	cout<<s.intToRoman(278)<<endl;
}