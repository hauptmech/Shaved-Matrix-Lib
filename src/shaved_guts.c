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

/*Matrix computations.

 Assume that dest point to either src or a,b
 Use temporary variables!
*/

void cpy_v3(double *dest, double *src)
{
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
} 
void add_v3(double* dest,double *a,double* b)
{
  dest[0] = a[0]+b[0];
  dest[1] = a[1]+b[1];
  dest[2] = a[2]+b[2];
}
void sub_v3(double* dest,double *a,double* b)
{
  dest[0] = a[0]-b[0];
  dest[1] = a[1]-b[1];
  dest[2] = a[2]-b[2];
}
double dot_v3(double* a,double* b)
{
  return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}
void cross_v3(double* dest,double *a,double* b)
{
  double T[3];
  T[0] = a[1]*b[2]-a[2]*b[1];
  T[1] = a[2]*b[0]-a[0]*b[2];
  T[2] = a[0]*b[1]-a[1]*b[0];
  dest[0] = T[0];
  dest[1] = T[1];
  dest[2] = T[2];
}
double norm_v3(double* a)
{
  return sqrt(a[0]*a[0]+a[1]*a[1]+a[2]*a[2]);
}
void unit_v3(double* dest,double *a)
{
  double div;
  div = norm_v3(a);
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
void scale_v3(double *dest, double *a,double s)
{
  dest[0] = s*a[0];
  dest[1] = s*a[1];
  dest[2] = s*a[2];
}
void neg_v3(double *dest, double *a)
{
  dest[0] = -a[0];
  dest[1] = -a[1];
  dest[2] = -a[2];
}


void cpy_vn(double *dest, double *src,int n)
{
   int cnt;
   
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = src[cnt];
} 
void add_vn(double* dest, double *a, double* b, int n)
{
   int cnt;
   
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = a[cnt]+b[cnt];
    
}
void sub_vn(double* dest,double *a,double* b, int n)
{
   int cnt;
   
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = a[cnt]-b[cnt];
    
}
double dot_vn(double* a,double* b, int n)
{
  int acc = 0;
  int cnt;
   
  for (cnt=0;cnt < n;cnt++)
    acc += a[cnt]*b[cnt];
    
  return acc;
}

double norm_vn(double* a, int n)
{
  return sqrt(dot_vn(a,a,n));
}
void unit_vn(double* dest,double *a, int n)
{
  double div;
  int cnt;
  div = norm_vn(a,n);
  
  if (!(div <= PRACTICALLY_ZERO)){
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = a[cnt]/div;
    
  } else {
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = 0;
  }
}
void scale_vn(double *dest, double *a,double s, int n)
{
   int cnt;
   
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = a[cnt]*s;
    
}
void neg_vn(double *dest, double *a, int n)
{
   int cnt;
   
   for (cnt=0;cnt < n;cnt++)
      dest[cnt] = -a[cnt];
    
}
/* */
void cpy_mh(double *dest, double *src)
{
  dest[0] = src[0];
  dest[1] = src[1];
  dest[2] = src[2];
  dest[3] = src[3];
  dest[4] = src[4];
  dest[5] = src[5];
  dest[6] = src[6];
  dest[7] = src[7];
  dest[8] = src[8];
  dest[9] = src[9];
  dest[10] = src[10];
  dest[11] = src[11];
}

void mul_mh(double *dest, double *a, double *b)
{
  double ret[12];
  
  ret[0] = a[0]*b[0] + a[1]*b[4] + a[2]*b[8];
  ret[4] = a[4]*b[0] + a[5]*b[4] + a[6]*b[8];
  ret[8] = a[8]*b[0] + a[9]*b[4] + a[10]*b[8];
  
  
  ret[1] = a[0]*b[1] + a[1]*b[5] + a[2]*b[9];
  ret[5] = a[4]*b[1] + a[5]*b[5] + a[6]*b[9];
  ret[9] = a[8]*b[1] + a[9]*b[5] + a[10]*b[9];
  
  ret[2] = a[0]*b[2] + a[1]*b[6] + a[2]*b[10];
  ret[6] = a[4]*b[2] + a[5]*b[6] + a[6]*b[10];
  ret[10] = a[8]*b[2] + a[9]*b[6] + a[10]*b[10];
  
  ret[3] = a[0]*b[3] + a[1]*b[7] + a[2]*b[11] + a[3];
  ret[3] = a[0]*b[3] + a[1]*b[7] + a[2]*b[11] + a[3];
  ret[3] = a[0]*b[3] + a[1]*b[7] + a[2]*b[11] + a[3];
  ret[3] = a[0]*b[3] + a[1]*b[7] + a[2]*b[11] + a[3];
  
  dest[0] = ret[0];
  dest[1] = ret[1];
  dest[2] = ret[2];
  dest[3] = ret[3];
  dest[4] = ret[4];
  dest[5] = ret[5];
  dest[6] = ret[6];
  dest[7] = ret[7];
  dest[8] = ret[8];
  dest[9] = ret[9];
  dest[10] = ret[10];
  dest[11] = ret[11];
}
/* 4x4 SE(3) (_mh) times 4x1 vector (_v3)*/
void matXvec_mh(double *dest, double *a, double *b)
{
  double ret[3];
  
  ret[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3];
  ret[1] = a[4]*b[0] + a[5]*b[1] + a[6]*b[2] + a[7];
  ret[2] = a[8]*b[0] + a[9]*b[1] + a[10]*b[2] + a[11];
  
  dest[0] = ret[0];
  dest[1] = ret[1];
  dest[2] = ret[2];
}
