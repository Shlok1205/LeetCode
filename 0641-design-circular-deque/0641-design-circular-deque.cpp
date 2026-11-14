class MyCircularDeque
{
    int *arr;
    int front;
    int size;
    int k;

public:
    MyCircularDeque(int k)
    {
        this->k=k;
        arr=new int[k];
        front=0;
        size=0;
    }

    bool insertFront(int value)
    {
        if(size==k)
        {
            return false;
        }

        front=(front-1+k)%k;
        arr[front]=value;
        size++;

        return true;
    }

    bool insertLast(int value)
    {
        if(size==k)
        {
            return false;
        }

        int rear=(front+size)%k;
        arr[rear]=value;
        size++;

        return true;
    }

    bool deleteFront()
    {
        if(size==0)
        {
            return false;
        }

        front=(front+1)%k;
        size--;

        return true;
    }

    bool deleteLast()
    {
        if(size==0)
        {
            return false;
        }

        size--;

        return true;
    }

    int getFront()
    {
        if(size==0)
        {
            return -1;
        }

        return arr[front];
    }

    int getRear()
    {
        if(size==0)
        {
            return -1;
        }

        int rear=(front+size-1)%k;
        return arr[rear];
    }

    bool isEmpty()
    {
        return size==0;
    }

    bool isFull()
    {
        return size==k;
    }
};