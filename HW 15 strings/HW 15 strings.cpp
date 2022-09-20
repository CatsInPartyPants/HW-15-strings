#include <iostream>

using namespace std;


//1

void del_char(char*, int);

//2

void del_all_chars(char*, char);

//3

void char_input(char*, char, int);

//4

void change_points(char* arr, int size);

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

    //3
    char* arr3 = new char[] {"hello world!"};
    cout << arr3 << endl;
    char_input(arr3, 'a', 6);
    cout << arr3 << endl;
    delete[] arr3;

    //4
    char* arr4 = new char[256];
    cout << "Enter string (all '.' will be changed to '!'):\n";
    gets_s(arr4, 256);
    arr4[255] = '\0';
    change_points(arr4, 256);
    cout << arr4 << endl;
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

//3

void char_input(char* arr, char simbol, int position)
{
    int size = strlen(arr);
    *(arr + position) = simbol;

}

//4

void change_points(char* arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (*(arr+i) == '.')
            *(arr+i) = '!';
    }
}