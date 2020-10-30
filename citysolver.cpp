// Kevin Le
// CPSC 121-01
// Lab-04, prob-01
// 2020-3-10
// kevin.lelele@csu.fullerton.edu
//
// Using nested loops, we are able to find every pair of LatLon objects and calculate the distance
//by using 5 daya files which contain twenty cities
//

#include <fstream>
#include <iostream>

#include "LatLon.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Please provide an input file with a list of 20 cities. Exiting.\n";
    exit(1);
  }

ifstream input_file(argv[1], ios::in);
const int NUM_CITIES = 20;
LatLon points [NUM_CITIES];
int current_point = 0;
float latitude, longitude; string city_name;


while(input_file >> city_name >> latitude >> longitude){
  points[current_point].setCity(city_name);
  points[current_point].setLatitude(latitude);
  points[current_point].setLongitude(longitude);
  current_point++;
}
float dist = 0;
 int start_point = 0;
 float max = 0;
 float min = 900;
 int max_start = 0;
 int max_end = 0;
 int min_start = 0;
 int min_end = 0;
  for(start_point = 0; start_point < 20; start_point++)
  {
      for(current_point = start_point+1; current_point < 20; current_point++)
    {
      dist= points[start_point].distanceFrom(points[current_point]);
      if (dist < min){
        min = dist;
        min_start = start_point;
        min_end = current_point;
      }
      if (dist > max){
        max = dist;
        max_start= start_point;
        max_end = current_point;
      }
}
}

  cout<< points[(max_start)].getCity()<< " and " << points[(max_end)].getCity();
cout << " have the greatest distance of" << max << " km "<< "\n";
cout << points[(min_start)].getCity()<< " and " << points[(min_end)].getCity();
cout << " have the lowest distance of " << min << " km "<< "\n";
return 0;
}
