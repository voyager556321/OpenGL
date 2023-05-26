#ifndef figure_h
#define figure_h

#include <stdio.h>
#include "point.h"

#define PT_NUM 3

typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;

Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);


typedef struct Figure_s{
    Point* points[PT_NUM]; // ВАЖЛИВО: в прикладі координати мають значення від [-100;100], але потім масштабуються до [-1;1] як цього потребує OpenGL
    Color_s* color;
} Figure_s;

Figure_s* createFigure(Point** points, Color_s * color);
void deleteFigure(Figure_s* figure);
void drawFigure(Figure_s* figure);

typedef struct FigureListElement_s{
    FigureListElement_s* prev;
    FigureListElement_s* next;
    Figure_s* figure;
} FigureListElement_s;

FigureListElement_s* createListElement(Figure_s* figure);
void deleteListElement(FigureListElement_s* listElement);
void drawListElement(FigureListElement_s* listElement);


// Двозв'язний список фігур
typedef struct FigureList_s{
    FigureListElement_s* head;
    FigureListElement_s* tail;
} FigureList_s;

FigureList_s *createFigList(void);
void deleteFigList(FigureList_s *list);
void drawFigList(FigureList_s *list);
long countOfFigList(FigureList_s *list);
int addFigToFigList(FigureList_s *list, Figure_s* figure); // 1 - успіх, 0 - провал
void removeLastElementFromFigList(FigureList_s *list);
void removeFirstElementFromFigList(FigureList_s *list);
int insertFigToFigListAtIndex(FigureList_s *list, int index, Figure_s* figure); // 1 - успіх, 0 - провал
int removeFigFromFigListAtIndex(FigureList_s *list, int index); // 1 - успіх, 0 - провал

#endif
