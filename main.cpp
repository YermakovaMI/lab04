#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    const size_t MAX_SIZE = 256;
    char text[MAX_SIZE];
    char* fgets(char* str, int count, FILE* stream);
    //stdin       expression of type FILE* associated with the input stream;
    fgets(text, MAX_SIZE, stdin);
    const char* separators = " \r\n,.!?:;()-";
    const char* start = text;
    while (true)
    {
        const size_t separator_count = strspn(start, separators);
        start += separator_count;
        if (start[0] == '\0')
        {
            break;
        }
        const size_t word_length = strcspn(start, separators);
        cout.write(start, word_length);
        cout << '\n';
        start += word_length;
    }
    return 0;
}
