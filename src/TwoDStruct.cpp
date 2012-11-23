#include "TwoDStruct.h"

TwoDStruct::TwoDStruct(float s, float r, float tX, float tY){
  scale = s;
  rot = r;
  tranX = tX;
  tranY = tY;
}

TwoDStruct::~TwoDStruct(){
}

float TwoDStruct::getScale(){
  return scale;
}

float TwoDStruct::getRotate(){
  return rot;
}

float TwoDStruct::getTranX(){
  return tranX;
}

float TwoDStruct::getTranY(){
  return tranY;
}
