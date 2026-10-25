class linkedList
{
private:
    int value;
    linkedList *next;

public:
    linkedList(int v)
    {
        value = v;
    };
};
linkedList *n1 = new linkedList(10);
linkedList *n2 = new linkedList(20);
linkedList *n3 = new linkedList(30);
linkedList *n4 = new linkedList(40);