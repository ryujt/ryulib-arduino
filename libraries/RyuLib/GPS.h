#ifndef GPS_H
#define GPS_H

#include <Arduino.h>

const double pi = 3.1415926535897932384626433832795028841971;
const int earth_radius = 6371;

double ConvertToRadians(double angle);
double ConvertToStaticDegrees(double rad);
double haversin(double input);
int get_heading(double lat1, double long1, double lat2, double long2);
double get_distance(double lat1, double long1, double lat2, double long2);

class GPS {
private:
  double lat_;
  double lon_;
  char nors_;
  String text_;
  String lat_str_;
  String lon_str_;
public:
  void decode(char c) {
    if ((c == '\r') || (c == '\n')) {
      String command = text_.substring(0, 6);
      // Serial.println(text_);

      if (command.equals("$GPGGA")) {
        Serial.println("$GPGGA -->");
        char *text = (char *) text_.c_str();
        char *str[6];
        for (int i=0; i<6; i++) {
          str[i] = strtok_r(text, ",", &text);

          Serial.print(i);
          Serial.print(": ");
          Serial.println(str[i]);
        }

        lat_str_ = str[2];
        lon_str_ = str[4];

        lat_ = lat_str_.substring(0, 2).toInt() + (atof(lat_str_.substring(2, 32).c_str()) / 60);
        lon_ = lon_str_.substring(0, 3).toInt() + (atof(lon_str_.substring(3, 32).c_str()) / 60);

        nors_ = *str[3];
      }
      
      text_ =  "";
      Serial.println("");
    } else {
      text_ = text_ + c;
    }
  }

  char get_nors() { return nors_; }

  double get_lat() { return lat_; }
  double get_lon() { return lon_; }

  String get_lat_str() { return lat_str_; }
  String get_lon_str() { return lon_str_; }
};

#endif // GPS_H