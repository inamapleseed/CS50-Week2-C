#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string msg = get_string("Message: ");

    int binaryArray[] = {0,0,0,0,0,0,0,0};

    for (int i = 0; i < strlen(msg); i++)
    {
        int rem = msg[i];

        for (int loop = 0; loop < 8; loop++)
        {
            if (rem % 2 == 0)
            {
                binaryArray[loop] = 0;
                rem = rem / 2;
            }
            else
            {
                binaryArray[loop] = 1;
                rem = (rem - 1) / 2;
            }
        }

        // print array loop
        for (int j = 7; j >= 0; j--)
        {
            print_bulb(binaryArray[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
