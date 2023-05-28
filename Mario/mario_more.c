#include <cs50.h>
#include <stdio.h>

int get_size(void);
void build_pyramid(int size);

int main(void)
{
    int size = get_size();
    build_pyramid(size);
}

int get_size(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    } 
    while (1 > size || size > 8);
    return size;
}

void build_pyramid(int size)
{
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 0; j < (size * 2) + 2; j++)
        {
            if ((j >= size - i && j < size) || (j >= size + 2 && j <= size + i + 1))
            {
                printf("#");
            }
            else if ((j < size - i) || (j < size + 2))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}