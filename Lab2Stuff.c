#include <stdio.h>

int main()
{


void stuff(int data[], int x, int y)
{
 data[data[x]] = data[y];
 data[y] = x;
}


 int numbers[] = {3, 7, 1, 0, 25, 4, 18, -1, 5};
void print_array(int *array, int length)
{
    int i = 0;
    for (int i = 0; i < length; i++) { /* whatever */ 
    printf(numbers[i]);
}
}

 stuff(numbers, 3, 1);
 print_array(numbers,9);
 stuff(numbers, 5, 6);
 print_array(numbers,9);
 stuff(numbers, 8, 4);
 print_array(numbers,9);
}
