#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    struct node *next;
    int vertex;
}
node;
node *G[20];  
//heads of linked list
int visited[20];
int n;
void read_graph();
//creating adjacency list
void insert(int,int);  
//insert an edge in adjacency list
void DFS(int);
void main()
{
    int i;
    read_graph();
    //starting with 0
  
for(i=0;i<n;i++)
        visited[i]=0;
    DFS(0);
}
void DFS(int i)
{
    node *p;
  
printf("\n%d",i);
    p=G[i];
    visited[i]=1;
    while(p!=NULL)
    {
       i=p->vertex;
      
   if(!visited[i])
            DFS(i);
        p=p->next;
    }
}
void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices:");
  
scanf("%d",&n);
    //starting G[] with NULL

for(i=0;i<n;i++)
    {
        G[i]=NULL;
        //taking input of Edges and inserting them in G[]
      
printf("Enter number of edges:");
       scanf("%d",&no_of_edges);
       for(i=0;i<no_of_edges;i++)
        {
         printf("Enter an edge(u,v):");
scanf("%d%d",&vi,&vj);
insert(vi,vj);
        }
    }
}
void insert(int vi,int vj)
{
    node *p,*q; 
//creating room at the memory with malloc
q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->next=NULL;
    //inserting vi in the linked list
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {
        //pointing the end of the linked list
        p=G[vi];
      
while(p->next!=NULL)
         p=p->next;
        p->next=q;
    }
}
