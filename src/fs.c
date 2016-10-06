#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array (int *array, int size) {
    for (int cx = 0; cx < size; cx++)
        printf ("%d ", *(array + cx));
    printf ("\n");
}

int sorted (int *array, int size) {
    int ret = 1;

    for (int cx = 0; (cx < size - 1) && ret; cx++) {
        ret = (*(array + cx) <= *(array + cx + 1));
    }

    return ret;
}

int main () {
    int size, max, min, swaps = 0;
    int *array;
    time_t t;

    srand ((unsigned) time(&t));

    printf ("Enter size of array: ");
    scanf ("%d", &size);

    printf ("Enter minimum number: ");
    scanf ("%d", &min);

    printf ("Enter maximum number: ");
    scanf ("%d", &max);

    array = (int*) calloc (size, sizeof (int));

    for (int cx = 0; cx < size; cx++) {
        *(array + cx) = (rand () % (max + 1)) + min;
    }

    printf ("Unsorted array: ");
    print_array (array, size);

    int test_pos = 0, test_val = 0;
    int pos = 0, pos_val = 0;
    for (pos = size - 1; pos > test_pos; pos--) {
        pos_val = *(array + pos);
        for (test_pos = 0; test_pos < pos; test_pos++) {
            test_val = *(array + test_pos);
            if (test_val > pos_val) {
                *(array + pos) ^= *(array + test_pos);
                *(array + test_pos) ^= *(array + pos);
                *(array + pos) ^= *(array + test_pos);
                pos_val ^= test_val;
                test_val ^= pos_val;
                pos_val ^= test_val;
                //print_array (array, size);
                swaps++;
            }
        }
        if (!sorted (array, size)) test_pos = 0;
    }

    printf ("Sorted array: ");
    print_array (array, size);
    printf ("Array swaps: %d\n", swaps);

    free (array);

    return 0;
}
