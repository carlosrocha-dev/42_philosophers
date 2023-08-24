<div align="center">

![philosophersn](https://github.com/carlosrocha-dev/42_philosophers/assets/3737837/f1851fb8-eeef-4683-8041-4f0a0ea56fcb)

</div>


![Build Status](https://github.com/carlosrocha-dev/42_philosophers/actions/workflows/philosophers/badge.svg)

# 42_philosophers | 🍽️ 💭 💤
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

 ---

Visão Geral

Aqui estão as coisas que você precisa saber se deseja ter sucesso nesta tarefa:
• Um ou mais filósofos estão sentados em uma mesa redonda. Há uma grande tigela de espaguete no centro da mesa.
• Os filósofos alternam entre comer, pensar ou dormir. Enquanto estão comendo, não estão pensando nem dormindo; enquanto estão pensando, não estão comendo nem dormindo; e, é claro, enquanto estão dormindo, não estão comendo nem pensando.
• Também há garfos na mesa. Há tantos garfos quanto filósofos.
• Como servir e comer espaguete com apenas um garfo é muito inconveniente, um filósofo pega os garfos da direita e da esquerda para comer, um em cada mão.
• Quando um filósofo termina de comer, ele coloca seus garfos de volta na mesa e começa a dormir. Quando acorda, começa a pensar novamente. A simulação para quando um filósofo morre de fome.
• Cada filósofo precisa comer e nunca deve passar fome.
• Os filósofos não conversam entre si.
• Os filósofos não sabem se outro filósofo está prestes a morrer.
• Não é necessário dizer que os filósofos devem evitar morrer.

Regras Gerais

Você deve escrever um programa para a parte obrigatória e outro para a parte bônus (caso decida fazer a parte bônus). Ambos devem obedecer às seguintes regras:

• Variáveis globais são proibidas!

• Seu(s) programa(s) deve(m) receber os seguintes argumentos:
número_de_filósofos tempo_para_morrer tempo_para_comer tempo_para_dormir [número_de_vezes_que_cada_filósofo_deve_comer]
◦ número_de_filósofos: O número de filósofos e também o número de garfos.
◦ tempo_para_morrer (em milissegundos): Se um filósofo não começar a comer após tempo_para_morrer milissegundos desde o início de sua última refeição ou o início da simulação, ele morre.
◦ tempo_para_comer (em milissegundos): O tempo que um filósofo leva para comer. Durante esse tempo, eles precisarão segurar dois garfos.
◦ tempo_para_dormir (em milissegundos): O tempo que um filósofo passará dormindo.
◦ número_de_vezes_que_cada_filósofo_deve_comer (argumento opcional): Se todos os filósofos tiverem comido pelo menos número_de_vezes_que_cada_filósofo_deve_comer vezes, a simulação para. Se não for especificado, a simulação para quando um filósofo morre.

• Cada filósofo tem um número de 1 a número_de_filósofos.

• O filósofo número 1 está ao lado do filósofo número número_de_filósofos. Qualquer outro filósofo número N está entre o filósofo número N - 1 e o filósofo número N + 1.

Sobre os registros do seu programa:
• Qualquer mudança de estado de um filósofo deve ser formatada da seguinte maneira:
◦ timestamp_em_ms X pegou um garfo ◦ timestamp_em_ms X está comendo
◦ timestamp_em_ms X está dormindo ◦ timestamp_em_ms X está pensando
◦ timestamp_em_ms X morreu Substitua timestamp_em_ms pelo timestamp atual em milissegundos e X pelo número do filósofo.

• Uma mensagem de estado exibida não deve ser misturada com outra mensagem.
• Uma mensagem anunciando a morte de um filósofo deve ser exibida em no máximo 10 ms após a morte real do filósofo.
• Novamente, os filósofos devem evitar morrer!

Obrigatório

As regras específicas para a parte obrigatória são:
• Cada filósofo deve ser uma thread.
• Há um garfo entre cada par de filósofos. Portanto, se houver vários filósofos, cada filósofo tem um garfo ao seu lado esquerdo e um garfo ao seu lado direito. Se houver apenas um filósofo, deve haver apenas um garfo na mesa.
• Para evitar que os filósofos dupliquem os garfos, você deve proteger o estado dos garfos com um mutex para cada um deles.
