#include <stdio.h>

//prototyping
float ceclciusToKelvin(float celcius);
float ceclciusToFarenheit(float celcius);
void celciusToKelvinAndFarenheit(float celcius, float* kelvin, float*farenheit);



void celciusToKelvinAndFarenheit(float celcius, float* kelvin, float*farenheit){
    //check if pointers are initalised; if kelvin = null
    *kelvin = ceclciusToKelvin(celcius);
    *farenheit = ceclciusToFarenheit(celcius);
}

float ceclciusToKelvin(float celcius){
    return celcius + 273.15;
}

float ceclciusToFarenheit(float celcius){
    return (celcius * 1.8) + 32;
}

int main()
{
    float celcius, kelvin, farenheit;
    celcius = 13.5; //give user input
    celciusToKelvinAndFarenheit(celcius, &kelvin, &farenheit);
    printf("%.3f celcius is equivalent to %.3f Kelvin and %.3f farenheit",
    celcius, kelvin, farenheit);
    return 0;
}

