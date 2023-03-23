#ifndef TRUCK_H
#define TRUCK_H
#include "Shipment.h"
#define MAXWEIGHT 1000.0 //kg of cargo
#define MAXVOLUME 36.0 //cubic meters of boxes

//Struct that tracks status of trucks
//Author: Marcus Brown
struct Truck
{
    double weight;// max 1000 kg of cargo
    double volume; // max 36 cubic meters of boxes
    struct Shipment box; //can hold array of boxes if needed with //struct Shipment box[MAXSHIPMENTS]
    char destinations[25][4]; //list of maximum 25 destinations each with a 3-character string
    int num_destinations; //number of valid destination codes
};
int whichTruck(const struct Map* map1, const struct Map* map2, const struct Map* map3, char m_destination[3]);
struct Truck* cmpTruck(const struct Truck* T1, const struct Truck* T2);
#endif