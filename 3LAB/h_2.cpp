#include <iostream>
using namespace std;

int main(){
    int n, m, mist, size = 0, cnt = 0, cnt1 = 0;
    int ar_block[n];
    cin >> n >> m;
    for (int i =0; i< n; i++){
        cin >> ar_block[i];
        size += ar_block[i];
    }



    
    for (int i =0; i< m; i++){
        cin >> mist;
        for (int j = 1; j < size+1; j++){
            
            if(cnt == ar_block[cnt1]){
                cnt = 0;
                cnt1++;
            }
            if(j == mist){
                cout <<cnt1+1 << endl;
                cnt = 0; cnt1 = 0;
                break;
            }
            else cnt++;
        }

    }
    return 0;
}