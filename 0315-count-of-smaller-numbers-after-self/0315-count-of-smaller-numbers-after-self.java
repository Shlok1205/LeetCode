import java.util.*;

class Solution
{
    int[] ans;
    int[] index;
    int[] temp;

    public List<Integer> countSmaller(int[] nums)
    {
        int n=nums.length;

        ans=new int[n];
        index=new int[n];
        temp=new int[n];

        for(int i=0;i<n;i++)
        {
            index[i]=i;
        }

        mergeSort(nums,0,n-1);

        List<Integer> result=new ArrayList<>();

        for(int x:ans)
        {
            result.add(x);
        }

        return result;
    }

    void mergeSort(int[] nums,int left,int right)
    {
        if(left>=right)
        {
            return;
        }

        int mid=(left+right)/2;

        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }

    void merge(int[] nums,int left,int mid,int right)
    {
        int i=left;
        int j=mid+1;
        int k=left;
        int smaller=0;

        while(i<=mid && j<=right)
        {
            if(nums[index[j]]<nums[index[i]])
            {
                temp[k++]=index[j++];
                smaller++;
            }
            else
            {
                ans[index[i]]+=smaller;
                temp[k++]=index[i++];
            }
        }

        while(i<=mid)
        {
            ans[index[i]]+=smaller;
            temp[k++]=index[i++];
        }

        while(j<=right)
        {
            temp[k++]=index[j++];
        }

        for(i=left;i<=right;i++)
        {
            index[i]=temp[i];
        }
    }
}