#include <iostream>

using namespace std;

class Array
{
    int length;
    int* arr;

public:
    Array(int len) : arr{ new int[len] }, length{len} {}
    Array() : Array(0) {}

    Array(const Array& obj)
    {
        length = obj.length;

        if (*(obj.arr + 0) )
        {
            arr = new int[obj.length];

            for (size_t i = 0; i < length; i++)
            {
                *(arr + i) = *(obj.arr + i);
            }
        }
        else
        {
            arr = new int[obj.length];
        }
    }

    ~Array()
    {
        delete[]arr;
    }


    void setLen(int length)
    {
        this->length = length;
        if (arr)
        {
            int* a = new int[length];
            for (size_t i = 0; i < length; i++)
            {
                *(a + i) = *(arr + i);
            }

            delete[]arr;

            arr = new int[length];

            for (size_t i = 0; i < length; i++)
            {
                for (size_t i = 0; i < length; i++)
                {
                    *(arr + i) = *(a + i);
                }
            }

            delete[]a;
        }
        else
        {
            arr = new int[length];
        }
    }

    void fillArr(int* arr)
    {
        for (size_t i = 0; i < length; i++)
        {
            *(this->arr + i) = *(arr + i);
        }
    }

    void print()
    {
        for (size_t i = 0; i < length; i++)
        {
            cout << *(arr + i) << ' ';
        }
    }

    void sortArr()
    {
        int temp;

        for (size_t i1 = 0; i1 < length; i1++)
        {
            for (size_t i = 0; i < length - 1; i++)
            {
                if (*(arr + i) > *(arr + i + 1))
                {
                    temp = *(arr + i);
                    *(arr + i) = *(arr + i + 1);
                    *(arr + i + 1) = temp;
                }
            }
        }
        
        
    }

    int arrMin()
    {
        int min = *(arr + 0);

        for (size_t i = 0; i < length; i++)
        {
            if (min > *(arr + i))
            {
                min = *(arr + i);
            }
        }

        return min;
    }

    int arrMax()
    {
        int max = *(arr + 0);

        for (size_t i = 0; i < length; i++)
        {
            if (max < *(arr + i))
            {
                max = *(arr + i);
            }
        }

        return max;
    }
};

int main()
{
    Array a(10), a2(a);

    int arr[10]{ 10,1,9,2,8,3,7,4,6,5 };
    int arr2[10]{ 10,11,19,12,18,13,17,14,16,15 };

    a.fillArr(arr);
    a2.fillArr(arr2);
    a.print();
    cout << endl;
    a2.print();
    cout << endl;
    a.print();
    cout << endl;
    cout << a.arrMin() << endl;
    cout << a.arrMax() << endl;

}