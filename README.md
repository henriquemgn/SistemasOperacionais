# SistemasOperacionais

## Aula 3 - 02/03/2023

### Exercicio 1 -
As principais chamadas de sistema foram open, write, read, exit e close<br>
Nas linhas 10, 11, 13, 16, 17, 20, 23, 24 e 27, totalizando 9

### Exercicio 2 -
As principais chamadas foram as mesmas do exercicio 1, sendo elas, open, write, read, exit e close<br>
Nas linhas 11, 13, 14, 16, 19,20, 23, 26, 27, 30 e 31, totalizando 11


## Aula 4 - 09/03/2023

### Exercicio 1 - 
Quando executado chamando ./Exemplo05.bin 999 retorna ordenado pelo valor de i até 999.

### Exercicio 2 -
Se fosse usado print ao invés de sys.stderr, as mensagens sairiam na saída padrão (stdout) ao invés de na saída de erro (stderr).
stderr separa as saídas entre de erro e saídas stdout padrão

## Aula 7 - 20/04/2023

a) No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?

Por conta das condições de corrida, sem a utilização de semaforos os valores não eram consistentes.

b) Implemente uma solução utilizando Mutex e comparece com a anterior. O que mudou? Por quê?

Como os semaforos/mutex impedem que seja acessado o elemento na memória caso dito elemento ja esteja em uso, não ocorre a competição para alterar a memoria. 
Enquanto sem os semaforos/mutex estava variando entre valores estranhos, com a utilização dos semaforos/mutex os resultados foram consistentes.
