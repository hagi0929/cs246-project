#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "window.h"

class GraphicsDisplay: public Observer {
  Xwindow display;
  
 public:
  GraphicsDisplay(Xwindow &w);
  void notify(Turn &t) override;
  ~GraphicsDisplay();
};

#endif
