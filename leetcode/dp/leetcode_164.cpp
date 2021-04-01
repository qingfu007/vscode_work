#include<bits/stdc++.h>

using namespace std;

class Bucket{
public:
    bool used=false;
    int minval=INT_MAX;
    int maxval=INT_MIN;
};


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;

        int MIN=INT_MAX;
        int MAX=INT_MIN;
        for(int& num:nums){
            MIN=min(MIN,num);
            MAX=max(MAX,num);
        }

        int bucketSize = max( 1, (MAX-MIN)/((int)nums.size()-1) );
        int bucketNum = (MAX-MIN)/bucketSize+1;
        vector<Bucket> buckets(bucketNum);
        for(const int& num:nums){
            int Idx=(num-MIN)/bucketSize;
            buckets[Idx].used=true;
            buckets[Idx].minval=min(num,buckets[Idx].minval);
            buckets[Idx].maxval=max(num,buckets[Idx].maxval);
        }
        int maxGap=0,premval=MIN;
        for(const auto&bucket:buckets){
            if(bucket.used==false) continue;
            maxGap=max(maxGap,bucket.minval-premval);
            premval=bucket.maxval;
        }
        return maxGap;

    }
};

  