#include <stdio.h>
#include <stdlib.h>
int v;

typedef struct node
{
    int data;
    struct node *next;
}node;

node *al[10001];

void insert(node **head, int ele)
{
    node *n = (node*)malloc(sizeof(node));
    n -> data = ele;
    n -> next = NULL;
    node *p = *head;
    if(!p)
        *head = n;
    else{
        while(p -> next)    
            p = p -> next;
        p -> next = n;
    }
}

void show()
{
    int i;
    for(i = 0; i < v; ++i)
    {
        printf("%i ", i);
        while(al[i])
        {
            printf("-> %i ", al[i] -> data);
            al[i] = al[i] -> next;
        }
        printf("\n");
    }
}
int main()
{
    int i, j, n;
    FILE *fp;
    fp = fopen("input.txt", "r");
    if(fp == NULL)
        exit(0);

    fscanf(fp, "%i", &v);
    int am[v+1][v+1];

    // scanf adjacency matrix from the file
    for(i = 0; i < v; ++i)
        for(j = 0; j < v; ++j)
            fscanf(fp, "%i", &am[i][j]);

    // initialize with null
    for(i = 0; i < v; ++i)
        al[i] = NULL;

    for(i = 0; i < v; ++i)
        for(j = 0; j < v; ++j)
            if(am[i][j] == 1)
                insert(&al[i], j);

    // to show the adjacency list
    show();
    fclose(fp);
    return 0;
}
