/*
 * > File Name: dehui27.cpp
 * > Author: Jack Kang
 * > Mail: kangyijie@xiyoulinux.org
 * > Created Time: 2017年05月26日 星期五 08时35分17秒
 */

#include <iostream>
using namespace std;
const double PI=3.1415926;
class Circle{
protected:
   double radius;
public: 
   Circle(double r){
      radius=r;
   }
   double getArea(){
      return PI*radius*radius;
   }
};
// 你提交的代码将嵌入在这里
class Cylinder :public Circle{
         double height;             
public:
        Circle(double r) : radius(r) {}
        Cylinder(double r,double h) : height(h),radius(r) {}
        double radius;
        double  getArea(){
                  return PI*radius*radius*height;
}
};

int main() 
{
   double r,h;
   cin>>r>>h;
   Cylinder Cy1(r,h) ;
   cout<<Cy1.getArea()<<endl;
   return 0;
}
