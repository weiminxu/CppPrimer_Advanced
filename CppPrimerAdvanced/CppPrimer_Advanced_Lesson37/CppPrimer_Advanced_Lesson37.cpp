// CppPrimer_Advanced_Lesson37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
int my_cp(const char* src_file, const char* dest_file)
{
    FILE *in_file, *out_file;

    int error = fopen_s(&in_file, src_file, "rb");
    if (error != 0)
    {
        return 1;
    }

    error = fopen_s(&out_file, dest_file, "wb");
    if (error != 0)
    {
        return 2;
    }

    char rec[25];
    size_t bytes_in, bytes_out;
    bytes_in = fread(rec, 1, 25, in_file);
   /* while (bytes_in > 0)
    {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);
        if (bytes_in != bytes_out)
        {
            return 3;
        }
    }*/

    bytes_out = fwrite(rec, 1, bytes_in, out_file);
    if (bytes_in != bytes_out)
    {
        return 3;
    }

    fclose(in_file);
    fclose(out_file);
   
    return 0;
}


int main()
{
    int result;
    result = my_cp("1.txt", "2.txt");

    if (result != 0)
    {
        switch (result)
        {
        case 1:
            printf("when opening source file, error was happened!");
            break;
        case 2:
            printf("when opening destination file, error was happened!");
            break;
        case 3:
            printf("when copying file, error was happened!");
            break;
        defult:
            printf("some error happened were unknown!");
            break;
        }
    }



   // std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
