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

### a) 
No final, entregue no README do repositório uma explicação resumida sobre as diferenças entre os valores atingidos. Quais foram as causas das divergências? Por que elas aconteceram?

R: Por conta das condições de corrida, sem a utilização de semaforos os valores não eram consistentes.

### b) 
Implemente uma solução utilizando Mutex e comparece com a anterior. O que mudou? Por quê?

R: Como os semaforos/mutex impedem que seja acessado o elemento na memória caso dito elemento ja esteja em uso, não ocorre a competição para alterar a memoria. 
Enquanto sem os semaforos/mutex estava variando entre valores estranhos, com a utilização dos semaforos/mutex os resultados foram consistentes.

## Aula 8 - Memória - 20/04/2023

Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.
R: Assumindo a maquina virtual com 200000 de memória livre, podemos calcular o número maximo de elementos como 200000/16 = 12500 elementos, isso, porém, ignora o resto do custo do programa, mas tomando apenas o peso das celulas seria isso.

## Projeto 2

Considere os seguintes requisitos para o problema acima:
1. A conta to pode receber mais de uma transferência simultânea;
    R: A utilização de threads faz com que as transferencias sejam simultaneas.
2. A conta from pode enviar mais de uma transferência simultânea;
    R: A utilização de threads faz com que as transferencias sejam simultaneas.
3. A conta from não pode enviar dinheiro se não tiver mais saldo;
    R: A verificação do while(saldo_to > valor && saldo_from > valor), evita que seja realizada transações sem saldo.
4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar;
    R: A variavel Tag foi utilizada para que a ordem de quem envia e quem recebe seja trocada de maneira aleatoria utilizando rand().
5. Poderão ser realizadas até 100 transações simultâneas de transferência.
    R: São criadas 100 threads para que sejam realizadas 100 transações simultaneas de transferência.
    
