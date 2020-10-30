
#include "LatLon.hpp"

#include <cmath>

// For every function, write a comment defining what the function does
// and clarify what the parameters mean.

auto degrees_to_radians(float degrees) -> float {
  float _pi = 3.141592653589793;
  return degrees * _pi / 180.0;
}

auto LatLon::getCity() const -> std::string{
  return city_;
}
auto LatLon::setCity(const std::string& city) -> LatLon&{
  city_=city;
  return *this;
}

auto LatLon::getLatitude() const -> float{
  return latitude_;
}
auto LatLon::setLatitude(const float latitude) -> LatLon&{
  latitude_=latitude;
  return *this;
}
auto LatLon::getLongitude() const -> float{
  return longitude_;
}
auto LatLon::setLongitude(const float longitude) -> LatLon&{
  longitude_=longitude;
  return *this;
}


// Calculate the distance between this and point using the haversine
// formula. See https://en.wikipedia.org/wiki/Haversine_formula
auto LatLon::distanceFrom(const LatLon& point) -> float {
  // Earth's average radius in km.
  float earth_radius = 6371.0;
  // The C++ math library uses radians, convert the latitudes from degress
  // to radians.w
  float phi_this = degrees_to_radians(latitude_);
  float phi_point = degrees_to_radians(point.getLatitude());

  // Remember that the angle is measured from the center of the Earth.

  // Find the change in the angle between this point on Earth and that
  // point on Earth (North/South direction)
  float delta_phi = degrees_to_radians(point.getLatitude() - latitude_);

  // Find the change in the angle between this point on Earth and that
  // point on Earth (East/West direction)
  float delta_lambda = degrees_to_radians(point.getLongitude() - longitude_);

  // Calculate the square of half the chord length between this point and
  // that point.
  // Remember these points are on something that we're simplifying down
  // to a sphere.
  float a = sin(delta_phi / 2.0) * sin(delta_phi / 2.0) +
            cos(phi_this) * cos(phi_point) * sin(delta_lambda / 2.0) *
                sin(delta_lambda / 2.0);

  // Calculate the angular distance (in radians)
  float c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

  // Since we know the angular distance, multiply this with the Earth's
  // average radius to arrive upon the distance between the two points.
  float distance = earth_radius * c;
  return distance;
}
