/* Implementar e testar o método de integração da Exponencial Simples para integração de funções que
apresentam singularidade em algum (ou em ambos) dos limites de integração.
O usuário deve fornecer como entrada:
1) os limites de integração (a e b);
2) uma tolerância (potência negativa de 10).
Obs: A função a ser integrada deve ser incluída diretamente no programa.
A tolerância fornecida pelo usuário será usada tanto para garantir que a integral calculada
entre os dois pontos de corte é precisa, quanto para verificar se os pontos de corte são adequados. */

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double f(double x){
   return 1/sqrt(x);
}

double midpoint(double a, double b, double error){
   double integral = 0;
   double aux = 0;
   double delta, alfa, x,s;
   float max = numeric_limits<float>::infinity();
   int i;
   int n = 1;
   alfa = 100;
   double N = 5;


     while(alfa > error){
        aux = integral;
        integral = 0;
        delta = (N+N)/n;
        for(i=0;i<n;i++){
           s = delta/2 + delta*i + -N;
           x = 0.5*(b+a)+ 0.5*(b-a)*tanh(s);
           integral = integral + delta*f(x)/(pow(cosh(s),2));
        }
        n = n*2;
        alfa = abs(integral-aux);
     }

   return 0.5*(b-a)*integral;
}


int main() {

    double a,b,e;
    cout << "Digite o intervalo:\n";
    cin >> a >> b;
    cout << "Digite o erro:\n";
    cin >> e;

    double result = midpoint(a, b, e);
    cout << "Resultado final: " << result << "\n";
    return 0;
}
