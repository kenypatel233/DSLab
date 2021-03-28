//Singular Doubly linked list operations
#include<iostream>

using namespace std;
class linked_list;

class node
{
    int data;
    node * prev;
    node *next;

    public:
        node(int n)
        {
            data = n;
            prev = NULL;
            next = NULL;
        }
friend class linked_list;
friend void concatenate(linked_list &list1,linked_list &list2);
};

class linked_list
{

node *head_ptr; // pointer to header
node *temp_ptr;


public :
    static int counter;
    static int no;
    linked_list()
    {
        head_ptr=NULL;


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
// List Manipulation operations
    friend void concatenate(linked_list &list1, linked_list &list2);

};

int linked_list::counter=0;
int linked_list::no=0;

void linked_list::create()
{
    int x,m;
    node *t;
    cout<<"\nEnter no. of nodes to be created:\t";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"\nEnter data for the node:\t";
        cin>>x;
        node *new_node=new node(x);
        if(head_ptr==NULL)//first node
        {
            head_ptr= temp_ptr = new_node;


        }
        else//not the first node to be created
        {
            temp_ptr->next=new_node;
            new_node->prev=temp_ptr;
            temp_ptr=temp_ptr->next;

        }
        no++;
        cout<<"\nSuccessfully created node";

    }

counter++;

}
void linked_list::display()
{
     if(counter==0)
    {
        cout<<"Linked list not created";
        return;
    }
    if (head_ptr==NULL)
    {
        cout<<"\nEmpty linked list";
        return;
    }

    cout<<"HEAD -->\t";
for(temp_ptr=head_ptr; temp_ptr!=NULL; temp_ptr=temp_ptr->next)
{
    cout<<"| "<< temp_ptr->data << " |";
    cout<<"\t<-->\t";

}
cout<<"| NULL |";

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
    new_node->next= head_ptr;

    head_ptr->prev = new_node;
    head_ptr=new_node;
    no++;
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
    while(temp_ptr->next!=NULL)
    {
        temp_ptr=temp_ptr->next;
    }
    temp_ptr->next=new_node;
    new_node->prev=temp_ptr;
    no++;
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
    if(position>no || position<0)
    {
        cout<<"invalid position";
        return;

    }
    if (position==1)
    {
        cout<<"\n Use function insert at beginning";
        return;

    }
    while(i< position-2)
    {
        temp_ptr=temp_ptr->next;

        i++;
    }
    if (temp_ptr->next == head_ptr)
    {
        cout<<"\n Use function insert at end";
        return;
    }
    else
    {
        new_node->next=temp_ptr->next;//inserting node b/w temp and its next node
        new_node->prev=temp_ptr;
        temp_ptr->next->prev=new_node;
        temp_ptr->next=new_node;
        no++;
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
    temp_ptr=head_ptr;
    if (no == 1)
    {


        cout<<"Deleting last node";

        no--;
        counter--;
        delete(head_ptr);
        return;
    }

    //Traverse temp to first node
    temp_ptr=head_ptr;
    head_ptr=temp_ptr->next;
    head_ptr->prev=NULL;

    delete(temp_ptr);
    no--;


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
    if (no == 1)
    {


        cout<<"Deleting last node";
        //q=temp_ptr->next;
        //temp_ptr->next=NULL;
        //q->prev=NULL;
        no--;
        counter--;
        delete(head_ptr);
        return;
    }

    else
    {
        while(temp_ptr->next->next !=NULL)
    {
        temp_ptr=temp_ptr->next;
    }
    q=temp_ptr->next;
    temp_ptr->next=NULL;
    q->prev=NULL;
    delete(q);
    no--;
    }

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
    if(position>no || position<=0)
    {
        cout<<"invalid position";
        return;

    }
    if (position==1)
    {
        cout<<"\n Use function delete at beginning";
        return;

    }
    while(i< position-2)
    {
        temp_ptr=temp_ptr->next;

        i++;
    }
    if (temp_ptr->next->next == NULL)
    {
        cout<<"\n Use function delete at end";
        return;
    }
    else
    {


                node *p =temp_ptr->next;
        p->next->prev=temp_ptr;
        temp_ptr->next=p->next;
        no--;
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
    node *curr=head_ptr;//current
    node *t=NULL;
    while(curr!=NULL)
    {
        t=curr->prev;
        curr->prev = curr->next;
        curr->next = t;
        curr = curr->prev;

    }
    if (t!=NULL)
    {
        head_ptr=t->prev;
    }
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
    while(list1.temp_ptr->next!=NULL)
    {
        list1.temp_ptr=list1.temp_ptr->next;
    }
    list1.temp_ptr->next=list2.head_ptr;
    list2.head_ptr->prev=list1.temp_ptr;

    cout<<"\nConcatenated list(list 2 to list 1) is:\n";list1.display();
}

int main()
{

    linked_list listt,list1,list2;
    int c;
    do
    {
        cout<<"\n************COUNTER:\t"<<linked_list::counter<<"\n"<<linked_list::no<<"**********\n___MENU___\n 1.Create\n 2.Display\n 3.Insert at beginning\n 4.Insert at end\n 5.Insert at intermediate position\n";
        cout<<"6.Delete at beginning\n 7.Delete at end\n 8.Delete at intermediate position\n 9.Reversal\n 10.Concatenate\n 11.Exit\n";
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
