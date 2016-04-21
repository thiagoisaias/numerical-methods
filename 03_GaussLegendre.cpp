/* Implementar e testar as quadraturas de Gauss-Legendre para integração de funções.
O método que retorna o valor da função para um dado x deve ser programado e incorporado ao código.
A entrada de dados deve ser:
1) Valor do início do intervalo de integração;
2) Valor do final do intervalo de integração;
3) Valor da tolerância (potência negativa de 10).
O output deve ser o valor da integral da função para os limites de integração fornecidos.
O usuário deve ter a opção de escolher o número de pontos de Legendre a serem usados no somatório: 1 a 5.
Anexe também um arquivo pdf com os seguintes desenvolvimentos:
1) O polinômio de Legendre de grau 4;
2) O cálculo das raízes do polinômio do ítem 1);
3) Os polinômios de interpolação de Lagrange associados aos pontos amostrais do item 2);
e o cálculo dos pesos associados aos pontos amostrais do item 2). */


#include <iostream>
#include <cmath>
#include <iomanip> //Biblioteca para manipulacao do cout

using namespace std;

double mainFunction(double x){
   return exp(x);
}

double calcIntegral(float a, float b, double roots[], double weights[], int grade){

   int j;
   double integral = 0;
   double x = 0;

   for(j=0;j<grade;j++){
      x = (a+b)/2 + ((b-a)/2)*roots[j];
      integral = integral + mainFunction(x)*weights[j];
   }
   return 0.5*(b-a)*integral;
}

double grade5(float a, float b, double error){
   double integral = 0; double aux = 0;
   double alfa,delta;
   int i; int n = 1;
   double weights[5] = {0.568888889, 0.478628670, 0.478628670, 0.236926885, 0.236926885};
   double roots[5] = {0, 0.538469310, -0.538469310, 0.906179846, -0.906179846};
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         integral = integral + calcIntegral(a + delta*i,a+delta*(i+1),roots,weights,5);
      }
      n = n*2;
      alfa = abs(integral-aux)/aux;
   }

   return integral;
}


double grade4(float a, float b, double error){
   double integral = 0; double aux = 0;
   double alfa,delta;
   int i; int n = 1;
   double weights[4] = {0.652145155,0.652145155, 0.347854845, 0.347854845};
   double roots[4] = {0.339981043, -0.339981043, 0.861136312, -0.861136312};
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         integral = integral + calcIntegral(a + delta*i,a+delta*(i+1),roots,weights,4);
      }
      n = n*2;
      alfa = abs(integral-aux)/aux;
   }

   return integral;
}

double grade3(float a, float b, double error){
   double integral = 0; double aux = 0;
   double alfa,delta;
   int i; int n = 1;
   double weights[3] = {0.888888889, 0.555555556, 0.555555556};
   double roots[3] = {0, 0.774596669, -0.774596669};
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         integral = integral + calcIntegral(a + delta*i,a+delta*(i+1),roots,weights,3);
      }
      n = n*2;
      alfa = abs(integral-aux)/aux;
   }

   return integral;
}

double grade2(float a, float b, double error){
   double integral = 0; double aux = 0;
   double alfa,delta;
   int i; int n = 1;
   double weights[2] = {1,1};
   double roots[2] = {0.577350269,-0.577350269};
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         integral = integral + calcIntegral(a + delta*i,a+delta*(i+1),roots,weights,2);
      }
      n = n*2;
      alfa = abs(integral-aux)/aux;
   }

   return integral;
}

double grade1(float a, float b, double error){
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
}

int main(){

   float a,b,error;
   int grade;
   cout << setprecision(4) << fixed;

   cout << "Digite os valores do intervalo: ";
   cin >> a >> b;
   cout << "Digite a tolerancia (erro): ";
   cin >> error;
   cout << "Digite o grau do polinomio de aproximacao (1 a 5): ";
   cin >> grade;

   switch (grade) {

      case 1:
         cout << grade1(a,b,error) << "\n";
         break;
      case 2:
         cout << grade2(a,b,error) << "\n";
         break;
      case 3:
         cout << grade3(a,b,error) << "\n";
         break;
      case 4:
         cout << grade4(a,b,error) << "\n";
         break;
      case 5:
         cout << grade5(a,b,error) << "\n";
         break;
      default:
         cout << "Metodo nao implementado\n";
   }
}
