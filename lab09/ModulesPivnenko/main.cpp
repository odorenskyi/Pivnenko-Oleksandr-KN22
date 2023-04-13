#include <math.h>
#include "ModulesPivnenko.hpp"
#define PI 3.1415
#include <iostream>

using namespace std;

int calc_bits(unsigned short N, char bit){
    char cnt_bits = 0;
    char cnt = sizeof(N) * 8; // bits
    char i = 0;
    unsigned short mask = 0b0100000000000000;

    if(bit == 0){
        while(i < cnt){
            if((N & mask) == bit){
                cnt_bits += 1;
            }
            mask = mask >> 1;
            i += 1;
        }
    }
    else if(bit == 1){
        while(i < cnt){
            if((N & mask) >= bit){
                cnt_bits += 1;
            }
            mask = mask >> 1;
            i += 1;
        }
        cnt_bits += 1;
    }

    return cnt_bits;
}

float s_calculation(int x, int y, int z){
    float pow_res = pow(2*z + 1, x);

    float sqrt_res = sqrt(abs(y - ((float)1/(float)2) * z));

    float S = pow_res - sqrt_res + z + PI;

    return S;
}

tornado_result task_9_1(int speedWind){
    tornado_result desc; desc.freq = 0; desc.tornType = ERR_F;

    if(speedWind >= 64 && speedWind <= 116){
        desc.freq = 38.9;
        desc.tornType = category::F0;
    }
    else if(speedWind >= 117 && speedWind <= 180){
        desc.freq = 35.6;
        desc.tornType = category::F1;
    }
    else if(speedWind >= 181 && speedWind <= 253){
        desc.freq = 19.4;
        desc.tornType = category::F2;
    }
    else if(speedWind >= 254 && speedWind <= 332){
        desc.freq = 4.9;
        desc.tornType = category::F3;
    }
    else if(speedWind >= 333 && speedWind <= 418){
        desc.freq = 1.1;
        desc.tornType = category::F4;
    }
    else if(speedWind >= 419 && speedWind <= 512){
        desc.freq = 0.1;
        desc.tornType = category::F5;
    }

    return desc;
}

temperatureDay task_9_2(float temp1, float temp2, float temp3, float temp4, float temp5, float temp6){
    float averageVal = (temp1 + temp2 + temp3 + temp4 + temp5 + temp6)/6;

    temperatureDay outTemperatures;

    outTemperatures.byCelsius = averageVal;
    outTemperatures.byFahrenheit = (32.0 + (9.0/5.0)*averageVal);

    return outTemperatures;
}

int task_9_3(unsigned short N){
    // Нехай біт D0 - це перший біт. Наприклад нехай маємо ^0010010010010011
    // Тоді в такому разі біт після символу ^ буде вважатись бітом D0.

    char counter = 0;
    unsigned short mask = 0b1000000000000000;

    int result = N & mask;

    if(result == 0){
        counter = calc_bits(N, 0);
    }
    else if(result > 0){
        counter = calc_bits(N, 1);
    }
    else {
        cout << "Something is bad...";
        return -1;
    }

    return counter;
}
