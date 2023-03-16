#ifndef TRUCK_H
#define TRUCK_H
#define MAXWEIGHT = 1000.0 //kg of cargo
#define MAXVOLUME = 36.0 //cubic meters of boxes

//Struct that tracks status of trucks
//Author: Marcus Brown
struct Truck
{
    double weight;// max 1000 kg of cargo
    double volume; // max 36 cubic meters of boxes
};

#endif