// Übungsblatt 9
// Aufgabe 4
// Stephan Aures

/*-----------------------------------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class skiplist{
public:
    skiplist();
    ~skiplist();

    void print();
    string *find(int key);
    void insert(int key,string value);
    void erase(int key);
private:
    struct node{
        int key;
        string value;
        vector<node*>forward;
        node(int k,string v,int level): key(k),value(v),forward(level,NULL){}
    };
    //generates random level for a node
    int randomlevel();
    //returns number of pointers
    int nodelevel(node *v);

    node *createnode(int key,string val,int level);
    //returns the first successor of the searched key
    node *lowerbound(int key);
    //returns the last predecessor of the searched key
    vector<node*>predecessor(int key);

    float probability;
    int maxlevel;
    node *head;
    node *tail;
};

skiplist::skiplist() : probability(0.5), maxlevel(16)
{
    int headkey=std::numeric_limits<int>::min();
    head=new node(headkey,"head",maxlevel);

    int tailkey=std::numeric_limits<int>::max();
    tail=new node(tailkey,"tail",maxlevel);

    fill(head->forward.begin(),head->forward.end(),tail);
}

skiplist::~skiplist(){
    auto node=head;
    while(node->forward[0]){
        auto tmp=node;
        node=node->forward[0];
        delete tmp;
    }
    delete node;
}

string *skiplist::find(int searchkey){
    string *res{};
    if(auto x=lowerbound(searchkey)){
        if(x->key==searchkey && x!=tail){
            res=&(x->value);
        }
    }
    return res;
}

void skiplist::print(){
    node *list=head->forward[0];
    int length=0;

    cout<<"{";

    while(list!=NULL){
        cout<<"value: "<<list->value<<", key: "<<list->key<<", level: "<<nodelevel(list);

        list=list->forward[0];
        if(list!=NULL){
            cout<<" : ";
            if(++length%2 == 0){
                cout<<"\n";
            }
        }
    }
    cout<<"}\n";
}

void skiplist::insert(int searchkey, string newvalue){
    auto preds=predecessor(searchkey);

    {
        auto next=preds[0]->forward[0];
        if(next->key==searchkey && next!=tail){
            next->value=newvalue;
            return;
        }
    }

    int newnodelevel=randomlevel();
    auto newnodepointer=createnode(searchkey,newvalue,newnodelevel);

    for(int i=0;i<newnodelevel;i++){
        newnodepointer->forward[i]=preds[i]->forward[i];
        preds[i]->forward[i]=newnodepointer;
    }
}

void skiplist::erase(int searchkey){
    auto preds=predecessor(searchkey);
    auto node=preds[0]->forward[0];
    if(node->key!=searchkey || node==tail){
        return;
    }

    for(size_t i=0; i<nodelevel(node);i++){
        preds[i]->forward[i]=node->forward[i];
    }
    delete node;
}

int skiplist::nodelevel(node *v){
    return v->forward.size();
}

skiplist::node *skiplist::createnode(int key, string val, int level){
    return new node(key,val,level);
}

int skiplist::randomlevel(){
    int v=1;
    while(((double)rand()/RAND_MAX) < probability && v < maxlevel){
        v++;
    }
    return v;
}

skiplist::node * skiplist::lowerbound(int searchkey){
    node *tmp=head;

    for(unsigned int i=nodelevel(head);i-- > 0;){
        while(tmp->forward[i]->key < searchkey){
            tmp=tmp->forward[i];
        }
    }
    return tmp->forward[0];
}

vector<skiplist::node*>skiplist::predecessor(int searchkey){
    vector<node*>result(nodelevel(head),NULL);
    node *tmp=head;

    for(unsigned int i=nodelevel(head);i-- >0;){
        while(tmp->forward[i]->key < searchkey){
            tmp=tmp->forward[i];
        }
        result[i]=tmp;
    }
    return result;
}

int main() {
    skiplist skip;

    for(int i=0;i<50;i++){
        stringstream ss;
        ss<<i;
        skip.insert(i,ss.str());
    }

    skip.print();
    cout<<endl;

    auto f=skip.find(10);
    if(f){
        cout<<"node found: "<<f<<endl;
    } else{
        cout<<"node not found"<<endl;
    }
    return 0;
}