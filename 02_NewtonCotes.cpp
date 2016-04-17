/* T02 - Fórmulas de Newton-Cotes Abertas
Descrição:
Implementar e testar as fórmulas de Newton-Cotes Abertas para integração de funções.
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
   return exp(x);
}

double grade5(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3,x4,x5,x6,x7;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/7)/n; //Distancia entre os pontos amostrais
      for(i=0;i<n;i++){
         x0 = a + 7*delta*i; //Pontos amostrais de cada subintervalo
         x1 = a + 7*delta*i + delta;
         x2 = a + 7*delta*i + 2*delta;
         x3 = a + 7*delta*i + 3*delta;
         x4 = a + 7*delta*i + 4*delta;
         x5 = a + 7*delta*i + 5*delta;
         x6 = a + 7*delta*i + 6*delta;
         x7 = a + 7*delta*i + 7*delta;
         integral = integral + (7*delta/1440)*(0*mainFunction(x0)+611*mainFunction(x1)+(-1*453)*mainFunction(x2)
            +562*mainFunction(x3) + 562*mainFunction(x4) + (-1*453)*mainFunction(x5) + 611*mainFunction(x6)
            + 0*mainFunction(x7));
      }
      n = n*2; //O numero de particoes dobra a cada iteracao
      alfa = abs(integral-aux); //Alfa recebe o modulo da diferença entre a integral atual e a anterior (aux)
      //cout << alfa << " erro\n";
   }

   return integral;
}


double grade4(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3,x4,x5,x6;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/6)/n;
      for(i=0;i<n;i++){
         x0 = a + 6*delta*i;
         x1 = a + 6*delta*i + delta;
         x2 = a + 6*delta*i + 2*delta;
         x3 = a + 6*delta*i + 3*delta;
         x4 = a + 6*delta*i + 4*delta;
         x5 = a + 6*delta*i + 5*delta;
         x6 = a + 6*delta*i + 6*delta;
         integral = integral + (6*delta/20)*(0*mainFunction(x0)+11*mainFunction(x1)+(-14)*mainFunction(x2)
            +26*mainFunction(x3) + (-14)*mainFunction(x4) + 11*mainFunction(x5) + 0*mainFunction(x6));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}

double grade3(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3,x4,x5;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = ((b-a)/5)/n;
      for(i=0;i<n;i++){
         x0 = a + 5*delta*i;
         x1 = a + 5*delta*i + delta;
         x2 = a + 5*delta*i + 2*delta;
         x3 = a + 5*delta*i + 3*delta;
         x4 = a + 5*delta*i + 4*delta;
         x5 = a + 5*delta*i + 5*delta;
         integral = integral + (5*delta/24)*(0*mainFunction(x0)+11*mainFunction(x1)+1*mainFunction(x2)
            +1*mainFunction(x3) + 11*mainFunction(x4) + 0*mainFunction(x5));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}

double grade2(float a, float b, double error){
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
         integral = integral + (4*delta/3)*(0*mainFunction(x0)+2*mainFunction(x1)+(-1)*mainFunction(x2)
            +2*mainFunction(x3) + 0*mainFunction(x4));
      }
      n = n*2;
      alfa = abs(integral-aux);
      //cout << alfa << " erro\n";
   }

   return integral;
}


double grade1(float a, float b, double error){
   double integral = 0; double aux = 0;
   double delta, alfa, x0,x1,x2,x3;
   int i; int n = 1;
   alfa = 1;

   while(alfa > error){
      aux = integral;
      integral = 0;
      delta = (b-a)/3/n;
      for(i=0;i<n;i++){ //Precisa-se de 2 pontos igualmente espaçados entre a e b
         x0 = a + 3*delta*i;
         x1 = a + 3*delta*i + delta;
         x2 = a + 3*delta*i + 2*delta;
         x3 = a + 3*delta*i + 3*delta;
         integral = integral + (3*delta/2)*(0*mainFunction(x0)+1*mainFunction(x1)+1*mainFunction(x2)
            +0*mainFunction(x3));
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
