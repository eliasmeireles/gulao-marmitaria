#include "main.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    return selecionarOpcaoDoMenu();
}

// Imprime o menu principal da aplicação
// e continuará a execução até que o usuário
// finalize o programa selecionando a opão pra finalizar.
int selecionarOpcaoDoMenu() {
    struct Estoque estoque;
    struct Producao producao;

    inicializarEstoque(&estoque);
    inicializarProducao(&producao);

    int opcaoMenuSelecionada;

    // Loop que será executado até que o usuário informe um valor
    // valido para as opções do menu apresentadas ou informe o
    // valor representante para a finalização do programa.
    do {
        opcaoMenuSelecionada = -1;
        mostrarOpcoesDoMenu();
        printf("\nDas opções acima, informe o código menu: ");
        fflush(stdin);
        scanf("%d", &opcaoMenuSelecionada);

        if (opcaoMenuSelecionada < 1 || opcaoMenuSelecionada > 8) {
            printf("\n%s", OPCAO_ERRO);
        } else {
            opcaoMenuPrincipal(&producao, &estoque, opcaoMenuSelecionada);
        }
    } while (opcaoMenuSelecionada != OPCAO_MENU_FINALIZAR);
    return 0;
}

// Inicializa o estoque com todos os insumos predefinidos
// com o valor do (tipo de medida) em 0.
void inicializarEstoque(struct Estoque *estoque) {
    struct Insumo arroz = {ARROZ_ID, 0, 120, ARROZ, TIPO_GRAMA};
    struct Insumo feijao = {FEIJAO_ID, 0, 80, FEIJAO, TIPO_GRAMA};
    struct Insumo carne = {CARNE_ID, 0, 120, CARNE, TIPO_GRAMA};
    struct Insumo legume = {LEGUME_ID, 0, 120, LEGUME, TIPO_GRAMA};
    struct Insumo ovo = {OVO_ID, 0, 1, OVO, TIPO_UNIDADE};
    struct Insumo embalagem = {EMBALAGEM_ID, 0, 1, EMBALAGEM, TIPO_UNIDADE};

    estoque->insumos[0] = arroz;
    estoque->insumos[1] = feijao;
    estoque->insumos[2] = carne;
    estoque->insumos[3] = legume;
    estoque->insumos[4] = ovo;
    estoque->insumos[5] = embalagem;
}

// Avalia a opção informada pelo usuário e executa a ação relativa
// a opção selecionada, se a opção for de finalizar o programa (default da condição do switch case)
// o programa será finalizado.
void opcaoMenuPrincipal(struct Producao *producao, struct Estoque *estoque, int opcaoDoMenuPrincipal) {
    switch (opcaoDoMenuPrincipal) {
        case OPCAO_MENU_CADASTRAR_ESTOQUE:
            cadastrarEstoque(estoque);
            break;
        case OPCAO_MENU_CONSULTAR_ESTOQUE:
            consultarEstoque(estoque);
            break;
        case OPCAO_MENU_CADASTRAR_PRODUCAO:
            cadastrarProducao(estoque, producao);
            break;
        case OPCAO_MENU_CONSULTAR_PRODUCAO:
            consultarProducao(producao);
            break;
        case OPCAO_MENU_CADASTRAR_VENDA:
            menuCadastrarVendas(estoque, producao);
            break;
        case OPCAO_MENU_CONSULTAR_VENDA:
            menuConsultarVendas(producao);
            break;
        case OPCAO_MENU_RELATORIO:
            printf(MENU_RELATORIO);
            break;
        default:
            printf("---------------> Finalizando o programa! <---------------");
    }
}

// Inicializa a lista de produção semanal com quantidade de
// marmitas produzidas no dia com o valor em 0.
void inicializarProducao(struct Producao *producao) {
    struct DiaDaSemana domingo = {ID_DIA_DOMINGO, DIA_DOMINGO, 0, 0};
    struct DiaDaSemana sengunda = {ID_DIA_SEGUNDA, DIA_SEGUNDA, 0, 0};
    struct DiaDaSemana terca = {ID_DIA_TERCA, DIA_TERCA, 0, 0};
    struct DiaDaSemana quarta = {ID_DIA_QUARTA, DIA_QUARTA, 0, 0};
    struct DiaDaSemana quinta = {ID_DIA_QUINTA, DIA_QUINTA, 0, 0};
    struct DiaDaSemana sexta = {ID_DIA_SEXTA, DIA_SEXTA, 0, 0};
    struct DiaDaSemana sabado = {ID_DIA_SABADO, DIA_SABADO, 0, 0};

    producao->producaoDiasDaSemana[0] = domingo;
    producao->producaoDiasDaSemana[1] = sengunda;
    producao->producaoDiasDaSemana[2] = terca;
    producao->producaoDiasDaSemana[3] = quarta;
    producao->producaoDiasDaSemana[4] = quinta;
    producao->producaoDiasDaSemana[5] = sexta;
    producao->producaoDiasDaSemana[6] = sabado;

}

// Apresenta o menu com as opções do menu com as
// opções para cadastrar uma produção de um determinado dia da
// semana ou da semana inteira.
void cadastrarProducao(struct Estoque *estoque, struct Producao *producao) {
    if (!estoqueCarregado(estoque)) {
        printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        printf("IIIIIIIIII Você precisa recarregar seu estoque para cadastrar uma produção!!! IIIIIIIIIIIIIIIIII\n");
        printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        return;
    }

    int opcaoSelecionada;

    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_PRODUCAO);

    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        printf("%s: %d --> %s \n", CODIGO, producao->producaoDiasDaSemana[i].id + 1,
               producao->producaoDiasDaSemana[i].nome);
    }

    printf("%s: %d --> Cadastro da semena\n", CODIGO, TOTAL_DIAS_SEMANA + 1);
    printf("Das opções acima, informe o %s para o dia da semana a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    // Valida se a opção informada é válida ou não, se não for válida
    // solicita novamente a entrada de uma opção válida do menu.
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_DIAS_SEMANA + 1) {

        if (opcaoSelecionada == TOTAL_DIAS_SEMANA + 1) {
            printf("\n");
            int idDiaDaSemana;
            for (idDiaDaSemana = 0; idDiaDaSemana < TOTAL_DIAS_SEMANA; ++idDiaDaSemana) {
                atualizarProducao(estoque, producao, idDiaDaSemana);
            }
        } else {
            atualizarProducao(estoque, producao, opcaoSelecionada);
        }
        consultarProducao(producao);
    } else {
        // Imprime a mensagem de opção selecionada inválida
        printf(OPCAO_ERRO);

        // Solicita novamente a entrada de uma opção do menu.
        cadastrarProducao(estoque, producao);
    }
}

// Solicita ao usuário do sistema o novo valor em (tipo de medida) para o insumo
// a ser atualizado no producao.
void atualizarProducao(struct  Estoque *estoque, struct Producao *producao, int idDiaDaProducao) {
    printf("\n-> %s -> %s -> Atualizar producao de %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_PRODUCAO,
           producao->producaoDiasDaSemana[idDiaDaProducao].nome);
    int quantidadeInformada = -1;
    printf("Informe a quantidade de marmitas produzidas em %s: ",
           producao->producaoDiasDaSemana[idDiaDaProducao].nome);

    fflush(stdin);
    scanf("%d", &quantidadeInformada);

    printf("\n");
    if (quantidadeInformada >= 0) {
        producao->producaoDiasDaSemana[idDiaDaProducao].totalMarmitasProduizadas = quantidadeInformada;
    } else {
        printf(DADO_INVALIDO);
        atualizarProducao(estoque, producao, idDiaDaProducao);
    }
}

bool podeCadastrarProducao(struct Estoque *estoque, int quantiaDeMarmitas) {

}

// Imprime as informações da produção do dia da semana
// informando o nome do dia da semana e a quantia de
// marmitas produzidas.
void consultarProducao(struct Producao *producao) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CONSULTAR_PRODUCAO);

    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];
        printf("Dia: %s - Marmitas produzidas: %d\n", diaDaSemana.nome, diaDaSemana.totalMarmitasProduizadas);
    }
    voltarAoMenuAnterior();
}


void voltarAoMenuAnterior() {
    printf("\n\nDigite qualque coisa e precione ENTER para voltar ao menu %s: ", MENU_PRINCIPAL);
    char continua;
    fflush(stdin);
    scanf("%s", &continua);
}

bool estoqueCarregado(struct Estoque *estoque) {
    bool estoqueEstaCarregado = true;
    int posicaoInsumo;

    for (posicaoInsumo = 0; posicaoInsumo < TOTAL_INSUMOS; posicaoInsumo++) {
        struct Insumo insumo = estoque->insumos[posicaoInsumo];
        if (insumo.quantidadeEmEstoque < insumo.quantiaPorMarmita) {
            estoqueEstaCarregado = false;
        }
    }
    return estoqueEstaCarregado;
}

// Imprime o menu com as opções disponíveis de insumos
// no estoque a ser atualizado.
void cadastrarEstoque(struct Estoque *estoque) {
    int opcaoSelecionada;

    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_ESTOQUE);

    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        printf("%s: %d --> %s \n", CODIGO, estoque->insumos[i].codigo + 1, estoque->insumos[i].nome);
    }

    printf("%s: %d --> Atulizar todos\n\n", CODIGO, TOTAL_INSUMOS + 1);
    printf("Das opções acima, informe o %s para o insumo a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    // Valida a opção selecionada.
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_INSUMOS + 1) {

        if (opcaoSelecionada == TOTAL_INSUMOS + 1) {
            printf("\n");
            int idDoConsumo;

            // Para cada insumo no estoque, será solicitado a nova quantia (válida) em
            // gramas ou unidade para o insumo.
            for (idDoConsumo = 0; idDoConsumo < TOTAL_INSUMOS; ++idDoConsumo) {
                atualizarInsumo(estoque, idDoConsumo);
            }
        } else {
            atualizarInsumo(estoque, opcaoSelecionada - 1);
        }

        // Após concluir a atualização do estoque, imprime os
        // dados dos insumos do estoque.
        consultarEstoque(estoque);
    } else {
        // Se a opção selecionada não for válida
        // será imprimida a mensagem de erro de opção inválida
        printf(OPCAO_ERRO);

        // Solicita novamente a entrada de uma opção de insumo a ser atualizado.
        cadastrarEstoque(estoque);
    }
}

// Solicita ao usuário do sistema o novo valor em (tipo de medida) para o insumo
// a ser atualizado no estoque.
void atualizarInsumo(struct Estoque *estoque, int idDoInsumo) {
    printf("\n-> %s -> %s -> Atualizar insumo %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_ESTOQUE,
           estoque->insumos[idDoInsumo].nome);
    int quantidadeInformada = -1;
    printf("Informe a quantidade (em %s) para %s no estoque: ",
           estoque->insumos[idDoInsumo].tipoMedia,
           estoque->insumos[idDoInsumo].nome);

    fflush(stdin);
    scanf("%d", &quantidadeInformada);

    printf("\n");
    if (quantidadeInformada >= 0) {
        estoque->insumos[idDoInsumo].quantidadeEmEstoque = quantidadeInformada;
    } else {
        printf(DADO_INVALIDO);
        atualizarInsumo(estoque, idDoInsumo);
    }
}

// Para cada insumo em estoque, será imprimido a
// informação do nome e (tipo de media do insumo)
// com o valor atual
void consultarEstoque(struct Estoque *estoque) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CONSULTAR_ESTOQUE);

    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        struct Insumo insumo = estoque->insumos[i];
        printf("%s --> Quantidade em estoque: %d %s\n", insumo.nome,
               insumo.quantidadeEmEstoque, insumo.tipoMedia);
    }
    voltarAoMenuAnterior();
}

// Imprime o submenu MENU_CADASTRAR_VENDA
void menuCadastrarVendas(struct Estoque *estoque, struct Producao *producao) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_VENDA);

    mostrarMenuProducao(producao, "Atualizar todos");

    int opcaoSelecionada;

    printf("Das opções acima, informe o %s para o dia a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    // Valida a opção informada
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_DIAS_SEMANA + 1) {

        if (opcaoSelecionada == TOTAL_DIAS_SEMANA + 1) {
            int posicaoDiaDaSemana;
            for (posicaoDiaDaSemana = 0; posicaoDiaDaSemana < TOTAL_DIAS_SEMANA; ++posicaoDiaDaSemana) {
                struct DiaDaSemana *diaDaSemana = &producao->producaoDiasDaSemana[posicaoDiaDaSemana];
                cadastrarVendas(estoque, diaDaSemana);
            }
        } else {
            cadastrarVendas(estoque, &producao->producaoDiasDaSemana[opcaoSelecionada - 1]);
        }
    } else {
        printf(OPCAO_ERRO);
        menuCadastrarVendas(estoque, producao);
    }
}

void cadastrarVendas(struct Estoque *estoque, struct DiaDaSemana *diaDaSemana) {
    printf("\n-> %s -> %s -> de %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_VENDA, diaDaSemana->nome);
    int quantiaInformada = -1;

    printf("Informe quantidade de marmitas vendidas em %s: ", diaDaSemana->nome);
    fflush(stdin);
    scanf("%d", &quantiaInformada);

    if (quantiaInformada >= 0 && quantiaInformada <= diaDaSemana->totalMarmitasProduizadas) {
        diaDaSemana->totalMarmitasVendidas = quantiaInformada;
    } else {
        printf("O valor informado não é válido!\n\n");
        cadastrarVendas(estoque, diaDaSemana);
    }
}

void menuConsultarVendas(struct Producao *producao) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CONSULTAR_PRODUCAO);
    mostrarMenuProducao(producao, "Consultar todos os dias");
    int opcaoSelecionada;

    printf("Das opções acima, informe o %s para o dia a ser consultado: ", CODIGO);

    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    if (opcaoSelecionada >= 0 && opcaoSelecionada <= TOTAL_DIAS_SEMANA + 1) {
        if (opcaoSelecionada != TOTAL_DIAS_SEMANA + 1) {
            struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[opcaoSelecionada - 1];
            consultarVendaDoDia(diaDaSemana);
        } else {
            int i;
            for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
                struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];
                consultarVendaDoDia(diaDaSemana);
            }
            voltarAoMenuAnterior();
        }
    } else {
        printf(OPCAO_ERRO);
        menuConsultarVendas(producao);
    }

}

void consultarVendaDoDia(const struct DiaDaSemana diaDaSemana) {
    printf("\n");
    printf("Dia ----------------------> %s\n", diaDaSemana.nome);
    printf("Marmitas produzidas ------> %d\n", diaDaSemana.totalMarmitasProduizadas);
    printf("Marmitas Vendidas --------> %d\n", diaDaSemana.totalMarmitasVendidas);

    float valorDaMarmita = VALOR_MARMITA_DIA_NORMAL;

    if (diaDaSemana.id == ID_DIA_SABADO || diaDaSemana.id == ID_DIA_DOMINGO) {
        valorDaMarmita = VALOR_MARMITA_DOMINGO_SABADO;
    }

    double valorTotalVendido = (double) diaDaSemana.totalMarmitasVendidas * valorDaMarmita;
    printf("Valor total de venda: ----> R$ %.2lf", valorTotalVendido);
}

void mostrarMenuProducao(struct Producao *producao, char *opcaoFinal) {
    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];
        printf("%s: %d --> Dia: %s\n", CODIGO, diaDaSemana.id + 1, diaDaSemana.nome);
    }
    printf("%s: %d --> %s\n", CODIGO, TOTAL_DIAS_SEMANA + 1, opcaoFinal);
}

// Imprimi as opções do menu principal da apliação.
void mostrarOpcoesDoMenu() {
    printf("\n\n-------- Menu Principal --------\n\n");
    imprimirOpcaoDoMenu(OPCAO_MENU_CADASTRAR_ESTOQUE, MENU_CADASTRAR_ESTOQUE);
    imprimirOpcaoDoMenu(OPCAO_MENU_CONSULTAR_ESTOQUE, MENU_CONSULTAR_ESTOQUE);
    imprimirOpcaoDoMenu(OPCAO_MENU_CADASTRAR_PRODUCAO, MENU_CADASTRAR_PRODUCAO);
    imprimirOpcaoDoMenu(OPCAO_MENU_CONSULTAR_PRODUCAO, MENU_CONSULTAR_PRODUCAO);
    imprimirOpcaoDoMenu(OPCAO_MENU_CADASTRAR_VENDA, MENU_CADASTRAR_VENDA);
    imprimirOpcaoDoMenu(OPCAO_MENU_CONSULTAR_VENDA, MENU_CONSULTAR_VENDA);
    imprimirOpcaoDoMenu(OPCAO_MENU_RELATORIO, MENU_RELATORIO);
    imprimirOpcaoDoMenu(OPCAO_MENU_FINALIZAR, MENU_FINALIZAR);
}

void imprimirOpcaoDoMenu(int codigo, char *nome) {
    printf("%s: %d --> %s\n", CODIGO, codigo, nome);
}