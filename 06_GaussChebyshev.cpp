<<<<<<< HEAD
/*  Implementar e testar a quadratura de Gauss-Chebyshev para integração adequada a esse tipo de quadratura.
O método que retorna o valor da função para um dado x deve ser programado e incorporado ao código.
A entrada de dados deve ser:
1) o número de pontos de Chebyshev a serem usados no somatório. */
=======
/* Implementar e testar a quadratura de Gauss-Chebyshev para integração adequada a esse tipo de quadratura.
O método que retorna o valor da função para um dado x deve ser programado e incorporado ao código.
A entrada de dados deve ser:
1) o número de pontos de Chebyshev a serem usados no somatório. */

#include <iostream>
#include <cmath>
#include <iomanip> //Biblioteca para manipulacao do cout

using namespace std;

double mainFunction(double x){
   return exp(x);
}

double calcIntegral(int num){

   int j;
   double integral = 0;

   double aux = 0;
   double w = M_PI/num;

   for(j = 1;j <= num; j++){
      integral = integral + mainFunction(cos((j-0.5)*M_PI/num))*w;
   }

   return integral;
}

int main(){

   int num;
   cout << setprecision(10) << fixed;

   cout << "Digite o numero de pontos de Chebyshev: ";
   cin >> num;

   cout << calcIntegral(num) << "\n";

}
>>>>>>> gaussian-quadratures
