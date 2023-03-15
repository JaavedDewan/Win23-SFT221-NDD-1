#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#define MIN_WEIGHT = 1;
#define MAX_WEIGHT = 1000;
#define MAX_SIZE = 1.0;

struct Shipment
{
	int m_weight;
	double m_size;
	char m_destination[3];
};

#endif