# Projeto 2

## Exercicios<br><br>

### A conta to pode receber mais de uma transferência simultânea;<br>
### A conta from pode enviar mais de uma transferência simultânea;<br>

Para que as transferências sejam simultâmneas foi utilizado Threads e para evitar o problema de condição de corrida foi utilizado semaforos como abaixo:<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/a89631f3-24d6-4bae-8e47-68916bb2e94b)

### A conta from não pode enviar dinheiro se não tiver mais saldo;<br>
Condição do loop while impede que sejam realizadas mais transações se o saldo for menor que o valor da transação.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/26c25ff6-cfbd-4f13-97d8-0c56d197083c)


### A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar; <br>
Para a troca acontecer foi utilizado uma variavel de tipo int que utilizando rand() varia entre 1 e 0 sendo 0 a conta "to" enviando e a "from" recebendo e 1 o contrário.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/651eb994-b6c2-4100-b0f8-8a4dee25b696)

### Poderão ser realizadas até 100 transações simultâneas de transferência.<br>
Para garantir que 100 transação são realizadas simultâneamente são inicializadas 100 threads.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/cbe564f9-5dfd-4f0a-b1a6-927f55ba1920)
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/1bbae7e8-e032-43a1-9051-9c703d7e1184)

