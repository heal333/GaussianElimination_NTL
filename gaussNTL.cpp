#include <NTL/mat_ZZ_p.h>
#include <iostream>
#include <chrono>

using namespace NTL;
using namespace std;

int main(){
  ZZ q = conv<ZZ>("2");
  ZZ_p::init(q);
  mat_ZZ_p M;
  long size;
  
  
  cout<<"enter the size of the matrix: ";
  cin>>size;
  random(M,size,size);
  //cout<<"enter the matrix in [[a b][c d]] form(any dimensions): ";
  //cin>>M;
  cout<<"given matrix: "<<endl<<M<<endl;
  
  
  auto start=chrono::high_resolution_clock::now();
  gauss(M);
  auto end = chrono::high_resolution_clock::now();

  
  auto duration= chrono::duration_cast<chrono::microseconds>(end-start);
  cout<<"row echelon form using gaussian elimination"<<endl<<M;
  cout<<"time taken: "<<duration.count()<<" microseconds";
  
  return 0;
}
  
  
