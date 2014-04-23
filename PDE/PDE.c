#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (){
  int i;
  int n_points=1000;
  float dx, dt;
  float *x, *initial;
  FILE *in;

  in = fopen("data.dat","w");

  x = malloc(n_points*sizeof(float));
  initial = malloc(n_points*sizeof(float));
  
  for (i=0;i<n_points+1;i++){
    x[i]=(float)i/(n_points);
  }
  for (i=0;i<n_points+1;i++){
    initial[i] = exp(-1*pow(((float)i/(n_points)-0.3),2)/0.01);
  }
  for(i=0;i<n_points+1;i++){

    fprintf(in,"%f\n", initial[i]);
  }
  fclose(in);

  return 0;
}
