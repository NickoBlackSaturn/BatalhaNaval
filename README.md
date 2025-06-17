# BATALHA-NAVAL

# O que o programa faz:
Usa um tabuleiro 10x10.
Mostra navios (valor 3), água (0) e áreas de habilidade (5).
Habilidades:
Cone: formato triangular para baixo.
Cruz: forma de "+" com centro fixo.
Octaedro: forma de losango.
Tudo com loops aninhados e condicionais como exigido.

# Estrutura Geral do Programa
O programa se divide nas seguintes partes principais:
Definições iniciais e constantes
Funções auxiliares para configuração do tabuleiro e habilidades
Função principal main() que organiza a lógica geral do jogo

# Posicionamento de Navios
Na função posicionarNavios, dois navios são posicionados manualmente:
Um navio horizontal (3 posições)
Um navio vertical (3 posições)
Cada posição ocupada recebe o valor 3, representando um navio.

# Exemplo de Saída Visual:
~ ~ N N N ~ ~ ~ ~ ~ 
~ * * * ~ ~ ~ ~ ~ ~ 
* * * * * ~ ~ ~ ~ ~ 
~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
~ ~ ~ ~ * N ~ ~ ~ ~ 
~ ~ ~ ~ * N ~ ~ ~ ~ 
~ ~ ~ ~ * N * * * ~ 
~ ~ ~ ~ ~ ~ * * * ~ 
~ ~ ~ ~ ~ ~ ~ * ~ ~ 
Legenda:
~: Água (0)
N: Navio (3)
*: Área afetada por habilidade (5)

# Função Principal (main)
A função main executa a seguinte sequência:
Cria e inicializa o tabuleiro.
Posiciona os navios.
Cria as três habilidades (cone, cruz e octaedro).
Aplica as habilidades em três posições diferentes do tabuleiro.
Exibe o tabuleiro final com os navios e as áreas afetadas.
