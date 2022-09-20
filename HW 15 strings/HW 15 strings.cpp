#define _CRT_SECURE_NO_WARNINGS

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

//8

int number_of_words(char* arr);

//9

bool isPalindrom(const char* arr);

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
    
    
    char* arr7 = new char[] {"aaa123rsd2s3a !a%l6r%la4rela a a!"};
    cout << arr7 << endl;
    change_spaces_to_tabs(arr7);
    cout << arr7 << endl;
    delete[] arr7;

    //8 
    char* arr8 = new char[] {"Hello my dear friends!"};
    cout << "Number of words in '" << arr8 << "' is " << number_of_words(arr8) << endl;
    delete[] arr8;


    //9

    if (isPalindrom("Never odd or even"))
    {
        cout << "Its palindrom!";
    }
    else
    {
        cout << "Its not palindrom!";
    }


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
    for (int i = 0; i < strlen(arr); i++)
        if (*(arr + i) == ' ')
            *(arr + i) = '\t';

}

//8

int number_of_words(char* arr)
{
    int number = 1;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (*(arr + i) == ' ')
            number++;
    }
    return number;
}

//9 

bool isPalindrom(const char* arr)
{
    // make string without spaces
    char* tmp1 = new char[strlen(arr) + 1];
    int j = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (*(arr + i) != ' ')
        {
            *(tmp1 + j) = *(arr + i);
            j++;
        }
        
    }
    *(tmp1 + j) = '\0';
    _strlwr(tmp1);
    // make reversed string without spaces

    char tmp2[256];
    int size = strlen(tmp1);
    tmp2[size] = '\0';
    j = 0;
    char* tmp3 = tmp1;
    while (*tmp3 != '\0')
    {
        tmp2[--size] = *tmp3;
        tmp3++;
    }
    _strlwr(tmp2);

    // testing palindrom or not
    for (int i = 0; i < strlen(tmp1); i++)
    {
        if (*(tmp1 + i) != *(tmp2 + i))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    

    
}