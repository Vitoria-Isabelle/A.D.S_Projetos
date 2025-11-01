#include <stdio.h>

int main() {
    char filmes[15][80] = { // Lista de filmes estreiados em Maio de 2025
        "Missao: Impossivel - O Acerto Final",
        "Thunderbolts",
        "Lilo & Stitch (Live-action)",
        "Karate Kid: Lendas",
        "Premonicao 6: Lacos de Sangue",
        "Detetive Chinatown: O Misterio de 1900",
        "Confinado",
        "O Esquema Fenicio (Wes Anderson)",
        "A Mulher no Jardim",
        "Hurry Up Tomorrow: Alem dos Holofotes",
        "Os 80 Gigantes (documentario brasileiro)",
        "As Quatro Estacoes da Juventude",
        "Manas (drama da Ilha do Marajo)",
        "Ernest Cole: Achados e Perdidos",
        "Ritas (documentario sobre Rita Lee)"
    };

    char data_de_lancamento[15][10] = {
        "22/05", "01/05", "22/05", "08/05", "15/08",
        "15/05", "29/05", "29/05", "08/05", "15/05",
        "08/05", "15/05", "15/05", "29/05", "22/05"
    };

    char duracao_do_filme[15][10] = {
        "2h00", "2h06", "2h39", "1h58", "1h40",
        "2h18", "1h35", "1h41", "1h25", "1h45",
        "1h15", "1h39", "1h41", "1h45", "1h23"
    };

    char vendas[15][20] = {
        "540 milhoes", "272 milhoes", "61 milhoes", "47 milhoes", "187 milhoes",
        "1 bilhao", "N/A", "N/A", "N/A", "N/A",
        "N/A", "N/A", "N/A", "N/A", "N/A"
    };

    char lista[5][50] = { // Inicio: referente a lista de filmes mais e menos assistido.
        "Lilo & Stitch",
        "Thunderbolts",
        "Premonicao 6",
        "Missao: Impossivel",
        "Karate Kid"
    };

    int publico[6] = {
        5730000,
        2000000,
        361120,
        259980,
        39290
    };

    int tamanho = 50000; // Fim: referente a lista de filmes mais e menos assistido.

    int opcao;

    do {
    	
    	printf("=====================================\n");
        printf("\nBem-vinde ao CinePop!\nA plataforma para quem ama analisar estatisticas do mundo cinematografico\n\n");
        printf("=====================================\n");
    
        printf("\nO que deseja ver: \n");
        printf("1. Estreia de filmes em Maio de 2025.\n");
        printf("2. Lista de estreias em Maio com mais e menos espectadores.\n");
        printf("3. Sair\n");
        printf("\n\nEscolha uma opcao: \n\n");
        scanf("%d", &opcao);
    
	    switch (opcao) { // Formação da tabela
            case 1:
                printf("--------------------------------------------------------------------------------------------\n");
                printf("| %-2s | %-45s | %-8s | %-8s | %-15s |\n", "ID", "Filme", "Data de lancamento", "Duracao", "Vendas");
                printf("--------------------------------------------------------------------------------------------\n");

                for (int i = 0; i < 15; i++) {
                    printf("| %-2d | %-45s | %-8s | %-8s | %-15s |\n",
                           i + 1, filmes[i], data_de_lancamento[i], duracao_do_filme[i], vendas[i]);
                }

                printf("--------------------------------------------------------------------------------------------\n\n");
                
                break;

            case 2: // Bar Chart 
                printf("\n\nDentre os lancamentos de Maio de 2025, listamos os mais e menos assistidos baseado no publico brasileiro\n\n");
                printf("Grafico de Barras - Publico nos Cinemas\n\n");

                for (int a = 0; a < 5; a++) {
                int blocos = publico[a] / tamanho;

                printf("%-25s | ", lista[a]);

                for (int b = 0; b < blocos; b++) {
                printf("|");
            }

                printf(" %d\n", publico[a]);
        }
                break;

            case 3: 
                printf("\n\nEncerrando a plataforma CinePop. Volte sempre!\n");
                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}