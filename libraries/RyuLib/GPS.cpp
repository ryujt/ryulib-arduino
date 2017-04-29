#include <GPS.h>

double ConvertToRadians(double angle)
{
  return (pi / 180) * angle;
}

double ConvertToStaticDegrees(double rad)
{
  double degrees = rad / (pi / 180);
  if (degrees <= 0) {
    return degrees + 360;
  } else {
    return degrees;
  }
}

double haversin(double input)
{
  return (sin(input / 2)) * (sin(input / 2));
}

int get_heading(double lat1, double long1, double lat2, double long2)
{
  lat1 = ConvertToRadians(lat1);
  lat2 = ConvertToRadians(lat2);
  long1 = ConvertToRadians(long1);
  long2 = ConvertToRadians(long2);

  double dLon = long2 - long1;
  double y = sin(dLon) * cos(lat2);
  double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(dLon);
  
  return (int) ConvertToStaticDegrees(atan2(y, x));
}

/// distance in meter
double get_distance(double lat1, double long1, double lat2, double long2)
{
  lat1 = ConvertToRadians(lat1);
  lat2 = ConvertToRadians(lat2);
  long1 = ConvertToRadians(long1);
  long2 = ConvertToRadians(long2);

  double dLat = lat2 - lat1;
  double dLon = long2 - long1;
  double a = haversin(dLat) + cos(lat1) * cos(lat2) * haversin(dLon);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  
  return earth_radius * c * 1000;
}

