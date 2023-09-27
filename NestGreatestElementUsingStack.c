#include <stdio.h>
void NextGreatestElement(int a[], int n)
{
    int nxe[n];
    int stack[n];
    int i, top = -1;
    for (i = 0; i < n; i++)
    {
        nxe[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        while (top != -1 && a[i] > a[stack[top]])
        {
            nxe[stack[top]] = a[i];
            top--;
        }
        top++;
        stack[top] = i;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d--> %d\n", a[i], nxe[i]);
    }
}
int main()
{
    int n, i;
    printf("Enter the size of Array\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the element of array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Next Greatest Element\n");
    NextGreatestElement(a, n);
    return 0;
}