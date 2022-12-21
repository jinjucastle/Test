#include<iostream>
#include<algorithm>

struct single_ll_node
{
    int data;
    single_ll_node* next;
};

class single_ll
{
public:
    using node=single_ll_node;
    using node_ptr=node*;

private:
        node_ptr head;

public:
    void push_front(int val){

        auto new_node= new node{val, NULL};
        if(head!=NULL)
            new_node->next=head;
        
        head=new_node;

    }
    void pop_front()
    {
        auto first=head;
        if(head)
        {
            head=head->next;
            delete first;
        }
    }

struct single_ll_iterater
{
    private:
        node_ptr ptr;
    
    public:
        single_ll_iterater(node_ptr p): ptr(p){}
        int& operator*(){return ptr->data;}
        node_ptr get(){return ptr;}
    

    single_ll_iterater& operator++(){
        ptr=ptr->next;
        return *this;//ptr을 받아오는듯
    }
    single_ll_iterater operator++(int)
    {
        single_ll_iterater result=*this;
        ++(*this);
        return result;
    }

    friend bool operator==(const single_ll_iterater& left, const single_ll_iterater& right)
    {
        return left.ptr==right.ptr;
    }
    friend bool operator!=(const single_ll_iterater&left, const single_ll_iterater& right)
    {
        return left.ptr!=right.ptr;

    }
};

    single_ll_iterater begin(){return single_ll_iterater(head);}
    single_ll_iterater begin()const{return single_ll_iterater(head);}
    single_ll_iterater end(){return single_ll_iterater(NULL);}
    single_ll_iterater end()const{return single_ll_iterater(NULL);}

    single_ll()=default;

    single_ll(const single_ll& other):head(NULL)
    {
        if(other.head)
        {
            head=new node{0,NULL};
            auto cur=head;
            auto it=other.begin();
            while(true)
            {
                cur->data=*it;

                auto tmp=it;
                ++tmp;
                if(tmp==other.end())
                 break;
                
                cur->next=new node{0,NULL};
                cur=cur->next;
                it=tmp;

            }
        }
    }

    single_ll(const std::initializer_list<int>& ilist):head(NULL)
    {
        for(auto i= std::rbegin(ilist);i!=std::rend(ilist);i++)
                push_front(*i);
    }

};

int main(){
    single_ll sll={1,2,3};
    sll.push_front(0);
    std::cout<<"first list: ";
    for(auto i: sll)
        std::cout<<i<<" ";
    
    std::cout<<std::endl;

    auto sll2=sll;

    sll2.push_front(-1);
    std::cout<<"first list is copy and front add -1: ";
    for(auto i:sll2)
        std::cout<<i<<' ';
    std::cout<<std::endl;

    std::cout<<"deep copy and first list: ";
    for(auto i: sll)
        std::cout<<i<<' ';
        std::cout<<std::endl;
}
