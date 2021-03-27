//BFS graph using matrix

#include<iostream>
using namespace std;

void bfs(int v)
{
    Queue q;
    int visited[vertices]=0;
    q.enQueue(v);
    visited[v]=1;
    while(!q.isEmpty)
    {
        int printvertex=q.deQueue[];
        cout<<" "<<printvertex<<endl;
        for(int i=0;i<vertices;i++)
        {
            if(adjecency[printvertex][i]==1 && visited[i]==0)
            {
                q.enQueue[i];
                visited[i]=1;
            }
        }
    }
}

BFS(G,s)
{
    
}










//BFS graph using list

#include<iostream>
using namespace std;

void bfs(int v)
{
    Queue q;
    int visited[vertices]={0};
    q.enQueue(v);
    visited[v]=1;
    while(!q.isEmpty)
    {
        int printvertex=q.deQueue[];
        cout<<" "<<printvertex<<endl;
        AdjListNode* temp= total[printvertex].head;
        while(temp!=NULL)
        {
            if(visited[temp->dest]==0)
            {
                q.enQueue[temp->dest];
                visited[temp->dest]=1;
            }
            temp=temp->next;
        }
    }
}

BFS(G,s)
{
    
}
