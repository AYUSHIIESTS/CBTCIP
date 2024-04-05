#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    char a[100];
    char ch;
    int lines = 0, words = 0, characters = 0;
    printf("Enter the filename: ");
    scanf("%s", a);
    // Open the file
    file = fopen(a, "r");
    //if no file exists for not showing core dumped output
    if (file == NULL) 
    {
        printf(" No such file exists.\n");
        exit(1);
    }
    // Read characters one by one from file
    while ((ch = fgetc(file)) != EOF) 
    {
        characters++;
        // Count the no of lines
        if (ch == '\n') {
            lines++;
        }
        // Count the no of  words
        if (ch == ' ' || ch == '\n')
        {
            words++;
        }
    }
    // Closing the file
    fclose(file);
    // last word count
    if (characters > 0) 
    {
        words++;
    }
    printf("\nStatistics for file: %s\n", a);
    printf("Number of lines: %d\n", lines);
    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
 return 0;
}