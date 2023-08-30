#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <math.h>
using namespace std;

struct gb{
    vector <int> vc;
    int pr; //ценность
    };
int main(){
    ifstream data("ks_100_0");
    int N, V;
    data >> N;
    data >> V;
    int* disk= new int[N];
    int** mm = new int *[N]; 
    for (int i=0; i < N; i++)
        mm[i] = new int [2];

    for(int i = 0; i<N;i++){
        data>>mm[i][0];
        data>>mm[i][1];
    }
    data.close();

    gb** kp = new  gb *[N]; 
    for (int i=0; i < N; i++){
        kp[i] = new gb [V];
    }

    for(int i = 0; i<V;i++){
        if(i+1 >= mm[0][1]){
                kp[0][i].pr = mm[0][0];
                kp[0][i].vc.push_back(1);
            }
        else {
            kp[0][i].pr=0;
            kp[0][i].vc.push_back(0);
            }
    }

    for(int i = 1; i<N;i++){
        for(int j = 0; j<V;j++){
            if(j >= mm[i][1]){
                kp[i][j].pr = max(kp[i-1][j].pr, mm[i][0] + kp[i-1][j-mm[i][1]].pr);

                if(kp[i][j].pr == kp[i-1][j].pr ){
                    for(int k = 0; k < kp[i-1][j].vc.size(); k++){
                    kp[i][j].vc.push_back(kp[i-1][j].vc[k]);}
                }
                else {
                for(int k = 0; k<kp[i-1][j-mm[i][1]].vc.size();k++){ kp[i][j].vc.push_back(kp[i-1][j-mm[i][1]].vc[k]);
                }
                kp[i][j].vc.push_back(i+1);
                }
            }
            else { kp[i][j].pr = kp[i-1][j].pr;
            for(int k = 0; k< kp[i-1][j].vc.size(); k++){
                    kp[i][j].vc.push_back(kp[i-1][j].vc[k]);}
            }
            
        }
    }

cout<<kp[N-1][V-1].pr<<endl;
for(int k = 0; k < kp[N-1][V-1].vc.size(); k++) 
cout<<kp[N-1][V-1].vc[k]<<" ";

} 