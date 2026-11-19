
#include <stdio.h>
#include <ctype.h>
#include <stddef.h>

/* Count words separated by whitespace */
static int word_count(const char s[])
{
    int count = 0;
    int inside = 0;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (isspace((unsigned char)s[i]))
        {
            inside = 0;
        }
        else if (!inside)
        {
            ++count;
            inside = 1;
        }
    }

    return count;
}

/* Check palindrome, ignoring spaces, punctuation and case */
static int palindrome(const char s[])
{
    size_t left = 0;
    size_t right = 0;

    while (s[right] != '\0')
    {
        ++right;
    }

    if (right == 0)
    {
        return 1;
    }

    --right;

    while (left < right)
    {
        while (left < right &&
               !isalpha((unsigned char)s[left]))
        {
            ++left;
        }

        while (left < right &&
               !isalpha((unsigned char)s[right]))
        {
            --right;
        }

        if (tolower((unsigned char)s[left]) !=
            tolower((unsigned char)s[right]))
        {
            return 0;
        }

        ++left;

        if (right > 0)
        {
            --right;
        }
    }

    return 1;
}

/* Convert string to uppercase */
static void uppercase(char s[])
{
    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        s[i] = (char)toupper((unsigned char)s[i]);
    }
}

/* Reverse string in place */
static void reverse(char s[])
{
    size_t n = 0;

    while (s[n] != '\0')
    {
        ++n;
    }

    for (size_t i = 0; i < n / 2; ++i)
    {
        char temp = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = temp;
    }
}

int main(void)
{
    char msg[] = " Meet at the library at 5 PM ";
    char copy[] = "C programming";

    printf("Words: %d\n", word_count(msg));

    printf("Palindrome tests: %d %d\n",
           palindrome("Madam, I'm Adam"),
           palindrome("Hello"));

    uppercase(copy);
    printf("Upper: %s\n", copy);

    reverse(copy);
    printf("Reverse: %s\n", copy);

    printf("Tab-separated words: %d\n",
           word_count("one\ttwo"));

    return 0;
}
