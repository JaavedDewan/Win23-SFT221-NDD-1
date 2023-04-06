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


	struct Truck trucks[3];
	for (int i = 0; i < 3; i++)
	{
		trucks[i].volume = 0.0;
		trucks[i].weight = 0;
	}
	struct Truck* ptr = trucks;

	struct Shipment shipment;

	process_shipments(ptr);
	printMap(&routeMap3, 1, 1);

	return 0;
}