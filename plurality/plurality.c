#include <stdio.h>
#include <string.h>


void merge(int arr[], int s, int m, int e);
void merge_sort(int arr[], int start, int end);

int main()
{
    int Arr[] = {5, 3, 2, 5, 3, 2};

    merge_sort(Arr, 0, 6);

    for(int i = 0; i < 7; ++i)
    {
        printf("%d\n", Arr[i]);
    }e

}

void merge(int arr[], int s, int m, int e)
{

    int *temp = malloc(sizeof(int) * e - s);

    int posL = s;
    int posR = m+1;
    int temp_i = 0;
    while(posL <= m && posR <= e)
    {
        if(arr[posL] <= arr[posR])
        {
            temp[temp_i] = arr[posL];
            ++posL;
        }
        else
        {
            temp[temp_i] = arr[posR];
            ++posR;
        }
        ++temp_i;
    }

    while(posL <= m) {
        temp[temp_i] = arr[posL];
        ++posL;
        ++temp_i;
    }

    while(posR <= e) {
        temp[temp_i] = arr[posR];
        ++posR;
        ++temp_i;
    }

    for(int i = 0; i < temp_i; ++i)
    {
        arr[s + i] = temp[i];
    }

    free(temp);
}

void merge_sort(int arr[], int start, int end)
{
    if(end > start)
    {
        int m = start + (end - start) / 2;
        merge_sort(arr, start, m);
        merge_sort(arr, m+1, end);
        merge(arr, start, m, end);

    }
    else
    {
        return;
    }

}