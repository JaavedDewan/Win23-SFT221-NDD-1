#ifndef TRUCK_H
#define TRUCK_H
#include "Shipment.h"
#include "mapping.h"
#define MAXWEIGHT 1000.0 //kg of cargo
#define MAXVOLUME 36.0 //cubic meters of boxes

//Struct that tracks status of trucks
//Author: Marcus Brown
struct Truck
{
    int weight;// max 1000 kg of cargo
    double volume; // max 36 cubic meters of boxes
    struct Shipment* shipment;
};
int whichTruck(const struct Map* baseMap, struct Point dest, struct Truck* trucks_Ptr);
int cmpTruck(struct Truck* trucksPtr, int truckIdx1, int truckIdx2);
int checkWeight(struct Truck* truckPtr, int truckIdx, int weight);
void addWeight(struct Truck* truckPtr, int truckIdx, int weight);
int checkVolume(struct Truck* trucksPtr, int truckIdx, double volume);
void addVolume(struct Truck* trucksPtr, int truckIdx, double volume);
#endif