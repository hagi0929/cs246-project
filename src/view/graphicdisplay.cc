#include "graphicdisplay.h"
#include "cell.h"
#include <iostream>

using namespace std;

GraphicsDisplay::GraphicsDisplay() : view{new Xwindow{500, 500}}, WIDTH{500}, HEIGHT{500}
{
    int rows[] = {8, 7, 6, 5, 4, 3, 2, 1};
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

    // for (int r = 0; r < boardSize; r++)
    // {
    //     for (int c = 0; c < boardSize; c++)
    //     {
    //         int x = c, y = r, wh = 0;
    //         transformation(x, y, wh);
    //         view->fillRectangle(x, y, wh, wh, 0);
    //     }
    // }
    cerr << "Graphic board is created" << endl;
}

void GraphicsDisplay::transformation(int &x, int &y, int &wh)
{
    const int GRID_WIDTH_HEIGHT = 500;
    wh = GRID_WIDTH_HEIGHT / boardSize;
    x = wh * x;
    y = wh * y;
}

GraphicsDisplay::~GraphicsDisplay()
{
}

void GraphicsDisplay::notify(Cell &c)
{
    int x = c.getCol(), y = c.getRow(), wh = 0;
    // TO DO: implement code to get colour from the cell
    bool colour = true;
    transformation(x, y, wh);
    view->fillRectangle(x, y, wh, wh, colour);
}

void GraphicsDisplay::displayText(std::string text)
{
    int x = 226, y = 498;
    view->drawString(x, y, "\n");
    view->drawString(x, y, text);
}

void GraphicsDisplay::display() {}
