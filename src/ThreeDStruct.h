#ifndef __THREEDSTRUCT_H__
#define __THREEDSTRUCT_H__
class ThreeDStruct{
  private:
    float scale;
    float rot;
    float tranX;
    float tranY;
  public:
    ThreeDStruct(float s, float r, float tX, float tY);
    ~ThreeDStruct();
    float getScale();
    float getRotate();
    float getTranX();
    float getTranY();
};
#endif
