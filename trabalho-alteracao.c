#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>


    //prototipo modulos
    void menu();
    void cadastroTurma();
    void consultaAluno();
    void alteracaoDadosAluno();
    void listagemDadosTurma();
    
    //definicao estruturas
    typedef struct{
        unsigned int matricula; 
        char CPF[12];
        char nome[100];
        double notas[5];
        double notaFinal;
        unsigned int numAusencias;
        char situacao[60];
        
    }Aluno;
    
    //funcoes especificas 
    void pesquisaNome(FILE *arq){
        char aux[100], nome[100];
        Aluno alunos[30]; 
        int i, j, encontrou=0;//DUVIDA TEM QUE PEGAR O MESMO STRUCT OU CRIAR OUTRO OU DECLARAR GLOBALMENTE 
        
        
        printf("\n\tDigite o nome do aluno ou \"menu\" para retornar ao menu:\n\t");
        getchar();
        fgets(nome, 100, stdin);
        
         strcpy(aux, nome); 
         for(i=0; aux[i] != '\0'; i++){
            if(isalpha(aux[i]))  aux[i] = toupper(aux[i]);
        }
        if(strcmp(aux, "MENU") ==0){
            menu();
        }
        while(strcmp(aux, "MENU") !=0){
            
            for(i=0; i<30; i++){
                fread(&alunos[i], sizeof(Aluno), 1, arq); 
                
                if(strcmp(alunos[i].nome, nome) == 0){
                    encontrou++;
                    printf("\n\tNOME: %s",alunos[i].nome); 
                    printf("\n\tMatricula: %u\n",alunos[i].matricula); 
                    printf("\n\tCPF: %s\n",alunos[i].CPF); 
                       for(j=0; j<5; j++){
                           printf("\n\tProva %d: %.2lf\n", j+1, alunos[i].notas[j]);
                       }
                    printf("\n\tNota Final: %.2lf\n", alunos[i].notaFinal);
                    printf("\n\tNúmero de ausências: %u\n", alunos[i].numAusencias);
                    printf("\n\tSituação: %s\n", alunos[i].situacao);
                }
            } //DUVIDA SABER TAMANHO DE ALUNOS 
            if(encontrou==0){
               printf("\n\tO aluno não foi encontrado na turma");
             }
            fgets(nome, 100, stdin);   
            strcpy(aux, nome);
             for(i=0; aux[i] != '\0'; i++){
                if(isalpha(aux[i]))  aux[i] = toupper(aux[i]);
            }
        }
        rewind(arq);
        fclose(arq);
        if(strcmp(aux, "MENU") ==0){
            menu();
        }
        
    }
    void pesquisaCPF(FILE *arq){
        char cpf[12]; 
        Aluno alunos[30];
        int i, j, encontrou=0;
        printf("\n\tDigite o CPF do aluno ou \"0\" para retornar ao menu:\n\t");
        getchar();
        scanf("%[^\n]", cpf);
    
        
        if(strcmp(cpf, "0") == 0){
            menu();
        }
        
        while(strcmp(cpf, "0") != 0){
        for(i=0; i<30; i++){
            fread(&alunos[i], sizeof(Aluno), 1, arq); 
              
            if(strcmp(cpf, alunos[i].CPF) == 0){
                encontrou++;
                printf("\n\tNOME: %s",alunos[i].nome); 
                printf("\n\tMatricula: %u",alunos[i].matricula); 
                printf("\n\tCPF: %s",alunos[i].CPF); 
                   for(j=0; j<5; j++){
                       printf("\n\tProva %d: %.2lf", j+1, alunos[i].notas[j]);
                   }
                printf("\n\tNota Final: %.2lf", alunos[i].notaFinal);
                printf("\n\tNúmero de ausências: %u", alunos[i].numAusencias);
                printf("\n\tSituação: %s\n", alunos[i].situacao);
            }
        }
            if(encontrou==0){
               printf("\n\tO aluno não foi encontrado na turma");
           }
          printf("\n\tDigite o CPF do aluno ou \"0\" para retornar ao menu:\n\t");
          scanf("%s", cpf);
          system("clear");
          
        }
        
        rewind(arq);
        fclose(arq);
        
        if(strcmp(cpf, "0") ==0){
            menu();
        }
        
    }
    void pesquisaMatricula(FILE *arq){
        unsigned int matricula;
        int i, j;
        Aluno alunos[30];
        int encontrou = 0;
        printf("\n\tDigite a matricula do aluno ou \"0\" para retornar ao menu:\n\t");
        scanf("%u", &matricula);
         if(matricula ==0){
            menu();
        }
        while(matricula != 0){
           for(i=0; i<30; i++){
               fread(&alunos[i], sizeof(Aluno), 1, arq); 
               
               if(matricula == alunos[i].matricula){
                encontrou++;
                printf("\n\tNOME: %s",alunos[i].nome); 
                printf("\n\tMatricula: %u",alunos[i].matricula); 
                printf("\n\tCPF: %s",alunos[i].CPF); 
                   for(j=0; j<5; j++){
                       printf("\n\tProva %d: %.2lf", j+1, alunos[i].notas[j]);
                   }
                printf("\n\tNota Final: %.2lf", alunos[i].notaFinal);
                printf("\n\tNúmero de ausências: %u", alunos[i].numAusencias);
                printf("\n\tSituação: %s\n", alunos[i].situacao);
               }
           }
           if(encontrou==0){
               printf("\n\tO aluno não foi encontrado na turma");
           }
           printf("\n\tDigite a matricula do aluno ou \"0\" para retornar ao menu:\n\t");
           scanf("%u", &matricula); 
           encontrou = 0;
           system("clear");
        }
       
        rewind(arq);
        fclose(arq);
        
        if(matricula ==0){
            menu();
        }
        
    }
    
    int estanoArquivo(Aluno *alunos, unsigned int mat, int *indice){
        int i;
         for(i=0;i<30; i++){ //DUVIDA TAMANHO DO VETOR
                if(mat == alunos[i].matricula){
                    *indice = i; 
                    return 1;
                }
            }
            
            return 0;
    }
    
    

int main()
{   
    setlocale(LC_ALL, "Portuguese");
    menu();
  

    return 0;
}
    void menu(){
        //MODULO PRINCIPAL
    printf("\n\t\t\t\t\tBEM VINDO AO SGT (Sistema de Gerenciamento de TURMAS)!\n");
    printf("\n\tEcolha a opção do menu ou digite 5 para encerrar a sessão\n");
    //menu
    char op; 
    
    printf("\t1- Cadastrar uma turma\n");
    printf("\t2- Consultar um aluno\n");
    printf("\t3- Alterar dados de um aluno\n");
    printf("\t4- Listar dados de uma turma\n");
    printf("\t5- Terminar a execução\n");
    printf("\n\t");
    do{ scanf(" %c", &op); 
        
        if(op !='1' && op !='2' && op !='3' && op !='4' && op !='5') printf("\tOpção Inválida! Digite novamente!\n\t");
    }while(op !='1' && op !='2' && op !='3' && op !='4' && op !='5');
    
    system("clear");
    switch(op){
        case '1': cadastroTurma();
            break;
        case '2': consultaAluno();
            break;
        case '3': alteracaoDadosAluno();
            break;
        case '4': listagemDadosTurma();
            break;
        case '5': printf("\n\tFoi um prazer! PROGRAMA ENCERRADO!");
            break;
        default: printf("\n\tERRO!\n"); 
            break;
        }
    }


    void cadastroTurma(){
        FILE *arquivo; 
        char nomearq[100]; 
        Aluno *alunos; 
        int i=0;
        int j;
       char strAprovado[9] = "Aprovado"; 
       char strRepAusencia[23] = "Reprovado por ausência";
       char strRepNota[19] = "Reprovado por Nota";
       char strRepAusNota[34] = "Reprovado por ausência e por nota";
       double aux = 0.0;
        
        printf("\n\tDigite o nome do aquivo para a turma a ser cadastrada: \n\t"); 
        getchar();
        scanf("%[^\n]", nomearq);
        
        arquivo = fopen(nomearq, "wb"); //DUVIDA COMO CONCILIAR CAMINHO E NOME PARA ABRIR UM ARQUIVO
        if(!arquivo){
            printf("\n\tErro de abertura no aquivo"); 
            exit(1);
        }
        
        alunos = (Aluno*) malloc(30 * sizeof(Aluno)); //DUVIDA COMO REALOCAR O ESPAÇO SE O TAMANHO DE ALUNOS FOR MAIOR Q O ESPERADO
        printf("\n\tDigite a matricula do aluno ou zero para encerrar");
        printf("\n\tMatrícula: \n\t");
        
        scanf("%u", &alunos[i].matricula);
        
        while(alunos[i].matricula!= 0){
            getchar();
            printf("\n\tCPF: ");
            scanf("%[^\n]", alunos[i].CPF);
            getchar();
            printf("\n\tNome: ");
            fgets(alunos[i].nome,100, stdin);
            printf("\n\tNotas das Provas: \n\t");
            for(j=0; j<5; j++){
            printf("\n\tProva %d: ", j+1);
               scanf("%lf", &alunos[i].notas[j]);  
               aux += alunos[i].notas[j]; 
            }
            printf("\n\tNumero de ausências: ");
            scanf("%u", &alunos[i].numAusencias);
            alunos[i].notaFinal = aux/5.0;
            
            int maxAusencia = (25 * 128)/100; 
            if(alunos[i].notaFinal >= 6.0 && alunos[i].numAusencias < maxAusencia){
                strcpy(alunos[i].situacao, strAprovado);
            }else if(alunos[i].notaFinal < 6.0 && alunos[i].numAusencias < maxAusencia){
                strcpy(alunos[i].situacao, strRepAusencia);
            }else if(alunos[i].notaFinal >= 6.0 && alunos[i].numAusencias >= maxAusencia){
                strcpy(alunos[i].situacao, strRepNota);
            }else{
                strcpy(alunos[i].situacao, strRepAusNota);
            }
            
            char op; 
            printf("\n\tDeseja Gravar os dados do aluno?");
            printf("\n\t1- Gravar"); 
            printf("\n\t2 - Retornar ao menu\n\t");
            do{scanf("%c", &op);
                if(op!= '1' && op!= '2'){
                    printf("\n\tPor favor, digite uma opção válida!\n\t");
                }
            }while(op!= '1' && op!= '2');
            system("clear");
            
            if(op== '1'){
            fwrite(&alunos[i], sizeof(Aluno), 1, arquivo); 
                if(ferror(arquivo)){
                    printf("\n\tErro na gravação!");
                    exit(1);
                }else{
                    printf("\n\tGravação Concluída\n");
                }
                
            }else if(op== '2'){
                menu();
                return; 
            }
                    
            system("clear");
            
            printf("\n\tDigite a matricula do aluno ou zero para encerrar\n");
            printf("\n\tMatrícula:\n\t");
            i++;
            scanf("%u", &alunos[i].matricula);
        }
        rewind(arquivo);
        free(alunos);
        fclose(arquivo);
    }
    
    void consultaAluno(){
        FILE *arquivo;
        char nomearq[60];
        char aux[60];
        int i;
        printf("\n\tDigite o nome de um arquivo de turma ou \"fim\" para encerrar\n\t"); //DUVIDA COMO VERIFICAR SE O NOME DO ARQUIVO É VALIDO
        scanf(" %s",nomearq);
        getchar();
        strcpy(aux, nomearq);
        for(i=0; aux[i] != '\0'; i++){
            if(isalpha(aux[i]))  aux[i] = toupper(aux[i]);
        }
        if(strcmp(aux, "FIM") ==0){
            menu();
        }
        
        arquivo = fopen(nomearq, "r+"); 
        
        if(!arquivo){
            printf("\n\tErro na abertura do arquivo\n");
            exit(1);
        }
        system("clear");
        char op;
        printf("\n\tDigite o modo de pesquisa que deseja:"); 
        printf("\n\t1- Por nome de aluno");
        printf("\n\t2- Por CPF");
        printf("\n\t3- Por matricula\n\t");
        do{scanf("%c", &op);
        if(op != '1' && op!= '2' && op != '3'){
            printf("\n\tPor favor, digite uma opção válida!\n\t");
        }
        }while(op != '1' && op!= '2' && op != '3'); 
        
        switch(op){
            case '1': pesquisaNome(arquivo);
                break;
            case '2': pesquisaCPF(arquivo);
                break;
            case '3': pesquisaMatricula(arquivo);
                break;
        }
        
    }
    void alteracaoDadosAluno(){
        FILE *arquivo;
        Aluno *alunos;
        char nomearq[60];
        char aux[60];
        unsigned int mat;
        int  indiceAluno; 
        int i=0, j=0;
        printf("\n\tDigite o nome de um arquivo de turma ou \"fim\" para encerrar\n\t"); //DUVIDA COMO VERIFICAR SE O NOME DO ARQUIVO É VALIDO
        scanf("%s",nomearq); //DUVIDA CRIAR UMA LISTA DE NOMES DE ARQUIVOS EXISTENTES
        getchar();
        strcpy(aux, nomearq);
        for(i=0; aux[i] != '\0'; i++){
            if(isalpha(aux[i]))  aux[i] = toupper(aux[i]);
        }
        if(strcmp(aux, "FIM") ==0){
            menu();
        }
        
        arquivo = fopen(nomearq, "wb");
        if(!arquivo){
            printf("Erro!"); 
            exit(1);
        }
        
        alunos = (Aluno*) malloc(30 * sizeof(Aluno));
        if(!alunos){
            printf("Erro!"); 
            exit(1); 
        }
         for(i=0; i<30; i++){
               fread(&alunos[i], sizeof(Aluno), 1, arquivo); }
               
        printf("\n\tDigite um numero de matricula válido ou 0 para encerrar\n\t");
            do{scanf("%u", &mat);
            if(!estanoArquivo(alunos, mat, &indiceAluno)){
                printf("\n\tO registro não se encontra no arquivo, tente novamente\n\t");
            }
            }while(estanoArquivo(alunos, mat, &indiceAluno) ==0 || mat != 0);
             if(mat==0){
                 system("clear");
                 menu();   
                }
     
                printf("\n\tNOME: %s",alunos[indiceAluno].nome); 
                printf("\n\tMatricula: %u",alunos[indiceAluno].matricula); 
                printf("\n\tCPF: %s",alunos[i].CPF); 
                   for(j=0; j<5; j++){
                       printf("\n\tProva %d: %.2lf", j+1, alunos[indiceAluno].notas[j]);
                   }
                printf("\n\tNota Final: %.2lf", alunos[indiceAluno].notaFinal);
                printf("\n\tNúmero de ausências: %u", alunos[indiceAluno].numAusencias);
                printf("\n\tSituação: %s\n", alunos[indiceAluno].situacao);
             
           
           
        }
        
    void listagemDadosTurma(){}