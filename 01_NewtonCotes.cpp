/* T01 - Fórmulas de Newton-Cotes Fechadas
Descrição:
Implementar e testar as fórmulas de Newton-Cotes Fecadas para integração de funções.
O método que retorna o valor da função para um dado x deve ser programado e incorporado ao código.
A entrada de dados deve ser:
1) Valor do início do intervalo de integração;
2) Valor do final do intervalo de integração;
3) Valor da tolerância (potência negativa de 10).
O output deve ser o valor da integral da função para os limites de integração fornecidos.
O usuário deve ter a opção de escolher os polinômios de substituição (g(x)) de graus de 0 a 5. */

#include <iostream>
#include <cmath>
#include <iomanip> //Biblioteca para manipulacao do cout

using namespace std;

double mainFunction(double x){
   return 1/sqrt(x);
}

double grade5(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3,x4,x5;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/5)/n; //Distancia entre os pontos amostrais
      for(i=0;i<n;i++){
         x0 = a + 5*delta*i; //Pontos amostrais de cada subintervalo
         x1 = a + 5*delta*i + delta;
         x2 = a + 5*delta*i + 2*delta;
         x3 = a + 5*delta*i + 3*delta;
         x4 = a + 5*delta*i + 4*delta;
         x5 = a + 5*delta*i + 5*delta;
         integral = integral + (delta*5/288)*(19*mainFunction(x0)+75*mainFunction(x1)+50*mainFunction(x2)
            +50*mainFunction(x3) + 75*mainFunction(x4) + 19*mainFunction(x5));
      }
      n = n*2; //O numero de particoes dobra a cada iteracao
      alfa = abs(integral-aux); //Alfa recebe o modulo da diferença entre a integral atual e a anterior (aux)
      //cout << alfa << " erro\n";
   }

   return integral;
}


double grade4(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3,x4;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/4)/n;
      for(i=0;i<n;i++){
         x0 = a + 4*delta*i;
         x1 = a + 4*delta*i + delta;
         x2 = a + 4*delta*i + 2*delta;
         x3 = a + 4*delta*i + 3*delta;
         x4 = a + 4*delta*i + 4*delta;
         integral = integral + (delta*2/45)*(7*mainFunction(x0)+32*mainFunction(x1)+12*mainFunction(x2)
            +32*mainFunction(x3) + 7*mainFunction(x4));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}

double grade3(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/3)/n;
      for(i=0;i<n;i++){
         x0 = a + 3*delta*i;
         x1 = a + 3*delta*i + delta;
         x2 = a + 3*delta*i + 2*delta;
         x3 = a + 3*delta*i + 3*delta;
         integral = integral + (delta*3/8)*(mainFunction(x0)+3*mainFunction(x1)+3*mainFunction(x2)+mainFunction(x3));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}

double grade2(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (0.5*(b-a))/n;
      for(i=0;i<n;i++){
         x0 = a + 2*delta*i;
         x1 = a + 2*delta*i + delta;
         x2 = a + 2*delta*i + 2*delta;
         integral = integral + (delta/3)*(mainFunction(x0)+4*mainFunction(x1)+mainFunction(x2));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}


double grade1(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         x0 = delta*i+a;
         x1 = delta*i+a+delta;
         integral = integral + (delta/2)*(mainFunction(x0)+mainFunction(x1));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}


double grade0(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, xp;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/n;
      for(i=0;i<n;i++){
         xp = (delta/2)+delta*i+a;
         integral = integral + delta*mainFunction(xp);
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << "Erro: " << alfa << "\n";
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
   cout << "Digite o grau do polinomio de aproximacao (0 a 5): ";
   cin >> grade;

   switch (grade) {
      case 0:
         cout << grade0(a,b,error) << "\n";
         break;
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
