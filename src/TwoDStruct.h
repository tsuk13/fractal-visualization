#ifndef __TWODSTRUCT_H__
#define __TWODSTRUCT_H__
class TwoDStruct{
  private:
    double scale;
    double rot;
    double tranX;
    double tranY;
  public:
    TwoDStruct(double s, double r, double tX, double tY);
    ~TwoDStruct();
    double getScale();
    double getRotate();
    double getTranX();
    double getTranY();
};
#endif
