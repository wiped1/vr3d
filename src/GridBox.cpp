#include "GridBox.h"

GridBox::GridBox(ofVec3f origin, double width, double height, double depth, double divisionFactor)
    : origin(origin), width(width), height(height), depth(depth), divisionFactor(divisionFactor)
{
    // do nothing
}

/*
 * @origin point of origin
 * @diagonalEnd point at the end of the diagonal from origin
 */
void drawGrid(ofVec3f botLeft, ofVec3f botRight, ofVec3f topRight, double divisionFactor)
{
    /* direction vector pointing from botLeft to botRight */
    ofVec3f direction = botRight - botLeft;
    ofVec3f slice = direction / divisionFactor;

    /* draw vertical lines */
    /* `t` is a traverse vector, that points along previously defined direction vector
     * and allows us to specify points from which we will draw lines across the grid */
    for (ofVec3f t = botLeft; t != botRight + slice; t += slice) {
        ofVec3f drawDirection = topRight - botRight;
        ofVec3f drawPoint = t + drawDirection;
        ofLine(t.x, t.y, t.z, drawPoint.x, drawPoint.y, drawPoint.z);
    }

    /* direction vector pointing `up` from botLeft */
    direction = (botLeft + (topRight - botRight)) - botLeft;
    slice = direction / divisionFactor;

    /* draw horizontal lines */
    for (ofVec3f t = botLeft; t != (botLeft + direction) + slice; t += slice) {
        ofVec3f drawDirection = botRight - botLeft;
        ofVec3f drawPoint = t + drawDirection;
        ofLine(t.x, t.y, t.z, drawPoint.x, drawPoint.y, drawPoint.z);
    }
}

void GridBox::draw()
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
