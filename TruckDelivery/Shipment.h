#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#define MIN_WEIGHT 1
#define MAX_WEIGHT 1000
#define MIN_SIZE 0.25
#define MAX_SIZE 1.0
#define DEST_COORDINATE 3
#define MAX_YAXIS 25
#define MIN_YAXIS 1

//Structure based on required input needed for the Truck Delivery software.
//Author: Jaaved Dewan
struct Shipment
{
	int m_weight; //Between 1 to 1000 kg
	double m_size; //Between 0.25 to 1 cubic metre
	char m_destination[DEST_COORDINATE + 1]; //Max 3 characters
};

void process_shipments(const struct Shipment* shipment);
void findPath(const int weight, const double size, const char* destination);
#endif
