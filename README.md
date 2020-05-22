# Trabalho C faculdade Pitágoras

 LEIA ATENTAMENTE AS SEGUINTES INSTRUÇÕES

1. Esta atividade será realizada em dupla ou em trio.
2. O código fonte (.cpp) deverá ser postado neste link até às 23h00min do dia 09/06/2020.
3. O código deve conter as boas práticas de programação, tais como nomes adequados para variáveis, indentação e comentários.
4. Escreva os nomes completos dos autores do código como comentário logo no início.
5. A interpretação dos enunciados faz parte da aferição dos conhecimentos dos integrantes.
6. Não serão aceitas entregas após o prazo.
7. Plágios serão zerados.
BOA ATIVIDADE!

1. O bar e restaurante Gulão Marmitaria precisou se adaptar aos tempos e COVID-19. Para isso, os donos fizeram o cadastro do restaurante nos aplicativos de entrega mais famosos, tais como, iFood, Uber Eats e Rappi. Apesar de ter uma boa demanda normalmente, eles se assustaram com o poder de uma marca nas redes. Os pedidos saltaram a níveis nunca antes vistos, mesmo nos melhores momentos da empresa.
Assim, eles desejam melhorar a organização, o estoque dos insumos e o controle da produção de marmitas que fabricam e vendem diariamente.
Desta forma, escreva um programa em C que atenda aos requisitos abaixo.
A tela de opções deve conter um menu de opções:

1. Cadastrar Estoque
2. Consultar Estoque
3. Cadastrar Produção
4. Consultar Produção
5. Cadastrar Vendas
6. Consultar Vendas
7. Relatórios
8. Finalizar

Esse sistema deverá controlar o estoque dos insumos e a produção de marmitas, no período de uma semana, da seguinte forma:

1. Cadastrar Estoque
É a opção que permite cadastrar os estoques dos insumos utilizados na produção das marmitas. Ao escolher esta opção, o sistema deve solicitar ao usuário qual insumo terá o estoque atualizado. Pode ser permitido ao usuário escolher um insumo específico para atualizar ou atualizar todos os insumos. O valor digitado pelo usuário sempre incidirá ao estoque atual do insumo.
2. Consultar Estoque
É a opção que permite consultar o estoque de insumos utilizados na produção das marmitas. Ao escolher esta opção, o sistema deve solicitar ao usuário qual o insumo deseja consultar. Pode ser permitido ao usuário escolher um insumo específico ou pedir a impressão do estoque de todos os insumos.
3. Cadastrar Produção
É a opção que permite cadastrar a produção de marmitas em um determinado dia a ser inserido pelo usuário. Ao escolher um dia, o sistema solicita o valor de produção. Caso o usuário escolha todos os dias, o sistema deverá solicitar a produção de cada um dos dias.
4. Consultar Produção
É a opção que permite consultar a produção de marmitas em um determinado dia a ser inserido pelo usuário. Ao escolher um dia, o sistema retorna o valor de marmitas produzidas. Caso o usuário escolha todos os dias, o sistema deverá mostrar a produção de todos os dias, dia a dia.
5. Cadastrar Vendas
É a opção que permite cadastrar a quantidade de marmitas vendidas em um determinado dia a ser inserido pelo usuário. Ao escolher um dia, o sistema solicita o valor de marmitas vendidas. Caso o usuário escolha todos os dias, o sistema deverá solicitar a quantidade de marmitas vendidas de cada um dos dias.
6. Consultar Vendas
É a opção que permite consultar a quantidade de marmitas vendidas em um determinado dia a ser inserido pelo usuário. Ao escolher um dia, o sistema retorna a quantidade de marmitas vendidas e o valor total obtido com a venda (R$). Caso o usuário escolha todos os dias, o sistema deverá mostrar a produção de todos os dias, dia a dia, e o total obtido em cada um dos dias com as vendas (R$).

7. Relatórios
É a opção que permite ter um controle gerencial das operações de estoque, produção e vendas. Deve mostrar na tela os seguintes indicadores:
i. A quantidade média de produção de marmitas, considerando apenas os dados cadastrados;
ii. A quantidade média de venda de marmitas, em número e em valor (R$), considerando apenas os dados cadastrados;
iii. O dia com a maior produção e a quantidade produzida;
iv. O dia com a menor produção e a quantidade produzida;
v. O dia com maior venda, a quantidade vendida em número de marmitas e em valor (R$);
vi. O dia com menor venda, a quantidade vendida em número de marmitas e em valor (R$);
vii. Os níveis atuais dos estoques de cada insumo.
8. Finalizar
É a opção que finaliza o programa.

Observações importantes
i. O sistema deverá ser feito em linguagem C e ser comentado.
ii. Todo valor de produção e venda de marmitas, seja de entrada ou saída, deve ser na unidade de medida de unidade.
iii. Os valores de dia da semana devem ser tratados assim: 1 – Domingo; 2 – Segunda; 3 – Terça; 4 – Quarta; 5 – Quinta; 6 – Sexta; 7 – Sábado.
iv. Toda vez que o processamento de uma opção chegar ao fim, o programa deve retornar ao menu inicial, com exceção da opção Finalizar.
v. Os diretores estão empolgados com a criação desse projeto, porque permitirá obter um bom controle, por isso não aceitarão inconsistências nos processos.
vi. Os diretores também acreditam que a Tecnologia da Informação é dinâmica, por isso veem com bons olhos incrementos ao projeto, desde que somem ao valor agregado proposto.
vii. O preço de venda da marmita é de R$ 12,99 de segunda a sexta e de R$ 15,99 aos sábados e domingos;
viii. Os insumos para produção da marmita são: arroz, feijão, carne, legumes e ovo.
ix. Para produzir uma marmita são necessários: 120g de arroz, 80g de feijão, 120g de carne, 120g de legumes e 1 ovo. Toda marmita é embalada em um invólucro de alumínio, sendo gasto um por marmita. O estoque do invólucro também deve ser controlado;
x. Quando insere a produção de marmitas, deve-se abater do estoque os insumos utilizados.