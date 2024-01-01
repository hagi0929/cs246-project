#include "player.h"

void Player::addScore(int changes) { score += changes; }
int Player::getScore() const { return score; }
void Player::setScore(int score) { score = score; }
