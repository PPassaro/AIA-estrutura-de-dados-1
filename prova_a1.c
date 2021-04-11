#include <stdio.h>
#include "prova_a1.h"
#define QTD_STUDENTS 2

// Questão 1 //

void populate_students (Student *students) {
  int i;
  char name[100];

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
  Student info_students[QTD_STUDENTS];
  populate_students(info_students);

  int i, highest_grade = 0, highest_average = 0, lowest_average = 0;
  double average = 0, aux_highest = 0, aux_lowest = 0; 

  for (i = 0; i < QTD_STUDENTS; i++){
    if (info_students[i].grade1 > info_students[highest_grade].grade1) {
      highest_grade = i;
    }
  }  

  for ( i = 0; i < QTD_STUDENTS; i++){
    average = 0; 
    average = (info_students[i].grade1 + info_students[i].grade2 + info_students[i].grade3) / 3;

    if (average >= aux_highest) {
      aux_highest = average;
      highest_average = i;
    } 
    if (average < aux_lowest) {
      aux_lowest = average;
      lowest_average = i;
    }
  }

  printf ("\nInfos do estudante com maior nota da primeira prova:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\n", info_students[highest_grade].code, info_students[highest_grade].name, info_students[highest_grade].grade1, info_students[highest_grade].grade2, info_students[highest_grade].grade3);

  printf ("\nAluno com MAIOR média geral:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3\tMédia");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\t%.2lf\n", info_students[highest_average].code, info_students[highest_average].name, info_students[highest_average].grade1, info_students[highest_average].grade2, info_students[highest_average].grade3, (double)aux_highest);

  printf ("\nAluno com MENOR média geral:\n" );
  printf ("\ncod\tNome\t\tNota 1\tNota 2\tNota 3\tMédia");
  printf ("\n%li\t%s\t\t%.2f\t%.2f\t%.2f\t%.2lf\n", info_students[lowest_average].code, info_students[lowest_average].name, info_students[lowest_average].grade1, info_students[lowest_average].grade2, info_students[lowest_average].grade3, (double)aux_lowest);

  printf ("\nRelação de aprovação e reprovação dos alunos:\n" );
  printf ("\nNome\t\t\tStatus");

  for (i = 0; i < QTD_STUDENTS; i++){
    average = 0; 
    average = (info_students[i].grade1 + info_students[i].grade2 + info_students[i].grade3) / 3;

    if (average >= 6){
      printf("\n%s\t\t\tAprovado\n", info_students[i].name);
    } else {
      printf("\n%s\t\t\tReprovado\n", info_students[i].name);
    }
  }
}


int main () {
  Student info_students[QTD_STUDENTS];
  reports(info_students);
}


// Questão 2 //