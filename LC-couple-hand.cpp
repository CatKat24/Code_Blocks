/***Function Code***/
/*
N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps 
so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.
The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).
The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.
Example 1:
Input: row = [0, 2, 1, 3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.

Example 2:
Input: row = [3, 2, 0, 1]
Output: 0
Explanation: All couples are already seated side by side.
*/
int swa;
void check(int j,vector<int>&v)
{
    int temp=v[j];
    for(int i=j+1;i<v.size();i++)
    {
        if(temp%2==0&&v[i]==temp+1&&i!=j+1) 
        {
            swa++;
            swap(v[j+1],v[i]);return;
        }
        else if(temp%2!=0&&v[i]==temp-1&&i!=j+1) 
        {
            swa++;
            swap(v[j+1],v[i]);return;
        }
    }
}
class Solution {
public:
    int minSwapsCouples(vector<int>&v) {
        if(v.size()<=0) return 0;
        int temp,i=0;swa=0;
        while(i<v.size())
        {
            check(i,v);
            i+=2;
        }
        return swa;
    }
};
