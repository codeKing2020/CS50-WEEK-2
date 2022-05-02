#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Prototypes OR function declarations
int count_letters(string strinput);
int spaces(string strinput);
int sentences(string strinput);
int colemanindex(int letters, int words, int sentences);

int main(void)
{
    printf("Hello! Let's see what grade your books are designed for!\n");

    // Get User Input
    string input = get_string("Text: ");

    // Functions that calculate amount of input, words, sentences in user's entry, and coleman-liau index
    int numofinput = count_letters(input);
    int numofwords = spaces(input);
    int numofsentences = sentences(input);
    int colemanLiauIndex = colemanindex(numofinput, numofwords, numofsentences);

    //If statements
    if (colemanLiauIndex <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (colemanLiauIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", colemanLiauIndex);
    }
}

// Function that counts letters in the text.
int count_letters(string strinput)
{
    int total_letters = 0;
    for (int i = 0, n = strlen(strinput); i < n; i++)
    {
        if (isalpha(strinput[i]))
        {
            total_letters++;
        }
    }
    return total_letters;
}

// Function that counts number of words
int spaces(string strinput)
{
    int total_spaces = 1;
    for (int i = 0, n = strlen(strinput); i < n; i++)
    {
        if (isspace(strinput[i]))
        {
            total_spaces++;
        }
    }
    return total_spaces;
}
int sentences(string strinput)
{
    int total_sentences = 0;
    for (int i = 0, n = strlen(strinput); i < n; i++)
    {
        if (strinput[i] == '.' || strinput[i] == '!' || strinput[i] == '?')
        {
            total_sentences++;
        }
    }
    return total_sentences;
}
int colemanindex(int letters, int words, int sentences)
{
    //first calculate what the average of letters and sentences is
    float l = (float) letters / words * 100.0;
    float s = (float) sentences / words * 100.0;

    //next apply to index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int answer = round(index);

    //return to sender!
    return answer;
}