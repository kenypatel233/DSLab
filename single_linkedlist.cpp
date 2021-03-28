//Single linked list operations
#include<iostream>

using namespace std;
class linked_list;

class node
{
    int data;
    node * link;
    public:
        node(int n)
        {
            data = n;
            link = NULL;
        }
friend class linked_list;
friend void concatenate(linked_list &list1,linked_list &list2);

};
class linked_list
{

node *head_ptr; // pointer to header
node *temp_ptr; //access pointer

public :
    static int counter;
    linked_list()
    {
        head_ptr=NULL;
        temp_ptr=NULL;

    }
    void create();
    void display();
    void insert_begin();
    void insert_end();
    void insert_position();
    void delete_first();
    void delete_end();
    void delete_position();
    void reversal();
    friend void concatenate(linked_list &list1,linked_list &list2);




// List Manipulation operations

};
int linked_list::counter=0;
void linked_list::create()
{
    int x,m;
    cout<<"\nEnter no. of nodes to be created:\t";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"\nEnter data for the node:\t";
        cin>>x;
        node *new_node=new node(x);
        if(head_ptr==NULL)//first node
        {
            head_ptr=new_node;
            temp_ptr=new_node;
        }
        else//not the first node to be created
        {
            temp_ptr->link=new_node;
            temp_ptr=new_node;

        }

        cout<<"\nSuccessfully created node";
    }
counter++;
}
void linked_list::display()
{
    if (head_ptr==NULL)
    {
        cout<<"\nEmpty linked list";
        return;
    }
for(temp_ptr=head_ptr; temp_ptr!=NULL; temp_ptr=temp_ptr->link)
{
    cout<<temp_ptr->data;
    cout<<"->\t";

}
cout<<"NULL";
}
void linked_list::insert_begin()
{
    if(counter==0)
    {
        cout<<"Linked list not created";
        return;
    }
    if(head_ptr==NULL)
    {
        cout<<"Linked list is Empty";
        return;
    }
    int x;
    cout<<"Enter data:\t";
    cin>>x;
    node *new_node=new node(x);
    new_node->link= head_ptr;
    head_ptr = new_node;
    cout<<"\nSuccessfully inserted node";
}
void linked_list::insert_end()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    if(head_ptr==NULL)
    {
        cout<<"Linked list is Empty";
        return;
    }
    int x;
    cout<<"Enter data:\t";
    cin>>x;
    node *new_node=new node(x);
    //Traverse temp to last node
    temp_ptr= head_ptr;
    while(temp_ptr->link!=NULL)
    {
        temp_ptr=temp_ptr->link;
    }
    temp_ptr->link=new_node;

    cout<<"\nSuccessfully inserted node";
}
void linked_list::insert_position()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    if(head_ptr==NULL)
    {
        cout<<"Linked list empty";
        return;
    }
    int x,position;
    cout<<"Enter data and position resp:\t";
    cin>>x;
    cin>>position;
    node *new_node=new node(x);
    //Traverse temp to position-1 node
    temp_ptr= head_ptr;
    int i=0;
    if (position==1)
    {
        cout<<"\n Use function insert at beginning";
        return;

    }
    while(i< position-2)
    {
        temp_ptr=temp_ptr->link;

        i++;
    }
    if (temp_ptr->link == NULL)
    {
        cout<<"\n Use function insert at end";
        return;
    }
    else
    {
        new_node->link=temp_ptr->link;
        temp_ptr->link=new_node;
        cout<<"\nSuccessfully inserted node";
    }

}
void linked_list::delete_first()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    if(head_ptr==NULL)
    {
        cout<<"\nEmpty linked list";
        return;
    }
    //Traverse temp to first node
    temp_ptr=head_ptr;
    head_ptr=temp_ptr->link;
    delete(temp_ptr);
    cout<<"\nSuccessfully deleted node";

}
void linked_list::delete_end()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    if(head_ptr==NULL)
    {
        cout<<"\nEmpty linked list";
        return;
    }
    node *q;

    //Traverse temp to second last node
    temp_ptr=head_ptr;
    while(temp_ptr->link->link !=NULL)
    {
        temp_ptr=temp_ptr->link;
    }
    q=temp_ptr->link;
    delete(q);
    temp_ptr->link=NULL;
    cout<<"\nSuccessfully deleted node";
}
void linked_list::delete_position()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    int position;
    cout<<"Enter position :\t";

    cin>>position;

    //Traverse temp to position-1 node
    temp_ptr= head_ptr;
    int i=0;
    if (position==1)
    {
        cout<<"\n Use function delete at beginning";
        return;

    }
    while(i< position-2)
    {
        temp_ptr=temp_ptr->link;

        i++;
    }
    if (temp_ptr->link == NULL)
    {
        cout<<"\n Use function delete at end";
        return;
    }
    else
    {
        node *p =temp_ptr->link;
        temp_ptr->link=p->link;
        delete(p);
        cout<<"\nSuccessfully deleted node";
    }

}
void linked_list::reversal()
{
    if(counter == 0)
    {
        cout<<"Linked list not created";
        return;
    }
    if (head_ptr==NULL)
    {
        cout<<"\nEmpty linked list";
    return;
    }
    node *fwd = head_ptr;
    node *curr=NULL;
    node *prev = NULL;
    while(fwd!=NULL)
    {
        prev = curr;
        curr= fwd;
        fwd=fwd->link;
        curr->link=prev;
    }
    head_ptr=curr;
}
void concatenate(linked_list &list1, linked_list &list2)
{
    list1.create();
    list2.create();
    cout<<"\nList 1 is:\t";
    list1.display();
    cout<<"\nList 2 is :\t";
    list2.display();
    list1.temp_ptr=list1.head_ptr;//Traverse first temp to last node
    while(list1.temp_ptr->link!=NULL)
    {
        list1.temp_ptr=list1.temp_ptr->link;
    }
    list1.temp_ptr->link=list2.head_ptr;

    cout<<"\nConcatenated list(list 2 to list 1) is:\t";list1.display();
}

int main()
{
    linked_list listt,list1,list2;
    int c;
    do
    {
        cout<<"\n************COUNTER:\t"<<linked_list::counter<<"**********\n___MENU___\n 1.Create\n 2.Display\n 3.Insert at beginning\n 4.Insert at end\n 5.Insert at intermediate position\n";
        cout<<"6.Delete at beginning\n 7.Delete at end\n 6.Delete at intermediate position\n 9.Reversal\n 10.Concatenate\n 11.Exit\n";
        cout<<"Enter choice:\t";
        cin>>c;
        switch(c)
        {
        case 1:
            listt.create();
            break;
        case 2:
            listt.display();
            break;
        case 3:
            listt.insert_begin();
            break;
        case 4:
            listt.insert_end();
            break;
        case 5:
            listt.insert_position();
            break;
        case 6:
            listt.delete_first();
            break;
        case 7:
            listt.delete_end();
            break;
        case 8:
            listt.delete_position();
            break;
        case 9:
            listt.reversal();
            break;
        case 10:
            concatenate(list1,list2);
            break;
        case 11:
            exit(1);
            break;
        default:
            cout<<"Enter valid choice\n";

        }
    }while(c<=11);

return 0;

}
