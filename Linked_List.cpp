
/* Question - 1.We Have to Find The Middle Element of the Linked List By
              Traverse only 1 time and in Linear time.

              2.We have to find the Cycle present or not in the Linked List
              */
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *ele;
}*p,*only_for_cycle_question;
node *head1 = new node;
void Insert(node *next,int d)
{
    next->data=d;
    next->ele=nullptr;
    p->ele=next;
    p=next;
}
void print(node *head)
{
    node *curr = new node;
    curr=head;
    while(curr)
    {
        cout<<curr->data<<" ";
        curr=curr->ele;
    }
}
int middle_element(node *head)
{
    node *curr = new node;
    curr=head;
    node *slowptr,*fastptr;
    slowptr=fastptr=curr;
    while(fastptr && fastptr->ele)
    {
        slowptr=slowptr->ele;
        fastptr=fastptr->ele;
        if(fastptr)
        {
            fastptr=fastptr->ele;
        }
    }
    return slowptr->data;
}
void cycle_present_or_not(node *head)
{
    node *curr = new node;
    curr=head;
    node *slowptr,*fastptr;
    slowptr=curr;
    fastptr=curr;
    while(fastptr)
    {
        if(fastptr==nullptr)
        {
            cout<<"No cycle Exist\n";
            return;
        }
        slowptr=slowptr->ele;
        fastptr=fastptr->ele;
        if(fastptr)
        {
            fastptr=fastptr->ele;
        }
        if(fastptr->data==slowptr->data)
        {
            break;
        }
    }
        while(slowptr->data!=curr->data)
           {
             slowptr=slowptr->ele;
               curr=curr->ele;
           }
           node *temp = new node;
           int value=slowptr->data;
           temp=slowptr;
           cout<<temp->data<<" ";
           temp=temp->ele;
        while(temp->data!=value)
           {
              cout<<temp->data<<" ";
              temp=temp->ele;
           }
  
} 
void Reverse_LinkedList(node *prev,node *head)
{
   if(head==NULL)
   {
       head1=prev;
       return;
   }
   node *curr=head;
   node *temp=curr->ele;
   Reverse_LinkedList(curr,temp);
   head->ele=prev;
}
int main()
{
  node *head = new node;
  cout<<"Enter the data of Head Element\n";
  int a;
  cin>>a;
  head->data=a;
  head->ele=nullptr;
  p=head;
  int one;
  cout<<"Enter 1 for insert a node\n";
  while(cin>>one)
  {
      if(one!=1)
      {
          break;
      }
      cin>>a;
      node *next = new node;
      Insert(next,a);
    //   if(a==6)
    //   {
    //       only_for_cycle_question=next;
    //   }
     cout<<"Enter 1 for insert a node\n";
  }
//   int middle = middle_element(head);
//   cout<<"Element in Middle is- "<<middle;
  
//    p->ele=only_for_cycle_question;
//    cycle_present_or_not(head);

//    Reverse_LinkedList(nullptr,head);
//    print(head1);
  return 0;
}