#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>

using namespace std;

namespace fast_sort{

class Solution {
   public:
    /*
     * 与快排算法中的划分算法一样，返回划分后基点的位置。
     */
    int partition(vector<int>& arr, int left, int right) {
        int pivot = left;
        int lt = left + 1;
        int gt = right;
        while (true) {
            while (lt <= right && arr[lt] < arr[pivot]) lt++;
            while (gt >= left && arr[gt] > arr[pivot]) gt--;
            if (lt > gt) break;
            swap(arr[lt], arr[gt]);
            lt++;
            gt--;
        }
        swap(arr[pivot], arr[gt]);
        return gt;
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        // 边界情况特殊处理
        if(k >= arr.size()) {
            return arr;
        } else if (k <= 0) {
            return {};
        } else { 
            int left = 0, right = arr.size() -1;
            do {
                int pivot = partition(arr, left, right);
                if(pivot == k){
                    break;
                }else if(pivot > k){
                    right = pivot - 1;
                }else {
                    left = pivot + 1;
                }
            }while(true);        

            vector<int> result(arr.begin(), arr.begin() + k);
            return result;
        }
        
    }
};
}

namespace heap_sort{


class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        
        priority_queue<int> q;
        for(auto c:arr)
        {
            q.push(c);
            if(q.size()>k) q.pop();
        }
        vector<int> res;
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        return res;

    }
};

}


namespace BFPTR_sort{//变体，寻找中位数的中位数时未使用BFPTR，而是递归找中位数
class Solution {
public:

    //插入排序 
    void InsertSort(vector<int>& a,int l,int r){
        for (int i=l+1; i<=r; i++){
            int num=a[i];
            int j=i;
            while (j-1>=l && num<a[j-1]) {
                a[j]=a[j-1];
                j--;		
            }
            a[j]=num;
        }
        return ;
    }
    
    //找key的位置 
    int Find(vector<int>& a,int l,int r,int key){
        for (int i=l; i<=r; i++){
            if (a[i]==key) return i;
        }
        return -1;
    }
    
    //BFPRT算法，找中位数的中位数 
    int BFPRT(vector<int>& a,int l,int r){
        int k=0; //有几个中位数 
        int i=l; //指针i用来遍历【l，r】区间
        while (i+4<=r){ //够分几个组（5个一组） 
            InsertSort(a,i,i+4);//用到插入排序 
            k++;
            swap(a[l+k-1],a[i+2]);
            i+=5;
        } 
        if (i<=r){ //剩下的 
            InsertSort(a,i,r);
            k++;
            swap(a[l+k-1],a[i+(r-i+1)/2]);
        }
        if (k==1) return a[l];
            else return BFPRT(a,l,l+k-1);
    }

    //快速选择算法 
    int QSelect(vector<int>& a,int l,int r,int K){
        if (l>r) return 0;
        int i=l;
        int j=r;
        int key=BFPRT(a,l,r); //利用BFPRT算法来产生基数 
        int k=Find(a,l,r,key);  //寻找基数的位置，也可以设置一个全局变量来传递位置 
        a[k]=a[l];
        while (i<j){
            while (i<j && a[j]>=key) j--;
            a[i]=a[j];
            while (i<j && a[i]<=key) i++;
            a[j]=a[i];
        }
        a[i]=key;
        if (K==i+1) return a[i];
        else if (K<i+1) return QSelect(a,l,i-1,K);
        else return QSelect(a,i+1,r,K);
    } 

    //原给定函数
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        int s=0;
        if (k==0) return ans;
        int x=QSelect(arr,0,arr.size()-1,k);
        //cout<<x<<endl;
        //for (int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
        for (int i=0; i<arr.size(); i++){
            if (arr[i]<=x){
                ans.push_back(arr[i]);
                s++;
                if (s==k) break;
            }         
        }
        return ans;
    }
};
}
namespace select{  //标准BFPTR算法
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k == 0 || arr.size() == 0)
        {
            return vector<int>();
        }

        // select(arr, 0, arr.size() - 1, k - 1); //BFPRT

        randomized_select(arr, 0, arr.size() - 1, k - 1);

        return vector<int>(arr.begin(), arr.begin() + k);
    }


    //在[begin, end]进行插入排序
    void insert_sort(vector<int>& arr, int begin, int end)
    {
        for (int i = begin + 1; i <= end; ++i)
        {
            int tmp = arr.at(i);
            int j = i;
            for (; j > begin; --j)
            {
                if (tmp < arr.at(j - 1))
                {
                    arr.at(j) = arr.at(j - 1);
                }
                else
                {
                    break;
                }
            }

            arr.at(j) = tmp;
        }
    }

    //对每组进行插入排序后，取中位数
    int median(vector<int>& arr, int begin, int end)
    {
        insert_sort(arr, begin, end);
        int mid = begin + (end - begin) / 2; //偶数个数，取上中位数
        return arr.at(mid);
    }

    int median_of_medians(vector<int>& arr, int begin, int end)
    {
        //分组，5个一组，最后剩余若不足5个也为一组  对每个组排序（使用插入排序） 取中位数
        int size = end - begin + 1;
        int offset = size % 5 == 0 ? 0 : 1;
        int group_count = size / 5 + offset; //分组数  N / 5 向上取整

        vector<int> medians(group_count); //各组的中位数  

        for (int i = 0; i < medians.size(); ++i)
        {
            int begin_i = begin + i * 5; //第i组begin
            int end_i = begin_i + 4;
            medians.at(i) = median(arr, begin_i, min(end_i, end));
        }

        //选出medians的中位数
        return select(medians, 0, int(medians.size()) - 1, (int(medians.size()) - 1) / 2);
    }

    //BFPRT 从 arr的[begin, end]中选出第i + 1小的数 （如果按升序排序，索引为i）
    int select(vector<int>& arr, int begin, int end, int i)
    {
        if (begin == end)
        {
            return arr.at(begin);
        }

        //获取pivot 中位数的中位数 
        int pivot = median_of_medians(arr, begin, end);

        //根据pivot 进行 partition  
        vector<int> pivot_region = partition(arr, begin, end, pivot);

        if (i >= pivot_region.at(0) && i <= pivot_region.at(1)) //pivot等于区域命中i, 返回pivot
        {
            return pivot;
        }
        else if(i < pivot_region.at(0)) //如果在左边 则左边递归select
        {
            return select(arr, begin, pivot_region.at(0) - 1, i);
        }
        else //如果在右边 则右边递归select
        {
            return select(arr, pivot_region.at(1) + 1, end, i);
        }
    }




    vector<int> partition(vector<int>& arr, int begin, int end, int pivot)
    {
        int less = begin - 1; //小于pivot区域
        int greater = end + 1; //大于pivot区域

        int i = begin;

        while (i < greater)
        {
            if (arr.at(i) < pivot)
            {
                swap(arr.at(i++), arr.at(++less));
            }
            else if (arr.at(i) == pivot)
            {
                ++i;
            }
            else
            {
                swap(arr.at(i), arr.at(--greater));
            }
        }

        return vector<int>{less + 1, greater - 1};
    }

    void randomized_select(vector<int>& arr, int begin, int end, int i)
    {
        if (begin >= end)
        {
            return;
        }

        //在 arr[begin, end]中随机产生pivot
        int pivot_index = begin + rand() % (end - begin + 1);
        int pivot = arr.at(pivot_index);

        vector<int> pivot_region = partition(arr, begin, end, pivot);

        if (i >= pivot_region.at(0) && i <= pivot_region.at(1))
        {
            return;
        }
        else if (i < pivot_region.at(0))
        {
            randomized_select(arr, begin, pivot_region.at(0) - 1, i);
        }
        else
        {
            randomized_select(arr, pivot_region.at(1) + 1, end, i);
        }
    }
};
}

namespace radom_select{
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k == 0 || arr.size() == 0)
        {
            return vector<int>();
        }
        randomized_select(arr, 0, arr.size() - 1, k - 1);

        return vector<int>(arr.begin(), arr.begin() + k);
    }

    vector<int> partition(vector<int>& arr, int begin, int end, int pivot)
    {
        int less = begin - 1; //小于pivot区域
        int greater = end + 1; //大于pivot区域

        int i = begin;

        while (i < greater)
        {
            if (arr.at(i) < pivot)
            {
                swap(arr.at(i++), arr.at(++less));
            }
            else if (arr.at(i) == pivot)
            {
                ++i;
            }
            else
            {
                swap(arr.at(i), arr.at(--greater));
            }
        }

        return vector<int>{less + 1, greater - 1};
    }

    void randomized_select(vector<int>& arr, int begin, int end, int i)
    {
        if (begin >= end)
        {
            return;
        }

        //在 arr[begin, end]中随机产生pivot
        int pivot_index = begin + rand() % (end - begin + 1);
        int pivot = arr.at(pivot_index);

        vector<int> pivot_region = partition(arr, begin, end, pivot);

        if (i >= pivot_region.at(0) && i <= pivot_region.at(1))
        {
            return;
        }
        else if (i < pivot_region.at(0))
        {
            randomized_select(arr, begin, pivot_region.at(0) - 1, i);
        }
        else
        {
            randomized_select(arr, pivot_region.at(1) + 1, end, i);
        }
    }
};    
}
    /*
Link: https://leetcode-cn.com/problems/smallest-k-lcci/
date: 2020/11/05
Author: qingfu
*/

//BFPTR    SELECT算法返回n个元素的输入数组中第i小的元素
//   int select(vector<int>& arr, int begin, int end, int i);

// 1.将输入数组的n个元素划分为Ln/5组，每组5个元素，且至多只有一组由剩下的个元素组成。
// 2.寻找这「n/5组中每一组的中位数：首先对每组元素进行插人排序，然后确定每组有序元素的中位数
// 3.对第2步中找出的「n/5个中位数，递归调用 SELECT以找出其中位数x（如果有偶数个中位数，为了方便，约定x是较小的中位数）
// 4.利用修改过的 PARTITION版本，按中位数的中位数x对输人数组进行划分。让k比划分的低区中的元素数目多1,因此x是第k小的元素，并且有nーk个元素在划分的高区。
// 5.如果=k，则返回x。如果试k，则在低区递归调用 SELECT来找出第i小的元素。如果>k，则在高区递归査找第一k小的元素