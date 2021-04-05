int menu () {
    int valor_inse, opc_1 = questao_1(), opc_2 = questao_2(), opc_3 = questao_3();
    int opc_4 = questao_4(), opc_5 = questao_5(), opc_sair = sair();

    do {
        printf("Insira o numero da questão que deseja rodar\n");
        printf("1. Questão 1\n");
        printf("2. Questão 2\n");
        printf("3. Questão 3\n");
        printf("4. Questão 4\n");
        printf("5. Questão 5\n");
        printf("0. Sair\n");

        scanf("%d", &valor_inse);

        switch(valor_inse) {
            case 1:
                questao_1();
                break;

            case 2:
                questao_2();
                break;

            case 3:
                questao_3();
                break;

            case 4:
                questao_4();
                break;
            
            case 5:
                questao_5();
                break;

            case 0:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(valor_inse);
}