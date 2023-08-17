// Este algoritmo escrito em C++ tem como objetivo auxiliar apostadores a 
// decidirem se devem ou não apostar em um determinado time jogo de futebol.
// O algoritmo utiliza como base os resultados dos ultimos 5 jogos do time
// em questão, e com base nesses resultados, calcula a média dos ultimos jogos
// e retorna uma chance de green ou de red para o apostador.

#include "iostream"

using namespace std;

//Coleta de dados com base nos ultimos 5 jogos:
//1=vitoria 0.5=empate; 0=derrota
double resultadoUltimoJogo = 0; 
double resultadoPenultimoJogo = 0;
double resultadoAntepenultimoJogo = 0;
double resultadoJogoAnterior = 0;
double resultadoJogoMaisAntigo = 0.5;

double mediaUltimosJogos = ((resultadoUltimoJogo*1.2) + (resultadoPenultimoJogo*1.1) + 
resultadoAntepenultimoJogo + resultadoJogoAnterior + resultadoJogoMaisAntigo) / 5.0;

double resultadoFinal = mediaUltimosJogos;

int main()
{
  cout << "Media dos ultimos jogos: " << mediaUltimosJogos << endl;
if (resultadoFinal >= 0.7) {
  cout << "Chance de dar green: Alta" << endl;
}
else if (resultadoFinal >= 0.4) {
  cout << "Chance de dar green: Media" << endl;
}
else if (resultadoFinal >= 0.1) {
  cout << "Chance de dar green: Baixa" << endl;
}
else {
  cout << "Vai dar Red!" << endl;
}
  return 0; 
}
