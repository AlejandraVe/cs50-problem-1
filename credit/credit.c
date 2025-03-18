#include <cs50.h>
#include <stdio.h>

void get_bank(long card);
int verify_card(long card);

int main(void)
{
    long card = get_long("Number: ");

    while (!card)
        card = get_long("Number: ");
    if (card < 1000000000000 || card > 10000000000000000)
        printf("INVALID\n");
    else
        get_bank(card);
}

int verify_card(long card)
{
    int i = 0;
    long new_card = card / 10;
    long temp;
    long temp_2;
    long add = 0;

    while (new_card > 0)
    {
        temp = new_card % 10; // Temp turns into the card minus the last digit
        temp *= 2;
        if (temp < 10)
        {
            add += temp;
        }
        else
        {
            add += (temp % 10) + (temp / 10);
        }
        new_card = new_card / 100;
    }
    while (card > 0)
    {
        temp_2 = card % 10;
        add += temp_2;
        card = card / 100;
    }
    if ((add % 10) == 0)
        i = 1;
    return (i);
}
// I need to divide the card in 100, to move 2 places from it to the left

void get_bank(long card)
{
    int i;

    if ((card < 5000000000000 && card >= 4000000000000) ||
        (card < 5000000000000000 && card >= 4000000000000000))
    {
        i = verify_card(card);
        if (i == 1)
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else if ((card < 350000000000000 && card >= 340000000000000) ||
             (card < 380000000000000 && card >= 370000000000000))
    {
        i = verify_card(card);
        if (i == 1)
            printf("AMEX\n");
        else
            printf("INVALID\n");
    }
    else if (card <= 5600000000000000 && card >= 5100000000000000)
    {
        i = verify_card(card);
        if (i == 1)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    else
        printf("INVALID\n");
}

// American Express uses 15-digit numbers
// Mastercard uses 16-digit numbers
// Visa uses 13 and 16 digit numbers, and aways start with 4
