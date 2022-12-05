//dynamic Array Create

#include<iostream>
#include<sstream>
#include<algorithm>

template<typename T>
class dynamic_array{

private:
    T* date;
    size_t n;

public:
    dynamic_array(int n)
    {
        this->n=n;
        date=new T[n];
    }
    dynamic_array(const dynamic_array<T>&other)
    {
        n=other.n;
        date=new T[n];

        for(int i=0;i<n;i++)
        date[i]=other[i];
    }
    T&operator[](int index)
    {
        return date[index];
    }
    const T& operator[](int index)const
    {
        return date[index];

    }
    T&at(int index)
    {
        if(index<n)
            return date[index];
        throw "Index out of range";

    }
    size_t size()const{
        return n;
    }

    ~dynamic_array()
    {
        delete[] date;
    }
    T* begin(){return date;}
    const T* begin()const{return date;}
    T*end(){return date+n;}
    const T*end()const{return date+n;}

    friend dynamic_array<T>operator+(dynamic_array<T>&a1,dynamic_array<T>&a2)
    {
        dynamic_array<T> result(a1.size()+a2.size());
        std::copy(a1.begin(),a1.end(),result.begin());
        std::copy(a2.begin(),a2.end(),result.begin()+a1.size());
        return result;
    }
    std::string to_string(const std::string& sep=", "){
        if(n==0)
            return "";
            std::ostringstream os;
            os<<date[0];
            for(int i=0;i<n;i++)
            os<<sep<<date[i];
            return os.str();
    }
    
};
struct student{
//private:
    int nstudent;
    std::string name;
/*public:
    student(int n,std::string name):nstudent(n),name(name){};
    std::string getName()const
    {
        return name;
    }
    int getNumber()const{
        return nstudent;
    }*/
};
std::ostream& operator<<(std::ostream& os ,const student& s)
{
    return (os<<"["<<s.name<<","<<s.nstudent<<"]");
}

int main(){

    int nStudent;
    std::cout<<"Enter the number of students in class 1";
    std::cin>>nStudent;
    dynamic_array<student>class1(nStudent);
    for(int i=0;i<nStudent;i++)
    {
        std::string name;
        int standerd;
        std::cout<<"Enter the standerdNumber and studentName: ";
        std::cin>>standerd>>name;
        class1[i]=student{standerd,name};
        
    }
    try{
        class1.at(nStudent)=student{8,"John"};

    }
    catch(...)
    {
        std::cout<<"Exception Occurred"<<std::endl;
    }
    auto class2=class1;
    std::cout<<"Copy 1st class to create 2nd class"<<class2.to_string()<<std::endl;
    auto class3=class2+class1;
    std::cout<<"Class 1 and 2 are combined to create Class 3"<<class3.to_string()<<std::endl;
    
    return 0;
}
