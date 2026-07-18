/* Remove vowels from a string */
#include <stdio.h>
#include <string.h>

int is_vowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return 1;
        default:
            return 0;
    }
}

void remove_vowels(char *str)
{
    int i = 0, j;
    while (str[i])
    {
        j = i;
        if (is_vowel(str[j]))
        {
            // Shift array elements
            while (str[j + 1])
            {
                str[j] = str[j + 1];
                j++;
            }
            str[j] = '\0';
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    char str[] = "Hello Bangalore. I am here";
    printf("Old str: %s\n", str);
    remove_vowels(str);
    printf("New str: %s\n", str);
    return 0;
}