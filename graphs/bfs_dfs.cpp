// Remember 2 words - visiting  and exploration 

#include <iostream>
#include <stdio.h>
#include "Queue.h"

using namespace std;

void BFS(int G[7][7], int start, int n)
{
    int i=start, j;
    int visited[7] = {0};
    cout << i;
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty())
    {
        i=dequeue();
        for(j=1; j<n; j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                cout << j;
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}


void DFS(int G[7][7], int start, int n)
{
    static int visited[7] = {0};
    if(visited[start]==0)
    {
        cout << start;
        visited[start] =1; 
        for(int j=1; j<n; j++)
        {
            if(G[start][j]==1 && visited[j]==0)
            {
                DFS(G,j,n);
            }
        }
    }
}


int main()
{
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
    cout << "BFS:" << endl;
    BFS(G,1,7);
    cout << endl;
    cout << "DFS:" <<endl; 
    DFS(G,1,7);
}
