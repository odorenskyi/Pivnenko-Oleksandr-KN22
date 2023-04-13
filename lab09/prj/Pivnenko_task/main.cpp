#include <iostream>
#include "ModulesPivnenko.hpp"

using namespace std;

int main()
{
    char symbol = '\0';

    while(symbol != 'Q' && symbol != 'q'){
        cin >> symbol;

        if(symbol == 'z'){
            float result = s_calculation(1, 1, 1);
            cout << "s_calculation result is " << result <<  "." <<endl;
        }
        else if(symbol == 'r'){
            tornado_result obj = task_9_1(100);
            cout << "Frequency and category: " << obj.freq << ", " << obj.tornType << endl;
        }
        else if(symbol == 's'){
            temperatureDay obj = task_9_2(10, 15, 20, 25, 30, 35);
            cout << "Average temperature by Celsius and Fahrenheit: " << obj.byCelsius << ", " << obj.byFahrenheit << "." << endl;
        }
        else if(symbol == 't'){
            cout << "Count on nulls ( or ones ) in number, " << task_9_3(100) << "." << endl;
        }
        else{
            cout << "\a";
        }

    }

    return 0;
}
