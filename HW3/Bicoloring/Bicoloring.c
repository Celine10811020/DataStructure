#include <stdio.h>

int graph[200][200];
int coloring[200];

int main()
{
    int i, j, temp;
    int node, edge;
    int one, two, color;
    int ans;

    while(1)
    {
        scanf("%d", &node);

        if(node == 0)
        {
            break;
        }

        scanf("%d", &edge);

        for(i=0; i<node; i++)
        {
            graph[i][0] = 1;
            coloring[i] = 0;
        }

        for(i=0; i<edge; i++)
        {
            scanf("%d", &one);
            scanf("%d", &two);

            temp = graph[one][0];
            graph[one][temp] = two;
            graph[one][0]++;

            temp = graph[two][0];
            graph[two][temp] = one;
            graph[two][0]++;
        }

        coloring[0] = 1;
        ans = 1;

        for(i=0; i<node; i++)
        {
            temp = graph[i][0];

            color = coloring[i];

            for(j=1; j<temp; j++)
            {
                if(color == coloring[graph[i][j]])
                {
                    ans = 0;
                }else
                {
                    coloring[graph[i][j]] = color * -1;
                }
            }

            if(ans == 0)
            {
                break;
            }
        }

        if(ans)
        {
            printf("BICOLORABLE.\n");
        }else
        {
            printf("NOT BICOLORABLE.\n");
        }
    }

    return 0;
}
