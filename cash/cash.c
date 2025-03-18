#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);
void print_spaces(int row, int n);
void print_hashtags(int col, int n);

int main(void)
{
    int n = get_int("Height: ");

    while (n < 1 || n > 8)
        n = get_int("Height: ");
    if (n > 0)
        print_pyramid(n);
}

void print_pyramid(int n)
{
    int row = 0;
    for (int col = 0; col < n; col++)
    {
        if (row < n) // This needs to be an if, because it's already inside a loop
        {
            print_spaces(row, n);
            print_hashtags(col, n);
            printf("  ");
            print_hashtags(col, n);
            printf("\n");
            row++;
        }
    }
}

void print_spaces(int row, int n)
{
    while (n - row - 1) // while n minus the row (which is modified in the print_pyramid function)
                        // and minus 1 exists, print the spaces
    {
        printf(" "); // I need to print n minus 1 characters in the beginning, but then i need to
                     // continue substracting 1; that's why I modify row
        row++;
    }
}

void print_hashtags(int col, int n)
{
    for (int i = 0; col >= i; i++)
    {
        printf("#");
    }
}