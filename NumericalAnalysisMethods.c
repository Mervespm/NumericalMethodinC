#include <stdio.h>
#include <math.h>
#define MAX 50



float Polfun(float x, int der, float *dizi);
float Derivatized(float x, int der, float *dizi);
void NumericalDer(float xp,float h,int der ,float *dizi);
void GaussSiedel(int n,float err,float a[][MAX], float *init);
void InverseMatris(int n, float a[][MAX]);
void GaussJordanElemination(int n, float a[][MAX]);
void NewtonRamphson(float a, float err, int derece,float *dizi);
void Bisection(float a,float b,float err, int derece,float *dizi);
void RegulaFalsi(float a,float b,float err, int derece,float *dizi);
void Trapez(float a,float b, int derece,float *dizi,float xn );
void Simpson3(float a,float b, int derece,float *dizi,float xn );
void Simpson8(float a,float b, int derece,float *dizi,float xn );
void Interpolation(int n, float *ax, float ay[][MAX], float x);
int Factoriel(int n); // interpolasyon icin kullanilmistir
float InterpolDiff(float diff, int n); // interpolasyon icin kullanilmistir


int main()
{

    int secim = 1;

    while (secim != 0){


      //MENU
      printf("\n1-Lineer olmayan denklemler icin yontemler\n2-Lineer denklemler icin yontemler\n3-Sayisal turev bulma\n");
      printf("4-Integral bulma\n5-Gregory Newton Interpolasyon\n6-Cikmak icin 0'a basiniz");
      printf("\nHangi Chapter hakkinda ornek denemek istersiniz ?\n");
      scanf("%d",&secim);

      int derece; // polinom derecesi
      int i,j,k;
      float dizi[MAX]; // polinom tutan dizi
      float a,b,err,h,xp,xn; // [a,b] , hata payi ve istenilen deger icin degiskenler

      int islem; // alt menulerde kullanilan secenek
      int n,m;
      float matris[MAX][MAX]; // matris tutan 2D dizi

      float fx[MAX][MAX],x[MAX]; // interpolasyondaki tablolar icin
     

      //ALT MENU 1 
      if(secim == 1)
      {
        printf("1- Bisection methodu\n2- Regula Falsi methodu\n3- Newton Ramphson methodu\n");
        scanf("%d",&islem);
        printf("Lutfen sirasiyla a(baslangic), b(bitis), hata payini ve polinomun derecesini giriniz :");
        scanf("%f %f %f %d",&a,&b,&err,&derece);

        for(i = 0; i<derece+1; i++)
         {
            printf("Lutfen son terimden baslayarak kaysayilari giriniz:\n ");
            scanf("%f",&dizi[i]);
         }


        if(islem == 1)
        {
          printf("\n-----BISECTION-------\n");
          Bisection(a,b,err,derece,&dizi[0]);
  
        }
        if(islem == 2)
        {
          printf("\n-----REGULA FALSI ----\n");
          RegulaFalsi(a,b,err,derece,&dizi[0]);
  
        }
        if(islem == 3)
        {
          printf("\n----NEWTON RAMPSON -----\n");
          NewtonRamphson(a,err,derece,&dizi[0]);

  
        }

        
         
      }
      // ALT MENU 2
        if (secim == 2)
        {

          printf("1-Matrisin tersini bulma\n2-Gauss Eleminatian yontemi ile kokleri bulmak\n");
          printf("3-Gauss Siedel yontemi ile kokleri bulmak\n");
          printf("\nLutfen matris ile yapmak istediginiz islemi seciniz...");
          scanf("%d",&islem);

           //ALT MENU 2.1
           if(islem ==1)
            {

              printf("\nLutfen sirayla matrisin satir/sutun sayisini giriniz...");
              scanf("%d",&n);

              for (i = 1; i <= n; ++i)
               {
                 for (j = 1; j <= n; ++j)
                  {
                  printf("matris[%d][%d] = ",i,j);
                  scanf("%f",&matris[i][j]);
                  }
               }

              InverseMatris(n,matris);
            }
           //ALT MENU 2.2
            if(islem ==2)
            {

              printf("\nBilinmeyen sayisi kactir ?");
              scanf("%d",&n);
              printf("\nElemanlari giriniz");

              for(i=1; i<=n; i++)
              {
                for(j=1; j<=n+1; j++)
                 {
                  printf("matris[%d][%d] = ",i,j);
                  scanf("%f", &matris[i][j]);
                  }
              }

              GaussJordanElemination(n,matris) ;

            }
            //ALT MENU 2.3
            if(islem == 3)
            {

              float bas_deger[MAX];

              printf("\nBilinmeyen sayisi kactir ?");
              scanf("%d",&n);

              printf("\nHata payini giriniz");
              scanf("%f",&err);

              printf("Her bir eleman icin baslangic degeri giriniz:\n");

              for (i = 0; i < n; ++i)
              {
                 scanf("%f",&bas_deger[i]);
              }

              printf("Elemanlari giriniz\n");

              for(i=0; i<n; i++)
              {
                for(j=0; j< n+1; j++)
                 {
                  printf("matris[%d][%d] = ",i+1,j+1);
                  scanf("%f", &matris[i][j]);
                  }
              }

              GaussSiedel(n,err,matris,&bas_deger[0]);


            }

        }

        //ALT MENU 3
        if(secim == 3)
        {

         printf("\nLutfen sirasiyla turevi bulanacak degeri,h degerini ve polinomun derecesini giriniz :");
         scanf("%f %f  %d",&xp,&h,&derece);

         for(i = 0; i<derece+1; i++)
         {
            printf("Lutfen son terimden baslayarak kaysayilari giriniz:\n ");
            scanf("%f",&dizi[i]);
         }

         NumericalDer(xp,h,derece,&dizi[0]);

        }

        if(secim == 4)
        {
         printf("\nLutfen sirasiyla integrali bulanacak degeri,a(baslangic) ve b(bitis) degerini ve polinomun derecesini giriniz:");
         scanf("%f %f %f %d",&xn,&a,&b,&derece);

         for(i = 0; i<derece+1; i++)
         {
            printf("Lutfen son terimden baslayarak kaysayilari giriniz:\n ");
            scanf("%f",&dizi[i]);
         }
          printf("\n----TRAPEZ YONTEMI----\n");
          Trapez(a,b,derece,&dizi[0],xn );

          printf("\n----SIMPSON YONTEMI (1/3)----\n");
          Simpson3(a,b,derece,&dizi[0],xn);

          printf("\n----SIMPSON YONTEMI (3/8)----\n");
          Simpson3(a,b,derece,&dizi[0],xn);



        }
        if(secim == 5)
        {
         printf("Tabloda kac tane x degeri vardir\n");
         scanf("%d",&n);


         for (i=0;i<n;i++)
         {
            printf("x%d degerini giriniz:\n",i+1);
            scanf("%f",&x[i]);
         }


         for (i=0;i<n;i++)
          {
            printf("f(x%d) degerini giriniz:\n",i+1);
            scanf("%f",&fx[i][0]);
          }

         printf("\nOgrenmek istediginiz f(x) degeri icin x degerini giriniz:\n");
         scanf("%f",&xn);

         Interpolation( n, &x[0],&fx[0],xn);


         
        }




    }

    return 0;
}


//GIRILEN DIZI HALINDAKI POLINOMA, KONULAN DEGERI RETURN EDER.
//HER YONTEMDE F(X) DEGERI ICIN BU FONKSIYON KULLANILIR.
float Polfun(float x, int der, float *dizi)
{
    float fun=0;
    for(int i = 0 ;i < der +1;i++)
    {
        fun += (dizi[i])*pow(x,i); //katsayilar ve indexlerin ustel hali kullanilarak sonuc bulunur
    }
    return fun;
}


//GIRILEN DIZI HALINDEKI POLINOMU TUREV HALINDE KONULAN DEGERI RETURN EDER
float Derivatized(float x, int der, float *dizi)
{
    float fun2 = 0;
    for (int i = 1;i < der +1 ; i++)
    {
        fun2 += ((dizi[i]) * pow(x,i-1)) * i; //katsayilar ve indexlerin eksiltilmis ustel hali kullanilarak sonuc bulunur
    }

    return fun2;
}
//NEWTON - RAMPHSON YONTEMI ILE KOK HESAPLANIR
void NewtonRamphson(float a, float err, int derece,float *dizi)
{
    printf("\nADIM\t\txo\t\tf(xo)\t\tx1\t\tf(x1)\n");

    float x1,gx,fx,err1;
    float xo = a;
    float f1 = 0;
    int step = 0;

    do
    {
        gx = Derivatized(xo, derece, &dizi[0]); // Turev hesaplanir
        fx = Polfun(xo,derece,&dizi[0]);

        x1 = xo - fx/gx;
        err1 = x1 - xo; // Hata payini bulmak icin ilerde kullanilmasi icin

        printf("%d\t\t%f\t%f\t%f\t%f\n",step+1,xo,fx,x1,f1);

        xo = x1;
        f1 = Polfun(x1,derece,&dizi[0]); //f1(x1)

        step ++;

    }while(err < fabs(err1) );

    printf("\nKok = %f\n",x1 );
}

//BISECTION YONTEMI ILE KOK HESAPLANIR
void Bisection(float a,float b,float err, int derece,float *dizi)
{
    float fa = Polfun(a,derece,&dizi[0]);//f(a)
    float fb = Polfun(b,derece,&dizi[0]);//f(b)
    float xo,fx;
    int step = 0;


    printf("ADIM\t\ta\t\tb\t\tx\t\tf(x)\n");

    do
    {
      xo = (a+b)/2;
      fx = Polfun(xo,derece,&dizi[0]);

      printf("%d\t\t%f\t%f\t%f\t%f\n",step+1,a,b,xo,fx);

      if(fa * fx < 0.0){
          b = xo;
          fb = fx;
       }
      else
      {
        a = xo;
        fa = fx;
      }

      step ++;

    }while(err < (b-a)/pow(2,step));

     printf("\nKok = %f",xo);

}

//REGULA FALSE YONTEMI ILE KOK HESAPLANIR
void RegulaFalsi(float a,float b,float err, int derece,float *dizi)
{
    float fa = Polfun(a,derece,&dizi[0]);
    float fb = Polfun(b,derece,&dizi[0]);
    float xo,fx;
    int step = 0;

    printf("\nADIM\t\ta\t\tb\t\txo\t\tf(x)\n");
    do
    {
      xo = (((a*fb)-(b*fa))/(fb-fa));//denklem implemente edilmistir
      fx = Polfun(xo,derece,&dizi[0]);//f(x)

      printf("%d\t\t%f\t%f\t%f\t%f\n",step+1,a, b, xo,fx);

      if(fa*fx < 0.0) // baslangic - bitis degerleri icin kontrol saglanir
      {
        b = xo;
        fb = fx;
      }
       else
      {
        a = xo;
        fa = fx;
      }
       step ++;

    }while(err < (b-a)/pow(2,step));

    printf("\nKok = %f",xo);

}
void InverseMatris(int n, float a[][MAX])
{

  int i,j,k;
  float ratio = 0;

  for(i = 1; i <= n; i++)
  {
    for(j = 1; j <=n ; j++)
    {
      if(i == j)
      {
        a[i][j+n] = 1;
      }
      else
      {
        a[i][j+n] = 0;
      }
    }
  }

  for(i = 1; i <= n; i++)
  {
    if(a[i][i] == 0.0)
    {
      printf("Hata!");

    }
    for(j = 1; j <= n; j++)
    {
      if(i != j)
       {
        ratio = a[j][i]/a[i][i];

        for(k = 1; k <= 2*n; k++)
          {
            a[j][k] = a[j][k] - ratio*a[i][k];
           }
        }
    }
  }

  for(i = 1; i <= n; i++)
   {
      for(j = n+1; j <= 2*n; j++)
      {
         a[i][j] = a[i][j]/a[i][i];
      }
   }


  printf("\n----TERS MATRIS-----\n");
  for(i = 1; i <=n ; i++)
  {
    for(j = n+1; j <= 2*n; j++)
    {
      printf("%0.3f\t",a[i][j]);
    }
      printf("\n");
  }
}



void GaussSiedel(int n,float err,float a[][MAX], float *init)
{
  int i,j,k,step=0,control = 0;
  float y,temp;

   for(i=0; i<n; i++)//max katsayilarin kosegen haline getirilir
    {
       for(k=i+1; k<n; k++)
        {
          if(fabs(a[i][i]) < fabs(a[k][i]))
           {

            for(j =0; j<=n ; j++)
            {
              temp = a[i][j];
              a[i][j]=a[k][j];
              a[k][j]=temp;
            }

           }
        }
    }

  printf("\nADIM\t\t");
  for ( i = 0; i < n; ++i)
  {
    printf("x%d\t\t",i);
  }

  printf("\n");

  while(control < n)
  {
    printf("%d.\t\t",step+1 );

    for (i = 0; i < n; ++i)
    {

      y = init[i]; // baslangic degerleri kullanilmistir
      init[i] = a[i][n];

      for (j = 0; j < n; ++j)
      {
        if(i != j)
        {
          init[i] = init[i] - (a[i][j]*init[j]);
        }
      }

      init[i]= init[i] / a[i][i];

      if(fabs(init[i]-y) < err)
      {
         control ++ ;

      }
      printf("%.3f\t\t",init[i]);

    }

    printf("\n");
    step++;

  }

  printf("Kokler : \n");
  for (i = 0; i < n; ++i)
  {
    printf("x%d = %.3f\n",i,init[i] );
  }
}



void GaussJordanElemination(int n, float a[][MAX])
{

  int i,j,k;
  float x[MAX];//kok tutan dizi
  float ratio; //oran tutulur

  for(i = 1; i <= n-1; i++)
   {
      if(a[i][i] == 0.0)
      {
         printf("Hata");

      }
      for(j = i+1; j <= n; j++)
      {
         ratio = a[j][i]/a[i][i];

         for(k = 1; k <= n+1; k++)
         {
            a[j][k] = a[j][k] - ratio*a[i][k];
         }
      }
   }

   x[n] = a[n][n+1] / a[n][n];

   for(i = n-1; i >= 1; i--)
   {

      x[i] = a[i][n+1];

      for(j = i+1; j <= n; j++)
      {
          x[i] = x[i] - a[i][j] * x[j];
      }

      x[i] = x[i] / a[i][i];
   }

   //Ekrana yazdirma
   printf("\nKOKLER:\n");

   for(i = 1; i <= n; i++)
   {
      printf("x%d = %0.3f\n",i, x[i]);
   }

}

//SAYISAL TUREV IMPLEMENTE EDILMISTIR
void NumericalDer(float xp,float h,int der ,float *dizi)
{
    int i,j,k;
    float a,b,c,fx;
    float sum,subs;

    sum = Polfun(xp+h,der,&dizi[0]); //f(x+h)
    subs = Polfun(xp-h,der,&dizi[0]); // f(x -h)
    fx = Polfun(xp,der,&dizi[0]); // f(x)

    a = (sum - fx)/h;
    b = (fx - subs)/h;
    c = (sum- subs )/(2*h);

    printf("----Ileri Fark------\n");
    printf("%f\n",a );
    printf("----Geri Fark------\n");
    printf("%f\n",b );
    printf("----Merkezi Fark------\n");
    printf("%f\n",c );


}


void Trapez(float a,float b, int derece,float *dizi,float xn )
{
  float k =0.0 ,h =0.0,integration = 0.0;
  float sum = 0.0;

  h = fabs(b - a)/xn;

  
  float fa = Polfun(a,derece,&dizi[0]);
  float fb = Polfun(b,derece,&dizi[0]);
  

 for(int i=1; i< xn ; i++)
 {
  k = a + i * h;
  sum = sum + Polfun(k,derece,&dizi[0]);
 
 }
 integration = (h/2)*(fa+fb+2*sum);

 printf("\nSonuc: %.3f\n", integration);
}

void Simpson3(float a,float b, int derece,float *dizi,float xn )
{
  float k =0 ,h = 0,integration = 0.0;
  float sum = 0.0;

  h = fabs(b - a)/xn;

  
  float fa = Polfun(a,derece,&dizi[0]);
  float fb = Polfun(b,derece,&dizi[0]);
  
  

 for(int i=1; i< xn ; i++)
 {
  k = a + i * h;

  if( i%2 == 0 )
  {
   sum = sum + 2* Polfun(k,derece,&dizi[0]);
  }
  else
  {
   sum=sum + 4 * Polfun(k,derece,&dizi[0]);
  }
 
 }
 integration = (h/3)*(fa + fb + sum);

 printf("\nSonuc: %.3f\n", integration);
}
void Simpson8(float a,float b, int derece,float *dizi,float xn )
{

  float k =0 ,h = 0,integration = 0.0;
  float sum = 0.0;

  h = fabs(b - a)/xn;

  
  float fa = Polfun(a,derece,&dizi[0]);
  float fb = Polfun(b,derece,&dizi[0]);
  
 for(int i=1; i< xn ; i++)
 {
  k = a + i * h;

  if(i%3 == 0)
  {
   sum = sum + 2* Polfun(k,derece,&dizi[0]);
  }
  else
  {
   sum = sum + 3 * Polfun(k,derece,&dizi[0]);
  }
 
 }
 integration = (3 * h/8)*(fa + fb + sum);

 printf("\nSonuc: %.3f\n", integration);
}

float InterpolDiff(float diff, int n)
{
    float temp = diff;
    for (int i = 1; i < n; i++)
    {
        temp = temp * (diff + i);
    }
    return temp;
}


int Factoriel(int n)
{
  int fact = 1;
  for(int i = 2; i <= n; i++ )
  {
    fact *= i;
  }
  return fact;
}

void Interpolation(int n, float *ax, float ay[][MAX], float x)
{

  float sum,diff;
  int i,j;

  for(i = 1 ; i< n; i++)
  {
    for (j = n-1 ; j >= i ; j--)
    {
      ay[j][i] = ay[j][i - 1] - ay[j - 1][i - 1];
      
    }
  }

  
  sum = ay[n-1][0];
  diff = (x - ax[n - 1]) / (ax[1] - ax[0]);

  for ( i = 1; i < n; i++) 
  {
        sum = sum + (InterpolDiff(diff, i) * ay[n - 1][i]) /Factoriel(i);
  }

  printf("%f teki deger = %f\n",x,sum );

}






