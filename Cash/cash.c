#include <stdio.h>
#include <cs50.h>

int get_cents(void);
int calculate_quarters(int change);
int calculate_after_quarters(int change, int number_quarters);
int calculate_dimes(int change_after_quarters);
int calculate_after_dimes(int change_after_quarters, int number_dimes);
int calculate_nickels(int change_after_dimes);
int calculate_pennies(int change_after_dimes, int number_nickels);
void calculate_total_coins(int number_quarters, int number_dimes, int number_nickels, int number_pennies);

int main(void)
{
  int amount = get_cents();

  int number_quarters = calculate_quarters(amount);
  int amount_after_quarters = calculate_after_quarters(amount, number_quarters);

  int number_dimes = calculate_dimes(amount_after_quarters);
  int amount_after_dimes = calculate_after_dimes(amount_after_quarters, number_dimes);

  int number_nickels = calculate_nickels(amount_after_dimes);

  int number_pennies = calculate_pennies(amount_after_dimes, number_nickels);

  calculate_total_coins(number_quarters, number_dimes, number_nickels, number_pennies);
}

int get_cents(void)
{
  int amount_change;
  do
  {
    amount_change = get_int("Change owed: ");
  } while (amount_change < 0);
  
  return amount_change;
}

int calculate_quarters(int change)
{
  int number_quarters = change / 25;
  return number_quarters;
}

int calculate_after_quarters(int change, int number_quarters)
{
  int change_after_quarters = change - (25 * number_quarters);
  return change_after_quarters;
}

int calculate_dimes(int change_after_quarters)
{
  int number_dimes = change_after_quarters / 10;
  return number_dimes;
}

int calculate_after_dimes(int change_after_quarters, int number_dimes)
{
  int change_after_dimes = change_after_quarters - (10 * number_dimes);
  return change_after_dimes;
}

int calculate_nickels(int change_after_dimes)
{
  int number_nickels = change_after_dimes / 5;
  return number_nickels;
}

int calculate_pennies(int change_after_dimes, int number_nickels)
{
  int number_pennies = change_after_dimes - (5 * number_nickels);
  return number_pennies;
}

void calculate_total_coins(int number_quarters, int number_dimes, int number_nickels, int number_pennies)
{
  int total_coins = number_quarters + number_dimes + number_nickels + number_pennies;
  printf("%i\n", total_coins);
}