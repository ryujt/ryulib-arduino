#include <thermistor.h>

double ThermistorToC(int RawADC) {  
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;  
 return Temp;
}

double ThermistorToF(int RawADC) {  
 double Temp;
 Temp = log(((10240000/RawADC) - 10000));
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;  
 Temp = (Temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit
 return Temp;
}