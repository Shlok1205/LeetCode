class MyLinkedList
{
public:
    struct Node
    {
        int val;
        Node* next;

        Node(int x)
        {
            val=x;
            next=NULL;
        }
    };

    Node* head;
    int size;

    MyLinkedList()
    {
        head=NULL;
        size=0;
    }

    int get(int index)
    {
        if(index<0 || index>=size)
        {
            return -1;
        }

        Node* temp=head;

        for(int i=0;i<index;i++)
        {
            temp=temp->next;
        }

        return temp->val;
    }

    void addAtHead(int val)
    {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
        size++;
    }

    void addAtTail(int val)
    {
        Node* newNode=new Node(val);

        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node* temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            temp->next=newNode;
        }

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if(index<0 || index>size)
        {
            return;
        }

        if(index==0)
        {
            addAtHead(val);
            return;
        }

        Node* temp=head;

        for(int i=0;i<index-1;i++)
        {
            temp=temp->next;
        }

        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if(index<0 || index>=size)
        {
            return;
        }

        Node* temp=head;

        if(index==0)
        {
            head=head->next;
            delete temp;
        }
        else
        {
            for(int i=0;i<index-1;i++)
            {
                temp=temp->next;
            }

            Node* del=temp->next;
            temp->next=del->next;
            delete del;
        }

        size--;
    }
};