#include "GridBox.h"

GridBox::GridBox(ofVec3f origin, double width, double height, double divisionFactor)
    : origin(origin), width(width), height(height), divisionFactor(divisionFactor)
{
    // do nothing
}

/*
 * @origin point of origin
 * @diagonalEnd point at the end of the diagonal from origin
 */
/* TODO change topRight to topLeft */
void drawGrid(ofVec3f botLeft, ofVec3f botRight, ofVec3f topRight, double divisionFactor)
{
    double slice = 1.0 / divisionFactor;
    for (double t = 0.0; t <= 1.0; t += slice) {
        /* vertical lines */
        ofVec3f origin = (1-t) * botLeft + t * botRight;
        ofVec3f drawDirection = topRight - botRight;
        ofVec3f drawTo = origin + drawDirection;
        ofLine(origin.x, origin.y, origin.z,
               drawTo.x, drawTo.y, drawTo.z);

        /* horizontal lines */
        origin = (1-t) * botLeft + t * (botLeft + (topRight - botRight));
        drawDirection = botRight - botLeft;
        drawTo = origin + drawDirection;
        ofLine(origin.x, origin.y, origin.z,
               drawTo.x, drawTo.y, drawTo.z);
    }
}

void GridBox::draw(float depth)
{
    /* even though drawGrid allows for drawing skewed grids,
     * we disallow it in GridBox for simplicity purposes */
    /* bottom wall */
    ofVec3f botLeft = origin;
    ofVec3f botRight(origin.x + width, origin.y, origin.z);
    ofVec3f topRight(origin.x + width, origin.y, origin.z - depth);
    drawGrid(botLeft, botRight, topRight, divisionFactor);
    /* top wall */
    botLeft  = ofVec3f(origin.x, origin.y + height, origin.z);
    botRight = ofVec3f(origin.x + width, origin.y + height, origin.z);
    topRight = ofVec3f(origin.x + width, origin.y + height, origin.z - depth);
    drawGrid(botLeft, botRight, topRight, divisionFactor);
    /* left wall */
    botLeft  = origin;
    botRight = ofVec3f(origin.x, origin.y, origin.z - depth);
    topRight = ofVec3f(origin.x, origin.y + height, origin.z - depth);
    drawGrid(botLeft, botRight, topRight, divisionFactor);
    /* right wall */
    botLeft  = ofVec3f(origin.x + width, origin.y, origin.z);
    botRight = ofVec3f(origin.x + width, origin.y, origin.z - depth);
    topRight = ofVec3f(origin.x + width, origin.y + height, origin.z - depth);
    drawGrid(botLeft, botRight, topRight, divisionFactor);
    /* back wall */
    botLeft  = ofVec3f(origin.x, origin.y, origin.z - depth);
    botRight = ofVec3f(origin.x + width, origin.y, origin.z - depth);
    topRight = ofVec3f(origin.x + width, origin.y + height, origin.z - depth);
    drawGrid(botLeft, botRight, topRight, divisionFactor);
}
