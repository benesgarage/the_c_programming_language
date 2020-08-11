#include <stdio.h>

float toCelsius(float fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0.0;
    upper = 104.0;
    step = 5.2;

    celsius = lower;

    printf("%10s %10s\n", "Fahrenheit", "Celsius");
    while (celsius <= upper) {
        fahr = celsius * 9.0/5.0 + 32.0;
        printf("%10.2f %10.1f\n", fahr, celsius);
        celsius += step;
    }

    return 0;
}
