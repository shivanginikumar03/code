#include <iostream>
using namespace std;


    struct node{
    
    int data;
    node* link;
    };

class linkedlist{
    public:
    node* start=new node;
    linkedlist(){
        start=NULL;
    }
    void addbet(int x,int pos){
        node* temp=new node;
        node* ptr=new node;
        ptr=start;
         temp->data=x;
         temp->link=NULL;
         int count=2;
         while(count!=pos){
             ptr=ptr->link;
             count++;
         }
         temp->link=ptr->link;
         ptr->link=temp;
    }
    void addstart(int x){
        
        node* temp=new node;
        temp->data=x;
        temp->link=NULL;
        if(start==NULL){
            start=temp;
            return;
        }
        temp->link=start;
        start=temp;
        
    }
    void addend(int x){
        node* temp=new node;
        temp->data=x;
        temp->link=NULL;
        if(start==NULL){
            start=temp;
            return;
        }
        node* ptr;
        ptr=start;
        while(ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=temp;
    }
    node* deletefirstnode(){
        if(start==NULL){
            cout<<"list is already empty"<<endl;
        }
        else{
        node* temp=new node;//link=next,start=head
        temp=start;
        start=temp->link;
        free(temp);
        return start;
        }
    }
    void deletelastnode(){
        if(start==NULL){
            cout<<"list is already empty"<<endl;
            return;
        }
        node* temp;
        temp=start;
        node* ptr=start;   //link=next,start=head
        while(temp->link!=NULL){
            temp=temp->link;
        }
        while(ptr->link!=temp){
            ptr=ptr->link;
        }
        ptr->link=NULL;
        free(temp);
    }
    void deltebetnode(int pos){
        node* current;
        node* previous;
        current=start;previous=start;
        int count=2;
        while(count!=pos){
            previous=previous->link;
            count++;
        }
         count=1;
        while(count!=pos){
            current=current->link;
            count++;
        }
        previous->link=current->link;
        free(current);
    }
    void display(){
        node* ptr=new node;
        if(start==NULL){
            cout<<"empty list"<<endl;
            return; 
        }
        ptr=start;
        while(ptr!=NULL){
            cout<<ptr->data<<" ";
            ptr=ptr->link;
        }
        
    }
   void addtofront(){
        if(start==NULL)
        return;
        if(start->link==NULL)
        return ;
        node* p=start;
        node* q=NULL;
        while(p->link!=NULL){
            q=p;
            p=p->link;
        }
        q->link=NULL;
        p->link=start;
        start=p;
        return;
    }
    void addsorted(int x){
        node* temp=new node;
        temp->data=x;
        temp->link=NULL;
        
        
        if(start==NULL || x<start->data){
            temp->link=start;
            start=temp;
        }
        else{
    node* ptr1;
    ptr1=start;
    
    while(ptr1->link!=NULL && ptr1->link->data < x){
       
        ptr1=ptr1->link;
    }
     temp->link=ptr1->link;
    ptr1->link=temp;
   
    return;
        }   
    
    }
};

int main(){
    
linkedlist l1;

l1.display();
cout<<endl;
l1.addstart(32);
l1.addstart(31);
l1.addend(33);
l1.addend(40);
l1.addend(42);
l1.display();
cout<<endl;

l1.addbet(19,3);
l1.display();
cout<<endl;

l1.deltebetnode(2);
l1.display();
cout<<endl;

l1.deletefirstnode();
l1.display();
cout<<endl;
l1.deletelastnode();
l1.display();
cout<<endl;
l1.addtofront();
l1.display();
cout<<endl;

for(int i=0;i<4;i++)
{
    int x;cin>>x;
 l1.addsorted(x);
}
l1.display();

    return 0;
}