#include <iostream>

using namespace std;

class mymatrix
{
     public:
     int **Matrix;
     int len;
     mymatrix(int lengthOfMatrix)
     {

         len=lengthOfMatrix;
         int **Matrix = new int*[lengthOfMatrix];
         for(int i = 0; i<lengthOfMatrix;i++)
        {
                Matrix[i] = new int[lengthOfMatrix+1];
                for(int k = 0; k < lengthOfMatrix+1; k++){
                    Matrix[i][k] = rand() % 10;
                }
        }
     }
     ~mymatrix()
     {
         for(int i = 0; i < len;i++)
        {
                delete [](Matrix[i]);
        }
        delete [](Matrix);
     }
     void solu()
     {
            float det[len + 1];
            for(int i = 0; i < len + 1; i++){
                det[i] = 0;
            }
            int k = 0;
            int pro = 1;


            for(int i = 0; i < len; i++){
                for(int m = 0; m < len; m++)
                {
                    pro *= Matrix[m][k];
                    if(k == len - 1)
                        k = 0;
                    k++;
                }
                det[0] += pro;
                pro = 1;
                k = i + 1;

            }
            cout<<2;


            for(int i = 0; i < len; i++){
                for(int m = 0; m<len; m++)
                {
                    pro *= Matrix[m][k];
                    if(k == 0)
                        k = len - 1;
                    k--;
                }
                det[0] -= pro;
                pro = 1;
                k = i+1;
            }
            if(det[0] == 0){
                cout <<"det = 0";
            }



            for(int s=0; s<len-1;s++){
                int k = 0;
                int pro = 1;


                for(int i = 0; i < len; i++){
                    for(int m = 0; m<len; m++)
                    {
                        if(s == k)
                            pro *= Matrix[m][len];
                        else
                            pro *= Matrix[m][k];
                        if(k == len - 1)
                            k = 0;
                        k++;
                    }
                    det[s+1] += pro;
                    pro = 1;
                    k = i+1;
                }


                for(int i = 0; i < len; i++){
                    for(int m = 0; m<len; m++)
                    {
                        if(s == k)
                            pro *= Matrix[m][len];
                        else
                            pro *= Matrix[m][k];
                        if(k == 0)
                            k = len - 1;
                        k--;
                    }
                    det[s+1] -= pro;
                    pro = 1;
                    k = i+1;
                }
                float e = (det[s+1])/det[0];
                cout <<e<<endl;
            }


     }

};

int main()
{
    mymatrix x(4);
    x.solu();
    return 0;
}
