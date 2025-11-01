#include <stdio.h>
#include <string.h>

int main() {
	#define max_transacoes 50
	char extratodet[max_transacoes][50];
	int transacoes = 0;
	
	int opcao;
	float saldo = 2500.00; // Saldo do usuário.
	float deposito, saque;
	
	char senha[17]; // Máximo de caracteres para a senha.
	const char senha_do_usuario[] = "bancoadmin123"; // Senha do usuário.
	int tentativas = 0;
	const int max_tentativas = 3;
  
  
  while (tentativas < max_tentativas) {
  	printf("====================\nOla, usuario!\nBem vindo ao Bank One, seu banco digital!\n");
    printf("\nPara acessar sua conta, digite sua senha: (%d/%d tentativas): ", tentativas + 1, max_tentativas);
    scanf("%s", senha);
    
    if (strcmp(senha, senha_do_usuario) == 0) { // Caso o usuário acerte a senha.
    	printf("\n=====Acesso liberado=====!\n");
    	
    	do {
    	printf("\nO que deseja fazer agora?\n"); // Menu de opções.
		printf("\n1 - Verificar saldo\n");
        printf("2 - Depositar dinheiro\n");
        printf("3 - Sacar dinheiro\n");
        printf("4 - Extrato de transacoes\n");
        printf("5 - Sair do sistema\n");
        printf("\nEscolha uma opcao: \n");
        scanf("%d", &opcao) ;
		
		switch(opcao) {
	case 1:
		printf("\nVoce possui %.2f reais na conta.\n\n\n", saldo); // Opção 1
		printf("=======================================\n");
		break;
	
	case 2: // Opção 2. 
		printf("\nDigite o valor que sera depositado:\n(Se os centavos forem incluidos, use um ponto e os dois digitos. Exemplo: 1500.00).\n(Caso nao, digite apenas o valor inteiro. Exemplo: 1500).\n\n"); //Aviso para que o usuário não use a vírgula.
		scanf("%f", &deposito);
		
		if (deposito > 0) {
			saldo += deposito;
			printf("\nDeposito de %.2f reais concluido!\n\n=======================================\n", deposito);
		    sprintf(extratodet[transacoes], "Valor Depositado: +%.2f centavos", deposito); // Código usado para armazenar o extrato de transações da conta
		    transacoes++;
			
		} else {
			printf("\n\nNao foi possivel depositar esse valor.\n========================\n\n");
		}
		break;
			
	case 3: // Opção 3	
    printf("\nDigite o valor de saque: \n(Se os centavos forem incluidos, use um ponto e os dois digitos. Exemplo: 1500.00).\n(Caso nao, digite apenas o valor inteiro. Exemplo: 1500).\n\n");
    scanf("%f", &saque);
    
    if (saque > 0 && saque <= saldo) { // Se o saque for maior que zero e o saque for menor ou igual ao saldo, sera concluído o saque com sucesso. 
    	saldo -= saque; // Calculo utilizado para o saque.
    	printf("\nSaque de %.2f reais concluido!\n\n=======================================\n", saque);
    	sprintf(extratodet[transacoes], "Valor sacado: -%.2f reais", saque); // Código usado para armazenar o extrato de transações da conta
    	transacoes++; 
    	
	} else {
		printf("\nNao foi possivel sacar esse valor!\n\n");
		printf("\n\n=======================================\n\n");
	}
        break;
        
    case 4: // Opção 4
    if (transacoes == 0) {
    	printf("\nNenhuma transacao foi localizada.\n");
    	printf("\n=======================================\n");
	} else {
		printf ("\nUltimas transacoes feitas: \n");
		for (int i = 0; i < transacoes; i++) { 
			printf("%d. %s \n", i + 1, extratodet[i]);	
		}
		printf("\n=======================================\n\n");
	}
        break;

	case 5: // Opção 5
	    printf("\nVoce esta saindo do sistema do banco. Obrigada(o) por usar o Bank One!\n");
        printf("\n=======================================\n");	
	break;
	
	default: //Caso o usuário escolha uma opção não descrita.
	    printf("\nOpcao nao reconhecida. Tente novamente.\n");  
    }

} while (opcao != 5);

    	return 0; 

	} else { 
	tentativas++;
	if (tentativas < max_tentativas) {
		printf("\nSenha incorreta! Voce tem %d tentativas.\n", max_tentativas - tentativas); // O sistema dá mais x tentativas para o usuário.
	}
  }
}
  
  printf("\nSeu acesso foi negado, pois excedeu o numero maximo de tentativas. Entre em contato com sua agencia. \n"); // O sistema encerra quando o usuário erra todas as tentativas.
  printf("=======================================\n");
  return 1;
  
} 