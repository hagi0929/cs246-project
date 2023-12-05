#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include "window.h"
#include "observer.h"
#include "display.h"

class Cell;

class GraphicsDisplay : public View
{
    Xwindow *view;
    const int WIDTH, HEIGHT;

    void transformation(int &x, int &y, int &wh);

public:
    GraphicsDisplay();
    ~GraphicsDisplay();
    void display() override;
    void notify(Cell &c) override;
    void displayText(std::string text);
};

#endif
