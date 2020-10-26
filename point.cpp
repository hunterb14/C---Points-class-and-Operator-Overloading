#include <iostream>

using namespace std;
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <math.h>

// Hunter Blackwood
// CS 372
// Points

ofstream outf;
ifstream inf;

class point
{

    private:
        float x, y;

    public:
        point(float a = 1, float b = 2){

            x = a; y = b;
        }
    float getx();
    float gety();
    void shift(float, float);
    void rotate90();
    void translate(float, float);
    void scale(float, float);
    void rotateD(float);
    void shear(float, float);
    bool operator==(point);
    bool operator!=(point);
    point operator+(point);
    point operator-(point);
    friend ostream& operator<<(ostream&,  point);
    bool operator>(point);
    bool operator<(point);
    bool operator>=(point);


};

    int rotationsneeded(point);
    float dist(point, point);
    point middle(point, point);

int main()
{

    outf.open("results.txt");


   point p1(2, 3), p2(-3, -5), boxp1(2, 2), boxp2(2, 5), boxp3(4, 5), boxp4(4, 2), p5(4, 2), p6(-3, 4), p7;

   int answer;
   float dist1;

    outf << "Testing points class methods. " << endl << endl;

    outf << "Point1 is " << "(" << p1.getx() << ", " << p1.gety() << ")" << endl << endl;

    p1.shift(3, 2);

    outf << "Point1 becomes " << "(" << p1.getx() << ", " << p1.gety() << ")" << " after shifting x by 3 and y by 2" << endl << endl;

    p1.rotate90();

    outf << "Point1 becomes " << "(" << p1.getx() << ", " << p1.gety() << ")" << " after 1 90 degree rotation" << endl << endl;


    answer = rotationsneeded(p1);

    outf << "It would take Point 1 " << answer << " rotations to reach the upper right quadrant" << endl << endl;

    dist1 = dist(p1, p2);

    outf << "The distance between Point1 " << "(" << p1.getx() << ", " << p1.gety() << ")" << " and Point2 " << "(" << p2.getx() << ", " << p2.gety() << ")"
    " is " << dist1 << endl << endl;

    point mid = middle(p1, p2);

    outf << "The midpoint between Point1 " << "(" << p1.getx() << ", " << p1.gety() << ")" << " and Point2 " << "(" << p2.getx() << ", " << p2.gety() << ")"
    " is (" << mid.getx() << ", " << mid.gety() << ")" << endl << endl;

    outf << "---------------------------------" << endl << endl;

    outf << "Box with 4 points" << endl << endl;

    outf << "---------------------------------" << endl << endl;

    outf << "The points for the box are " << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;

    boxp1.translate(2, 1);
    boxp2.translate(2, 1);
    boxp3.translate(2, 1);
    boxp4.translate(2, 1);

    outf << "The points for the box after translating the points by 2 for x and 1 for y are " << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;

    boxp1.scale(2, 0.5);
    boxp2.scale(2, 0.5);
    boxp3.scale(2, 0.5);
    boxp4.scale(2, 0.5);

    outf << "The points for the box after scaling the points by 2 for x and 0.5 for y are " << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;


    boxp1.rotateD(30);
    boxp2.rotateD(30);
    boxp3.rotateD(30);
    boxp4.rotateD(30);

    outf << "The points for the box after rotating the points by 30 degrees" << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;

    boxp1.rotateD(60);
    boxp2.rotateD(60);
    boxp3.rotateD(60);
    boxp4.rotateD(60);

    outf << "The points for the box after rotating the points by 60 degrees" << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;

    boxp1.shear(1.5, 0);
    boxp2.shear(1.5, 0);
    boxp3.shear(1.5, 0);
    boxp4.shear(1.5, 0);

    outf << "The points for the box after shearing by 1.5 in the x direction  " << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;

    boxp1.shear(0, 1.7);
    boxp2.shear(0, 1.7);
    boxp3.shear(0, 1.7);
    boxp4.shear(0, 1.7);

    outf << "The points for the box after shearing by 1.7 in the y direction  " << "(" << boxp1.getx() << ", " << boxp1.gety() << ") "
    << "(" << boxp2.getx() << ", " << boxp2.gety() << ") "
    << "(" << boxp3.getx() << ", " << boxp3.gety() << ") "
    << "(" << boxp4.getx() << ", " << boxp4.gety() << ") " << endl << endl;


    outf << endl << endl << "-------------------------------------------------------------------" << endl;

    outf << "Beginning of testing overload methods." << endl;

    outf << "--------------------------------------------------------------------" << endl << endl;

   outf << "Testing == method" << endl;

   if(p5 == p6){

        outf << "Point p5(" << p5.getx() << ", " << p5.gety() << ") is equal to p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;;

   }else{

       outf << "Point p5(" << p5.getx() << ", " << p5.gety() << ") is not equal to p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;;

       }


    outf << endl << "Testing != method" << endl;

    if(p5 != p6){

        outf << "Point p5(" << p5.getx() << ", " << p5.gety() << ") is not equal to p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;;

   }else{

       outf << "Point p5(" << p5.getx() << ", " << p5.gety() << ") is equal to p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;;

       }

    p7 = p5 + p6;

    outf << endl << "Testing + operator method" << endl;
    outf << "Adding Point p5(" << p5.getx() << ", " << p5.gety() << ") to p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;
    outf << "The points of p7 after summing p5 and p6 is (" << p7.getx() <<", " << p7.gety() << ")" << endl;

    p7 = p5 - p6;

    outf << endl << "Testing - operator method" << endl;
    outf << "Subtracting Point p5(" << p5.getx() << ", " << p5.gety() << ") and p6(" << p6.getx() <<", " << p6.gety() << ")" << endl;
    outf << "The points of p7 after subtracting p5 and p6 is (" << p7.getx() <<", " << p7.gety() << ")" << endl;

    outf << endl << "Testing << operator method" << endl;
    outf << "Point p5 = " << p5 << endl;

    outf << endl;
    outf << "Testing > operator method for true" << endl;

    if(p6 > p5){
    outf << "Point p6 " << p6 << " is further from the origin than Point p5 " << p5 << endl;

    } else{

        outf << "Point p6 " << p6 << " is closer to the origin than Point p5 " << p5 << endl;

    }

    outf << endl;
    outf << "Testing > operator method for false" << endl;

    if(p5 > p6){
    outf << "Point p5 " << p5 << " is further from the origin than Point p6 " << p6 << endl;

    } else{

        outf << "Point p5 " << p5 << " is closer to the origin than Point p6 " << p6 << endl;

    }

    outf << endl;
    outf << "Testing < operator method for true" << endl;

    if(p5 < p6){
    outf << "Point p5 " << p5 << " is closer to the origin than Point p6 " << p6 << endl;

    } else{

        outf << "Point p5 " << p5 << " is further from the origin than Point p6 " << p6 << endl;

    }

    outf << endl;
    outf << "Testing < operator method for false" << endl;

    if(p6 < p5){
    outf << "Point p6 " << p6 << " is closer to the origin than Point p5 " << p5 << endl;

    } else{

        outf << "Point p6 " << p6 << " is further from the origin than Point p5 " << p5 << endl;

    }

    outf << endl;
    outf << "Testing >= operator method for true" << endl;

    if(p6 >= p5){
    outf << "Point p6 " << p6 << " is equal to or further from the origin than Point p5 " << p5 << endl;

    } else{

        outf << "Point p6 " << p6 << " is closer to the origin than Point p5 " << p5 << endl;

    }

    outf << endl;
    outf << "Testing >= operator method for false" << endl;

    if(p5 >= p6){
    outf << "Point p5 " << p5 << " is equal to or further from the origin than Point p6 " << p6 << endl;

    } else{

        outf << "Point p5 " << p5 << " is closer to the origin than Point p6 " << p6 << endl;

    }

}

void point::shift(float amount1, float amount2){

    x += amount1;
    y += amount2;
}

void point::rotate90(){

    float newx, newy;

    newx = y;
    newy = -x;
    x = newx;
    y = newy;

}

int rotationsneeded(point p){

    int answer;

    answer = 0;

    while(p.getx() < 0 || p.gety() < 0){

        p.rotate90();
        ++answer;
    }

    return answer;

}

float dist(point p1, point p2){

    float a, b, csquared;

    a = p1.getx() - p2.getx();
    b = p2.gety() - p2.gety();

    csquared = a*a + b*b;

    return sqrt(csquared);

}

point middle(point p1, point p2){

    float xmid, ymid;

    xmid = (p1.getx() + p2.getx()) / 2;
    ymid = (p2.gety() + p2.gety()) / 2;

    point midpoint(xmid, ymid);

    return midpoint;
}

void point::translate(float amount1, float amount2){

    x += amount1;
    y += amount2;

}

void point::scale(float amount1, float amount2){

    x *= amount1;
    y *= amount2;

}

void point::rotateD(float degrees){

     float radian;
     float nx, ny;


  radian = degrees*3.14159/180;

  nx = ((x *cos(radian)) - (y * sin(radian)));
  ny = ((x *sin(radian)) + (y * cos(radian)));

  x = nx;
  y = ny;
}

void point::shear(float xShear, float yShear){

    x = x + xShear;
    y = y + yShear;

}

float point::getx(){

    return x;
}

float point::gety(){

    return y;
}

bool point::operator==(point p){

    return(p.getx() == x && p.gety() == y);
}

bool point::operator!=(point p){

    return(p.getx() != x && p.gety() !=y);

}

point point::operator+(point p){

    float nx = x + p.getx();
    float ny = y + p.gety();

    point p7(nx, ny);

    return p7;
}

point point::operator-(point p){

    float nx = this->x - p.getx();
    float ny = this->y - p.gety();

    point p7(nx, ny);

    return p7;
}


ostream& operator<<(ostream& out,  point p){

    out << "(" << p.getx() << ", " << p.gety() << ")";

    return out;

}

bool point::operator>(point p){

      float dis1, dis2;

    dis1 = sqrt(pow(0 - x, 2)+ pow(0 - y, 2));
    dis2 = sqrt(pow(0 - p.getx(), 2)+ pow(0 - p.gety(), 2));

    return(dis1 > dis2);

}

bool point::operator<(point p){

      float dis1, dis2;

    dis1 = sqrt(pow(0 - x, 2)+ pow(0 - y, 2));
    dis2 = sqrt(pow(0 - p.getx(), 2)+ pow(0 - p.gety(), 2));

    return(dis1 < dis2);

}

bool point::operator>=(point p){

      float dis1, dis2;

    dis1 = sqrt(pow(0 - x, 2)+ pow(0 - y, 2));
    dis2 = sqrt(pow(0 - p.getx(), 2)+ pow(0 - p.gety(), 2));

    return(dis1 >= dis2);

}



