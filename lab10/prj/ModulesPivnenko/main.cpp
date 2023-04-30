#include <math.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <ctype.h>
#define PI 3.1415

using namespace std;

string toBinary(unsigned short b){
    int cnt = sizeof(b);
    unsigned short mask = 32768;
    string binary_view = "";

    for (int i = 0; i < (cnt * 8); i++)
    {
        int temp_val = b & mask;
        if(temp_val == 0)
            binary_view += "0";
        else
            binary_view += "1";
        mask = mask >> 1;
    }

    return binary_view;
}

string findWords(string text, string words[], int cntWords){
    bool IsFind = false;
    int i = 0;
    int j = 0;
    int letter = 0;
    int text_size = text.length();
    string output = "";

    while(i < cntWords){
        while(j < text_size){
            if(words[i][letter] == text[j]){
                IsFind = true;
                letter += 1;
            }
            else{
                IsFind = false;
                letter = 0;
            }

            if(IsFind == true && letter == int(words[i].length()) && (text[j + 1] == ' ' || text[j + 1] == ':' || text[j + 1] == ';' || text[j + 1] == ',' || text[j + 1] == '!' || text[j + 1] == '?' || text[j + 1] == '-' || text[j + 1] == '.')){
                output += words[i] + " ";
                letter = 0;
                IsFind = false;
                break;
            }
            else if(IsFind == true && letter == int(words[i].length())){
                letter = 0;
                IsFind = false;
            }

            j += 1;
        }
        j = 0;
        i += 1;
    }

    return output;
}

float s_calculation(int x, int y, int z){
    float pow_res = pow(2*z + 1, x);

    float sqrt_res = sqrt(abs(y - ((float)1/(float)2) * z));

    float S = pow_res - sqrt_res + z + PI;

    return S;
}

bool Task_10_1(string inputPath){
    string toWrite = "Розробник: О. Півненко.\nЦНТУ, м.Кропивницький, Україна, 2023 р.";
    string readLine;
    string text;
    string toFind[4] = {"програма", "модуль", "студент", "програміст"};

    string outputPath = "outfile.txt";
    ofstream outStream;
    ifstream readFile;

    readFile.open(inputPath, ios_base::in);
    outStream.open("outputfile.txt", ios_base::out);

    try
    {
        if(!outStream.is_open() || !readFile.is_open())
            throw exception();

        while(!readFile.eof()){
            getline(readFile, readLine);
            text += readLine;
            text += "\n";
        }
        readFile.close();

        outStream << toWrite << endl;
        outStream << "К-ть символів у тексті: " << text.length() << endl;
        outStream << "Знайдені слова у тексті: " << findWords(text, toFind, 4);

        outStream.close();
    }
    catch(...){
        cout << "Файл не можна відкрити." << endl;
        return false;
    }


	return true;
}

bool Task_10_2(string inputPath){
    try{
        string toWrite = "Державними символами України є Державний Прапор України, Державний Герб України і Державний гімн України.\n";

        time_t now = time(nullptr);
        tm *local_time = localtime(&now);

        ofstream writer;
        writer.open(inputPath, ios_base::out | ios_base::app);

        if(!writer.is_open())
            throw exception();

        writer << toWrite << endl;
        writer << "Час запису: " << local_time -> tm_hour << ":" << local_time -> tm_min << ":" << local_time -> tm_sec << endl;
        writer << "Дата запису: " << local_time -> tm_mday << "." << local_time -> tm_mon + 1 << "." << local_time -> tm_year + 1900 << endl;

        writer.close();
    }
    catch(...){
        cout << "Файл не можна відкрити." << endl;
        return false;
    }
    return true;
}

bool Task_10_3(int x, int y, int z, unsigned short b, string inputPath){
    try{
        ofstream writer;
        writer.open(inputPath, ios_base::out | ios_base::app);

        if(!writer.is_open())
            throw exception();

        float result_s = s_calculation(x, y, z);

        writer << "Результати обчислення s_calculation: " << result_s << endl;
        writer << "Число b у двійковому коді: " << toBinary(b) << endl;

        writer.close();
    }
    catch(...){
        cout << "Файл не можна відкрити.";
        return false;
    }

    return true;
}
