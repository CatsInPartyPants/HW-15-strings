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

//5

int number_of_simbols(char* arr, char simbol, int size);

//6

void analyze_array(char* arr);

//7

void change_spaces_to_tabs(char* arr);

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
    delete[] arr4;

    //5
    char* arr5 = new char[256];
    char simbol_for_find;
    cout << "Enter string:\n";
    gets_s(arr5, 256);
    cout << "Simbol for find:\n";
    cin >> simbol_for_find;
    cout << "Simbol " << simbol_for_find << " is " << number_of_simbols(arr5, simbol_for_find, 256) << " times in the string!\n";
    delete[] arr5;

    //6
    char* arr6 = new char[] {"aaa123rsd2s3a !a%l6r%la4relaa a a a!"};
    analyze_array(arr6);
    delete[] arr6;

    //7 
    
    char* arr7 = new char[] {"aaa123rsd2s3a !a%l6r%la4relaa a a a!"};
    cout << arr7 << endl;
    change_spaces_to_tabs(arr7);
    cout << arr7 << endl;
    delete[] arr7;

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

//5

int number_of_simbols(char* arr, char simbol, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == simbol)
            count++;
    }
    return count;
}

//6

void analyze_array(char* arr)
{
    int number_count = 0;
    int letter_count = 0;
    int other_count = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (isdigit(*(arr + i)) != 0)
        {
            number_count++;
        }
        else if (isalpha(*(arr + i)) != 0)
        {
            letter_count++;
        }
        else if (*(arr + i) != ' ')
        {
            other_count++;
        }
    }
    cout << "Numbers in the string: " << number_count << " Letters in the string: " << letter_count << " other simbols in the string " << other_count << endl;
}

//7 
void change_spaces_to_tabs(char* arr)
{
    while(*arr != '\0')
    {
        if (*arr == ' ')
        {
            *arr == '\t';
        }
        arr++;
    }
}