#include <iostream>
#include <vector>
#include "leetcodeproblems.h"

using namespace std;

LeetcodeProblems::LeetcodeProblems()
{
    cout<<"Solve leetcode problems"<<endl;
}

vector<int> LeetcodeProblems::runningSum(vector<int> &nums)
{
    int size=nums.size();
    vector<int> storageArr;

    for(int i=0; i<size; i++)
    {
        storageArr.push_back(0);
    }

    for(int i=0; i<size; i++)
    {
        storageArr[i]=(i>0)?storageArr[i-1]+nums[i]:nums[i];
    }

    for(int num:storageArr)
    {
        cout<< num<< " " ;
    }

    return storageArr;
}
