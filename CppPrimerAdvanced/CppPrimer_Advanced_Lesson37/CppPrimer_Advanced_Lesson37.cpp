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

void my_cp2(const char* src_file, const char* dest_file)
{
    FILE* in_file, * out_file;

    int error = fopen_s(&in_file, src_file, "rb");
    if (error != 0)
    {
        //return 1;
        throw 1;
    }

    error = fopen_s(&out_file, dest_file, "wb");
    if (error != 0)
    {
        //return 2;
        throw 2;
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
        //return 3;
        throw 3;
    }

    fclose(in_file);
    fclose(out_file);

}


void my_cp3(const char* src_file, const char* dest_file)
{
    FILE* in_file, * out_file;

    int error = fopen_s(&in_file, src_file, "rb");
    if (error != 0)
    {
        //return 1;
        //throw 1;
        throw "when opening source file, error was happened!";
    }

    error = fopen_s(&out_file, dest_file, "wb");
    if (error != 0)
    {
        //return 2;
        //throw 2;
        throw "when opening destination file, error was happened!";
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
        //return 3;
        //throw 3;
        throw "when copying file, error was happened!";
    }

    fclose(in_file);
    fclose(out_file);

}


class BadSrcFile {};
class BadDestFile {};
class BadCopy {};


void my_cp4(const char* src_file, const char* dest_file)
{
    FILE* in_file, * out_file;

    int error = fopen_s(&in_file, src_file, "rb");
    if (error != 0)
    {
        //return 1;
        //throw 1;
        //throw "when opening source file, error was happened!";
        throw BadSrcFile();
    }

    error = fopen_s(&out_file, dest_file, "wb");
    if (error != 0)
    {
        //return 2;
        //throw 2;
        //throw "when opening destination file, error was happened!";
        throw BadDestFile();
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
        //return 3;
        //throw 3;
        //throw "when copying file, error was happened!";
        throw BadCopy();
    }

    fclose(in_file);
    fclose(out_file);

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

    try
    {
        my_cp2("1.txt", "3.txt");
    }
    catch (int e)
    {
        printf("error happened: %d\n", e);
    }

    try
    {
        my_cp4("1.txt", "4.txt");
    }
    catch (const char* e)
    {
        printf("%s\n", e);
    }

    try
    {
        my_cp3("1.txt", "5.txt");
    }
    catch (BadSrcFile e)
    {
        printf("when opening source file, error was happened!");
    }
    catch (BadDestFile e)
    {
        printf("when opening destination file, error was happened!");
    }
    catch (BadCopy e)
    {
        printf("when copying file, error was happened!");
    }
    catch (...)
    {
        printf("unknown error has happened!");
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
