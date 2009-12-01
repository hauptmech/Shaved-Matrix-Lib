/*
Copyright (c) 2009, Traveler Hauptman
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY Traveler Hauptman ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#define PRACTICALLY_ZERO 1.0e-10

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

  Vect3R& operator+(Vect3R& B);
  Vect3R& operator-(Vect3R& B);
  Vect3R& operator^(Vect3R& B);
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
  Vect3& operator=(Vect3R& A);
  Vect3& operator=(Vect3& A);
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
Vect3R& operator-(Vect3& A);
Vect3R& operator-(Vect3R& A);
//Subtraction

Vect3R& operator-(Vect3& A,Vect3& B);
Vect3R& operator-(Vect3R& A,Vect3& B);
Vect3R& operator-(Vect3& B,Vect3R& A );

//Addition

Vect3R& operator+(Vect3& A,Vect3& B);
Vect3R& operator+(Vect3R& A,Vect3& B);
Vect3R& operator+(Vect3& B,Vect3R& A );
//Unit
Vect3R& operator!(Vect3& A);
Vect3R& operator!(Vect3R& A);
//Norm
double operator~(Vect3& A);
double operator~(Vect3R& A);
//Dot product
double operator*(Vect3& A,Vect3& B);
double operator*(Vect3& A,Vect3R& B);
double operator*(Vect3R& B,Vect3& A);
double operator*(Vect3R& A,Vect3R& B);
//Scalar product
Vect3R& operator*(double B,Vect3R& A);
Vect3R& operator*(Vect3R& A,double B);
Vect3R& operator*(double B,Vect3& A);
Vect3R& operator*(Vect3& A,double B);
//Cross Product

Vect3R& operator^(Vect3& A,Vect3& B);
Vect3R& operator^(Vect3R& A,Vect3& B);
Vect3R& operator^(Vect3& B,Vect3R& A );


