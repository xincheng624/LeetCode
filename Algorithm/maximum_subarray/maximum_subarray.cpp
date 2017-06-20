#include <iostream>
using namespace std;
//dp Ì°ÐÄ
/*
class Solution {
public:
	
    int maxSubArray(int A[], int n) {
        if( n <= 0 ) return 0;
        int max = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; ++i){
            if( sum < 0 ) sum = 0;
            sum += A[i];
            if( sum > max )
                max = sum;
        }
        return max;
    }
	

};*/
//·ÖÖÎ
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if( n <= 0 ) return 0;
        return maxSub(A,0,n-1);
    }
    int maxSub(int A[], int begin, int end){
        if( begin == end )
            return A[begin];
        int mid = (begin+end)/2;
         
        int maxL = maxSub(A,begin,mid);
        int maxR = maxSub(A,mid+1,end);
        int maxC = maxSubCross(A,begin,mid,end);
        return max(max(maxL,maxR),maxC);
    }
    int maxSubCross(int A[], int begin, int mid, int end){
        int sumL = INT_MIN;
        int sum = 0;
        for(int i=mid; i>=begin; --i){
            sum += A[i];
            if( sum > sumL )
                sumL = sum;
        }
        int sumR = INT_MIN;
        sum = 0;
        for(int i=mid+1; i<=end; ++i){
            sum += A[i];
            if( sum > sumR )
                sumR = sum;
        }
        return sumL+sumR;
    }
     
};

int main()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout<<s.maxSubArray(a,9)<<endl;
}