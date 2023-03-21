#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Shipment.h"
#include "Truck.h"
#include "mapping.h"

//Input Function
//Author: Jaaved Dewan

void process_shipments(const struct Shipment* shipment) {
    printf("=================\n");
    printf("Seneca Deliveries\n");
    printf("=================\n");


    // Continuously prompt user for shipment information
    while (1) {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        scanf("%d %2.1f %3s", &shipment->m_weight, &shipment->m_size, shipment->m_destination);

        // Check if user wants to stop entering shipments
        if (shipment->m_weight == 0 && shipment->m_size == 0 && shipment->m_destination == 'x') {
            printf("Thanks for shipping with Seneca!\n");
            break;
        }

        // Check if weight is within valid range
        if (shipment->m_weight < 1 || shipment->m_weight > 1000) {
            printf("Invalid weight (must be 1-1000 Kg.)\n");
            continue;
        }

        // Check if box size is valid
        if (shipment->m_size < 0.25 || shipment->m_size > 1) {
            printf("Invalid size\n");
            continue;
        }

        // Check if destination code is valid
        if (shipment->m_destination == 0) {
            printf("Invalid destination\n");
            continue;
        }

        // Check if shipment can be shipped on BLUE LINE
        if () {
            printf("Ship on BLUE LINE, ");
            continue;
        }

        // Check if shipment can be shipped on GREEN LINE
        if () {
            printf("Ship on GREEN LINE, ");
            continue;
        }

        // Check if shipment can be shipped on RED LINE
        if () {
            printf("Ship on RED LINE, ");
            continue;
        }

        //Check if there is a diversion or not
        if () {
            printf("divert: ");
            continue;
        }
        else() {
            printf("no diversion\n");
            continue;
        }

        // Shipment cannot be shipped on any available truck line
        printf("Cannot ship: no available truck line\n");
    }
}


