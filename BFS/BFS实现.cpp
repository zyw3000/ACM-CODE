#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

const int max_dist=9999;
const int invalid_p=-1;

struct adjNode{
    int node;
    struct adjNode *next;
};

enum Color{w, g, b};

struct BFS_struct{
    Color color;
    int d;
    int parent;
};

/*图的矩阵表示向邻接表表示的转换*/
void matrixToAdjlist(int *matrix, adjNode *adjList, int n){
    int i, j;
    adjNode *tempNode;
    for(i=0; i<n; ++i){
        adjList[i].node=i;
        adjList[i].next=NULL;

        for(j=n-1; j>=0; j--){
            if(*(matrix+i*n+j)== 1){
                tempNode=(adjNode *)malloc(sizeof(adjNode));
                tempNode->next=adjList[i].next;
                tempNode->node=j;
                adjList[i].next=tempNode;
            }
        }
    }
}

/*释放邻接表中分配的空间*/
void freeAdjList(adjNode *adjList, int n){
    int i;
    adjNode *tempNode;

    for(i=0; i<n; ++i){
        tempNode=adjList[i].next;
        while(tempNode != NULL){
            adjList[i].next=tempNode->next;
            free(tempNode);
            tempNode=adjList[i].next;
        }
    }

    free(adjList);
}

/*BFS算法*/
void BFS(adjNode *adjList, BFS_struct *bfsArray, int s, int n){
    int i, temp1, temp2;
    adjNode *tempNode;
    //vector<int> bfsQueue;
    queue<int> bfsQueue;
    for(i=0; i<n; ++i){
        bfsArray[i].color=w;
        bfsArray[i].d=max_dist;
        bfsArray[i].parent=invalid_p;
    }
    bfsArray[s].color=g;
    bfsArray[s].d=0;
    bfsArray[s].parent=invalid_p;

    bfsQueue.push(s);
    while(!bfsQueue.empty()){
       temp1=bfsQueue.front();
       bfsQueue.pop();
       tempNode=adjList[temp1].next;
       while(tempNode != NULL){
           temp2=tempNode->node;
           if(bfsArray[temp2].color == w){
               bfsArray[temp2].color=g;
               bfsArray[temp2].d=bfsArray[temp1].d+1;
               bfsArray[temp2].parent=temp1;
               bfsQueue.push(temp2);
           }

           tempNode=tempNode->next;
       }

       bfsArray[temp1].color=b;
    }

}

/*输出BFS学习之后从源节点s到各个节点的最短路径*/
void print_path(BFS_struct *bfsArray, int s, int u){
    if(s == u)
        printf("%d ", s);
    else if(bfsArray[u].parent == invalid_p)
        printf("There is no path form %d to %d", s, u);
    else{
        print_path(bfsArray, s, bfsArray[u].parent);
        printf("%d ", u);
    }
}

int main(){
    int *matrix;
    adjNode *adjList, *tempNode;
    int nodeNum=0, i, j, startpoint=0;
    BFS_struct *bfsArray;

    printf("Input node number: ");
    scanf("%d", &nodeNum);

    matrix=(int *)malloc(sizeof(int)*nodeNum*nodeNum);
    adjList=(adjNode *)malloc(sizeof(adjNode)*nodeNum);

    for(i=0; i<nodeNum; ++i)
        for(j=0; j<nodeNum; ++j)
            scanf("%d", matrix+i*nodeNum+j);

    /*以矩阵形式输出图*/
    printf("matrix: \n");
    for(i=0; i<nodeNum; ++i){
        for(j=0; j<nodeNum; ++j)
            printf("%d ", *(matrix+i*nodeNum+j));
        printf("\n");
    }

    matrixToAdjlist(matrix, adjList, nodeNum);
    /*以邻接表形式输出图*/
    printf("adjacency list: \n");
    for(i=0; i<nodeNum; ++i){
        printf("node %d:", adjList[i].node);
        tempNode=adjList[i].next;
        while(tempNode != NULL){
            printf("->%d", tempNode->node);
            tempNode=tempNode->next;
        }
        printf("\n");
    }

    printf("Please intput startpoint: ");
    scanf("%d", &startpoint);
    bfsArray=(BFS_struct *)malloc(sizeof(BFS_struct)*nodeNum);
    BFS(adjList, bfsArray, startpoint, nodeNum);
    for(i=0; i<nodeNum; ++i){
        printf("path form %d to %d: ", startpoint, i);
        print_path(bfsArray, startpoint, i);
        printf("\n");
    }

    free(matrix);
    free(bfsArray);
    freeAdjList(adjList, nodeNum);
    return 0;
}
