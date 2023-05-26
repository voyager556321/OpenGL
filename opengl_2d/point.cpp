#include "point.h"
#include <stdlib.h>

void printPoint(Point *ptr)
{
	if (NULL != ptr) {
		printf("{ x:%d, y:%d}", ptr->x, ptr->y);
	}
}

void fillPoint(Point *ptr)
{
	if (NULL != ptr) {
		ptr->x = 50;
		ptr->y = 30;
	}
}

Point *createPoint(int x, int y)
{
	Point *result = (Point *)malloc(sizeof(Point));
	if (NULL != result) {
		result->x = x;
		result->y = y;
	}

	return result;
}

Point *copyPoint(Point *ptr) {
	if (NULL == ptr) {
		return NULL;
	}

	return createPoint(ptr->x, ptr->y);
}

void deletePoint(Point *ptr) {
	if (NULL != ptr) {
		free(ptr);
	}
}

void setPointValues(Point* point, int x, int y){
    if (NULL != point) {
		point->x = x;
		point->y = y;
	}
}
