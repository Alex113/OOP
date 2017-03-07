#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

 const double eps=10E-10;



int _tmain()
{
    ifstream fin_Matr("Text1.txt");
    ifstream fin_B("vector_B.txt");
     int N;
      fin_Matr>>N;

      double* B = new double[N];//стобец свободных членов
      double** A = new double*[N];//матрица исходная
       for(int i=0;i<N;i++)
        A[i] = new double[N];

      double** E = new double*[N];//еденичная матрица
       for(int i=0;i<N;i++)
        E[i] = new double[N];

       for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)//заполнение еденичной матрицы
         {
          if(i==j)
            E[i][j]=1;
          else
            E[i][j]=0;
         }

       for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
         fin_Matr>>A[i][j];//считаем матрицу из файла в массив

       for(int i=0;i<N;i++)
        fin_B>>B[i];//считаем матрицу из файла в массив

 

    fin_B.close();
    fin_Matr.close();

    double t1;
    double tA2;

      for(int i=0;i<N;i++)
        {
          for(int j=i;j<N;j++)
          {
            if(abs(A[j][i])<eps)
             {
               A[j][i]=0;
             }
            else
             {
                for(int k=i;k<N;k++)
                 {
                  swap(A[i][k],A[j][k]);//меняем строки местами 
                 }
                    swap(B[i],B[j]);//меняем свободные слены местами 

                 for(int k=0;k<N;k++)
                  swap(E[i][k],E[j][k]);//меняем строки еденичной матрицы  местами 
				 //прямой ход 
                    t1=A[i][i];

                for(int k=i;k<N;k++)
                 {
                  A[i][k]/=t1;
                 }
                  B[i]/=t1;

                for(int k=0;k<N;k++)
                 {
                  E[i][k]/=t1;
                 }

                 for(int k=i+1;k<N;k++)
                  {
                   tA2= A[k][i];
                   B[k] = B[k] - tA2*B[i];

                    for(int q=i;q<N;q++)
                    {
                        A[k][q]=A[k][q]-tA2*A[i][q];
                    }

                    for(int q=0;q<N;q++)
                     {
                        E[k][q]=E[k][q]-tA2*E[i][q];
                     }
                  }
                break;
            }
          }
        }



	  //обратный ход 
         double tempX;
         for(int i=N-1;i>0;i--)
         {
          for(int j=i;j>0;j--)
           {
             B[j-1] = B[j-1] - A[j-1][i]*B[i];
             tempX=A[j-1][i];

              for(int k=i;k<N;k++)
               A[j-1][k] = A[j-1][k] - tempX*A[i][k];

              for(int k=0;k<N;k++)
                {
                 E[j-1][k] = E[j-1][k] - tempX*E[i][k];
                }
            }
          }


        double Det=1;
         for(int i=0;i<N;i++)
          Det*=A[i][i];

        if(Det!=0)
         {
            ofstream fout("Text2.txt");

            for (int i=0;i<N;i++)
            {
              fout<<B[i]<<endl;
            }

            fout.close();



			//проверка что нашли верно обратную матрицу
            ifstream fin_Matr1("Text1.txt");

            fin_Matr1>>N;

                for(int i=0;i<N;i++)
                  for(int j=0;j<N;j++)
                     fin_Matr1>>A[i][j];

                fin_Matr1.close();

             cout<<endl<<"A^(-1) : "<<endl<<endl;

                for(int i=0;i<N;i++)
                 {
                 for(int j=0;j<N;j++)
                  printf("%8.2f",E[i][j]);
                  cout<<endl;
                 }
           cout<<endl<<" Test A*A^(-1) : "<<endl<<endl;

          double x;

          for(int i=0;i<N;i++)
           {
            for(int j=0;j<N;j++)
             {
                x=0;
                 for(int k=0;k<N;k++)
                  x+=A[i][k]*E[k][j];

                 if(abs(x)<eps)
                  x=0;
                printf("%5.1f",x);
             }
             cout<<endl;
           }

       cout<<endl;




       double* X = new double[N];

        for (int i=0;i<N;i++)
          {
            X[i]=0;
            for(int j=0;j<N;j++)
             X[i]+=A[i][j]*B[j];
          }

        cout<<"Test : "<<endl<<endl;
        cout<<" B : "<<endl;
         for(int i=0;i<N;i++)
          printf("%.2f\n",X[i]);
        cout<<endl;
        cout<<"solution X : "<<endl;
         for(int i=0;i<N;i++)
          printf("%.2f\n",B[i]);

        delete [] X;
        delete [] B;
    }
    else
     {
         ofstream fout("Text2.txt");
               fout<<"System don't have one solution !!";
     }

     for (int i=0;i<N;i++)
      {
      delete A[i];
      delete E[i];
      }
    delete [] A;
    delete [] E;

    return 0;
}
