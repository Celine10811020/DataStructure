#include <stdio.h>
#include <stdlib.h>

int bellmanFord(int node, int edge, int start, int end);
int min(int one, int two);

int graph[1000][1000];
int result[1000];

int main()
{
    int i, j, k;
    int node, edge;
    int num, start, end;
    int one, two, cost;
    int ans;

    scanf("%d", &num);

    for(i=0; i<num; i++)
    {
        scanf("%d", &node);
        scanf("%d", &edge);
        scanf("%d", &start);
        scanf("%d", &end);

        for(j=0; j<node; j++)
        {
            for(k=0; k<node; k++)
            {
                graph[j][k] = 0;
            }
        }

        for(j=0; j<edge; j++)
        {
            scanf("%d", &one);
            scanf("%d", &two);
            scanf("%d", &cost);

            graph[one][two] = cost;
        }

        ans = bellmanFord(node, edge, start, end);

        if(ans == 2147483647)
        {
            printf("UNREACHABLE\n");
        }else if(ans == 2147483646)
        {
            printf("INF\n");
        }else
        {
            printf("%d\n", ans);
        }
    }

    return 0;
}

int bellmanFord(int node, int edge, int start, int end)
{
    int i, j, k, temp;

    for(i=0; i<node; i++)
    {
        result[i] = 2147483647;
    }

    result[start] = 0;

    for(i=1; i<node; i++)
    {
        for(j=0; j<node; j++)
        {
            for(k=0; k<node; k++)
            {
                if(graph[j][k] != 0)
                {
                    if(result[j] != 2147483647)
                    {
                        temp = min(result[j]+graph[j][k], result[k]);

                        result[k] = temp;
                    }

                }
            }
        }
    }

    for(j=0; j<node; j++)
    {
        for(k=0; k<node; k++)
        {
            if(graph[j][k] != 0)
            {
                if(result[j]!=2147483647)
                {
                    temp = min(result[j]+graph[j][k], result[k]);

                    if(temp < result[k])
                    {
                        return 2147483646;
                    }
                }
            }
        }
    }

    return result[end];
}

int min(int one, int two)
{
    if(one < two)
    {
        return one;
    }else
    {
        return two;
    }
}

