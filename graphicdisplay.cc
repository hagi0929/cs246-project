#include "graphicsdisplay.h"
#include "cell.h"
#include <iostream>

using namespace std;

GraphicsDisplay::GraphicsDisplay() : view{new Xwindow{500, 500}}, WIDTH{500}, HEIGHT{500}
{
    int tiles[2][2] = {
        {1, 0}, // tiles for even rows
        {0, 1}  // tiles for odd rows
    };

    for (int r = 0; r < boardSize; r++)
    {
        for (int c = 0; c < boardSize; c++)
        {
            int x = c, y = r, wh = 0;
            int i = r % 2, j = c % 2;
            transformation(x, y, wh);
            view->fillRectangle(x, y, wh, wh, tiles[i][j]);
        }
    }

    cerr << "Graphic board is created" << endl;
}

void GraphicsDisplay::transformation(int &x, int &y, int &wh)
{
    const int GRID_WIDTH_HEIGHT = 500;
    wh = GRID_WIDTH_HEIGHT / boardSize;
    x = wh * x;
    y = wh * y;
}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::notify(Cell &c)
{
    int x = c.getCol(), y = c.getRow(), wh = 0;
    if (c.isEmpty()) {
        int tiles[2][2] = {
            {1, 0}, // tiles for even rows
            {0, 1}  // tiles for odd rows
        };
        int i = y % 2, j = x % 2;
        transformation(x, y, wh);
        view->fillRectangle(x, y, wh, wh, tiles[i][j]);
    } else {
        transformation(x, y, wh);
        int pieceColor = c.getPiece()->getPlayer();
        int backgroundWh = wh * 3/4;
        int backgroundX = x + 3 + backgroundWh/8;
        int backgroundY = y + 3 + backgroundWh/8;
        view->fillGreyCircle(backgroundX, backgroundY, backgroundWh, backgroundWh);
        int pieceX = x + 2 + 4 * backgroundWh/8;
        int pieceY = y + 2 + 6 * backgroundWh/8;
        char pieceType = c.getPiece()->getType();
        string pieceString(1, pieceType);
        view->drawString(pieceX, pieceY, pieceString, pieceColor);
    }
}

void GraphicsDisplay::display() {}
