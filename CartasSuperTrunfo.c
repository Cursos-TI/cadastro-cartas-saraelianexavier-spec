#include <stdio.h>

// Definição da estrutura da Carta/Cidade
struct CartaCidade {
    char codigo[4];
    long long populacao;
    double area;
    double pib;
    int pontos_turisticos;
};

// --- Funções de Ajuda ---

// Função para cadastrar uma única carta
void cadastrar_carta(struct CartaCidade *carta, const char *cod) {
    // Copia o código para a struct
    // (Em C 'pura', seria necessário usar <string.h> e a função strcpy.
    // Para o escopo deste desafio, vamos simular a atribuição direta ou pedir o input do usuário)

    // Simulando a atribuição direta do código (assumindo que já está definido, como 'A01')
    // Se fosse necessário input para o código: scanf("%s", carta->codigo);
    sprintf(carta->codigo, "%s", cod);

    printf("\n--- Cadastro da Carta %s ---\n", carta->codigo);

    // 1. População (long long para números grandes)
    printf("Digite a População (Ex: 1500000): ");
    // O '&' é importante para passar o endereço da variável para o scanf
    scanf("%lld", &carta->populacao);

    // 2. Área (double para valores com casas decimais)
    printf("Digite a Área em km² (Ex: 120.5): ");
    scanf("%lf", &carta->area);

    // 3. PIB (double, representando bilhões/trilhões, dependendo da unidade)
    printf("Digite o PIB (Ex: 50.7 - em Bilhões, por exemplo): ");
    scanf("%lf", &carta->pib);

    // 4. Número de Pontos Turísticos (int)
    printf("Digite o Número de Pontos Turísticos (Ex: 25): ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibir_carta(const struct CartaCidade *carta) {
    printf("\n============================================\n");
    printf("         DADOS DA CARTA: %s\n", carta->codigo);
    printf("============================================\n");
    printf("1. População:           %lld\n", carta->populacao);
    printf("2. Área (km²):          %.2lf\n", carta->area);
    printf("3. PIB:                 %.2lf\n", carta->pib);
    printf("4. Pontos Turísticos:   %d\n", carta->pontos_turisticos);
    printf("--------------------------------------------\n");
}

// --- Função Principal ---
int main() {
    struct CartaCidade carta_exemplo;
    
    // Chamada para o cadastro
    cadastrar_carta(&carta_exemplo, "A01");

    // Chamada para a exibição
    exibir_carta(&carta_exemplo);

    printf("\nNível Novato Concluído!\n");
    
    // Uma função extra para limpar o buffer do teclado
    // pode ser necessária em alguns sistemas, mas é omitida aqui
    // para manter a simplicidade do desafio focado em scanf/printf.

    return 0;
}
