/*Sakshi Tendulkar
  SECOC347
*/

//adjecency matrix and list

#include<iostream>
#define size 10
using namespace std;

struct node
{
    int vertex;
    node * next;
};

class adjecency
{
      int v;
      node* hn[size];
      int m[size][size];
      public:
            //default constructor
            adjecency()
            {
                v=0;
                for(int i=0;i<size;i++)
                {
                    hn[i]=NULL;
                }
                for(int i=0;i<size;i++)
                {
                    for(int j=0;j<size;j++)
                    {
                        m[i][j]=0;
                    }
                }
            }//end
            
            void create_mat();
            void create_list();
            void display_mat();
            void display_list();
            void add_edge(int, int);
            
};

void adjecency::create_mat()
{
    int i,j;
    char n;
    cout<<"\nenter the number of vertices: ";
    cin>>v;
    do{
        cout<<"\nenter the pair of vertices: ";
        cin>>i>>j;
        m[i][j]=m[i][j]+1;
        cout<<"\ndo you want to continue?: ";
        cin>>n;
        if(i>=v || j>=v)
        {
            cout<<" \nrange out of scope...";
            break;
        }
    }while(n=='y' || n=='Y');
}


void adjecency::display_mat()
{
    for(int i=0;i<v;i++)
    {
        cout<<"\n";
        for(int j=0;j<v;j++)
        {
            cout<<m[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
//undirected edges
void adjecency::create_list()
{
    int i,j;
    char n;
    cout<<"\nenter the number of vertices: ";
    cin>>v;
    do{
        cout<<"\nenter the edges in pair: ";
        cin>>i>>j;
        add_edge(i,j);
        if(i!=j)
            add_edge(j,i);
        cout<<"do you want to continue? ";
        cin>>n;
    }while(n=='y' || n=='Y');
}


void adjecency::add_edge(int i,int j)  //will create a linked list 
{
    //we will require node
    node* nn, *cn;
    nn= new node;
    nn->vertex=j;
    nn->next=NULL;
    if(hn[i]==NULL)  //array index[i] has no linkes attached
        hn[i]=nn;
    else
    {
        cn=hn[i];
        while(cn->next!=NULL)
            cn=cn->next;
        cn->next=nn;
    }
    
}


void adjecency::display_list()
{
    node* cn;
    for(int i=0;i<=v;i++)
    {
        cn=hn[i];
        
        while(cn!=NULL)
        {
            cout<<i<<"->";
            cout<<cn->vertex<<"\t";
            cn=cn->next;
        }
        cout<<"\n";
    }
}






int main()
{
    adjecency adj;
    int ch;
    do
    {
        cout<<"code for adjecency matrix and list\n";
        cout<<"what would you prefer?\n"
            <<"1.creating adjecency matrix\n"
            <<"2.creating adjecency list\n"
            <<"3.display adjecency matrix\n"
            <<"4.display adjecency list\n"
            <<"5.exit";
        cout<<"\nenter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:{
                adj.create_mat();
                break;
            }
            case 2:{
                adj.create_list();
                break;
            }
            case 3:{
                adj.display_mat();
                break;
            }
            case 4:{
                adj.display_list();
                break;
            }
            case 5:{
                break;
            }
            default:{
                cout<<"invalid input\n";
            }
        }
    }while(ch!=5);
    return 0;
}
