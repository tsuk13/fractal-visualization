#ifndef __THREEDSTRUCT_H__
#define __THREEDSTRUCT_H__
class ThreeDStruct{
  private:
    float scaleX;
    float scaleY;
    float scaleZ;
    float rotX;
    float rotY;
    float rotZ;
    float tranX;
    float tranY;
    float tranZ;
  public:
    ThreeDStruct(float sX, float sY, float sZ,  float rX, float rY, float rZ, float tX, float tY, float tZ);
    ~ThreeDStruct();
    float getScaleX();
    float getScaleY();
    float getScaleZ();
    float getRotateX();
    float getRotateY();
    float getRotateZ();
    float getTranX();
    float getTranY();
    float getTranZ();
};
#endif
