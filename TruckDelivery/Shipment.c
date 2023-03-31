#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Shipment.h"
#include "Truck.h"
#include "mapping.h"

//Input Function
//Author: Jaaved Dewan

//Brian Cheung: Input validation, 
void process_shipments(struct Shipment* shipment) {
	int flag = 0;
	int valid = 0;
	printf("=================\n");
	printf("Seneca Deliveries\n");
	printf("=================\n");

	//input validation
	do {
		int yAxis = 0;
		char xAxis = 0;
		do {
			printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
			scanf("%d %lf %3[^\n]", &shipment->m_weight, &shipment->m_size, shipment->m_destination);
			if (!shipment->m_weight && !shipment->m_size && shipment->m_destination[0] == 'x') {//exit condit
				flag = 1;
				valid = 1;
				break;
			}
			sscanf(shipment->m_destination, "%d%c", &yAxis, &xAxis);//parse string
			printf("\n%d %lf %s %d %c\n", shipment->m_weight, shipment->m_size, shipment->m_destination, yAxis, xAxis);
			if (shipment->m_weight < MIN_WEIGHT || shipment->m_weight > MAX_WEIGHT) {
				printf("Invalid weight (must be 1-1000 Kg.)\n");
			}
			else if (shipment->m_size < MIN_SIZE || shipment->m_size > MAX_SIZE) {
				printf("Invalid size\n");
			}
			else if (yAxis < MIN_YAXIS || yAxis > MAX_YAXIS || xAxis < 'A' || xAxis > 'Y') {
				printf("Invalid destination\n");
			}
			else {
				valid = 1;
			}

		} while (!valid);

		//struct Point P = { xAxis , yAxis };
		//int truck = whichTruck(&mapB, &mapG, &mapY, P);
		//if (truck == 1) {
		//	printf("Ship on BLUE LINE, \n");
		//}
		//else if (truck == 2) {
		//	printf("Ship on GREEN LINE, \n");
		//}
		//else if (truck == 3) {
		//	printf("Ship on YELLOW LINE, \n");
		//}

	} while (!flag);

	printf("Thanks for shipping with Seneca!\n");
	//while (1) {
	//	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
	//	scanf("%d %2.1f %[]", &shipment->m_weight, &shipment->m_size, shipment->m_destination);

	//	// Check if user wants to stop entering shipments
	//	if (shipment->m_weight == 0 && shipment->m_size == 0 && shipment->m_destination == 'x') {
	//		printf("Thanks for shipping with Seneca!\n");
	//		break;
	//	}

	//	// Check if weight is within valid range
	//	if (shipment->m_weight < 1 || shipment->m_weight > 1000) {
	//		printf("Invalid weight (must be 1-1000 Kg.)\n");
	//		continue;
	//	}

	//	// Check if box size is valid
	//	if (shipment->m_size < 0.25 || shipment->m_size > 1) {
	//		printf("Invalid size\n");
	//		continue;
	//	}

	//	// Check if destination code is valid
	//	if (shipment->m_destination == 0) {
	//		printf("Invalid destination\n");
	//		continue;
	//	}

	//	// Check if shipment can be shipped on BLUE LINE
	//	if () {
	//	    printf("Ship on BLUE LINE, ");
	//	    continue;
	//	}

	//	// Check if shipment can be shipped on GREEN LINE
	//	if () {
	//	    printf("Ship on GREEN LINE, ");
	//	    continue;
	//	}

	//	// Check if shipment can be shipped on RED LINE
	//	if () {
	//	    printf("Ship on RED LINE, ");
	//	    continue;
	//	}

	//	//Check if there is a diversion or not
	//	if () {
	//	    printf("divert: ");
	//	    continue;
	//	}
	//	else() {
	//	    printf("no diversion\n");
	//	    continue;
	//	}

	//	// Shipment cannot be shipped on any available truck line
	//	printf("Cannot ship: no available truck line\n");
	//}
}

//TO DO:
//find path for shipment, should figure out which truck first then path, and finally divert path if any
//
void findPath(const struct Shipment* shipment){
	//whichTruck();

}


