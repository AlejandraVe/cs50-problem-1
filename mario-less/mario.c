#include <cs50.h>
#include <stdio.h>

void print_pyramid(int n);
void print_spaces(int row, int n);
void print_hashtags(int col, int n);

int main(void)
{
    int n = get_int("Height: ");

    while (n < 1)
    {
        n = get_int("Height: ");
    }
    if (n > 1)
    {
        print_pyramid(n);
    }
}

void print_pyramid(int n)
{
    int row = 0;
    for (int col = 0; col < n; col++)
    {
        if (row < n)
        {
            print_spaces(row, n);
            print_hashtags(col, n);
            printf("\n");
            row++;
        }
    }
}

void print_spaces(int row, int n)
{
    while (n - row - 1)
    {
        printf(" ");
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
