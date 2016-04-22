/* Implementar e testar a quadratura de Gauss-Laguerre para integração adequada a esse tipo de quadratura.
O método que retorna o valor da função para um dado x deve ser programado e incorporado ao código.
A entrada de dados deve ser:
1) o número de pontos de Laguerre a serem usados no somatório (1 a 6). */


#include <iostream>
#include <cmath>
#include <iomanip> //Biblioteca para manipulacao do cout

using namespace std;

double mainFunction(double x){
   return pow(x,2);
}

double calcIntegral(double roots[], double weights[], int grade){

   int j;
   double integral = 0;

   for(j=0;j<grade;j++){
      integral = integral + mainFunction(roots[j])*weights[j];
   }
   return integral;
}

double grade6(){

   double weights[6] = {0.45896467394996,0.4170008307721,0.113373382074,0.0103991974531,
      2.610172028149E-4,8.9854790643E-7};
   double roots[6] = {0.22284660417926,1.1889321016726,2.9927363260593,5.7751435691045,
      9.8374674183826,15.982873980602};

   return calcIntegral(roots,weights,6);
}


double grade5(){

   double weights[5] = {0.52175561058281,0.398666811083,0.075942449682,0.00361175867992,2.33699723858E-5};
   double roots[5] = {0.26356031971814,1.4134030591065,3.5964257710407,7.0858100058588,12.640800844276};

   return calcIntegral(roots,weights,5);

}


double grade4(){

   double weights[4] = {0.6031541043416,0.3574186924378,0.038887908515,5.392947055613E-4};
   double roots[4] = {0.32254768961939,1.7457611011583,4.5366202969211,9.3950709123011};

   return calcIntegral(roots,weights,4);

}

double grade3(){

   double weights[3] = {0.71109300992917,0.2785177335692,0.01038925650159};
   double roots[3] = {0.41577455678348,2.294280360279,6.2899450829375};

   return calcIntegral(roots,weights,3);

}

double grade2(){

   double weights[2] = {0.8535533905933,0.14644660940673};
   double roots[2] = {0.5857864376269,3.4142135623731};

   return calcIntegral(roots,weights,2);
}

/*double grade1(float a, float b, double error){
   double integral = 0; double aux = 0;
   double alfa,delta;
   int i; int n = 1;
   double weights[1] = {2};
   double roots[1] = {0};
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         integral = integral + calcIntegral(a + delta*i,a+delta*(i+1),roots,weights,1);
      }
      n = n*2;
      alfa = abs(integral-aux)/aux;
   }

   return integral;
}*/

int main(){

   int grade;
   cout << setprecision(7) << fixed;

   cout << "Digite os número de pontos de Laguerre: ";
   cin >> grade;


   switch (grade) {

      case 1:
         //cout << grade1() << "\n";
         break;
      case 2:
         cout << grade2() << "\n";
         break;
      case 3:
         cout << grade3() << "\n";
         break;
      case 4:
         cout << grade4() << "\n";
         break;
      case 5:
         cout << grade5() << "\n";
         break;
      case 6:
         cout << grade6() << "\n";
         break;
      default:
         cout << "Metodo nao implementado\n";
   }
}
