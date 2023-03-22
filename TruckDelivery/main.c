#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Route greenRoute = getGreenRoute();
	struct Route yellowRoute = getYellowRoute();

	struct Map routeMap = addRoute(&baseMap, &blueRoute);
	struct Map routeMap2 = addRoute(&baseMap, &greenRoute);
	struct Map routeMap3 = addRoute(&baseMap, &yellowRoute);

	printMap(&routeMap3, 1, 1);

	return 0;
}