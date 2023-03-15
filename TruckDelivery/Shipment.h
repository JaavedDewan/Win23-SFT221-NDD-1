#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#define MIN_WEIGHT = 1;
#define MAX_WEIGHT = 1000;
#define MIN_SIZE = 0.25;
#define MAX_SIZE = 1.0;

struct Shipment
{
	int m_weight; //Between 1 to 1000 kg
	double m_size; //Between 0.25 to 1 cubic metre
	char m_destination[3]; //Max 3 characters
};

#endif
