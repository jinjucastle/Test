#include<iostream>
#include<queue>

struct node{
    std::string position;
    node * frist;
    node * second;
};

class org_tree{

    node* root;

public:
static org_tree create_org_structure(const std::string& pos)
{
    org_tree tree;
    tree.root=new node{pos,NULL,NULL};
    return tree;

}

static node* find(node* root,const std::string& value)
{
    if(root==NULL)
    return NULL;
    
    if(root->position==value)
    return root;

    auto firstNode=org_tree::find(root->frist,value);

    if(firstNode!=NULL)
        return firstNode;
    
    return org_tree::find(root->second,value); 
}

bool addSubordinate(const std::string& manager,const std::string& subordinate)
{
    auto managerNode=org_tree::find(root,manager);

    if(!managerNode)
        {
            std::cout<<manager<<" is not found"<<std::endl;
            return false;
        }
    if(managerNode->frist&&managerNode->second)
    {
        std::cout<<"Unable to add "<<subordinate<<" under "<<manager<<std::endl;
        return false;
    }
    if(!managerNode->frist)
    {
        managerNode->frist=new node{subordinate,NULL,NULL};
    }
    else 
        managerNode->second=new node{subordinate,NULL,NULL};

    std::cout<<"Add "<<subordinate<<" Under "<<manager<<std::endl;

    return true;

}

};

int main()
{
     auto tree=org_tree::create_org_structure("CEO");

    tree.addSubordinate("CEO","COO");
    tree.addSubordinate("COO","IT");
    tree.addSubordinate("COO","POWER");
    tree.addSubordinate("IT","SUB");
    tree.addSubordinate("IT","FIND");
    tree.addSubordinate("POWER","LESS");
    tree.addSubordinate("POWER","CURRENT");

    tree.addSubordinate("COO","MOTH");

}