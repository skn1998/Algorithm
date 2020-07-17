//SINGLY LINKED LISTS//

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* root=NULL;

void insert_at_the_front(int val)
{
    struct node* temp;
    temp = new struct node[sizeof(struct node)];
    temp->data = val;
    temp->next = NULL;
    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
    }
    cout<<"Inserted in the beginning"<<endl;
}

void insert_at_the_end(int val)
{
    struct node* temp;
    temp = new struct node[sizeof(struct node)];
    temp->data = val;
    temp->next = NULL;
    if(root==NULL)
    {
        root = temp;
    }
    else
    {
        struct node* it;
        it = root;
        while(it->next!=NULL)
        {
            it = it->next;
        }
        it->next = temp;
    }
    cout<<"Inserted at the end"<<endl;
}

void print_list()
{
    struct node* temp;
    temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool search(int val)
{
    struct node* temp;
    temp = root;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==NULL)
    {
        return(false);
    }
    return(true);
}

void delete_node(int val)
{
    bool z = search(val);
    if(z==false)
    {
        cout<<val<<" can not be deleted as it is not present"<<endl;
    }
    else
    {
        struct node* temp;
        temp = root;
        while(temp->data!=val)
        {
            temp = temp->next;
        }
        struct node* it;
        it = root;
        while(it->next!=temp)
        {
            it = it->next;
        }
        it->next = temp->next;
        temp->next = NULL;
        cout<<val<<" deleted successfully"<<endl;
    }
}

int main()
{
    bool temp;
    insert_at_the_front(5);
    insert_at_the_front(7);
    insert_at_the_front(-1);
    print_list();
    insert_at_the_end(4);
    insert_at_the_end(1);
    print_list();
    temp = search(12);
    cout<<temp<<endl;
    temp = search(1);
    cout<<temp<<endl;
    delete_node(43);
    delete_node(5);
    print_list();
}