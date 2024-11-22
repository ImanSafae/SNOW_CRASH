#include <stdio.h>

void main(int argc, char **argv)
{
        if (argc != 2)
                return ;
        int i = 0;
        while (argv[1] && argv[1][i])
        {
                argv[1][i] -= i;
                i++;
        }
        printf("token:%s\n", argv[1]);
}

