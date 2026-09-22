class Solution
{
    int k;
    int n;
    int[][] prod;
    int[][] pref;

    public int[] resultArray(int[] nums,int k,int[][] queries)
    {
        this.k=k;
        n=nums.length;

        prod=new int[4*n][k];
        pref=new int[4*n][k];

        build(1,0,n-1,nums);

        int[] result=new int[queries.length];

        for(int q=0;q<queries.length;q++)
        {
            int index=queries[q][0];
            int value=queries[q][1];
            int start=queries[q][2];
            int x=queries[q][3];

            update(1,0,n-1,index,value);

            Node node=query(1,0,n-1,start,n-1);

            result[q]=node.pref[x];
        }

        return result;
    }

    public void build(int tree,int left,int right,int[] nums)
    {
        if(left==right)
        {
            int r=nums[left]%k;

            prod[tree][r]=1;
            pref[tree][r]=1;

            return;
        }

        int mid=(left+right)/2;

        build(tree*2,left,mid,nums);
        build(tree*2+1,mid+1,right,nums);

        merge(tree,tree*2,tree*2+1);
    }

    public void update(int tree,int left,int right,int index,int value)
    {
        if(left==right)
        {
            for(int i=0;i<k;i++)
            {
                prod[tree][i]=0;
                pref[tree][i]=0;
            }

            int r=value%k;

            prod[tree][r]=1;
            pref[tree][r]=1;

            return;
        }

        int mid=(left+right)/2;

        if(index<=mid)
        {
            update(tree*2,left,mid,index,value);
        }
        else
        {
            update(tree*2+1,mid+1,right,index,value);
        }

        merge(tree,tree*2,tree*2+1);
    }

    public void merge(int tree,int leftTree,int rightTree)
    {
        for(int i=0;i<k;i++)
        {
            prod[tree][i]=0;
            pref[tree][i]=pref[leftTree][i];
        }

        for(int a=0;a<k;a++)
        {
            for(int b=0;b<k;b++)
            {
                int r=(a*b)%k;

                prod[tree][r]+=prod[leftTree][a]*prod[rightTree][b];

                pref[tree][r]+=prod[leftTree][a]*pref[rightTree][b];
            }
        }
    }

    public Node query(int tree,int left,int right,int ql,int qr)
    {
        if(ql<=left && right<=qr)
        {
            return new Node(prod[tree],pref[tree]);
        }

        int mid=(left+right)/2;

        if(qr<=mid)
        {
            return query(tree*2,left,mid,ql,qr);
        }

        if(ql>mid)
        {
            return query(tree*2+1,mid+1,right,ql,qr);
        }

        Node a=query(tree*2,left,mid,ql,qr);
        Node b=query(tree*2+1,mid+1,right,ql,qr);

        return combine(a,b);
    }

    public Node combine(Node a,Node b)
    {
        int[] newProd=new int[k];
        int[] newPref=new int[k];

        for(int i=0;i<k;i++)
        {
            newPref[i]=a.pref[i];
        }

        for(int x=0;x<k;x++)
        {
            for(int y=0;y<k;y++)
            {
                int r=(x*y)%k;

                newProd[r]+=a.prod[x]*b.prod[y];

                newPref[r]+=a.prod[x]*b.pref[y];
            }
        }

        return new Node(newProd,newPref);
    }

    class Node
    {
        int[] prod;
        int[] pref;

        Node(int[] prod,int[] pref)
        {
            this.prod=prod.clone();
            this.pref=pref.clone();
        }
    }
}