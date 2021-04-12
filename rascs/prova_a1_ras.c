#include <stdio.h>
#include "a1_ras.h"
#define QTD_TEAMS 3

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
  
  for (i = 0; i < QTD_TEAMS; i++) {
    int victories_points = teams[i].victories * 3;
    int draws_points = teams[i].draws * 1;
    int total_points = victories_points + draws_points;
    teams[i].points = total_points;

    if (total_points == teams[victory_team_index].points && teams[i].goal_diff > teams[victory_team_index].goal_diff || total_points > teams[victory_team_index].points){
      victory_team_index = i;
    }

    int p_total = teams[i].victories + teams[i].draws + teams[i].defeats;
    teams[i].P = p_total;
  }    

  // printf("indice: %i\n", victory_team_index);

return victory_team_index;
}

int main () {
  Team info_teams[QTD_TEAMS];
  tournment(info_teams);

return 0;
  
}



