// catmull.h: interface for the catmull class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CATMULL_H__27EEFB10_E01C_4540_94B1_94F9D5CFC5DC__INCLUDED_)
#define AFX_CATMULL_H__27EEFB10_E01C_4540_94B1_94F9D5CFC5DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "foundation.h"
#include "stuff.h"


#define MAXP 1000
#define RADIUS 8
#define numStepsMax 100000

class catmull  
{
public:
	catmull();
    enum Mode{XY, XZ, ZY};
	virtual ~catmull();
    void mouseReleaseEvent();
    void mouseMoveEvent   (int x, int y, int z , Mode window);
    void mousePressEvent  (int x, int y, int z, int button , Mode window);
	void draw();

    void setxoff(int i){xoff=i;}
    void setyoff(int i){yoff=i;}
    void clear(){lastpt=0;}
    void setHull(bool b){hull=b;}
    void animate();
	void setSpeed(int v){
		if (v>numSteps) error=1;
		else frames=v;
    } // speed for now is no. of frames/segment

	void setSteps(int g){
		if (g<frames) {
            error=2;
		}
		else {
        numSteps=g;
		}
    }

    void showSteps(bool b){showsteps=b;}
    void setTV(int j){tvmethod=j;}
    void setArcLength(bool b){arcLengthSwitch=b; }
    void setMotionType(int j){motionType=j;}
    int pnts[MAXP][3];
    int lastpt;

    void changeLookAt();
    void tensionSlider(int tensionValueL);
    void controlPoints(bool showControlPointsL);
    void controlLines(bool showControlLinesL);
    void catmullRom(bool showCatmullRomL);

public slots:
    void genCylRadius(int tradius);
    void genCylCircComplexity(int complexity);
    void genCylSegComplexity(int complexity);
    void triangleMesh(bool enabled);
    void wireFrameCyl(bool enabled);
    void frenetFrameBoxFunc(bool enabled);
    void genCyl(bool enabled);

private:
    double arc[numStepsMax][2];  // the table holds
	int lastArc, error;
    int cpt, seg, tvmethod;

	bool mousedown, hull, animatenow, showsteps, arcLengthSwitch, makeArcMode;
    int frames,numSteps, nframe;
    int param; // t parameter
    int xoff, yoff;

    void addPoint(int x, int y, int z);
    void movePoint(int x, int y, int z, Mode window);
    int select(int x, int y, int z, Mode window);
    bool nearzero(double x);
    int motionType; // 0 = parameter value 1 = const velocity

    QVector<QVector3D> find3dCirclePoints(QVector3D norm, QVector3D biNorm, QVector3D point);
    void drawCylinder(QVector<QVector3D> lastPoints, QVector<QVector3D> currentPoints, QVector3D center);
    QVector3D vectorTransform(QVector3D v, QMatrix3x3 m);
    void drawWireFrame(QVector<QVector3D> lastPoints, QVector<QVector3D> currentPoints);
    QVector<QVector3D> findCatPoints();
    QVector< QVector<QVector3D> > findGenCylPoints(QVector<QVector3D> catPoints);
    void drawCatmull(QVector<QVector3D> catPoints);
    void drawGenCyl(QVector< QVector<QVector3D> > genCylPoints, QVector<QVector3D> catPoints);

    QTime time;
    int frenetFrameBoxIndex;
    QVector<QVector3D> frenetFrameBox;
    void drawFrenetFrameBox();
    double fbSize;

    int tensionValue;
    bool showControlPoints;
    bool showControlLines;
    bool showCatmullRom;
    bool showGeneralizedCylinder;
    bool showFrenetFrameBox;
    bool drawCylinderEnabled;
    bool drawWireFrameEnabled;
    double numCircleSegs;
    double radius;
};

#endif // !defined(AFX_CATMULL_H__27EEFB10_E01C_4540_94B1_94F9D5CFC5DC__INCLUDED_)




