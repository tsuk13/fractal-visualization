#include "ThreeDStruct.h"

ThreeDStruct::ThreeDStruct(float sX, float sY, float sZ,  float rX, float rY, float rZ, float tX, float tY, float tZ){
  scaleX = sX;
  scaleY = sY;
  scaleZ = sZ;
  rotX = rX;
  rotY = rY;
  rotZ = rZ;
  tranX = tX;
  tranY = tY;
  tranZ = tZ;
}

ThreeDStruct::~ThreeDStruct(){
}

float ThreeDStruct::getScaleX(){
  return scaleX;
}

float ThreeDStruct::getScaleY(){
  return scaleY;
}

float ThreeDStruct::getScaleZ(){
  return scaleZ;
}

float ThreeDStruct::getRotateX(){
  return rotX;
}

float ThreeDStruct::getRotateY(){
  return rotY;
}

float ThreeDStruct::getRotateZ(){
  return rotZ;
}

float ThreeDStruct::getTranX(){
  return tranX;
}

float ThreeDStruct::getTranY(){
  return tranY;
}

float ThreeDStruct::getTranZ(){
  return tranY;
}
