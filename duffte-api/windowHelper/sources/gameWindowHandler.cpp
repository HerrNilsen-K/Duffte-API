#include "gameWindowHandler.h"

gameWindow::gameWindow(argPTR arg, int width, int height){
    functionID = arg;
}

gameWindow::~gameWindow(){

}

bool gameWindow::startRenderLoop(){
    while(windowOBJ.runs()){
        functionID();
    }
    return true;
}