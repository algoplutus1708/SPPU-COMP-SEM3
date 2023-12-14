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
    cout<<endl;
}

Node* merge(Node* &head1,Node* &head2)
{
   Node* p1=head1;
   Node* p2=head2;
   Node* dummyNode=new Node(-1) ;
   Node* p3=dummyNode;

   while(p1!=NULL && p2!=NULL)
   {
    if(p1->data<p2->data)
    {
        p3->next=p1;
        p1=p1->next;
    }
    else
    {
        p3->next=p2;
        p2=p2->next;
    }
    p3=p3->next;
   }
   while(p1!=NULL)
   {
    p3->next=p1;
    p1=p1->next;
    p3=p3->next;
   }
   while(p2!=NULL)
   {
    p3->next=p2;
    p2=p2->next;
    p3=p3->next;
   }
   return dummyNode->next;
}

Node* mergeRecursive(Node* &head1,Node* &head2)
{                      // Recursive way of merging two sorted LL
    if(head1==NULL)
    {
        return head2;
    }
    if(head2==NULL)
    {
        return head1;
    }
    Node* result;
    if(head1->data<head2->data)
    {
        result=head1;
        result->next=mergeRecursive(head->next,head2);
    }
    else
    {
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }
    return result;
}

int main()
{
    Node* head1=NULL;
    Node* head2=NULL;
    int arr1[]={1,4,5,7};
    int arr2[]={2,3,6};
    for(int i=0;i<4;i++)
    {
        insertNodeEnd(head1,arr1[i]);
    }
    for(int j=0;j<3;j++)
    {
        insertNodeEnd(head2,arr2[j]);
    }
    printLL(head1);
    printLL(head2);
    Node* newhead=merge(head1,head2);
    printLL(newhead);
}