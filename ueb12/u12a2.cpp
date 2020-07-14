// Übungsblatt 12
// Aufgabe 2
// Stephan Aures


/*-----------------------------------------*/

#include <iostream>
  
using namespace std;

struct node 
{
    int key; // Wert
    int element;
    struct node *link;
};
  
class PQueue
{
private:
    node *front;
public:
    PQueue()
    {
        this->front = NULL;
    }
    ~PQueue(){}

    void Insert(int element, int key)
    {
        node *tmp, *q;
        tmp = new node;
        tmp->key = key;
        tmp->element = element;
        if (front == NULL || element < front->element)
        {
            tmp->link = front;
            front = tmp;
        }
        else
        {
            q = front;
            while (q->link != NULL && q->link->element <= element)
            {
               q = q->link; 
            } 
            tmp->link = q->link;
            q->link = tmp;
        }
    }

    void Display()
    {
        node *p;
        p = this->front;
        if (this->front == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            while (p != NULL)
            {
                cout << "Element: " << p->element << endl;
                cout << "Key:     " << p->key << endl;
                cout << "----------------" << endl;
                p = p->link;
            }
        }   
    }

    int GetMin()
    {
        if(front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return 0;     
        }
        return this->front->key;
    }

    int ExtractMin()
    {
        GetMin();
        if(front == NULL)
        {
            cout << "Queue is empty!" << endl;
            return 0;     
        }
        
        // todo
        
        return 0;
    }

    void DecreaseKey(int element, int position, int minus);
}; 
  
int main() 
{ 
    PQueue pq;
    pq.Insert(5, 5);
    pq.Insert(3, 2);
    pq.Insert(2, 1);
    pq.Insert(1, 100);
    pq.Insert(4, 20);

    pq.Display();
/*
    if(pq.ExtractMin() == 0)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << pq.ExtractMin() << endl;
    }
*/    
    

    return 0;
}