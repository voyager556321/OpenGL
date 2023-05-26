#ifndef point_h
#define point_h

#include <stdio.h>

struct tagPoint {
	int x;
	int y;
};
typedef struct tagPoint Point;

Point *createPoint(int x, int y);
Point *copyPoint(Point *ptr);
void deletePoint(Point *ptr);
void printPoint(Point *ptr);
void fillPoint(Point *ptr);
void setPointValues(Point* point, int x, int y);

#endif /* point_h */
