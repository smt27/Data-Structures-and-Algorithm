//hashtable with only linear probing

#include<iostream>
#include<string>
using namespace std;
#define Tablesize 10


struct node
{
    int id;
    string name;
    long long int tele;
};
struct node* HashTable[Tablesize]={NULL};

int gethash(int ids)
{
    
    return ids%Tablesize;
}
//insertion the data
void insertion(int key,string n,long long int t)
{
    struct node* nn=new node();
    nn->id=key;
    nn->name=n;
    nn->tele=t;
    int hash=gethash(key); 
    //linear probing 
    while(HashTable[hash]!=NULL)
    {
        ++hash;
        hash=hash%Tablesize;
    }
    HashTable[hash]=nn;
    cout<<"\nwe have entered the data in HashTable at "<<hash<<" position";
    
}

//searching the data
struct node* searching(int key)
{
    int hash=gethash(key);
    while(HashTable[hash]!=NULL)
    {
        if(HashTable[hash]->id==key)
        {
            return HashTable[hash];
        }
        hash++;
        hash=hash%Tablesize;
        
    }
    
    return NULL;
    
}

//deletion of data
void deletion(int key)
{
    int hash=gethash(key);
    while(HashTable[hash]!=NULL)
    {
        if(HashTable[hash]->id==key)
        {
            HashTable[hash]=NULL;
            break;
        }
        hash++;
        hash=hash%Tablesize;
        
    }
    if(HashTable[hash]==NULL)
    {
        cout<<"data of id "<<key<<" deleted successfully from "<<hash<<" position";
    }
}

//updating the data
void updating(int key)
{
    struct node* nn=new node();
    int hash=gethash(key);
    nn->id=key;
    cout<<"enter name to be updated for "<<key<<" id";cin>>nn->name;
    cout<<"enter the telephone number for updation: ";cin>>nn->tele;
    while(HashTable[hash]!=NULL)
    {
        if(HashTable[hash]->id==key)
        {
            HashTable[hash]=nn;
            cout<<"the data is successfully updated";
            break;
        }
    }
    
}

int main()
{
    char ch;
    int choice;
    do{
        cout<<"phone directory\n"
            <<"which choice do you prefer?\n1.insertion\n2.searching\n3.deletion\n4.updating : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int id;
                string name;
                long long int tele;
                cout<<"\nenter id";cin>>id;
                cout<<"\nenter name";cin>>name;
                cout<<"\nenter the telephone number:";cin>>tele;
                insertion(id,name,tele);
                break;
            }
            case 2:
            {
                int temp;
                cout<<"\nenter id for searching: ";cin>>temp;
                struct node* result=searching(temp);
                if(result==NULL)
                    cout<<"\ndata not found";
                else
                {
                    cout<<"\nid\tname\ttelephone number";
                    cout<<"\n"<<result->id<<"\t"<<result->name<<"\t"<<result->tele;
                }
                    
                break;
            }
            case 3:
            {
                int temp;
                cout<<"\nenter id to delete : ";cin>>temp;
                deletion(temp);
                break;
            }
            case 4:
            {
                int temp;
                cout<<"\nenter id to update : ";cin>>temp;
                updating(temp);
                break;
            }
            default:
            {
                cout<<"invalid input";
            }
        }
        
        cout<<"\nwant to continue?(y/n)";
        cin>>ch;
    }while(ch=='y');
    return 0;
}