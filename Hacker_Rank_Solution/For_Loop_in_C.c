/* For Loop in C */

#include<stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    char labels[11][6] = {"one","two","three","four","five","six","seven","eight","nine","even","odd"};
    int label_index;
        for(int i = a; i <= b; i++)
        {
            label_index = i <= 9 ? i - 1 : 9 + i % 2;
            printf("%s\n", labels[label_index]);
        }
        return 0;
}