#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
   Node* next;
   Node()
   {
	this->data=0;
	this->next=NULL;
   }
   Node(int data)
   {
	 this->data=data;
     this->next=NULL;
   }
};

void insertNodeEnd(Node* &head,int val)
{
  Node* temp=head;
  if(head==NULL)
  {
	head=new Node(val);
	return;
  }
  while(temp->next!=NULL)
  {
     temp=temp->next;
  }
  temp->next=new Node(val);
}

void btwnNode(Node* head,int val,int posval)
{
	Node* temp=head;
    while(temp->data!=posval)
	{
		temp=temp->next;
	}
	Node* newone=new Node(val);
	newone->next=temp->next;
	temp->next=newone;
}

void headNodeinsert(Node* &head,int val)
{
	Node* temp=head;
	head=new Node(val);
	head->next=temp;
}

void deleteNode(Node* &head,int val)
{
	Node* temp=head;
	if(val!=head->data)
	{
		while((temp->next)->data!=val)
		{
			temp=temp->next;
		}
		Node* toBeDel=temp->next;
		temp->next=toBeDel->next;
		delete toBeDel;
	}
	else
	{
	   Node* del=head;
       head=head->next;
	   delete del;
	}
}

void printLL(Node* head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

Node* reverseLL(Node* head)
{
    Node* prevptr=NULL;
    Node* currptr=head;
    Node* nextptr;
    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
   return prevptr; 
}

void makeCycle(Node* &head,int pos)
{
   Node* temp=head;
   Node* startNode;
   int count=1;
   while(temp->next!=NULL)
   {
      if(count==pos)
      {
         startNode=temp;
      }
      temp=temp->next;
      count++;
   }
   temp->next=startNode;
}

bool detectCycle(Node* head)
{
                      //Floyd's Algorithm 
                      //Hare and Tortoise Algorithm
   Node* slow=head;
   Node* fast=head;

   while(fast!=NULL && fast->next!=NULL)
   {
      slow=slow->next;
      fast=fast->next->next;
      if(fast==slow)
      {
        return true;
      }
   }
   return false;
}

void removeCycle(Node* head)
{
   Node* slow=head;
   Node* fast=head;

   do
   {
      slow=slow->next;
      fast=fast->next->next;
   }while (slow!=fast);
   
   fast=head;
   while(slow->next!=fast->next)
   {
      slow=slow->next;
      fast=fast->next;
   }
   slow->next=NULL;
}

int main()
{
   Node* head=NULL;
   insertNodeEnd(head,5);
   insertNodeEnd(head,1);
   insertNodeEnd(head,12);
   insertNodeEnd(head,23);
   insertNodeEnd(head,25);
   insertNodeEnd(head,45);
   // makeCycle(head,4);
   // cout<<detectCycle(head);
   // btwnNode(head,6,12);
   // headNodeinsert(head,2);
   // deleteNode(head,2);
   // printLL(head);
   // cout<<endl;
   // Node* revLL=reverseLL(head);
   // printLL(revLL);
}

