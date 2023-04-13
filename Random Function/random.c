#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_index(int array_size) 
{

    /*This sets a variable */
    static int seed = 0; 

    /*The code below generate a new seed based on the system clock*/
    seed = (seed + (int)time(NULL)) % 10000; 

    

    /*This will generate a pseudo-random number between 0 and 32767
    * 
    */
    int random_num = (seed * 1103515245 + 12345) % 32768; 

    int x = random_num % array_size;
    printf("x: %d\n", x);
    return x; // Return a random index within the bounds of the array
}


int main() {
    int array[] = {1, 2, 3, 4, 5};
    int array_size = sizeof(array) / sizeof(int);

    int random_index = get_random_index(array_size);
    printf("Random element: %d\n", array[random_index]);

    return 0;
}