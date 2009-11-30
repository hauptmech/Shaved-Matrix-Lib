/*
  The start of a matrix library after I spent yet another day looking for an existing one.
  I looked at blitz++ and tvmet

  This library creates two types, a user type and a temporary type. Infix operations create temporary types.

  The idea is to recreate the fuctionality of btmath and then write a btrobot on top.

*/


#include "math.h"

#define PRACTICALLY_ZERO 1.0e-10
void add3(double* dest,double *a,double* b)
{
  dest[0] = a[0]+b[0];
  dest[1] = a[1]+b[1];
  dest[2] = a[2]+b[2];
}
void sub3(double* dest,double *a,double* b)
{
  dest[0] = a[0]-b[0];
  dest[1] = a[1]-b[1];
  dest[2] = a[2]-b[2];
}
double dot3(double* a,double* b)
{
  return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}
void cross3(double* dest,double *a,double* b)
{
  double T[3];
  T[0] = a[1]*b[2]-a[2]*b[1];
  T[1] = a[2]*b[0]-a[0]*b[2];
  T[2] = a[0]*b[1]-a[1]*b[0];
  dest[0] = T[0];
  dest[1] = T[1];
  dest[2] = T[2];
}
void unit3(double* dest,double *a)
{
  double div;
  div = sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
  if (!(div <= PRACTICALLY_ZERO)){
		dest[0] = a[0]/div;
  	dest[1] = a[1]/div;
		dest[2] = a[2]/div; 
  } else {
    dest[0] = 0.0;
    dest[1] = 0.0;
    dest[2] = 0.0;
  }
}
void scale3(double *dest, double *a,double s)
{
  dest[0] = s*a[0];
  dest[1] = s*a[1];
  dest[2] = s*a[2];
}
void neg3(double *dest, double *a)
{
  dest[0] = -a[0];
  dest[1] = -a[1];
  dest[2] = -a[2];
}
void cpy3(double *dest, double *src)
{
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
} 


struct Vect3R {
  int n;
  double *q;
  double data[3];
  
  Vect3R(){
    init();
  }

  Vect3R(double x,double y,double z)
	{
		init();
    q[0] = x; q[1] = y; q[2] = z;
	}
  void init(){q = data; n=3;}
  void set(double x, double y, double z)
  {
    q[0] = x; q[1] = y; q[2] = z;
  }

  Vect3R& operator+(Vect3R& B)
  { 
    add3(q,B.q,q);
    delete &B;
    return *this;
  }
  Vect3R& operator-(Vect3R& B)
  { 
    sub3(q,B.q,q);
    delete &B;
    return *this;
  }
  Vect3R& operator^(Vect3R& B)
  { 
    cross3(q,B.q,q);
    delete &B;
    return *this;
  }
  double& operator[](int idx){return q[idx];} 

};


struct Vect3 {
  int n;
  double *q;
  double data[3];

  Vect3(){
    init();
  }
  Vect3(double x,double y,double z)
	{
		init();
    set(x,y,z);
	}
  void init(){q = data; n=3;}
  void set(double x, double y, double z)
  {
    q[0] = x; q[1] = y; q[2] = z;
  }
  Vect3& operator=(Vect3R& A){
    cpy3(q,A.q);
    delete &A;
    return *this;
	}
  Vect3& operator=(Vect3& A){
    cpy3(q,A.q);
    return *this;
	}
  //fill
  Vect3& operator=(double& A){
    q[0] = A;
    q[1] = A; 
    q[2] = A;
    return *this;
	}
  double& operator[](int idx){return q[idx];} 
   
  		
		
};
//Unary negation
Vect3R& operator-(Vect3& A)
{
		Vect3R* ret = new Vect3R();
    neg3(ret->q,A.q);
    return *ret;
}
Vect3R& operator-(Vect3R& A)
{
    neg3(A.q,A.q);
    return A;
}
//Subtraction

Vect3R& operator-(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    sub3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator-(Vect3R& A,Vect3& B){
    sub3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator-(Vect3& B,Vect3R& A ){
    sub3(A.q,B.q,A.q);
    return A;
}

//Addition

Vect3R& operator+(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    add3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator+(Vect3R& A,Vect3& B){
    add3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator+(Vect3& B,Vect3R& A ){
    add3(A.q,B.q,A.q);
    return A;
}
//Unit
Vect3R& operator!(Vect3& A)
{
	Vect3R* ret = new Vect3R();
  unit3(ret->q,A.q);
  return *ret;
}
Vect3R& operator!(Vect3R& A)
{
  unit3(A.q,A.q);
  return A;
}

//Norm
double operator~(Vect3& A)
{
  double* q = A.q;
  return sqrt(q[0]*q[0]+q[1]*q[1]+q[2]*q[2]);
}
double operator~(Vect3R& A)
{
  double* q = A.q;
  double ret =  sqrt(q[0]*q[0]+q[1]*q[1]+q[2]*q[2]);
  delete &A;
  return ret;
}
//Dot product
double operator*(Vect3& A,Vect3R& B)
{
  double ret;
  ret =  dot3(A.q,B.q);
  delete &B;
  return ret;
}
double operator*(Vect3R& B,Vect3& A)
{
  double ret;
  ret =  dot3(A.q,B.q);
  delete &B;
  return ret;
}
double operator*(Vect3& A,Vect3& B)
{
  return dot3(A.q,B.q);
}
double operator*(Vect3R& A,Vect3R& B)
{
  double ret;
  ret =  dot3(A.q,B.q);
  delete &B;
  delete &A;
  return ret;
}
//Scalar product
Vect3R& operator*(double B,Vect3R& A)
{
  scale3(A.q,A.q,B);
  return A;
}
Vect3R& operator*(Vect3R& A,double B)
{
  scale3(A.q,A.q,B);
  return A;
}
Vect3R& operator*(double B,Vect3& A)
{
	Vect3R* ret = new Vect3R();
  scale3(ret->q,A.q,B);
  return *ret;
}
Vect3R& operator*(Vect3& A,double B)
{
	Vect3R* ret = new Vect3R();
  scale3(ret->q,A.q,B);
  return *ret;
}
//Cross Product

Vect3R& operator^(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    cross3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator^(Vect3R& A,Vect3& B){
    cross3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator^(Vect3& B,Vect3R& A ){
    cross3(A.q,B.q,A.q);
    return A;
}

/*
Vect3::Vect3(int a)
{ n = a;}
*/
