#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "Shipment.h"
#include "Truck.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	const struct Map routeMap = addRoute(&baseMap, &blueRoute);
	const struct Map routeMap2 = addRoute(&routeMap, &greenRoute);
	const struct Map routeMap3 = addRoute(&routeMap2, &yellowRoute);

	// struct Truck truck1 = {0,0,0,0,0};
	// struct Truck truck2 = {0,0,0,0,0};
	// struct Truck truck3 = {0,0,0,0,0};

	struct Shipment shipment;

	process_shipments(&shipment);
	printMap(&routeMap3, 1, 1);

	return 0;
}