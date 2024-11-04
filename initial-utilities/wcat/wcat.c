#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Error: missing file parameter!");
        return -1;
    }

    int fileParams = argc - 1;
    for (int i = 0; i < fileParams; ++i)
    {
        FILE *file1 = fopen(argv[i + 1], "r");

        if (file1 == NULL)
        {
            printf("Error: file not found");
            return -1;
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