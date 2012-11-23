#ifndef __TWODSTRUCT_H__
#define __TWODSTRUCT_H__
class TwoDStruct{
  private:
    float scale;
    float rot;
    float tranX;
    float tranY;
  public:
    TwoDStruct(float s, float r, float tX, float tY);
    ~TwoDStruct();
    float getScale();
    float getRotate();
    float getTranX();
    float getTranY();
};
#endif
