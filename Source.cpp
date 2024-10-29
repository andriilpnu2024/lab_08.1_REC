#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
char* Change(char* dest, const char* str, char* t, int i);
//void Count(char* str, const char* str1, int& k,int i , int j);
void Count(char* str, const char* str1, int j, int i, int& k);
int main()
{
    int k = 0;
    char str[101];
    char str1[6] = { "BASIC" };
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    Count(str, str1, 0, 0 ,k);
    cout << "String contained "<<k<< " elements of 'BASIC'" << endl;
    char* dest = new char[151];
    char* dest1 = new char[151];
    dest1[0] = '\0';
    dest = Change(dest1 ,str,dest1,0);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}
void Count(char* str, const char* str1, int j, int i , int& k)
{
    if (str[j] == '\0')
        return ;
    if (str[j] == str1[i])
        k += 1;
    if(str1[i + 1] != 0 )
        Count(str, str1, j, i + 1, k);
    if (str1[i+1] == '\0') {
        Count(str, str1, j + 1, 0, k);
    }
}
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 4] != '\0')
    {
        if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' &&
            str[i + 3] == 'I' && str[i + 4] == 'C')
        {
            strcat(t, "Delphi");
            return Change(dest, str, t + 6, i + 5);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}

