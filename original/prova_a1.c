#include <stdio.h>
#include "prova_a1.h"
#define QTD_STUDENTS 5
#define QTD_TEAMS 3

// Questão 1 //

void populate_students (Student *students) {
  int i;

  for (i = 0; i < QTD_STUDENTS; i++) {
    printf ("\nDiga o código do Aluno %d: ", i+1);
    scanf ("%li", &students[i].code);

    printf ("Diga o nome do Aluno %d: ", i+1);
    scanf("%s", students[i].name);

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

  for (i = 0; i < QTD_TEAMS; i++) {
    printf ("\nDiga o código do Time %i: ", i+1);
    scanf ("%li", &teams[i].code);

    printf ("Diga o nome do Time %i: ", i+1);
    scanf("%s", teams[i].name);

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
  
  for (i = 0; i < QTD_TEAMS; i++) {
    int victories_points = teams[i].victories * 3;
    int draws_points = teams[i].draws * 1;
    int total_points = victories_points + draws_points;
    teams_points[i] = total_points;

    if (total_points == teams_points[victory_team_index] && teams[i].goal_diff > teams[victory_team_index].goal_diff || total_points > teams_points[victory_team_index]){
      victory_team_index = i;
    }
  }    

  // printf("indice: %i\n", victory_team_index);

return victory_team_index;
}



int main () {
  Student info_students[QTD_STUDENTS];
  reports(info_students);

  Team info_teams[QTD_TEAMS];
  tournment(info_teams);



  return 0;
}


