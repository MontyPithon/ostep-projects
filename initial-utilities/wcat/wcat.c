#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int fileParams = argc - 1;
    for (int i = 0; i < fileParams; ++i)
    {
        FILE *file1 = fopen(argv[i + 1], "r");

        if (file1 == NULL)
        {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        int count = 128;
        char buffer[count];
        while (fgets(buffer, count, file1))
        {
            printf("%s", buffer);
        }
        fclose(file1);
    }

    return 0;
}