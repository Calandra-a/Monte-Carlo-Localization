#include "partical.cpp"

struct node
{
	partical p;
    node *next;
};

class pVector
{
private:
    node *head,*tail;
public:
    vector()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(particle p)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};