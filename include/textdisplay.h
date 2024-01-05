#include <vector>

#include "coor.h"
#include "view.h"
class TextDisplay : public Display {
  char board[8][8];
  
  void notifyAdd(Coor, char) override;
  void notifyRemove(Coor) override;
  void notifyMove(Coor, Coor) override;

 public:
  void show() override;
};