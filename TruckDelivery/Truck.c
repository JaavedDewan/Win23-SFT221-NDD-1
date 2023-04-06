#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Shipment.h"
#include "Truck.h"
#include "mapping.h"

//function to find which truck to use
//Author: Marcus Brown
int whichTruck(const struct Map* baseMap, struct Point dest) {
	// struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getYellowRoute(); //green and yellow are litearlly reversed...
	struct Route yellowRoute = getGreenRoute(); //green and yellow are litearlly reversed...

	// struct Route finalBlueRoute = { {0, 0}, 99, BLUE };
	// struct Route finalGreenRoute = { {0, 0}, 99, GREEN };
	// struct Route finalYellowRoute = { {0,0}, 99, YELLOW };

	double Distance = 0.0;
	double closestBlueDistance = 99.99;
	int closestBlueIndex = 99;
	double closestGreenDistance = 99.99;
	int closestGreenIndex = 99;
	double closestYellowDistance = 99.99;
	int closestYellowIndex = 99;
	//checking distance between each point on the blue path and the destination and saving the closest distance
	for (int i = 0; i < blueRoute.numPoints; i++)
	{
		Distance = distance(&blueRoute.points[i], &dest);
		if (closestBlueDistance >= Distance)
		{
			closestBlueDistance = Distance;
			closestBlueIndex = i;
		}
	}
	//shortest path function just does not work properly
		//finalBlueRoute = shortestPath(&baseMap, blueRoute.points[closestBlueIndex], dest); 
//checking distance between each point on the green path and the destination and saving the closest distance
	for (int i = 0; i < greenRoute.numPoints; i++)
	{
		Distance = distance(&greenRoute.points[i], &dest);
		if ( closestGreenDistance >= Distance)
		{
			closestGreenDistance = Distance;
			closestGreenIndex = i; 
		}
	}
	//finalGreenRoute = shortestPath(&baseMap, greenRoute.points[closestgreenIndex], dest);
//checking distance between each point on the yellow path and the destination and saving the closest distance
	for (int i = 0; i < yellowRoute.numPoints; i++)
	{
		Distance = distance(&yellowRoute.points[i], &dest);
		if (closestYellowDistance >= Distance)
		{
			closestYellowDistance = Distance;
			closestYellowIndex = i; 
		}
	}
	//finalYellowRoute = shortestPath(&baseMap, yellowRoute.points[closestyellowIndex], dest);

	//for (int i = 0; i < blueRoute.numPoints; i++)
//{
//	blueroute1 = shortestPath(&baseMap, blueRoute.points[i], dest);
//		if (finalblueRoute.numPoints > blueroute1.numPoints && blueroute1.numPoints != 0)
//		{
//		finalblueRoute = blueroute1;
//		}
//	}
//for (int i = 0; i < greenRoute.numPoints; i++)
//{
//	greenroute1 = shortestPath(&baseMap, greenRoute.points[i], dest);
//		if (finalGreenRoute.numPoints > greenroute1.numPoints && greenroute1.numPoints != 0)
//		{
//		finalGreenRoute = greenroute1;
//		}
//	}
//for (int i = 25; i < yellowRoute.numPoints; i++)
//{
//	yellowroute1 = shortestPath(&baseMap, yellowRoute.points[i], dest);
//		if (finalYellowRoute.numPoints > yellowroute1.numPoints && yellowroute1.numPoints != 0)
//		{
//		finalYellowRoute = yellowroute1;
//		}
//}

//int distanceBlue = finalBlueRoute.numPoints;
//int distanceGreen = finalGreenRoute.numPoints;
//int distanceYellow = finalYellowRoute.numPoints;

	int truck = 0;
	if (closestBlueDistance <= closestGreenDistance && closestBlueDistance <= closestYellowDistance)
	{
		truck = 1; //1 = blue
	}
	else if (closestGreenDistance <= closestBlueDistance && closestGreenDistance <= closestYellowDistance)
	{
		truck = 2; //2 = green
	}
	else if (closestYellowDistance <= closestBlueDistance && closestYellowDistance <= closestGreenDistance)
	{
		truck = 3; //3 = yellow
	}
	//should print path to dest for diversion if shortestpath worked
	/*for (int i = 0; i < finalBlueRoute.numPoints; i++)
	{
		printf(" {%d,%d},", finalBlueRoute.points[i].row, finalBlueRoute.points[i].col);
		printf("\n");
	}*/
	return truck;
}
//returns truck that's less full (used when distance are the same)//Brian Cheung
// struct Truck* cmpTruck(const struct Truck* T1, const struct Truck* T2) {
// 	double weight1 = (T1->weight / MAXWEIGHT) * 100;
// 	double weight2 = (T2->weight / MAXWEIGHT) * 100;
// 	double volume1 = (T1->volume / MAXVOLUME) * 100;
// 	double volume2 = (T2->volume / MAXVOLUME) * 100;
// 	double T1Load = (volume1 + weight1) / 2;
// 	double T2Load = (volume2 + weight2) / 2;
// 	if (T1Load > T2Load) {
// 		return T2;
// 	}
// 	else {
// 		return T1;
// 	}
// }