//Binary tree(Dynamic implementation + Traversal)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class b_tree;
class node
{
    int data;
    node* left;
    node* right;

public:
    node(int m)
    {
        data=m;
        left=NULL;
        right=NULL;
    }
    friend class b_tree;

};

class b_tree
{


public:
    static int counter;
    node *root;
    b_tree()
    {
        root=NULL;
    }
    void create();
    void preorder_t(node*);
    void inorder_t(node*);
    void postorder_t(node*);
    void non_rec_preorder();
    void non_rec_inorder();
    void non_rec_postorder();

};
int b_tree::counter=0;
void b_tree::create()
{
  node *temp;
  int d,m;
  char child;
  cout<<"\nEnter no. of elements to be attached:\t";
  cin>> m;
  for(int i=0;i<m;i++)
  {
      cout<<"Enter element:\t";
      cin>>d;
      node *newnode = new node(d);
      if(root==NULL)
      {
          root=newnode;
      }
      else
      {
          temp = root;
          while(1)
          {

              cout<<"Left(l) or right(r) of parent "<< temp->data<<"?";
              cin>>child;
              if(child=='l')
              {
                  if(temp->left==NULL)
                  {
                      temp->left=newnode;
                      break;
                  }
                  else
                  {
                      temp=temp->left;
                      //continue;
                  }
              }
              else
              {
                  if(child=='r')
                  {
                      if(temp->right==NULL)
                  {
                      temp->right=newnode;
                      break;
                  }
                    else
                    {
                      temp=temp->right;
                      //continue;
                    }
                  }

              }
      }

          }
      }

  counter++;
  cout<<"\n Successfully created tree!\n";
}
void b_tree::preorder_t(node *root)//data,left,right
{
    node *temp;
    temp=root;
    /*if (root==NULL)
    {
        cout<<"\nEmpty tree.\n";
        return;
    }*/

        if(temp != NULL)
        {
            cout<<temp->data<<"\t";
            preorder_t(temp->left);
            preorder_t(temp->right);

        }


}
void b_tree::inorder_t(node *root)//left,data,right
{
    node *temp;
    temp=root;
    /*if (root==NULL)
    {
        cout<<"NULL\t";
        return;
    }*/

        if(temp != NULL)
        {

            inorder_t(temp->left);
            cout<<temp->data<<"\t";
            inorder_t(temp->right);

        }

}
void b_tree::postorder_t(node *root)//left,right,data
{
    node *temp;
    temp=root;
    /*if (root==NULL)
    {
        cout<<"\nEmpty tree.\n";
        return;
    }*/

        if(temp != NULL)
        {

            postorder_t(temp->left);
            postorder_t(temp->right);
            cout<<temp->data<<"\t";

        }

}

void b_tree::non_rec_inorder()
{
    stack <node*> s;
    node *temp =root;
    if(root==NULL){ return;}
    cout<<"Non-recursive in-order traversal:\t";
    while(s.empty()==false || temp!=NULL)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        //temp will be Null
        temp=s.top();
        s.pop();
        cout<<temp->data<<"\t";
        temp=temp->right;

    }


}
void b_tree::non_rec_preorder()
{
    stack <node*> s;
    node *temp =root;
    if(root==NULL){ return;}
    s.push(root);
    cout<<"Non-recursive pre-order traversal:\t";
    while(s.empty()==false)
    {
        temp=s.top();
        s.pop();
        cout<<temp->data<<"\t";

        //push right first (during pop left will come first)
        if(temp->right)
        {
            s.push(temp->right);
        }
        if(temp->left)
        {
            s.push(temp->left);
        }



    }


}

void b_tree::non_rec_postorder()
{
    node *temp=root;
    if(root==NULL)
        return;
    stack <node*> s;
    cout<<"Non-recursive post-order traversal:\t";
    while(true)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()){return;}
        temp=s.top();
        s.pop();
        if(!s.empty() && s.top()==temp)
        {
            temp=temp->right;
        }
        else
        {
            cout<<temp->data<<"\t";
            temp=NULL;
        }
    }
}
int main()
{
    b_tree tree1;
    int c;
    do
    {
        cout<<"\n************COUNTER:\t"<<b_tree::counter<<"**********\n___MENU___\n 1.Create\n 2.Rec. preorder\n 3.Rec. inorder\n 4. Rec. postorder\n ";
        cout<<"5.Non-rec. preorder \n 6.Non-rec. inorder\n 7.Non-rec. postorder\n  8.Exit\n";
        cout<<"Enter choice:\t";
        cin>>c;
        switch(c)
        {
        case 1:
            tree1.create();
            break;
        case 2:
            tree1.preorder_t(tree1.root);
            break;
        case 3:
            tree1.inorder_t(tree1.root);
            break;
        case 4:
            tree1.postorder_t(tree1.root);
            break;
        case 5:
            tree1.non_rec_preorder();
            break;
        case 6:
            tree1.non_rec_inorder();
            break;
        case 7:
            tree1.non_rec_postorder();
            break;

        case 8:
            exit(1);
            break;
        default:
            cout<<"Enter valid choice\n";

        }
    }while(c<=8);

return 0;

}
/*
void b_tree::non_rec_postorder()
{
    stack <node*> s;

    if(root==NULL){  return;}
    node *temp = root;
    cout<<"Non-recursive post-order traversal:\t";
    do
    {s
        //go to the leftmost node
        while(temp)
        {
            if(temp->right)
                {s.push(temp->right);} //1. push right child
            s.push(temp);//2. push the root
            temp=temp->left;//3.set temp to left child
        }
        //set the pop item as temp
        temp=s.top();
        s.pop();
        //check if the popped item has a non visited right child
        if(temp->right && s.top()==temp->right)
        {
          //remove right child and push temp back
          s.pop();
          s.push(temp);
          //change temp to visit the right child
          temp=temp->right;

        }
        else
        {
            cout<<temp->data<<"\t";
            temp=NULL;
        }


    }while(!s.empty());



}
*/
