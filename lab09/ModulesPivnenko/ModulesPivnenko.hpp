#ifndef MODULESPIVNENKO_HPP_INCLUDED
#define MODULESPIVNENKO_HPP_INCLUDED

enum category{
    F0,
    F1,
    F2,
    F3,
    F4,
    F5,
    ERR_F
};

struct tornado_result{
    category tornType;
    float freq;
};

struct temperatureDay{
    float byCelsius;
    float byFahrenheit;
};

float s_calculation(int x, int y, int z);

tornado_result task_9_1(int speedWind);

temperatureDay task_9_2(float, float, float, float, float, float);

int task_9_3(unsigned short N);

#endif // MODULESPIVNENKO_HPP_INCLUDED
