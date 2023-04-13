#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cmath>
#include "ModulesPivnenko.hpp"

using namespace std;

float shortVal(float in_val){
    in_val = round(in_val*100)/100;

    return in_val;
}

bool testCase_9_1(int speedWind, category etalon){
    tornado_result result = task_9_1(speedWind);

    if(result.tornType == etalon)
        return true;
    return false;
}

bool testCase_9_2(float temp1, float temp2, float temp3, float temp4, float temp5, float temp6, float etalonCelsie, float etalonFahr){
    temperatureDay result = task_9_2(temp1, temp2, temp3, temp4, temp5, temp6);

    result.byCelsius = shortVal(result.byCelsius);
    result.byFahrenheit = shortVal(result.byFahrenheit);
    etalonCelsie = shortVal(etalonCelsie);
    etalonFahr = shortVal(etalonFahr);


    cout << "Celsius val: " << result.byCelsius << endl;
    cout << "Fahrenheit val: " << result.byFahrenheit << endl;

    if(result.byCelsius == etalonCelsie && result.byFahrenheit == etalonFahr)
        return true;
    return false;
}

bool testCase_9_3(unsigned short N, int etalon){
    int cnt_bits = task_9_3(N);

    if(cnt_bits == etalon){
        return true;
    }
    return false;
}

bool TestSuite_9_1(void){
    int speedVals[8] = { 70, 125, 200, 300, 367, 421, -5, 600};
    category catVal[8] = { F0, F1, F2, F3, F4, F5, ERR_F, ERR_F};

    bool findFail = false;

    for(int i = 0; i < 8; i += 1){
        bool test_res = testCase_9_1(speedVals[i], catVal[i]);
        cout << "TC number " << i << ": " << speedVals[i] << ". Category: " << catVal[i] << endl;
        cout << "Result is ";
        if(test_res == true)
            cout << "PASSED." << endl;
        if(test_res == false){
            findFail = true;
            cout << "FAILED" << endl;
        }
    }

    if(findFail == true)
        return false;

    return true;
}

bool TestSuite_9_2(void){
    bool resultSuite = true;

    float temp_vals[7][6] =
    {
        { 20, 21, 23, 24, 25, 26 },
        { 10, 15, 20, 25, 30, 40},
        { -10, -20, -30, -40, -50, -60},
        { -4, -7, -11, -1, -8, -20 },
        { 5.5, 10.1, 20.1, 9.9, 30.5, 31 },
        { -7.1, -3.5, -9.253, -1, -11.2, -10 },
        { 0, 0, 0, 0, 1, 1 }
    };

    float etalon_vals[7][2] =
    {
        { 23.166666, 73.7 },
        { 23.33333, 73.9999 },
        { -35, -31 },
        { -8.5, 16.7},
        { 17.8501, 64.13 },
        { -7.01000023, 19.3799992 },
        { 0.33, 32.6 }
    };

    for(int i = 0; i < 7; i += 1){
        bool case_res = testCase_9_2(temp_vals[i][0], temp_vals[i][1], temp_vals[i][2], temp_vals[i][3], temp_vals[i][4], temp_vals[i][5], etalon_vals[i][0], etalon_vals[i][1]);

        cout << "Input values: " <<  temp_vals[i][0] << ", " << temp_vals[i][1] << ", ";
        cout << temp_vals[i][2] << ", " << temp_vals[i][3] << ", " << temp_vals[i][4] << ", " << temp_vals[i][5] << endl;
        cout << "Etalon values: " << etalon_vals[i][0] << ", " << etalon_vals[i][1] << endl;

        if(case_res == true)
            cout << "Result is PASSED." << endl;
        else{
            cout << "Result is FAILED." << endl;
            resultSuite = false;
        }
    }

    return resultSuite;
}

bool TestSuite_9_3(void){
    unsigned short in_vals[10] = {0, 100, 200, 2340, 65535, 21000, 7801, 42050,  1, 50000};
    int benchmark[10] =          {16, 13, 13,  12,   16,     12,    7,    5,     15,  6 };
    // int benchark_ones[10] =      { 0, 3 , 3 ,  4 ,   16,     6,    9,    6,    1,   5  };

    for(int i = 0; i < 10; i += 1){
        if(testCase_9_3(in_vals[i], benchmark[i]) == true)
            cout << in_vals[i] << ", " << benchmark[i] << ". " << "PASSED." << endl;
        else
            cout << in_vals[i] << ", " << benchmark[i] << ". " << "FAILED." << endl;
    }

    return false;
}

int main()
{
    cout << "TEST DRIVER." << endl << "DEVELOPER: OLEKSANDR PIVNENKO, KN-22, MTF" << endl << "LABORATORY WORK 9.\n\n\n";

    TestSuite_9_1();

    cout << "\n\n";

    TestSuite_9_2();

    cout << "\n\n";

    TestSuite_9_3();

    return 0;
}
