/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/
#include <stdlib.h>

typedef struct
{
    int pos;
    int speed;
} Car;

int compare(const void *a, const void *b)
{
    Car *x = (Car *)a;
    Car *y = (Car *)b;

    return y->pos - x->pos; // descending order
}

int carFleet(int target, int *position, int positionSize, int *speed, int speedSize)
{
    Car cars[positionSize];

    for (int i = 0; i < positionSize; i++)
    {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, positionSize, sizeof(Car), compare);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < positionSize; i++)
    {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > maxTime)
        {
            fleets++;
            maxTime = time;
        }
    }

    return fleets;
}