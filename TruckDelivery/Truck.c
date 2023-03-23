#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Shipment.h"
#include "Truck.h"
#include "mapping.h"

//function to find which truck to use
//Author: Marcus Brown
int whichTruck(const struct Map* map1, const struct Map* map2, const struct Map* map3, char m_destination[3]) {

	//not going to work since can be 3 chars long should be handled in shipment read function (ie. 12B) then pass struct Point into this function
	const struct Point dest = { colValue, rowValue };


	// struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	// struct Map routeMap = addRoute(&baseMap, &blueRoute);
	// struct Map routeMap2 = addRoute(&routeMap, &greenRoute);
	// struct Map routeMap3 = addRoute(&routeMap2, &yellowRoute);
	struct Route route1;
	struct Route route2;
	struct Route route3;
	//need if statement to only replace route if shorter
	for (int i = 0; i < blueRoute.numPoints; i++)
	{
		route1 = shortestPath(map1, blueRoute.points[i], dest);
	}
	for (int i = 0; i < greenRoute.numPoints; i++)
	{
		route2 = shortestPath(map2, greenRoute.points[i], dest);
	}
	for (int i = 0; i < yellowRoute.numPoints; i++)
	{
		route3 = shortestPath(map3, yellowRoute.points[i], dest);
	}

	double distanceBlue = distance(&dest, route1.points);
	double distanceGreen = distance(&dest, route2.points);
	double distanceYellow = distance(&dest, route3.points);

	int truck = 0;
	if (route1.numPoints <= route2.numPoints && route1.numPoints <= route3.numPoints)
	{
		truck = 1; //1 = blue
	}
	else if (route2.numPoints <= route1.numPoints && route2.numPoints <= route3.numPoints)
	{
		truck = 2; //2 = green
	}
	else if (route3.numPoints <= route1.numPoints && route3.numPoints <= route2.numPoints)
	{
		truck = 3; //3 = yellow
	}

	return truck;


	//should print path to dest for diversion??
	for (int i = 0; i < blueRoute.numPoints; i++)
	{
		printf(" %c %c ,", blueRoute.points[i].row, blueRoute.points[i].col);
	}
}
//returns truck that's less full (used when distance are the same)//Brian Cheung
struct Truck* cmpTruck(const struct Truck* T1, const struct Truck* T2) {
	double weight1 = (T1->weight / MAXWEIGHT) * 100;
	double weight2 = (T2->weight / MAXWEIGHT) * 100;
	double volume1 = (T1->volume / MAXVOLUME) * 100;
	double volume2 = (T2->volume / MAXVOLUME) * 100;
	double T1Load = (volume1 + weight1) / 2;
	double T2Load = (volume2 + weight2) / 2;
	if (T1Load > T2Load) {
		return T2;
	}
	else {
		return T1;
	}
}