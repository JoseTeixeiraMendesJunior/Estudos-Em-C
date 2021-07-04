#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    unsigned int T, size, i, count;
    char string[100000];

    scanf("%u",&T);

    while (T--)
    {
        count = 0;

        getchar();
        scanf("%[^\n]",string);

        size = strlen(string);

        for(i = 0; i < size; i++)
        {
            switch (string[i])
            {
            case 'a':
                count++;
                break;
            case 'A':
                count++;
                break;
            case 'e':
                count++;
                break;
            case 'E':
                count++;
                break;
            case 'i':
                count++;
                break;
            case 'I':
                count++;
                break;
            case 'o':
                count++;
                break;
            case 'O':
                count++;
                break;
            case 'u':
                count++;
                break;
            case 'U':
                count++;
                break;
            
            default:
                break;
            }
        }

        printf("%u\n",count);

    }
    

    return (0);
}