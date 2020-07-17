#include<iostream>
using namespace std;

struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* head = NULL;
struct node* tail = NULL;

void insert_at_the_front(int val)
{
    struct node* temp;
    temp = new struct node[sizeof(struct node)];
    temp->left = temp->right = NULL;
    temp->data = val;
    if(head==NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->right = head;
        head->left = temp;
        head = temp;
    }
}

void print_list()
{
    struct node* temp;
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void insert_at_the_end(int val)
{
    struct node* temp;
    temp = new struct node [sizeof(struct node)];
    temp->left = temp->right = NULL;
    temp->data = val;
    if(head==NULL)
    {
        head = tail = temp;
    }
    else
    {
        tail->right = temp;
        temp->left = tail;
        tail = temp;
    }
}

bool search(int val)
{
    struct node* temp;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            break;
        }
        temp = temp->right;
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
    if(z==0)
    {
        cout<<val<<" can not be deleted as it is not present."<<endl;
    }
    else
    {
        struct node* temp;
        temp = head;
        while(temp->data!=val)
        {
            temp = temp->right;
        }
        struct node* it;
        it = temp->left;
        it->right = temp->right;
        it->right->left = it;
        temp->left = temp->right = NULL;
        cout<<val<<" deleted succesfully"<<endl;
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