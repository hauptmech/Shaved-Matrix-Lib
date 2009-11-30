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

#include "math.h"

#include "shaved.h"
#include "shaved_guts.c"


Vect3R& Vect3R::operator+(Vect3R& B)
{ 
    add_v3(q,B.q,q);
    delete &B;
    return *this;
}
Vect3R& Vect3R::operator-(Vect3R& B)
{ 
    sub_v3(q,B.q,q);
    delete &B;
    return *this;
}
Vect3R& Vect3R::operator^(Vect3R& B)
{ 
    cross_v3(q,B.q,q);
    delete &B;
    return *this;
}

Vect3& Vect3::operator=(Vect3R& A){
    cpy_v3(q,A.q);
    delete &A;
    return *this;
	}
Vect3& Vect3::operator=(Vect3& A){
    cpy_v3(q,A.q);
    return *this;
}

//Unary negation
Vect3R& operator-(Vect3& A)
{
		Vect3R* ret = new Vect3R();
    neg_v3(ret->q,A.q);
    return *ret;
}
Vect3R& operator-(Vect3R& A)
{
    neg_v3(A.q,A.q);
    return A;
}
//Subtraction

Vect3R& operator-(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    sub_v3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator-(Vect3R& A,Vect3& B){
    sub_v3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator-(Vect3& B,Vect3R& A ){
    sub_v3(A.q,B.q,A.q);
    return A;
}

//Addition

Vect3R& operator+(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    add_v3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator+(Vect3R& A,Vect3& B){
    add_v3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator+(Vect3& B,Vect3R& A ){
    add_v3(A.q,B.q,A.q);
    return A;
}
//Unit
Vect3R& operator!(Vect3& A)
{
	Vect3R* ret = new Vect3R();
  unit_v3(ret->q,A.q);
  return *ret;
}
Vect3R& operator!(Vect3R& A)
{
  unit_v3(A.q,A.q);
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
  ret =  dot_v3(A.q,B.q);
  delete &B;
  return ret;
}
double operator*(Vect3R& B,Vect3& A)
{
  double ret;
  ret =  dot_v3(A.q,B.q);
  delete &B;
  return ret;
}
double operator*(Vect3& A,Vect3& B)
{
  return dot_v3(A.q,B.q);
}
double operator*(Vect3R& A,Vect3R& B)
{
  double ret;
  ret =  dot_v3(A.q,B.q);
  delete &B;
  delete &A;
  return ret;
}
//Scalar product
Vect3R& operator*(double B,Vect3R& A)
{
  scale_v3(A.q,A.q,B);
  return A;
}
Vect3R& operator*(Vect3R& A,double B)
{
  scale_v3(A.q,A.q,B);
  return A;
}
Vect3R& operator*(double B,Vect3& A)
{
	Vect3R* ret = new Vect3R();
  scale_v3(ret->q,A.q,B);
  return *ret;
}
Vect3R& operator*(Vect3& A,double B)
{
	Vect3R* ret = new Vect3R();
  scale_v3(ret->q,A.q,B);
  return *ret;
}
//Cross Product

Vect3R& operator^(Vect3& A,Vect3& B){
		Vect3R* ret = new Vect3R();
    cross_v3(ret->q,B.q,A.q);
    return *ret;
}
Vect3R& operator^(Vect3R& A,Vect3& B){
    cross_v3(A.q,B.q,A.q);
    return A;
}
Vect3R& operator^(Vect3& B,Vect3R& A ){
    cross_v3(A.q,B.q,A.q);
    return A;
}

/*
Vect3::Vect3(int a)
{ n = a;}
*/
