#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define USAGE "USAGE: ./pi.x n_points"
#define PI 3.141592

int main (int argc, char **argv){
  int n;
  int i;
  double count=0;
  int seed;
  double integral=0;
  double *x;
  double *y;
  double *z;
  int xmax=1;
  int ymax=1;
  int zmax=1;
  int xmin=-1;
  int ymin=-1;
  int zmin=0;
  int vol =0;

  vol=(xmax-xmin)*(ymax-ymin)*(zmax-zmin);
  n=atoi(argv[1]);
  seed=atoi(argv[2]);
  srand48(seed);

  x=malloc(n*sizeof(double));
  y=malloc(n*sizeof(double));
  z=malloc(n*sizeof(double));

  for (i=0; i<n;i++){    
    x[i]=drand48()*(xmax-xmin)+xmin;
    y[i]=drand48()*(ymax-ymin)+ymin;
    z[i]=drand48()*(zmax-zmin)+zmin;
    if(sqrt(pow(x[i],2)+pow(y[i],2))<=1 && (z-zmin)>=0){
      count=count+1;     
    }
  }
    printf("Puntos: %d\tInside: %f\n", n, count);

  if(!(x=malloc(n*sizeof(float)))){
    printf("Problem whit data allocation\n");
    exit(1);
    }
  integral= (count/n)*vol;
  printf("Resultado: %f\n", integral);

  return 0;
}
