#include <stdio.h>
#include "prova_a1.h"
#define QTD_STUDENTS 5
#define QTD_TEAMS 3
#define P 5

// Questão 1 //
void flush_in(){
  int ch;
  do{
    ch = fgetc(stdin);
  } while (ch != EOF && ch != '\n');
}

void populate_students (Student *students) {
  int i;

  for (i = 0; i < QTD_STUDENTS; i++) {
    printf ("\nDiga o código do Aluno %d: ", i+1);
    scanf ("%li", &students[i].code);

    flush_in();
    printf ("Diga o nome do Aluno %d: ", i+1);
    scanf("%[A-Z a-z]", students[i].name);
    flush_in();
    
    printf ("Diga a primeira nota do Aluno %d: ", i+1);
    scanf ("%f", &students[i].grade1);

    printf ("Diga a segunda nota do Aluno %d: ", i+1);
    scanf ("%f", &students[i].grade2);

    printf ("Diga a terceira nota do Aluno %d: ", i+1);
    scanf ("%f", &students[i].grade3);
  }
}

void reports (Student *students) {
  populate_students(students);

  int i, highest_grade = 0, highest_average = 0, lowest_average = 0;
  double average = 0, aux_highest = 0, aux_lowest = 0; 

  for (i = 0; i < QTD_STUDENTS; i++){
    if (students[i].grade1 > students[highest_grade].grade1) {
      highest_grade = i;
    }
  }  

  for ( i = 0; i < QTD_STUDENTS; i++){
    average = (students[i].grade1 + students[i].grade2 + students[i].grade3) / 3;

    if (average >= aux_highest) {
      aux_highest = average;
      highest_average = i;
    } 

    if ( i == 0){
      aux_lowest = average;
    }

    if (average <= aux_lowest) {
      aux_lowest = average;
      lowest_average = i;
    }
  }

  printf ("\nInfos do estudante com maior nota da primeira prova:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\n", students[highest_grade].code, students[highest_grade].name, students[highest_grade].grade1, students[highest_grade].grade2, students[highest_grade].grade3);

  printf ("\nAluno com MAIOR média geral:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3\tMédia");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\t%.2lf\n", students[highest_average].code, students[highest_average].name, students[highest_average].grade1, students[highest_average].grade2, students[highest_average].grade3, (double)aux_highest);

  printf ("\nAluno com MENOR média geral:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3\tMédia");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\t%.2lf\n", students[lowest_average].code, students[lowest_average].name, students[lowest_average].grade1, students[lowest_average].grade2, students[lowest_average].grade3, (double)aux_lowest);

  printf ("\nRelação de aprovação e reprovação dos alunos:\n" );
  printf ("\nNome\t\t\tStatus");

  for (i = 0; i < QTD_STUDENTS; i++){
    average = 0; 
    average = (students[i].grade1 + students[i].grade2 + students[i].grade3) / 3;

    if (average >= 6){
      printf("\n%s\t\t\tAprovado\n", students[i].name);
    } else {
      printf("\n%s\t\t\tReprovado\n", students[i].name);
    }
  }
}

// Questão 2 //

void populate_teams (Team *teams){
  int i;
    
  printf("\nDIGITE AS INFORMAÇÕES DE 3 TIMES COM O TOTAL DE 5 PARTIDAS. CASO DIGTE A MAIS, O PROGRAMA VOLTARÁ PARA O INICIO!\n");

  for (i = 0; i < QTD_TEAMS; i++) {
    printf ("\nDiga o código do Time %i: ", i+1);
    scanf ("%li", &teams[i].code);

    flush_in();
    printf ("Diga o nome do Time %i: ", i+1);
    scanf("%[A-Z a-z]", teams[i].name);
    flush_in();
    
    printf ("Diga a quantidade de vitórias Time %i: ", i+1);
    scanf ("%i", &teams[i].victories);

    printf ("Diga a quantidade de empates do Time %i: ", i+1);
    scanf ("%i", &teams[i].draws);

    printf ("Diga a quantidade de derrotas do Time %i: ", i+1);
    scanf ("%i", &teams[i].defeats);

    printf ("Diga a quantidade de gols do time %i: ", i+1);
    scanf ("%i", &teams[i].goal_diff);
  }
}

int tournment (Team *teams){
  populate_teams(teams);

  int i = 0;
  int victory_team_index = 0;
  int teams_points[QTD_TEAMS];
  int p_points;
  
  for (i = 0; i < QTD_TEAMS; i++) {
    int victories_points = teams[i].victories * 3;
    int draws_points = teams[i].draws * 1;
    int total_points = victories_points + draws_points;
    teams_points[i] = total_points;
    int p_points = teams[i].victories + teams[i].draws + teams[i].defeats;

    if (total_points == teams_points[victory_team_index] && teams[i].goal_diff > teams[victory_team_index].goal_diff || total_points > teams_points[victory_team_index]){
      victory_team_index = i;
    }

    if(p_points > P){
      populate_teams(teams);
    }   
  }   

  // printf("\nIndice do time vitorioso (lembrando que o indice começa do 0): %i\n", victory_team_index);

  return victory_team_index;
}

// Questão 3 //

void max_min (int *v, int N, int *max, int *min) {
  int i;

  for(i = 0; i < N; i++){    
    int currentValue = v[i];
    
    if (i == 0){
      *max = currentValue;
      *min = currentValue;
    }

    if(currentValue > *max){
      *max = currentValue;
    }

    if (currentValue < *min){
      *min = currentValue;
    }
  }
}

// Questão 4 //

int bin_search (int *v, int begin, int end, int value) {
  while (begin <= end) { 
    int m = (begin + end)/2;
    if (value == v[m]) return m;
    if (value < v[m]) end = m - 1; 
    else begin = m + 1;
  }
  return -1;

}

// Questão 5 //

int mult( int x, int n ){
  if( n == 1)
    return x;
  return x + mult(x, n-1);
}

// MENU //

void questao_1() {
   // Questão 1
  Student info_students[QTD_STUDENTS];
  reports(info_students);
}

void questao_2() {
  // Questão 2
  Team info_teams[QTD_TEAMS];
  tournment(info_teams);
}

void questao_3() {
 // Questão 3
  int N = 5;

  int vetNumber[5] = {10, 20, 30, 40, 50};

  int max = 0;
  int min = 0;

  max_min(vetNumber, N, &max, &min);

  printf("Max value: %i\n", max);
  printf("Min value: %i\n", min);
}

void questao_4() {
  // Questão 4 
  int vetNumber[5] = {10, 20, 30, 40, 50};
  int index = bin_search(vetNumber, 0, 3, 100);
  printf("Result: %i\n", index);
}

void questao_5() {
  // Questão 5
  int result = mult(3, 4);
  printf ("Result: %i\n", result);
}

void menu () {
  int valor_inse;

    do {
      printf("\nInsira o numero da questão que deseja rodar\n");
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
          printf("Saindo\n");
          break;

        default:
          printf("Digite uma opcao valida\n");
      }
  } while(valor_inse != 0);
}

int main () {

  menu();

  return 0;
}


