// 원형음악 플레이어//
#include<iostream>
#include<algorithm>
template<typename T>

struct Music 
{
    T* data;
    Music* prev;
    Music* next;
    ~Music()
    {
        delete data;
    }
};


template<typename T>
class Circle_Music{

public:
    using node=Music<T>;
    using node_ptr=node*;

    
private:
    node_ptr head;
    size_t n;
public:
    Circle_Music():n(0)
    {
        head=new node{NULL,NULL,NULL};
        head->next=head;
        head->prev=head;
    }
    size_t size()const{
        return n;
    }

    void insert(const T& value)
    {
        node_ptr newNode=new node{new T(value),NULL,NULL};
        n++;
        auto dummy=head->prev;
        dummy->next=newNode;
        newNode->prev=dummy;
        if(dummy==head)
        {
            dummy->prev=newNode;
            newNode->next=dummy;
            head=newNode;
            return ;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    void erase(const T& value)
    {
        auto cur=head, dummy=head->prev;
        while(cur!=dummy)
        {
            if(*(cur->data)==value)
            {
                cur->prev->next=cur->next;
                cur->next->prev=cur->prev;
                if(cur==head)
                head=head->next;

                n--;
                return;
            }
            cur=cur->next;
        }
    }

struct music_list
{
    private:
        node_ptr ptr;
    public: 
        music_list(node_ptr p):ptr(p){}

        T& operator*()
        {
            return *(ptr->data);
        }
        node_ptr get(){
            return ptr;
        }

        music_list& operator++()
        {
            ptr=ptr->next;
            return *this;
        }
        music_list operator++(int)const{
            music_list result=*this;
            ++(*this);
            return result;
        }
        music_list& operator--()
        {
            ptr=ptr->prev;
            return *this;

        }
        music_list operator--(int)const
        {
            music_list result=*this;
            --(*this);
            return result;

        } 
        friend bool operator==(const music_list& left,const music_list&right)
        {
            return left.ptr==right.ptr;

        }
        friend bool operator!=(const music_list& left, const music_list&right)
        {
            return left.ptr!=right.ptr;
        }
};

    music_list begin()
    {
        return music_list{head};
    }
    music_list begin()const
    {
        return music_list{head};
    }
    music_list end()
    {
        return music_list{head->prev};
    }
    music_list end() const
    {
        return music_list{head->prev};
    }

    Circle_Music(const Circle_Music<T>& other):Circle_Music()
    {
        for(const auto &i: other)
            insert(i);
    }
    Circle_Music(const std::initializer_list<T>&il):head(NULL),n(0){
        for(const auto &i:il)
            insert(i);
    }
    ~Circle_Music()
    {
        while(size())
        {
            erase(*(head->data));
        }
        delete head;
    }
};
template<typename T>
struct playlist
{
    Circle_Music<T> list;

    void insert(T song)
    {
        list.insert(song);
    }
    void erase(T song)
    {
        list.erase(song);
    }
     
     void loopOnce()
      {
        for(auto& song: list)
            std::cout<<song<<" ";
        std::cout<<std::endl;
      }  
};

int main()
{
    playlist<std::string> p1;
    p1.insert("power");
    p1.insert("over");
    std::cout<<"music_List: ";
    p1.loopOnce();

    playlist<std::string> p12=p1;
    p12.erase("over");
    p12.insert("name");
    std::cout<<"Music_List: ";
    p12.loopOnce();

}