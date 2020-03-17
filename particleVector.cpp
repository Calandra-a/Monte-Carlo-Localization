#include "partical.cpp"

struct node
{
	partical p;
	//pointer to a node 
    node *next;
};

class pVector
{
private:
	//creates head and tail nodes
    node *head,*tail;
public:
    //constuctor - sets head and tail nodes to null
    pVector()
    {
    	//head and tail pointers are pointing to null
        head = NULL;
        tail = NULL;
    }

    void push_back(particle p)
    {
    	//node pointer temp points to space allocated for a node 
        node *tmp = new node;
        //tmps particle = passed in particle
        tmp->p = p;
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