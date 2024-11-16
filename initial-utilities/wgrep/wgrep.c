#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // missing search param
    if (argc < 2)
    {
        printf("%s", "wgrep: searchterm [file ...]\n");
        exit(1);
    }

    // no file was given, we search through std input
    if (argc < 3)
    {
        char buffer[256];
        fgets(buffer, 256, stdin);
        printf("%s", buffer);
    }

    char searchParam[256];
    strcpy(searchParam, argv[1]);

    // try to open each file and search for it
    for (int i = argc - 1; i > 1; --i)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("%s", "wgrep: cannot open file");
            exit(1);
        }
        // file found lets read for the searchParam
        char *buffer = NULL;
        size_t len;

        // compare all lines

        int sizeOfWord = getdelim(&buffer, &len, ' ', file);

        while (sizeOfWord != -1 || sizeOfWord == 0)
        {
            sizeOfWord = getdelim(&buffer, &len, ' ', file);
            buffer[sizeOfWord - 1] = '\0';
                }
    }

    return 0;
}