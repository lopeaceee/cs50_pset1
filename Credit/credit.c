#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_number(void);
int get_length(long credit_number);
long get_nth_starting(int length, long credit_number, int n);
int sum_operator(int length, long credit_number);
void check_if_credit(int length, long credit_number);

int main(void)
{
    long credit_number = get_number();
    int number_length = get_length(credit_number);
    check_if_credit(number_length, credit_number);
}

void check_if_credit(int length, long credit_number)
{
    int sum_remainder = sum_operator(length, credit_number) % 10;
    if (sum_remainder == 0)
    {
        if (length == 16 && get_nth_starting(length, credit_number, 2) > 50 && get_nth_starting(length, credit_number, 2) < 56)
        {
            printf("MASTERCARD\n");
        }
        else if (length == 15 && (get_nth_starting(length, credit_number, 2) == 34 || get_nth_starting(length, credit_number, 2) == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && get_nth_starting(length, credit_number, 1) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int sum_operator(int length, long credit_number)
{
    int i = 1;
    long sum = 0;
    while (i < length)
    {
        long number_with_digit = get_nth_starting(length, credit_number, length - i);
        long number_residue = get_nth_starting(length, credit_number, length - i - 1) * 10;
        long number_digit = (number_with_digit - number_residue) * 2;

        if (number_digit > 9)
        {
            number_digit = (number_digit % 10) + 1;
        }

        sum += number_digit;
        i += 2;
    }

    int j = 0;
    while (j < length)
    {
        long number_with_digit = get_nth_starting(length, credit_number, length - j);
        long number_residue = get_nth_starting(length, credit_number, length - j - 1) * 10;
        long final_digit = number_with_digit - number_residue;

        sum += final_digit;
        j += 2;
    }

    return sum;
}

int get_length(long credit_number)
{
    int i = 0;
    while (credit_number > 0)
    {
        i++;
        credit_number /= 10;
    }
    return i;
}

long get_number(void)
{
    long credit_number = get_long("Number: ");
    return credit_number;
}

long get_nth_starting(int length, long credit_number, int n)
{
    long nth_digits = credit_number / pow(10, length - n);
    return nth_digits;
}
