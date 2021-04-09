#include <stdio.h>
#include "prova_a1.h"
#define QTD_STUDENTS 2


// Questão 1 //


// void flush_in(){ 
//   int ch;
//   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
// }

void populate_students (Student *students) {
  int i;
  char name[100];

  for (i = 0; i < QTD_STUDENTS; i++) {
    printf ("\nDiga o código do Aluno %d: ", i+1);
    scanf ("%li", &students[i].code);

    printf ("Diga o nome do Aluno %d: ", i+1);
    // fflush(stdin)
    scanf("%s", students[i].name);
    // flush_in();

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
  int highest_grade;
  int i;
  int average, highest_average, lowest_average, aux_highest, aux_lowest;

  populate_students(info_students);

  highest_grade = 0;

  for (i = 0; i < QTD_STUDENTS; i++){
    if (info_students[i].grade1 > info_students[highest_grade].grade1) {
      highest_grade = i;
    }
  }  
  
  aux_highest = 0;
  aux_lowest = 0;

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


}





// -> OK (b) Encontrar e imprimir os dados do aluno com maior nota da primeira prova. 
// -> OK (c) Encontrar e imprimir os dados do aluno com maior media geral.
// -> OK (d) Encontrar e imprimir os dados do aluno com menor media geral.
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação. Apresente esta
// informação na forma de uma tabela.



int main () {
  Student info_students[QTD_STUDENTS];
  reports(info_students);



   
}



