#include<iostream>
#include<queue>

class Job{
private:
    int JobNumber;
    std::string name;
    int pageNumber;
    
public:
    static int JobCount; 
public:
    Job(std::string U,int P):JobNumber(++JobCount),name(U),pageNumber(P){}

    friend std::ostream& operator<<(std::ostream&os ,const Job& J)
    {   
        os<<"id: "<<J.JobNumber<<", name; "<<J.name<<", the number of Page: "<<J.pageNumber<<std::endl;
        return os;
    }

};
int Job::JobCount=0;
template<size_t N>
class Printer{

    std::queue<Job>currnetPrint;
    public:
       

        bool addPrint(const Job& Jobs){

          if(currnetPrint.size()==N){
            std::cout<<"Woakload is full"<<Jobs<<std::endl;
            return false; 
          }
          std::cout<<"add Print:"<<Jobs<<std::endl;
            currnetPrint.push(Jobs);
            return true;  
        }
        void PrintStart()
        {
            while(not currnetPrint.empty())
            {
                std::cout<<"is press"<<currnetPrint.front()<<std::endl;
                currnetPrint.pop();
                
            }

        }
};

int main()
{
    Printer<5> Printer;

    Job j1("Lee",10);
    Job j2("kim",3);
    Job j3("park",14);
    Job j4("oh",2);
    Job j5("choi",6);
    Job j6("Lee",8);
    
    Printer.addPrint(j1);
    Printer.addPrint(j2);
    Printer.addPrint(j3);
    Printer.addPrint(j4);
    Printer.addPrint(j5);
    Printer.addPrint(j6);
    Printer.PrintStart();

    Printer.addPrint(j6);
    Printer.PrintStart();
    
}