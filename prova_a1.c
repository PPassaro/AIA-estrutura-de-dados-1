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

  populate_students(info_students);

  highest_grade = 0;

  for (i = 1; i < QTD_STUDENTS; i++){
    if (info_students[i].grade1 > info_students[highest_grade].grade1) {
      highest_grade = i;
    }
  }  

  for ( i = 1; i < QTD_STUDENTS; i++){
   
  }

  printf ("Infos do estudante com maior nota da primeira prova:\n" );
  printf ("\ncod\tNome\tNota 1\tNota 2\tNota 3");
  printf ("\n%li\t%s\t%.2f\t%.2f\t%.2f\n", info_students[highest_grade].code, info_students[highest_grade].name, info_students[highest_grade].grade1, info_students[highest_grade].grade2, info_students[highest_grade].grade3);
}




// -> OK (b) Encontrar e imprimir os dados do aluno com maior nota da primeira prova. 
// (c) Encontrar e imprimir os dados do aluno com maior media geral.
// (d) Encontrar e imprimir os dados do aluno com menor media geral.
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação. Apresente esta
// informação na forma de uma tabela.



int main () {
  Student info_students[QTD_STUDENTS];
  reports(info_students);



   
}



