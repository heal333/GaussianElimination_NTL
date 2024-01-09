#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <chrono>

using namespace NTL;
using namespace std;

int main(){
  ZZ q = conv<ZZ>("2");
  ZZ_p::init(q);
  ZZ_p d;
  long size;
  mat_ZZ_p M;
  vec_ZZ_p b;
  vec_ZZ_p x;

  
  cout<<"enter the size: ";
  cin>>size;
  //cout<<"enter the matrix in [[a b][c d]] form(any dimensions): ";
  //cin>>M;
  random(M,size,size);
  //cout<<"enter the vector: ";
  //cin>>b;
  random(b,size);
  
  cout<<"given matrix: "<<endl<<M<<endl;
  cout<<"given vector: "<<b<<endl<<endl;

  
  auto start = chrono::high_resolution_clock::now();
  solve(d,M,x,b);
  auto end = chrono::high_resolution_clock::now();

  
  auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
  cout<<"the solution will be: "<<x;
  cout<<endl<<"time taken: "<<duration.count()<<" microseconds";
  
  return 0;
}
