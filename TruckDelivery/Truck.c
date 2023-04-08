#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Truck.h"

//function to find which truck to use
//Author: Marcus Brown
int whichTruck(const struct Map* baseMap, struct Point dest, struct Truck* trucks_ptr) {
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getYellowRoute(); //green and yellow are litearlly reversed...
	struct Route yellowRoute = getGreenRoute(); //green and yellow are litearlly reversed...
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
		if (closestGreenDistance >= Distance)
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

	int truck = 0;
	//conditions to check which truck is closest, then if truck has space, if not must check second closest truck
	if (closestBlueDistance == closestGreenIndex)
	{
		truck = cmpTruck(trucks_ptr, 0, 1);
	}
	else if (closestBlueDistance == closestYellowDistance)
	{
		truck = cmpTruck(trucks_ptr, 0, 2);
	}
	else if (closestGreenDistance == closestYellowDistance) {
		truck = cmpTruck(trucks_ptr, 1, 2);
	}
	else if (closestBlueDistance <= closestGreenDistance && closestBlueDistance <= closestYellowDistance )
	{
		if (checkWeight(trucks_ptr, 0, trucks_ptr->shipment->m_weight) && checkVolume(trucks_ptr, 0, trucks_ptr->shipment->m_size))
		{
		truck = 1; //1 = blue
		}
		else if(closestGreenDistance < closestYellowDistance) {
			truck = 2;
		}
		else {
			truck = 3;
		}
	}
	else if (closestGreenDistance <= closestBlueDistance && closestGreenDistance <= closestYellowDistance)
	{
		if (checkWeight(trucks_ptr, 1, trucks_ptr->shipment->m_weight) && checkVolume(trucks_ptr, 1, trucks_ptr->shipment->m_size))
		{
		truck = 2; //2 = green
		}
		else if (closestBlueDistance < closestYellowDistance)
		{
			truck = 1;
		} else {
			truck = 3;
		}
	}
	else if (closestYellowDistance <= closestBlueDistance && closestYellowDistance <= closestGreenDistance)
	{
		if (checkWeight(trucks_ptr, 2, trucks_ptr->shipment->m_weight) && checkVolume(trucks_ptr, 2, trucks_ptr->shipment->m_size))
		{
		truck = 3; //3 = yellow
		}
		else if (closestBlueDistance < closestGreenDistance)
		{
			truck = 1; 
		}else{
			truck = 2;
		}
	}
	return truck;
}
//returns truck that's less full (used when distance are the same)//Brian Cheung
int cmpTruck(struct Truck* trucksPtr, int truckIdx1, int truckIdx2) {
	double weight1 = (trucksPtr[truckIdx1].weight / MAXWEIGHT) * 100;
	double weight2 = (trucksPtr[truckIdx2].weight / MAXWEIGHT) * 100;
	double volume1 = (trucksPtr[truckIdx1].volume / MAXVOLUME) * 100;
	double volume2 = (trucksPtr[truckIdx2].volume / MAXVOLUME) * 100;
	double T1Load = (volume1 + weight1) / 2;
	double T2Load = (volume2 + weight2) / 2;
	if (T1Load > T2Load) {
		return truckIdx1 + 1;
	}
	return truckIdx2 + 1;
}
//checks if package would exceed truck weight limit
int checkWeight(struct Truck* truckPtr, int truckIdx, int weight) {
	return (truckPtr[truckIdx].weight + weight <= MAX_WEIGHT) ? 1 : 0;
}
//adds weight to the truck
void addWeight(struct Truck* truckPtr, int truckIdx, int weight) {
	truckPtr[truckIdx].weight += weight;
}
//checks if package would exceed truck volume limit
int checkVolume(struct Truck* trucksPtr, int truckIdx, double size) {
	return (trucksPtr[truckIdx].volume + size <= MAXVOLUME) ? 1 : 0;
}
//adds volume to the truck
void addVolume(struct Truck* trucksPtr, int truckIdx, double size) {
	trucksPtr[truckIdx].volume += size;
}
