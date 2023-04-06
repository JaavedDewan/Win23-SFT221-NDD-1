#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Shipment.h"

//Input Function
//Author: Jaaved Dewan

//Brian Cheung: Input validation, 
void process_shipments(struct Truck* trucksPtr) {
	struct Shipment shipment;
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
			scanf("%d %lf %3[^\n]", &shipment.m_weight, &shipment.m_size, shipment.m_destination);
			if (!shipment.m_weight && !shipment.m_size && shipment.m_destination[0] == 'x') {//exit condit
				flag = 1;
				valid = 1;
				break;
			}
			sscanf(shipment.m_destination, "%d%c", &yAxis, &xAxis);//parse string
			printf("\n%d %lf %s %d %c\n", shipment.m_weight, shipment.m_size, shipment.m_destination, yAxis, xAxis);
			if (shipment.m_weight < MIN_WEIGHT || shipment.m_weight > MAX_WEIGHT) {
				printf("Invalid weight (must be 1-1000 Kg.)\n");
			}
			else if (shipment.m_size < MIN_SIZE || shipment.m_size > MAX_SIZE) {
				printf("Invalid size\n");
			}
			else if (yAxis < MIN_YAXIS || yAxis > MAX_YAXIS || xAxis < 'A' || xAxis > 'Y') {
				printf("Invalid destination\n");
			}
			else {
				valid = 1;
			}

		} while (!valid);
		//map is zero indexed so have to -1
		int x = 0;//done in switch statement
		int y = yAxis - 1;
		switch (xAxis)
		{
		case 'A':
			x = 0;
			break;
		case 'B':
			x = 1;
			break;
		case 'C':
			x = 2;
			break;
		case 'D':
			x = 3;
			break;
		case 'E':
			x = 4;
			break;
		case 'F':
			x = 5;
			break;
		case 'G':
			x = 6;
			break;
		case 'H':
			x = 7;
			break;
		case 'I':
			x = 8;
			break;
		case 'J':
			x = 9;
			break;
		case 'K':
			x = 10;
			break;
		case 'L':
			x = 11;
			break;
		case 'M':
			x = 12;
			break;
		case 'N':
			x = 13;
			break;
		case 'O':
			x = 14;
			break;
		case 'P':
			x = 15;
			break;
		case 'Q':
			x = 16;
			break;
		case 'R':
			x = 17;
			break;
		case 'S':
			x = 18;
			break;
		case 'T':
			x = 19;
			break;
		case 'U':
			x = 20;
			break;
		case 'V':
			x = 21;
			break;
		case 'W':
			x = 22;
			break;
		case 'X':
			x = 23;
			break;
		case 'Y':
			x = 24;
			break;
		default:
			break;
		}
		struct Point P = { x , y };
		const struct Map baseMap = populateMap();
		trucksPtr[0].shipment = &shipment;
		trucksPtr[1].shipment = &shipment;
		trucksPtr[2].shipment = &shipment;
		int truck = whichTruck(&baseMap, P, trucksPtr);
		if (truck == 1) {
			printf("Ship on BLUE LINE, \n");
			addWeight(trucksPtr, 0, shipment.m_weight);
			addVolume(trucksPtr, 0, shipment.m_size);
		}
		else if (truck == 2) {
			printf("Ship on GREEN LINE, \n");
			addWeight(trucksPtr, 1, shipment.m_weight);
			addVolume(trucksPtr, 1, shipment.m_size);
		}
		else if (truck == 3) {
			printf("Ship on YELLOW LINE, \n");
			addWeight(trucksPtr, 2, shipment.m_weight);
			addVolume(trucksPtr, 2, shipment.m_size);
		}
		//can remove printf later
		printf("T1: Volume: %lf Weight: %d\n", trucksPtr[0].volume, trucksPtr[0].weight);
		printf("T2: Volume: %lf Weight: %d\n", trucksPtr[1].volume, trucksPtr[1].weight);
		printf("T3: Volume: %lf Weight: %d\n", trucksPtr[2].volume, trucksPtr[2].weight);

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
void findPath(const struct Shipment* shipment) {
	//whichTruck();

}


