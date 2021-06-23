double max(double arr[], int size)
{
    double x;

    x = arr[0];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > x)
            x = arr[i];
    }

    return(x);
}