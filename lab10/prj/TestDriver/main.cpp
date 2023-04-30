#include <iostream>
#include <iomanip>
#include <locale.h>
#include <windows.h>
#include <cmath>
#include "ModulesPivnenko.hpp"
#include <fstream>

using namespace std;

bool TestCase_10_3(int x, int y, int z, unsigned short b, string b_code, bool exceptRes, string inPath){
    bool result = Task_10_3(x, y, z, b, inPath);

    if(result == exceptRes && b_code == toBinary(b))
        return true;
    else
        return false;
}

bool TestCase_10_2(bool expectRes, string inPath){
    bool result = Task_10_2(inPath);

    if(expectRes == result)
        return true;
    else
        return false;

    return false;
}

bool TestCase_10_1(bool expectRes, string inPath){
    bool result = Task_10_1(inPath);

    if(expectRes == result)
        return true;

    return false;
}

bool TestSuite_10_1(){
    const bool exp_results[7] = { true, false, true, false, true, false, true};
    const string paths[7] = { "new_f.txt", "newf.txt", "new_f.txt", " ", "new_f.txt", "what_is_it", "new_f.txt"};
    int cnt_bools = 0;

    for(int i = 1; i <= 7; i += 1){
        bool case_res = TestCase_10_1(exp_results[i - 1], paths[i - 1]);

        cout << "Текст-кейс 10.1 за номером " << i;

        if(case_res == true){
            cout << " PASSED" << endl;
            cnt_bools += 1;
        }
        else{
            cout << " FAILED" << endl;
        }
        getchar();
    }


    if(cnt_bools == 7)
        return true;
    else
        return false;
}

bool TestSuite_10_2(){
    const string paths[7] = {"ukr.txt", "second_ukr.txt", "ukr.txt", "second_ukr.txt", " ", "ukr.txt", " "};
    const bool expectRes[7] = {true, true, true, true, false, true, false};
    int cnt_bools = 0;

    for(int i = 1; i <= 7; i += 1){
        bool case_res = TestCase_10_2(expectRes[i - 1], paths[i - 1]);

        cout << "Текст-кейс 10.2 за номером " << i;

        if(case_res == true){
            cout << " PASSED" << endl;
            cnt_bools += 1;
        }
        else{
            cout << " FAILED" << endl;
        }

        getchar();
    }
    if(cnt_bools == 7)
        return true;
    else
        return false;
}

bool TestSuite_10_3(){
    const bool exceptRes[6] = {true, true, true, true, true, true};
    const string b_codes[6] = {"0000000001100100", "0000000001100100", "0000000000000100", "0000010000000000", "0000001111111111", "0000101110111000"};
    const string paths[6] = {"main_f.txt", "main_f.txt", "main_f.txt", "main_f.txt", "main_f.txt", "main_f.txt"};
    const unsigned short b_vals[6] = {100, 100, 4, 1024, 1023, 3000};
    const int x[6] = {3, 3, 1, 0, 0, 4};
    const int y[6] = {3, 3, 5, 0, 0, 7};
    const int z[6] = {3, 3, 2, 0, 0, 7};

    int cnt_bools = 0;

    for(int i = 1; i <= 6; i += 1){
        bool case_res = TestCase_10_3(x[i - 1], y[i - 1], z[i - 1], b_vals[i - 1], b_codes[i - 1], exceptRes[i - 1], paths[i - 1]);
        int cnt_bools = 0;

        cout << "Текст-кейс 10.3 за номером " << i;

        if(case_res == true){
            cout << " PASSED" << endl;
            cnt_bools += 1;
        }
        else{
            cout << " FAILED" << endl;
        }

        getchar();
    }

    if(cnt_bools == 6)
        return true;
    else
        return false;
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TestSuite_10_1();
    TestSuite_10_2();
    TestSuite_10_3();

    cout << "\nНатисніть ENTER щоб вийти із програми." << endl;
    getchar();
    return 0;
}
