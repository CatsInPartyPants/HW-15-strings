#include <iostream>

using namespace std;


//1

void del_char(char*, int);

//2

void del_all_chars(char*, char);

int main()
{
    //1

    char* arr1 = new char[] {"hello world!"};
    cout << arr1 << endl;
    del_char(arr1, 5);
    cout << arr1 << endl;
    delete[] arr1;

    //2
    char* arr2 = new char[] {"aaarsdsa alrlarelaa a a a!"};
    del_all_chars(arr2, 'a');
    cout << arr2 << endl;
    delete[] arr2;
}

//1

void del_char(char* arr, int position)
{
    int size = strlen(arr);

    for (int i = position; i < size; i++)
    {
        *(arr +i) = *(arr + i + 1);
    }
    *(arr + size - 1) = '\0';
    
}

//2

void del_all_chars(char* arr, char simbol)
{
    for (int i = 0; i < strlen(arr); i++)
    {
        if (*(arr + i) == simbol)
        {
            del_char(arr, i);
            i--;
        }
    }
}