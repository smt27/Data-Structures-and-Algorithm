//hashtable with chaining

#include<iostream>
#include<string>
using namespace std;
#define Tablesize 10


struct node
{
    int id;
    string name;
    long long int tele;
    int chain;
};
struct node* HashTable[Tablesize]={NULL};

int gethash(int ids)
{
    
    return ids%Tablesize;
}
//insertion the data
struct node* insertion(int key,string n,long long int t)
{
    struct node* nn=new node();
    nn->id=key;
    nn->name=n;
    nn->tele=t;
    nn->chain=-1;
    
    int hash=gethash(key);
    int prev=-1;
    if(HashTable[hash]==NULL)
    {
        HashTable[hash]=nn;
        cout<<"\nplaced at "<<hash<<" position in hash table";
        return HashTable[hash];
    }
    //linear probing with chaining
    
    while(HashTable[hash]!=NULL)
    {
        prev=hash;   //stores previous value of hash before probing
        ++hash;
        hash=hash%Tablesize;
       
    }
     
    HashTable[hash]=nn;
    HashTable[prev]->chain=hash;
    cout<<"\nplaced at "<<hash<<" position in hash table";
    return HashTable[hash];
    
    
}

//searching the data
struct node* searching(int key)
{
    int hash=gethash(key);
    while(HashTable[hash]!=NULL)
    {
        
        if(HashTable[hash]->id==key){
            cout<<"\nFound at "<<hash<<" position";
            return HashTable[hash];
        }
        else
        {   
            hash=HashTable[hash]->chain;
            hash=hash%Tablesize;
        }
        
    }
    if (HashTable[hash]->chain==-1)
        return NULL;
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
        cout<<"\ndata of id "<<key<<" deleted successfully from "<<hash<<" position";
    }
}

//updating the data
void updating(int key)
{
    struct node* nn=new node();
    int hash=gethash(key);
    nn->id=key;
    cout<<"\nenter name to be updated for "<<key<<" id";cin>>nn->name;
    cout<<"\nenter the telephone number for updation: ";cin>>nn->tele;
    while(HashTable[hash]!=NULL)
    {
        if(HashTable[hash]->id==key)
        {
            HashTable[hash]=nn;
            cout<<"\nthe data is successfully updated";
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
                struct node* result=insertion(id,name,tele);;
                if(result!=NULL)
                {
                    cout<<"\nwe have entered the data in HashTable";
    
                }
                
                break;
            }
            case 2:
            {
                int temp;
                cout<<"\nenter id for searching: ";cin>>temp;
                struct node* result=searching(temp);
                if(result==NULL)
                    cout<<"\ndata is not present";
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
                cout<<"\ninvalid input";
            }
        }
        
        cout<<"\nwant to continue?(y/n)";
        cin>>ch;
    }while(ch=='y');
    return 0;
}

