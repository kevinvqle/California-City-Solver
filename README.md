
The class has three data members. There are two floating point data members which represent latitude and longitude and a `string` which represents the name of the location. You are provided with five data files which contain twenty cities in California. Each file starts with the name of the city (with spaces exchanged for underscores `_`), the latitude, and finally the longitude. The latitude and longitude are expressed as floating point values. Positive value of of latitude mean degrees north of the Earth's Equator. Negative values represent degrees south of the Earth's Equator. Positive values of longitude represent degrees east from the Prime Meridian, while negative values represent degrees west from the Prime Meridian. (Note that all the cities in California will have positive degrees latitude and negative degrees longitude because California is north of the Equator and east of the Prime Meridian.)

The objective of the program is to use the `LatLon` data type to read in twenty data points from the included data files, `location_data*.txt`, and identify the shortest distance and greatest distance defined by the twenty cities in the file. 

Generally, the program shall open `argv[1]` and initialize an array of `LatLon` objects with the data. Next, define two floating point variables and four integer variables. (You may wish to define these variables in one or more arrays.) The six variables will represent the following:
* The pair of integer indices that represent the pair of points with the least distance
* The pair of integer indices that represent the pair of points with the greatest distance
* The greatest floating point distance
* The least floating point distance

The pair of indexes represent the location in the array of the pair of `LatLon` objects that are the greatest or least distance.

Select a pair of `LatLon` objects and use that pair to initialize these six variables.

Using nested loops, iterate over every pair of `LatLon` objects and calculate the distance. Should the distance be less than the current maximum or minimum, update the state of your program accordingly.
