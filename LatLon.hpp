

// This is a header guard.
// Read more about it at https://en.wikipedia.org/wiki/Include_guard
#ifndef _LATLON_HPP_
#define _LATLON_HPP_

#include <string>
#include <iostream>

// For every function, write a comment defining what the function does
// and clarify what the parameters mean.

auto degrees_to_radians(float degrees) -> float;

class LatLon {
 private:
  // Define two floats, latitude and longitude, and a city name
  std::string city_;
  float latitude_;
  float longitude_;

 public:
  LatLon(const std::string& city = std::string(), float latitude = 0,
         float longitude = 0) : city_(city), latitude_(latitude), longitude_(longitude)
         {};

  auto getCity() const -> std::string;

  auto setCity(const std::string& city) -> LatLon&;

  auto getLatitude()const -> float;

  auto setLatitude(const float latitude) -> LatLon&;

  auto getLongitude() const -> float;

  auto setLongitude(const float longitude) -> LatLon&;

  // Add the other getters and setters.
  auto write(std::ostream& out) const -> std::ostream&;
  ~LatLon(){};
  // Returns the number of kilometers between this LatLon and the
  // LatLon point. Assume's the earth's radius is about 6,371 KM.
  // Angles must be in radians for use with the C++ math library.
  auto distanceFrom(const LatLon& point) -> float;
};

#endif
// The #endif matches the #ifdef at the start of the file
// This is the end of the header guard.
