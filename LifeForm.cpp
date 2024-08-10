#include "LifeForm.h"

// Constructors
LifeForm::LifeForm() {
    LF_posX = 0; 
    LF_posY = 0; 
    LF_isAlive = false; 
}

LifeForm::LifeForm(int x, int y, bool alive){
    LF_posX = x; 
    LF_posY = y; 
    LF_isAlive = alive; 
}

// Destructor
LifeForm::~LifeForm() {

}

// Getters
int LifeForm::getPosX() {
    return LF_posX; 
}

int LifeForm::getPosY() {
    return LF_posY;
}

bool LifeForm::getIsAlive() {
    return LF_isAlive;
}

bool LifeForm::getIsDying(){
    return LF_isDying; 
}

int LifeForm::getLivingNeighbours(){
    return LF_livingNeighbours; 
}


// Setters
void LifeForm::setPosX(int x) {
    LF_posX = x; 
}

void LifeForm::setPosY(int y) {
    LF_posY = y; 
}

void LifeForm::setIsAlive(bool alive) {
    LF_isAlive = alive; 
}

void LifeForm::setisDying(bool dying) {
    LF_isDying = dying; 
}

void LifeForm::setLivingNeighbours(int livingNeighbours) {
    LF_livingNeighbours = livingNeighbours; 
}