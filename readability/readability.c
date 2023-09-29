#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentences(text);

    float L = 100.0 * letter / word;
    float S = 100.0 * sentence / word;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        char chars = tolower(text[i]);

        if(chars >= 97 && chars <= 122)
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0; i <= strlen(text); i++)
    {
        char chars = text[i];

        if(chars == 32)
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; i <= strlen(text); i++)
    {
        char chars = text[i];

        if (chars == 33 || chars == 46 || chars == 63)
        {
            sentences++;
        }
    }
    return sentences;
}