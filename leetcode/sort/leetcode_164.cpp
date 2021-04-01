#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;
namespace radix_sort{
//字符串要用+=，避免拷贝构造函数。
//要用稳定排序，或者直接对下标排序？？
// sort(idx.begin(), idx.end(), [&](int& i, int& j) {
//            return words[i].size() < words[j].size() || ((words[i].size() == words[j].size()) && i < j); });


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int exp=1;        //exp：1，10，100，1000....表征数据长度
        int radix=10;     //表示r,基数范围
        int MAX=*max_element(nums.begin(),nums.end());

        vector<int> aux(nums.size());  //临时数组，存储排序结果

        while(MAX/exp>0){
            vector<int> count(radix,0);     //记录同一基数下的元素个数
            for(int i=0;i<nums.size();++i){
                count[(nums[i]/exp)%10]++;
            }
            for(int i=1;i<count.size();++i){   //统计累积计数，最大值必然为nums.size(),每个count代表同一基数的元素排序后位置的最大值
                count[i]+=count[i-1];
            }

            for(int i=0;i<nums.size();++i){
                aux[ --count[(nums[i]/exp)%10] ]=nums[i];
            }
            exp*=10;

        }
        int maxGap=0;
        for(int i=0;i<nums.size();++i){
            maxGap=max(nums[i+1]-nums[i],maxGap);

        }
        return maxGap;

    }
};
}

namespace bucket_sort{

class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
    vector<Bucket> buckets(bucketNum);

    for (auto&& num : nums) {
        int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (auto&& bucket : buckets) {
        if (!bucket.used)
            continue;

        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}
}
    
    




/*
Link: https://leetcode-cn.com/problems/maximum-gap/
date: 2020/11/13
Author: qingfu
*/