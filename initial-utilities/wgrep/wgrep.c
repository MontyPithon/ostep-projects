#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// takes in search param cstring, cstring buffer, pointer to len, and file stream pointer
void searchStream(char *searchParam, char *buffer, size_t *len, FILE *file)
{
    // read each line in stream
    while (getline(&buffer, len, file))
    {
        // first we check if on on eof
        if (feof(file) == 0)
        {
            // begin at
            char *ptr = buffer;
            char *ptrParam = searchParam;
            while (*ptr != '\0')
            {
                // they match
                if (*ptrParam == *ptr)
                {
                    ++ptrParam;
                }
                // they dont match and search param is not at end
                else
                {
                    if (*ptrParam != '\0')
                    {
                        ptrParam = searchParam;
                    }
                    else
                    {
                        // break as ptrParam is at end of search sequence tf we found a match
                        printf("%s", buffer);
                        break;
                    }
                }
                ptr++;
            }
        }
        else
        {
            break;
        }
    }
    fclose(file);
    if (buffer != NULL)
    {
        free(buffer);
    }
}

int main(int argc, char *argv[])
{
    // missing search param
    if (argc < 2)
    {
        printf("%s", "wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char searchParam[256];
    strcpy(searchParam, argv[1]);

    // no file was given, we search through std input
    if (argc < 3)
    {
        char *buffer = NULL;
        size_t len;
        searchStream(searchParam, buffer, &len, stdin);
        return 0;
    }

    // try to open each file and search for it
    for (int i = argc - 1; i > 1; --i)
    {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL)
        {
            printf("%s", "wgrep: cannot open file\n");
            exit(1);
        }
        // file found lets read for the searchParam
        char *buffer = NULL;
        size_t len;

        // compare all lines

        searchStream(searchParam, buffer, &len, file);
    }

    return 0;
}