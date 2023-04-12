#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Shipment.h"

//Input Function
//Author: Jaaved Dewan
//.git/hook test

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
			int numValuesRead = scanf("%d %lf %3s", &shipment.m_weight, &shipment.m_size, shipment.m_destination);
			if (numValuesRead != 3) { //makes sure there are three spaces in the input which will be ignored
				printf("Invalid input format. Please enter three values separated by spaces.\n");
				while (getchar() != '\n'); // Clear input buffer
				continue;
			}
			if (shipment.m_weight == 0 && shipment.m_size == 0 && strcmp(shipment.m_destination, "x") == 0) {
				flag = 1;
				valid = 1;
				break;
			}
			sscanf(shipment.m_destination, "%d%c", &yAxis, &xAxis);//parse string
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
			printf("Ship on BLUE LINE, ");
			addWeight(trucksPtr, 0, shipment.m_weight);
			addVolume(trucksPtr, 0, shipment.m_size);
		}
		else if (truck == 2) {
			printf("Ship on GREEN LINE, ");
			addWeight(trucksPtr, 1, shipment.m_weight);
			addVolume(trucksPtr, 1, shipment.m_size);
		}
		else if (truck == 3) {
			printf("Ship on YELLOW LINE, ");
			addWeight(trucksPtr, 2, shipment.m_weight);
			addVolume(trucksPtr, 2, shipment.m_size);
		}
		//can remove printf later
		/*printf("T1: Volume: %lf Weight: %d\n", trucksPtr[0].volume, trucksPtr[0].weight);
		printf("T2: Volume: %lf Weight: %d\n", trucksPtr[1].volume, trucksPtr[1].weight);
		printf("T3: Volume: %lf Weight: %d\n", trucksPtr[2].volume, trucksPtr[2].weight);*/
		findDiversion(truck, P);
	} while (!flag);

	printf("Thanks for shipping with Seneca!\n");
}

//Brian Cheung: find divert paths, if there are none, displays none
void findDiversion(const int truck, const struct Point P) {
	struct Route route = { {0,0}, 0, 0 };
	struct Route divertRoute = { {0,0}, 0, 0 };
	struct Map map = populateMap();
	if (truck == 1) {//blue 
		route = getBlueRoute();
	}
	else if (truck == 2) {//green
		route = getYellowRoute();
	}
	else if (truck == 3) {//yellow
		route = getGreenRoute();
	}
	int i = getClosestPoint(&route, P);
	divertRoute = shortestPath(&map, route.points[i], P);//shortestPath() fixed, see mapping module
	if (divertRoute.numPoints <= 3) {
		printf("no diversion\n");
	}
	else {
		printf("divert: ");
		printDiversion(&divertRoute);
		printf("\n");
	}
}
//Brian Cheung: Displays divertions
void printDiversion(const struct Route* diversion) {
	for (size_t i = 0; i < diversion->numPoints; i++) {
		char n = 0;
		switch (diversion->points[i].row) {
		case 24:
			n = 'Y';
			break;
		case 23:
			n = 'X';
			break;
		case 22:
			n = 'W';
			break;
		case 21:
			n = 'V';
			break;
		case 20:
			n = 'U';
			break;
		case 19:
			n = 'T';
			break;
		case 18:
			n = 'S';
			break;
		case 17:
			n = 'R';
			break;
		case 16:
			n = 'Q';
			break;
		case 15:
			n = 'P';
			break;
		case 14:
			n = 'O';
			break;
		case 13:
			n = 'N';
			break;
		case 12:
			n = 'M';
			break;
		case 11:
			n = 'L';
			break;
		case 10:
			n = 'K';
			break;
		case 9:
			n = 'J';
			break;
		case 8:
			n = 'I';
			break;
		case 7:
			n = 'H';
			break;
		case 6:
			n = 'G';
			break;
		case 5:
			n = 'F';
			break;
		case 4:
			n = 'E';
			break;
		case 3:
			n = 'D';
			break;
		case 2:
			n = 'C';
			break;
		case 1:
			n = 'B';
			break;
		default:
			n = 'A';
			break;
		}
		printf("%d%c", diversion->points[i].col,n);
		if (i != diversion->numPoints - 1) printf(", ");
	}
}

