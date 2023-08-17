
<head>
  <title>Algoritmo de Apostas em Futebol</title>
</head>
<body>
  <h1>Algoritmo de Apostas em Futebol</h1>
  <p>Este algoritmo é escrito em C++ e tem como objetivo auxiliar apostadores a decidirem se devem ou não apostar em um determinado time de futebol. O algoritmo utiliza como base os resultados dos últimos 5 jogos do time em questão, e com base nesses resultados, calcula a média dos últimos jogos e retorna uma chance de green ou de red para o apostador.</p>
  <h2>Como usar</h2>
  <p>Altere o valor das variáveis nas linhas 14 a 18, atribuindo 1 para vitória, 0.5 para empate e 0 para derrota:</p>
  <p>Exemplo:</p>
  <pre>double resultadoUltimoJogo = 0; 
double resultadoPenultimoJogo = 0;
double resultadoAntepenultimoJogo = 0;
double resultadoJogoAnterior = 0;
double resultadoJogoMaisAntigo = 0.5;</pre>
  <p>Utilize esse comando para compilar o algorítmo:</p>
  <pre>g++ -o mecanismo_apostas mecanismo_apostas.cpp</pre>
  <p>O algoritmo retornará um valor entre 0 e 1. Um valor mais próximo de 1 significa uma chance maior de green, enquanto um valor mais próximo de 0 significa uma chance maior de red.</p>
  <h2>Exemplo de saída</h2>
  <p>Aqui está um exemplo da saída do algoritmo:</p>
  <pre>Media dos ultimos jogos: 0.1
Chance de dar green: Baixa
</pre>
  <p>Isso significa que há uma chance de 10% do time em questão ganhar o próximo jogo.</p>
  <h2>Disclaimer</h2>
  <p>Este algoritmo é apenas um modelo e não deve ser usado como uma garantia de ganhos. O apostador deve sempre fazer sua própria pesquisa antes de apostar em qualquer equipe.</p>
</body>
