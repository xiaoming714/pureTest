#include <vector>
#include <iostream>

using namespace std;

void insertSort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int temp = vec[i];
        int j = 0;
        for (j = i - 1; j >= 0 && vec[j] > temp; j--)
        {
            vec[j + 1] = vec[j];
        }
        vec[j + 1] = temp;
    }
}

void bubbleSort(vector<int> &vec)
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

void selectSort(vector<int> &vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[maxIndex])
            {
                maxIndex = j;
            }
        }
        swap(vec[i], vec[maxIndex]);
    }
}

void heapAdjust(vector<int> &vec, int start, int end)
{
    int father = start;
    int child = father * 2 + 1;
    while (child <= end)
    {
        if (child + 1 <= end && vec[child] < vec[child + 1])
        {
            ++child;
        }
        if (vec[child] > vec[father])
        {
            swap(vec[child], vec[father]);
            father = child;
            child = father * 2 + 1;
        }
        else
        {
            return;
        }
    }
}

void heapSort(vector<int> &vec)
{
    for (int i = (int)vec.size() / 2 - 1; i >= 0; i--)
    {
        heapAdjust(vec, i, (int)vec.size() - 1);
    }
    for (int i = (int)vec.size() - 1; i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapAdjust(vec, 0, i - 1);
    }
}

int main()
{
    vector<int> vec = {9, 8, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> vec1 = {5, 2, 3, 1};
    heapSort(vec1);
    for (auto &it : vec1)
    {
        cout << it << " ";
    }
    return 0;
}