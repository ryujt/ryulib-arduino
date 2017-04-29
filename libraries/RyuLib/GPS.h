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
    if (c == '$') {
      String command = text_.substring(0, 5);
      Serial.println(command);
      Serial.println(text_);

      if (command.equals("GPGGA")) {
        char *text = text_.c_str();
        char *str[6];
        for (int i=0; i<6; i++) {
          str[i] = strtok_r(text, ",", &text);
//          Serial.println(str[i]);
        }

        lat_str_ = str[2];
        lon_str_ = str[4];

        lat_ = atof(str[2]) / 100;
        lon_ = atof(str[4]) / 100;

        nors_ = *str[3];
      }
      
      text_ =  "";
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