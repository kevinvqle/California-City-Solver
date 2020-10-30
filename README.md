### Distance Between California Cities
This exercise is meant to be an extension of the previous exercise. Previously, a Cartesian coordinate was defined as a class and focused uniquely on storing one type of data, namely floating point values. In this exercise, the data type you are creating is a [latitude](https://en.wikipedia.org/wiki/Latitude) and [longitude](https://en.wikipedia.org/wiki/Longitude) pair along with the name of the point on the Earth that it represents.

The class has three data members. There are two floating point data members which represent latitude and longitude and a `string` which represents the name of the location. You are provided with five data files which contain twenty cities in California. Each file starts with the name of the city (with spaces exchanged for underscores `_`), the latitude, and finally the longitude. The latitude and longitude are expressed as floating point values. Positive value of of latitude mean degrees north of the Earth's Equator. Negative values represent degrees south of the Earth's Equator. Positive values of longitude represent degrees east from the Prime Meridian, while negative values represent degrees west from the Prime Meridian. (Note that all the cities in California will have positive degrees latitude and negative degrees longitude because California is north of the Equator and east of the Prime Meridian.)

The objective of the program is to use the `LatLon` data type to read in twenty data points from the included data files, `location_data*.txt`, and identify the shortest distance and greatest distance defined by the twenty cities in the file. 

Generally, after ascertaining that there are command line arguments to process, the program shall open `argv[1]` and initialize an array of `LatLon` objects with the data. Next, define two floating point variables and four integer variables. (You may wish to define these variables in one or more arrays.) The six variables will represent the following:
* The pair of integer indices that represent the pair of points with the least distance
* The pair of integer indices that represent the pair of points with the greatest distance
* The greatest floating point distance
* The least floating point distance

The pair of indexes represent the location in the array of the pair of `LatLon` objects that are the greatest or least distance.

Select a pair of `LatLon` objects and use that pair to initialize these six variables.

Using nested loops, iterate over every pair of `LatLon` objects and calculate the distance. Should the distance be less than the current maximum or minimum, update the state of your program accordingly.

Additionally, define the following [member functions](https://en.wikipedia.org/wiki/Method_(computer_programming)#Member_functions_in_C++) (aka [methods](https://en.wikipedia.org/wiki/Method_(computer_programming))):
```
auto distanceFrom(const LatLon& point) -> float;
auto getCity() const -> std::string;
auto getLatitude() const -> float;
auto getLongitude() const -> float;
auto setCity(const std::string& city) -> LatLon&;
auto setLatitude(const float latitude) -> LatLon&;
auto setLongitude(const float longitude) -> LatLon&;
auto write(std::ostream& out) const -> std::ostream&{
```

Note that in this exercise, we are making use of [references](https://en.wikipedia.org/wiki/Reference_(C%2B%2B)) rathern than [pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming)). Additionally, you are strongly encouraged to use C++11 syntax rather than the older syntax used in the textbook. (Please don't use C++14 or later syntax.)

In the LatLon class, define three private data members named `city_`, `longitude_`, and `latitude_`. Note the trailing underscores (`_`). This is an easy way to make sure you can identify which data members are private data members.

Finally, print out what was calculated like this:
```
Thermalito and Rohnerville have the greatest distance of 246.7 km.
Cometa and Placerville have the least distance of 97.93 km.
```

Use the same pairwise comparison that was used in the previous exercise.

The pair of `LatLon`, `latlon_a` and `latlon_b` with the greatest or least distance is defined as the pair which has the greatest distance between them where `latlon_a != latlon_b` using the distance [haversine formula](https://en.wikipedia.org/wiki/Haversine_formula). An implementation is provided for you in `LatLon.cpp` with some notes on what is being calculated. The code is duplicated here for your review. (You do not need to edit it.)
```
// Calculate the distance between this and point using the haversine
// formula. See https://en.wikipedia.org/wiki/Haversine_formula
auto LatLon::distanceFrom(const LatLon& point) -> float {
  // Earth's average radius in km.
  float earth_radius = 6371.0;
  // The C++ math library uses radians, convert the latitudes from degress
  // to radians.
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
```

To build the program use the `make` command. The Makefile's default target is to build `all` which results in creating the binary `citysolver`.

The included `Makefile` includes the targets:
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the linter to give you tips on how to improve your code

To build your program, use the command `make` or `make all`. 


## Example Output
Pleae make sure your output matches the examples given.
```
$ ./citysolver 
Please provide an input file with a list of 20 cities. Exiting.
$ ./citysolver foobarfile
No such file.
$ ./citysolver location_data1.txt 
Elk_Grove and Freda have the greatest distance of 389.669 km.
Zee_Estates and Garden_Valley have the least distance of 19.2002 km.
$ ./citysolver location_data3.txt 
Tustin_Foothills and Poffenbergers_Landing have the greatest distance of 628.627 km.
New_Chinatown and Sherman_Oaks have the least distance of 21.7228 km.
$ ./citysolver location_data5.txt 
Redwoods and Wilsona_Gardens have the greatest distance of 551.13 km.
Juniper_Hills and Wilsona_Gardens have the least distance of 26.8177 km.
$ 
```

