#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T, N, K, i, j, l, count = 0;

    scanf("%d",&T);

    while (T--)
    {
        scanf("%d %d",&N, &K);
        char mtrz[N][N];

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                scanf("%s",&mtrz[i][j]);
            }
        }

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                if(mtrz[i][j] == 'P')
                {
                    for(l = K; l >= 1; l--)
                    {
                        if((j - l >= 0) && (mtrz[i][j-l] == 'L'))
                        {
                            count++;
                            mtrz[i][j-l] = 'X';
                            break;
                        }
                        else if((j + l <= N - 1) && (mtrz[i][j+l] == 'L'))
                        {
                            count++;
                            mtrz[i][j+l] = 'X';
                            break;
                        }
                    }
                }
            }
        }

        printf("%d\n",count);
        count = 0;
    }
    
    return (0);
}