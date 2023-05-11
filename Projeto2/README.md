# Projeto 2

## Exercicios<br><br>

### A conta to pode receber mais de uma transferência simultânea;<br>
### A conta from pode enviar mais de uma transferência simultânea;<br>

Para que as transferências sejam simultâneas foram utilizadas Threads.<br>
E para evitar o problema de condição de corrida foi utilizado semaforos como abaixo:<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/a89631f3-24d6-4bae-8e47-68916bb2e94b)

### A conta from não pode enviar dinheiro se não tiver mais saldo;<br>
Condição dentro da thread verifica se a saldo suficiente na conta enviando dinheiro.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/b605be0e-a0a9-4ac0-b8ab-d814c2d44305)


### A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar; <br>
Para a troca acontecer foi utilizado uma variavel de tipo int que utilizando rand() varia entre 1 e 0 sendo 0 a conta "to" enviando e a "from" recebendo e 1 o contrário.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/2c2fcf8b-6004-4301-871a-09206061d342)


### Poderão ser realizadas até 100 transações simultâneas de transferência.<br>
Para garantir que 100 transação são realizadas simultâneamente são inicializadas 100 threads.<br>
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/7af97fd6-d5f7-4d84-b9d4-d2a32195a2cb)
![image](https://github.com/henriquemgn/SistemasOperacionais/assets/32944009/b80175c4-a367-40ab-ad94-31e3605a4ecd)



