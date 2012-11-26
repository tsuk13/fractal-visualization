#include "ThreeDStruct.h"

ThreeDStruct::ThreeDStruct(float s, float r, float tX, float tY){
  scale = s;
  rot = r;
  tranX = tX;
  tranY = tY;
}

ThreeDStruct::~ThreeDStruct(){
}

float ThreeDStruct::getScale(){
  return scale;
}

float ThreeDStruct::getRotate(){
  return rot;
}

float ThreeDStruct::getTranX(){
  return tranX;
}

float ThreeDStruct::getTranY(){
  return tranY;
}
