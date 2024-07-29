#include "LifeForm.h"

LifeForm::LifeForm(int x, int y, bool alive){
    posX = x; 
    posY = y; 
    isAlive = alive; 
}

LifeForm::~LifeForm() {

}

int LifeForm::getPosX() {
    return posX; 
}

int LifeForm::getPosY() {
    return posY;
}

bool LifeForm::getIsAlive() {
    return isAlive;
}

void LifeForm::setPosX(int x) {
    posX = x; 
}

void LifeForm::setPosY(int y) {
    posY = y; 
}

void LifeForm::setIsAlive(bool alive) {
    isAlive = alive; 
}

