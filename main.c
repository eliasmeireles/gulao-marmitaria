#include "main.h"


/**
 * Elias Meireles
 * Kaique Cairan
 *
 * */

int main() {
    setlocale(LC_ALL, "Portuguese");
    menuPrincipal();
    return 0;
}

//// Imprime o menu principal da aplicação
//// e continuará a execução até que o usuário
//// finalize o programa selecionando a opão pra finalizar.
void menuPrincipal() {
    struct Estoque estoque;
    struct Producao producao;

    inicializarEstoque(&estoque);
    inicializarProducao(&producao);

    int codigoMenu;

    ////Loop que será executado até que o usuário informe um valor
    ////valido para as opções do menu apresentadas ou informe o
    ////valor representante para a finalização do programa.
    do {
        codigoMenu = -1;
        mostrarOpcoesDoMenu();
        printf("\nDas opções acima, informe o código menu: ");
        fflush(stdin);
        scanf("%d", &codigoMenu);
        printf("\n");

        if (codigoMenu < 1 || codigoMenu > 8) {
            printf("\n%s", OPCAO_ERRO);
        } else {
            opcaoMenuPrincipal(&producao, &estoque, codigoMenu);
        }
    } while (codigoMenu != OPCAO_MENU_FINALIZAR);
}

//// Inicializa o estoque com todos os insumos predefinidos
//// com o valor do (tipo de medida) em 0.
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

//// Avalia a opção informada pelo usuário e executa a ação relativa
//// a opção selecionada, se a opção for de finalizar o programa (default da condição do switch case)
//// o programa será finalizado.
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
            imprimirRelatorio(producao, estoque);
            break;
        default:
            printf("\n\n---------------> Finalizando o programa! <---------------\n\n");
    }
}

//// Inicializa a lista de produção semanal com quantidade de
//// marmitas produzidas no dia com o valor em 0.
void inicializarProducao(struct Producao *producao) {
    struct DiaDaSemana domingo = {ID_DIA_DOMINGO, DIA_DOMINGO, 0, 0, VALOR_MARMITA_DOMINGO_SABADO};
    struct DiaDaSemana sengunda = {ID_DIA_SEGUNDA, DIA_SEGUNDA, 0, 0, VALOR_MARMITA_DIA_NORMAL};
    struct DiaDaSemana terca = {ID_DIA_TERCA, DIA_TERCA, 0, 0, VALOR_MARMITA_DIA_NORMAL};
    struct DiaDaSemana quarta = {ID_DIA_QUARTA, DIA_QUARTA, 0, 0, VALOR_MARMITA_DIA_NORMAL};
    struct DiaDaSemana quinta = {ID_DIA_QUINTA, DIA_QUINTA, 0, 0, VALOR_MARMITA_DIA_NORMAL};
    struct DiaDaSemana sexta = {ID_DIA_SEXTA, DIA_SEXTA, 0, 0, VALOR_MARMITA_DIA_NORMAL};
    struct DiaDaSemana sabado = {ID_DIA_SABADO, DIA_SABADO, 0, 0, VALOR_MARMITA_DOMINGO_SABADO};

    producao->producaoDiasDaSemana[0] = domingo;
    producao->producaoDiasDaSemana[1] = sengunda;
    producao->producaoDiasDaSemana[2] = terca;
    producao->producaoDiasDaSemana[3] = quarta;
    producao->producaoDiasDaSemana[4] = quinta;
    producao->producaoDiasDaSemana[5] = sexta;
    producao->producaoDiasDaSemana[6] = sabado;

}

//// Apresenta o menu com as opções do menu com as
//// opções para cadastrar uma produção de um determinado dia da
//// semana ou da semana inteira.
void cadastrarProducao(struct Estoque *estoque, struct Producao *producao) {
    if (!estoqueCarregado(estoque)) {
        printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        printf("IIIIIIIIII Você precisa recarregar seu estoque para cadastrar uma produção!!! IIIIIIIIIIIIIIIIII\n");
        printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        return;
    }

    int opcaoSelecionada;

    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_PRODUCAO);

    imprimirMenuConsultarProducao(producao);

    printf("%s: %d --> Cadastro da semana\n", CODIGO, TOTAL_DIAS_SEMANA + 1);
    printf("Das opções acima, informe o %s para o dia da semana a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);
    printf("\n");

    ////Valida se a opção informada é válida ou não, se não for válida
    ////solicita novamente a entrada de uma opção válida do menu.
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_DIAS_SEMANA + 1) {

        if (opcaoSelecionada == TOTAL_DIAS_SEMANA + 1) {
            printf("\n");
            int idDiaDaSemana;
            for (idDiaDaSemana = 0; idDiaDaSemana < TOTAL_DIAS_SEMANA; ++idDiaDaSemana) {
                atualizarProducao(estoque, producao, idDiaDaSemana);
            }
        } else {
            atualizarProducao(estoque, producao, opcaoSelecionada - 1);
        }
        imprimirDadosDasProducoes(producao);
        voltarAoMenuAnterior();
    } else {
        ////Imprime a mensagem de opção selecionada inválida
        printf(OPCAO_ERRO);

        ////Solicita novamente a entrada de uma opção do menu.
        cadastrarProducao(estoque, producao);
    }
}

///// Imprime o menu com as opção de produção
void imprimirMenuConsultarProducao(struct Producao *producao) {
    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        printf("%s: %d --> %s \n", CODIGO, producao->producaoDiasDaSemana[i].id + 1,
               producao->producaoDiasDaSemana[i].nome);
    }
}

//// Solicita ao usuário do sistema o novo valor em (tipo de medida) para o insumo
//// a ser atualizado no producao.
void atualizarProducao(struct Estoque *estoque, struct Producao *producao, int idDiaDaProducao) {
    printf("\n-> %s -> %s -> Atualizar producao de %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_PRODUCAO,
           producao->producaoDiasDaSemana[idDiaDaProducao].nome);
    int marmitasProduzidas = -1;
    printf("Informe a quantidade de marmitas produzidas em %s: ",
           producao->producaoDiasDaSemana[idDiaDaProducao].nome);

    fflush(stdin);
    scanf("%d", &marmitasProduzidas);

    printf("\n");
    if (marmitasProduzidas >= 0) {

        if (podeCadastrarProducao(estoque, marmitasProduzidas)) {
            producao->producaoDiasDaSemana[idDiaDaProducao].totalMarmitasProduizadas = marmitasProduzidas;

            atualizaEstoque(estoque, marmitasProduzidas);
        } else {
            printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
            printf("IIIIIIII Você não tem insumo o suficiente para a produção de %d marmitas!!! IIIIIIII\n",
                   marmitasProduzidas);
            printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n\n");

            printf("Deseja atualizar seu estualizar seu estoque agora? SIM --> 1, NÂO --> qualquer coisa: ");

            int opcaoSelecionada;

            scanf("%d", &opcaoSelecionada);

            printf("\n");
            if (opcaoSelecionada == 1) {
                cadastrarEstoque(estoque);
                atualizarProducao(estoque, producao, idDiaDaProducao);
            }
        }

    } else {
        printf(DADO_INVALIDO);
        atualizarProducao(estoque, producao, idDiaDaProducao);
    }
}

/// Atualiza a quantidade disponivel em estoque do insumos
/// com base na quantia de marmitas produzidas.
void atualizaEstoque(struct Estoque *estoque, int marmitasProduzidas) {
    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        struct Insumo *insumo = &estoque->insumos[i];
        int insumoGasto = insumo->quantiaPorMarmita * marmitasProduzidas;
        insumo->quantidadeEmEstoque = insumo->quantidadeEmEstoque - insumoGasto;
    }
}


///// Verifica o tem insumo o suficiente para produzir a quantias
///// de marmitas informada
bool podeCadastrarProducao(struct Estoque *estoque, int quantiaDeMarmitas) {
    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        struct Insumo insumo = estoque->insumos[i];
        int insumoNescerrario = insumo.quantiaPorMarmita * quantiaDeMarmitas;

        if (insumoNescerrario > insumo.quantidadeEmEstoque) {
            return false;
        }
    }
    return true;
}

///// Imprime as informações da produção do dia da semana
///// informando o nome do dia da semana e a quantia de
///// marmitas produzidas.
void consultarProducao(struct Producao *producao) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CONSULTAR_PRODUCAO);

    int opcaoSelecionada;
    imprimirMenuConsultarProducao(producao);

    printf("%s: %d --> Consulta da semana\n", CODIGO, TOTAL_DIAS_SEMANA + 1);
    printf("Das opções acima, informe o %s para o dia da semana a ser consultado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);
    printf("\n");

    ///// Valida se a opção informada é válida ou não, se não for válida
    ///// solicita novamente a entrada de uma opção válida do menu.
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_DIAS_SEMANA + 1) {

        if (opcaoSelecionada == TOTAL_DIAS_SEMANA + 1) {
            printf("\n");
            imprimirDadosDasProducoes(producao);
        } else {
            printf("\n");
            struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[opcaoSelecionada - 1];
            imprimirDadosDaProducao(&diaDaSemana);
        }
    } else {
        printf(OPCAO_ERRO);
        consultarProducao(producao);
    }
    voltarAoMenuAnterior();
}

///// Imprime os dados da produção semanal
void imprimirDadosDasProducoes(struct Producao *producao) {
    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];
        imprimirDadosDaProducao(&diaDaSemana);
    }
}

///// Imprime os dados da produção do dias
void imprimirDadosDaProducao(struct DiaDaSemana *diaDaSemana) {
    printf("Dia: %s - Marmitas produzidas: %d\n", (*diaDaSemana).nome, (*diaDaSemana).totalMarmitasProduizadas);
}


void voltarAoMenuAnterior() {
    printf("\n\nPrescione ENTER para voltar ao %s: ", MENU_PRINCIPAL);
    char continua[1];
    fflush(stdin);
    scanf("%1[^\n]s", continua);
}

/// Verifica se tem insumo para o cadastro de ao menos uma marmita.
bool estoqueCarregado(struct Estoque *estoque) {
    int posicaoInsumo;

    for (posicaoInsumo = 0; posicaoInsumo < TOTAL_INSUMOS; posicaoInsumo++) {
        struct Insumo insumo = estoque->insumos[posicaoInsumo];
        if (insumo.quantidadeEmEstoque < insumo.quantiaPorMarmita) {
            return false;
        }
    }
    return true;
}

///// Imprime o menu com as opções disponíveis de insumos
///// no estoque a ser atualizado.
void cadastrarEstoque(struct Estoque *estoque) {
    int opcaoSelecionada;

    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_ESTOQUE);

    menuOpcoesInsumo(estoque);

    printf("%s: %d --> Atulizar todos\n\n", CODIGO, TOTAL_INSUMOS + 1);
    printf("Das opções acima, informe o %s para o insumo a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);
    printf("\n");

    ////Valida a opção selecionada.
    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_INSUMOS + 1) {

        if (opcaoSelecionada == TOTAL_INSUMOS + 1) {
            printf("\n");
            int idDoConsumo;

            ///// Para cada insumo no estoque, será solicitado a nova quantia (válida) em
            ///// gramas ou unidade para o insumo.
            for (idDoConsumo = 0; idDoConsumo < TOTAL_INSUMOS; ++idDoConsumo) {
                atualizarInsumo(estoque, idDoConsumo);
            }
        } else {
            atualizarInsumo(estoque, opcaoSelecionada - 1);
        }

        ////Após concluir a atualização do estoque, imprime os
        ////dados dos insumos do estoque.
        imprimirDadosDoEstoque(estoque);
        voltarAoMenuAnterior();
    } else {
        ////Se a opção selecionada não for válida
        ////será imprimida a mensagem de erro de opção inválida
        printf(OPCAO_ERRO);

        ////Solicita novamente a entrada de uma opção de insumo a ser atualizado.
        cadastrarEstoque(estoque);
    }
}

//// Imprime as opções do menu de insumos.
void menuOpcoesInsumo(struct Estoque *estoque) {
    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        printf("%s: %d --> %s \n", CODIGO, estoque->insumos[i].codigo + 1, estoque->insumos[i].nome);
    }
}

//// Solicita ao usuário do sistema o novo valor em (tipo de medida) para o insumo
//// a ser atualizado no estoque.
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
        estoque->insumos[idDoInsumo].quantidadeEmEstoque += quantidadeInformada;
    } else {
        printf(DADO_INVALIDO);
        atualizarInsumo(estoque, idDoInsumo);
    }
}

//// Para cada insumo em estoque, será imprimido a
//// informação do nome e (tipo de media do insumo)
//// com o valor atual
void consultarEstoque(struct Estoque *estoque) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CONSULTAR_ESTOQUE);

    menuOpcoesInsumo(estoque);

    int opcaoSelecionada;
    printf("%s: %d --> Consultar todos\n\n", CODIGO, TOTAL_INSUMOS + 1);
    printf("Das opções acima, informe o %s para o insumo a ser consultado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    printf("\n");

    if (opcaoSelecionada > 0 && opcaoSelecionada <= TOTAL_INSUMOS + 1) {
        if (opcaoSelecionada == TOTAL_INSUMOS + 1) {
            imprimirDadosDoEstoque(estoque);
        } else {
            struct Insumo insumo = estoque->insumos[opcaoSelecionada - 1];
            imprimirInsumo(&insumo);
        }
    } else {
        printf(OPCAO_ERRO);
        consultarEstoque(estoque);
    }

    voltarAoMenuAnterior();
}

//// Imprime os dados de todos os insumos cadastrados.
void imprimirDadosDoEstoque(struct Estoque *estoque) {
    printf("\n");
    int i;
    for (i = 0; i < TOTAL_INSUMOS; ++i) {
        struct Insumo insumo = estoque->insumos[i];
        imprimirInsumo(&insumo);
    }
}

//// Imprime os dados do insumo
void imprimirInsumo(struct Insumo *insumo) {
    printf("%s --> Quantidade em estoque: %d %s\n", insumo->nome,
           insumo->quantidadeEmEstoque, insumo->tipoMedia);
}

//// Imprime o submenu MENU_CADASTRAR_VENDA
void menuCadastrarVendas(struct Estoque *estoque, struct Producao *producao) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_VENDA);

    mostrarMenuProducao(producao, "Atualizar todos");

    int opcaoSelecionada;

    printf("Das opções acima, informe o %s para o dia a ser atualizado: ", CODIGO);
    fflush(stdin);
    scanf("%d", &opcaoSelecionada);

    ////Valida a opção informada
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

/// Opção para o cadastro de vendas ou de uma venda.
void cadastrarVendas(struct Estoque *estoque, struct DiaDaSemana *diaDaSemana) {
    printf("\n-> %s -> %s -> de %s\n\n", MENU_PRINCIPAL, MENU_CADASTRAR_VENDA, diaDaSemana->nome);
    int quantiaInformada = -1;

    printf("Informe quantidade de marmitas vendidas em %s: ", diaDaSemana->nome);
    fflush(stdin);
    scanf("%d", &quantiaInformada);

    if (quantiaInformada >= 0 && quantiaInformada <= diaDaSemana->totalMarmitasProduizadas) {
        diaDaSemana->totalMarmitasVendidas = quantiaInformada;
    } else {
        printf("\nIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        printf("IIIIII A quantidade de marmitas vendidas não pode ser superior à quantidade de marmitas produzidas!!! IIIIIIIIIII\n");
        printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
        cadastrarVendas(estoque, diaDaSemana);
    }
}

/// Ação para cunsultar vendas ou venda.
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

///// Imprime o dados da produção do dia
void consultarVendaDoDia(struct DiaDaSemana diaDaSemana) {
    printf("\n\n");
    printf("Dia ----------------------> %s\n", diaDaSemana.nome);
    printf("Marmitas produzidas ------> %d\n", diaDaSemana.totalMarmitasProduizadas);
    printf("Marmitas Vendidas --------> %d\n", diaDaSemana.totalMarmitasVendidas);

    double valorTotalVendido = (double) diaDaSemana.totalMarmitasVendidas * diaDaSemana.valorDaMarmita;
    printf("Valor total de venda: ----> R$ %.2lf", valorTotalVendido);
}

///// Imprime o menu da opções para produção.
void mostrarMenuProducao(struct Producao *producao, char *opcaoFinal) {
    int i;
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];
        printf("%s: %d --> Dia: %s\n", CODIGO, diaDaSemana.id + 1, diaDaSemana.nome);
    }
    printf("%s: %d --> %s\n", CODIGO, TOTAL_DIAS_SEMANA + 1, opcaoFinal);
}

//// Imprimi as opções do menu principal da apliação.
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

/// Imprime as opções do menu principal formatado
void imprimirOpcaoDoMenu(int codigo, char *nome) {
    printf("%s: %d --> %s\n", CODIGO, codigo, nome);
}

///// Imprime o relatório da semana
void imprimirRelatorio(struct Producao *producao, struct Estoque *estoque) {
    printf("\n-> %s -> %s\n\n", MENU_PRINCIPAL, MENU_RELATORIO);

    int totalMarmitasProduzidas = 0;
    int totalMarmitasVendidas = 0;
    double totalValorVendas = 0;
    double totalValorPrejuizo = 0;

    struct DiaDaSemana diaMenorVenda = producao->producaoDiasDaSemana[0];
    struct DiaDaSemana diaMenorProducao = producao->producaoDiasDaSemana[0];
    struct DiaDaSemana diaMaiorProducao = producao->producaoDiasDaSemana[0];
    struct DiaDaSemana diaMaiorVenda = producao->producaoDiasDaSemana[0];

    int i;

    ///// Alaliza os dados dos dias de produção
    for (i = 0; i < TOTAL_DIAS_SEMANA; ++i) {
        struct DiaDaSemana diaDaSemana = producao->producaoDiasDaSemana[i];

        totalMarmitasProduzidas += diaDaSemana.totalMarmitasProduizadas + diaDaSemana.totalMarmitasVendidas;
        totalMarmitasVendidas += diaDaSemana.totalMarmitasVendidas;
        totalValorVendas += diaDaSemana.totalMarmitasVendidas * diaDaSemana.valorDaMarmita;
        totalValorVendas += diaDaSemana.totalMarmitasVendidas * diaDaSemana.valorDaMarmita;

        totalValorPrejuizo +=
                (diaDaSemana.totalMarmitasProduizadas - diaDaSemana.totalMarmitasVendidas) * diaDaSemana.valorDaMarmita;
        ///// Pega o dia com a menor venda de marmitas.
        if (diaDaSemana.totalMarmitasVendidas < diaMenorVenda.totalMarmitasVendidas) {
            diaMenorVenda = diaDaSemana;
        }

        ///// Pega o dia com a maior venda de marmitas.
        if (diaDaSemana.totalMarmitasVendidas > diaMaiorVenda.totalMarmitasVendidas) {
            diaMaiorVenda = diaDaSemana;
        }

        ///// Pega o dia com a menor produção de marmitas.
        if (diaDaSemana.totalMarmitasProduizadas < diaMenorProducao.totalMarmitasProduizadas) {
            diaMenorProducao = diaDaSemana;
        }

        ///// Pega o dia com a mior produção de marmitas.
        if (diaDaSemana.totalMarmitasProduizadas > diaMaiorProducao.totalMarmitasProduizadas) {
            diaMaiorProducao = diaDaSemana;
        }

    }

    int mediaProducaoMarmitas = round(totalMarmitasProduzidas / TOTAL_DIAS_SEMANA);
    int mediaVendaMarmitas = round(totalMarmitasVendidas / TOTAL_DIAS_SEMANA);
    double mediaValorVenda = totalValorVendas / TOTAL_DIAS_SEMANA;

    printf("Valor total em vendas ------------> R$ %.2lf \n", totalValorVendas);
    printf("Marmitas vendidas ----------------> %d \n", totalMarmitasVendidas);
    printf("Marmitas produzidas --------------> %d \n", totalMarmitasProduzidas);
    printf("Prejuízo -------------------------> R$ %.2lf \n\n", totalValorPrejuizo);

    printf("Média de marmitas produzidas -----> %d \n", mediaProducaoMarmitas);
    printf("Média de marmitas vendidass-------> %d \n", mediaVendaMarmitas);
    printf("Média de venda de marmitas -------> R$ %.2lf \n\n", mediaValorVenda);

    printf("Maior produção -------------------> %s - Marmitas produzidas: %d\n", diaMaiorVenda.nome,
           diaMaiorVenda.totalMarmitasProduizadas);

    printf("Menor produção -------------------> %s - Marmitas produzidas: %d\n", diaMenorProducao.nome,
           diaMenorProducao.totalMarmitasProduizadas);

    printf("Maior venda ----------------------> %s - Marmitas vendidas: %d\n", diaMaiorVenda.nome,
           diaMaiorVenda.totalMarmitasVendidas);

    printf("Valor maior venda-----------------> %s - R$ %.2f\n", diaMaiorVenda.nome,
           diaMaiorVenda.totalMarmitasVendidas * diaMaiorVenda.valorDaMarmita);

    printf("Menor venda ----------------------> %s - Marmitas vendidas: %d\n", diaMenorVenda.nome,
           diaMenorVenda.totalMarmitasVendidas);

    printf("Valor menor venda ----------------> %s - R$ %.2f\n", diaMenorVenda.nome,
           diaMenorVenda.totalMarmitasVendidas * diaMenorVenda.valorDaMarmita);


    printf("\n-------- Estatus do Estoque --------\n");

    imprimirDadosDoEstoque(estoque);
    voltarAoMenuAnterior();
}