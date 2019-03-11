#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int day;
  int month;
  int year;
} DATA;

typedef struct {
  char name[31];
  char phone[21];
  DATA birthday;
} PESSOA;

void setPerson(PESSOA *agenda);
void getPerson(PESSOA *agenda);

int main(int argc, char const *argv[]) {
  PESSOA agenda[2];
  int i;
  for (i = 0; i < 2; i++) {
    PESSOA *pointer = &agenda[i];
    setPerson(pointer);
  }
  for (i = 0; i < 2; i++) {
    PESSOA *pointer = &agenda[i];
    getPerson(pointer);
  }

  return 0;
}

void getPerson(PESSOA *agenda) {
  printf("Nome: %s\n", agenda -> name);
  printf("Telefone: %s\n", agenda -> phone);
  printf("Data de nascimento: %.2d/%.2d/%.4d\n", agenda -> birthday.day, agenda -> birthday.month, agenda -> birthday.year);
}

void setPerson(PESSOA *agenda) {
  char name[31];
  printf("Enter the person's name:\n");
  scanf("%30[^\n]", name);
  strcpy(agenda -> name, name);
  getchar();

  printf("Input the person's phone number:\n");
  char phone[21];
  scanf("%20[^\n]", phone);
  getchar();
  strcpy(agenda -> phone, phone);

  int day, month, year;
  printf("Enter day, month and year the person was born:\n");
  scanf("%d %d %d", &day, &month, &year);
  getchar();
  agenda -> birthday.day = day;
  agenda -> birthday.month = month;
  agenda -> birthday.year = year;

  printf("\nSuccessfull Registration\n");
}
