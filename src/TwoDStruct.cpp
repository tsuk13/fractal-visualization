#include "TwoDStruct.h"

TwoDStruct::TwoDStruct(double s, double r, double tX, double tY){
  scale = s;
  rot = r;
  tranX = tX;
  tranY = tY;
}

TwoDStruct::~TwoDStruct(){
}

double TwoDStruct::getScale(){
  return scale;
}

double TwoDStruct::getRotate(){
  return rot;
}

double TwoDStruct::getTranX(){
  return tranX;
}

double TwoDStruct::getTranY(){
  return tranY;
}
