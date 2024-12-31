#include <vector>
using namespace std;

vector<long long> insertSort(vector<long long> A, int n)
{
    long long pivo;
    for(int i=1; i<n; i++)
    {
        pivo = A[i];
        int j = i-1;
        while (j>=0 && A[j]>pivo)
        {
            A[j+1] = A[j];
            j = j-1;
        }
        A[j+1] = pivo;
    }
    return A;
}

vector<long long> selectionSort(vector<long long> A, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int i_min = i;
        for(int j=i+1; j<n; j++)
            if(A[j] <  A[i_min])
                i_min = j;
        if (A[i] != A[i_min])
        {
            int temp = A[i];
            A[i] = A[i_min];
            A[i_min] = temp;
        }
    }
    return A;
}