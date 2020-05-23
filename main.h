#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MENU_PRINCIPAL "Menu Principal"

#define OPCAO_ERRO "A opção escolhinda não é válida, tente novamente!\n"
#define DADO_INVALIDO "A infomação inserida não é válida, tente novamente!\n"
#define MENU_CADASTRAR_ESTOQUE "Cadastrar Estoque"
#define MENU_CONSULTAR_ESTOQUE "Consultar Estoque"
#define MENU_CADASTRAR_PRODUCAO "Cadastrar Produção"
#define MENU_CONSULTAR_PRODUCAO "Consultar Produção"
#define MENU_CADASTRAR_VENDA "Cadastrar Vendas"
#define MENU_CONSULTAR_VENDA "Consultar Vendas"
#define MENU_RELATORIO "Relatórios"
#define MENU_FINALIZAR "Finalizar"

#define OPCAO_MENU_CADASTRAR_ESTOQUE 1
#define OPCAO_MENU_CONSULTAR_ESTOQUE 2
#define OPCAO_MENU_CADASTRAR_PRODUCAO 3
#define OPCAO_MENU_CONSULTAR_PRODUCAO 4
#define OPCAO_MENU_CADASTRAR_VENDA 5
#define OPCAO_MENU_CONSULTAR_VENDA 6
#define OPCAO_MENU_RELATORIO 7
#define OPCAO_MENU_FINALIZAR 8

#define TOTAL_OPCAO_MENU_PRINCIPAL 8

#define TIPO_UNIDADE "unidades"
#define TIPO_GRAMA "gramas"

#define ARROZ "Arroz"
#define FEIJAO "Feijão"
#define CARNE "Carne"
#define LEGUME "Legume"
#define OVO "Ovo"
#define EMBALAGEM "Embalagem"

#define ARROZ_ID 0
#define FEIJAO_ID 1
#define CARNE_ID 2
#define LEGUME_ID 3
#define OVO_ID 4
#define EMBALAGEM_ID 5

#define TOTAL_INSUMOS 6

#define CODIGO "Código"

#define ID_DIA_DOMINGO 0
#define ID_DIA_SEGUNDA 1
#define ID_DIA_TERCA 2
#define ID_DIA_QUARTA 3
#define ID_DIA_QUINTA 4
#define ID_DIA_SEXTA 5
#define ID_DIA_SABADO 6

#define DIA_DOMINGO "Domingo"
#define DIA_SEGUNDA "Segunda"
#define DIA_TERCA "Terça"
#define DIA_QUARTA "Quarta"
#define DIA_QUINTA "Quinta"
#define DIA_SEXTA "Sexta"
#define DIA_SABADO "Sábado"

#define TOTAL_DIAS_SEMANA 7

#define VALOR_MARMITA_DOMINGO_SABADO 15.99
#define VALOR_MARMITA_DIA_NORMAL 12.99

struct DiaDaSemana {
    int id;
    char *nome;
    int totalMarmitasProduizadas;
    int totalMarmitasVendidas;
};

struct Producao {
    struct DiaDaSemana producaoDiasDaSemana[TOTAL_DIAS_SEMANA];
};

struct Insumo {
    int codigo;
    int quantidade;
    char *nome;
    char *tipoMedia;
};

struct Estoque {
    struct Insumo insumos[TOTAL_INSUMOS];
};

void menuConsultarVendas(struct Producao *producao);

void inicializarEstoque(struct Estoque *estoque);

void mostrarOpcoesDoMenu();

void atualizarInsumo(struct Estoque *estoque, int idDoInsumo);

void imprimirOpcaoDoMenu(int codigo, char *nome);

int selecionarOpcaoDoMenu();

void
opcaoMenuPrincipal(struct Producao *producao, struct Estoque *estoque, int opcaoDoMenuPrincipal);

void cadastrarEstoque(struct Estoque *estoque);

void consultarEstoque(struct Estoque *estoque);

void inicializarProducao(struct Producao *producao);

void cadastrarProducao(struct Producao *producao);

void atualizarProducao(struct Producao *producao, int idDiaDaProducao);

void consultarProducao(struct Producao *producao);

void menuCadastrarVendas(struct Estoque *estoque, struct Producao *producao);

void cadastrarVendas(struct Estoque *estoque, struct DiaDaSemana *diaDaSemana);

void voltarAoMenuAnterior();

void consultarVendaDoDia(struct DiaDaSemana diaDaSemana);

void mostrarMenuProducao(struct Producao *producao, char *opcaoFinal);
