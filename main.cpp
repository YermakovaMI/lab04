#include <iostream>
#include <cassert>
#include<cstdint>
#include<cstdio>

using namespace std;

char nibble_to_hex(uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}

const uint8_t*
as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}

void
print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}

void
print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);

        if ((i + 1) % 16)
        {
            cout << ' ';
        }
        else
        {
            cout << '\n';
        }
    }
}
void
print_in_hex_separation(const void* data, size_t size,size_t separat[6])
{
    const uint8_t* bytes = as_bytes(data);
    size_t j = 0;
    for (size_t i = 0; i < size; i++)
    {
            if (i == separat[j]){
            cout<<"|";
            j++;
        }
        print_in_hex(bytes[i]);


        if ((i + 1) % 16)
        {
            cout << ' ';
        }
        else
        {
            cout << '\n';
        }
    }
}


char
bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}

void
print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 8; bit > 0; bit--)
    {

        cout << bit_digit(byte, bit-1);

    }
}
void
print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);

        // Для удобства чтения: пробелы между байтами, по 4 байта на строку.
        if ((i + 1) % 4 )
        {
            cout << ' ';
        }
        else
        {
            cout << '\n';
        }
    }
}

void bitcalc()
{
    uint16_t operand1,operand2,result;
    char op; // опреатор

    cin>> operand1>>op>>operand2;

    switch (op)
    {
    case '&':
        result = operand1 & operand2;
        break;
    case '|':
        result = operand1 | operand2;
        break;
    case '^':
        result = operand1 ^ operand2;
        break;
    }
    print_in_hex(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_hex(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_hex(&result, sizeof(result));
    cout<<'\n';

    print_in_binary(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_binary(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_binary(&result, sizeof(result));

}

    struct Student{
        char name[17];
        uint16_t year;
        float mark;
        uint8_t gender : 1;
        uint8_t cours_compleate;
        Student *starosta;
    };

int main()
{
   // bitcalc();

   Student students[3]={
        {"Alexey",2000,4.55,1,10,&students[2]},
        {"Vladimir",2000,4.31,1,2,&students[2]},
        {"Maria",2001,4.80,0,2,nullptr}
    };


    cout<< "Adress of struct: "<<&students<<"; Size of struct: "<<sizeof(students)<<'\n';
     cout<< "Elements of struct: \n";
    cout<< "#\tAdress\t\tSize"<<'\n';
    for (size_t i = 0;i<3;i++){
        cout<<i<<'\t'<<&students[i]<<'\t'<<sizeof(students[i])<<'\n';
    }
        size_t s = 0;
    cout<<"\nElement #"<<s<<":\n";
    cout<<"\nField\tAdress\t\tOffset\tSize\n"
         <<"Name\t"<<&students[s].name<<'\t'<<offsetof(Student,name)<<'\t'<<sizeof(students[s].name);
        cout<<"\nHex:\n";print_in_hex(students[s].name,sizeof(students[s].name));
         cout<<"\nBin:\n"; print_in_binary(students[s].name,sizeof(students[s].name));
    cout<<"\n\nField\tAdress\t\tOffset\tSize\n"
        <<"Year\t"<<&students[s].year<<'\t'<<offsetof(Student,year)<<'\t'<<sizeof(students[s].year);
           cout<<"\nHex:\t"; print_in_hex(&students[s].year,sizeof(students[s].year));cout<<'\t';
           cout<<"\nBin:\t"; print_in_binary(&students[s].year,sizeof(students[s].year));
    cout<<"\n\nField\tAdress\t\tOffset\tSize\n"
        <<"Mark\t"<<&students[s].mark<<'\t'<<offsetof(Student,mark)<<'\t'<<sizeof(students[s].mark);
           cout<<"\nHex:\t"; print_in_hex(&students[s].mark,sizeof(students[s].mark));cout<<'\t';
           cout<<"\nBin:\t"; print_in_binary(&students[s].mark,sizeof(students[s].mark));
    cout<<"\n\nField\tAdress\tOffset\tSize\n"
        <<"Courses\t"<<"none"<<'\t'<<offsetof(Student,cours_compleate)<<'\t'<<sizeof(students[s].cours_compleate);
           cout<<"\nHex:\t"; print_in_hex(&students[s].cours_compleate,sizeof(students[s].cours_compleate));cout<<'\t';
           cout<<"\nBin:\t"; print_in_binary(&students[s].cours_compleate,sizeof(students[s].cours_compleate));
    cout<<"\n\nField\t\tAdress\t\tOffset\tSize\n"
        <<"starosta\t"<<&students[s].starosta<<'\t'<<offsetof(Student,starosta)<<'\t'<<sizeof(students[s].starosta);
           cout<<"\nHex:\t"; print_in_hex(&students[s].starosta,sizeof(students[s].starosta));cout<<'\t';
           cout<<"\nBin:\t"; print_in_binary(&students[s].starosta,sizeof(students[s].starosta));

    size_t offsetarrey[6] = {
        offsetof(Student,name),offsetof(Student,year),offsetof(Student,mark),
       // offsetof(Student,gender),
        24,offsetof(Student,cours_compleate),offsetof(Student,starosta),
    };

        cout<<"\n#|Name|Year|Mark|Gender|Courses|Starosta\n";
    for( size_t i = 0; i<3; i++) {
            cout<<'\n'<<"#"<<i<<" ";
            print_in_hex_separation(&students[i],sizeof(students[i]),offsetarrey);

    }



 /*
         <<"Name\t"<<offsetof(Student,name)<<'\t';field_info(students[element_show_num].name);
    cout<<"Year\t"<<offsetof(Student,year)<<'\t';field_info(students[element_show_num].year);

    */
    return 0;
}
