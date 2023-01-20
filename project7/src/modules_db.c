#include "master_levels.h"
#include "master_modules.h"
#include "master_status_events.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void startmenu();
void sl_next();
void in_next();
void del_next();
void upd_next();
void car_next();
void sh_next();
void def_next();
int main() {
  int f;
  int tmp;
  char trash;
  tmp = 0;
  while (tmp == 0) {
    startmenu();
    scanf("%d", &f);
    switch (f) {
    case 1:
      sl_next();
      break;
    case 2:
      in_next();
      break;
    case 3:
      del_next();
      break;
    case 4:
      upd_next();
      break;
    case 5:
      printactive();
      break;
    case 6:
      car_next();
      break;
    case 7:
      sh_next();
      break;
    case 8:
      def_next();
      break;
    case -1:
      exit(1);
      break;
    default:
      scanf("%c", &trash);
      break;
    }
  }
}
void startmenu() {
  printf("\n\nВыберете фунцкии, нажав на цифру, обозначающую её номер\n");
  printf("1-SELECT\n2-INSERT\n3-DELETE\n4-UPDATE\n5-Вывести включенные "
         "допмодули, выключить их и удалить флагом\n");
  printf("6-Отправить модуль на каратнин по айди\n7-Вывести модули из "
         "определенного уровня памяти и ячейки\n8-Перевод в защитный режим "
         "модуля по id\n-1-Выход\n");
}
void sl_next() {
  printf("\nВыберете фaил\n1-Модули\n2-Уровни памяти\n3-Ивенты\n");
  printf("\nЗатем напишите сколько элеменов вы хотите увидеть, или -1 если "
         "хотите вывести всю базу данных\n");
  int f, id;
  char trash;
  if (scanf("%d %d", &f, &id) != 2) {
    scanf("%c", &trash);
    sl_next();
  } else if (id == -1) {
    SELECT(f, id);
  } else if (id < -1) {
    sl_next();
  } else {
    for (int i = 0; i < id; i++) {
      SELECT(f, i);
      if (i < id - 1) {
        printf("\n");
      }
    }
  }
}
void in_next() {
  printf("\nВыберете фaил в который хотите добавить запись\n1-Модули\n2-Уровни "
         "памяти\n3-Ивенты\n");
  int f;

  scanf("%d", &f);
  switch (f) {
  case 1:
    printf("\nВнесите данные: id(число) Название(строка) уровень и ячейка "
           "памяти(два числа) флаг удаления (1/0)\n");
    INSERT(1);
    break;
  case 2:
    printf("\nВнесите данные: уровень памяти, количество ячеек памяти, степень "
           "защиты (три числа)\n");
    INSERT(2);
    break;
  case 3:
    printf("\nВнесите данные: id ивента id модуля, новый статус модуля, дату, "
           "время\n");
    INSERT(3);
    break;
  default:
    in_next();
    break;
  }
}

void del_next() {
  printf("\nВыберете фaил, из которого нужно удалить\n1-Модули\n2-Уровни "
         "памяти\n3-Ивенты\n");
  printf("\nЗатем напишите номер записи, которую нужно удалить\n");
  int f, id;
  char trash;
  if (scanf("%d %d", &f, &id) != 2) {
    scanf("%c", &trash);
    del_next();
  } else {
    DELETE(f, id);
  }
}

void upd_next() {
  printf("\nВыберете фaил, в котором нужно изменить запись ");
  printf("\n1-Модули\n2-Уровни памяти\n3-Ивенты\n");
  int f, id, place, new;
  char trash;
  if (scanf("%d", &f) == 0) {
    f = 0;
  } else {
    printf("\nНапишите номер записи, которую нужно заменить, а так же что "
           "именно хотите заменить и на какое значение\n");
  }
  switch (f) {
  case 1:
    printf("\n1-Уровень памяти\n2-номер ячейки памяти\n3-Флаг удаления\n");
    if (scanf("%d %d %d", &id, &place, &new) != 3) {
      scanf("%c", &trash);
      upd_next();
    } else {
      UPDATE(f, id, place, new);
    }
    break;
  case 2:
    printf("\n1-Номер уровня\n2-Количество ячеек\n3-Степень защиты\n");
    if (scanf("%d %d %d", &id, &place, &new) != 3) {
      scanf("%c", &trash);
      upd_next();
    } else {
      UPDATE(f, id, place, new);
    }
    break;
  case 3:
    printf("\n1-id ивента \n2-id модуля\n3-Новый статус\n");
    if (scanf("%d %d %d", &id, &place, &new) != 3) {
      scanf("%c", &trash);
      upd_next();
    } else {
      UPDATE(f, id, place, new);
    }
    break;
  default:
    upd_next();
    break;
  }
}

void car_next() {
  free_start();
  printf("\n\nCколько вы хотите переместить модулей?\n");
  int num;
  char trash;
  if (scanf("%d", &num) != 1) {
    scanf("%c", &trash);
    car_next();
  } else {
    int mod;

    for (int i = 0; i < num; i++) {
      printf("\nВведите id\n");
      scanf("%d", &mod);
      caranteen(find_mod(mod));
    }
  }
}
void sh_next() {
  printf("\nНапишите номер уровня и ячейки, элементы которой хотите вывести\n");
  int lvl, num;
  char trash;
  if (scanf("%d %d", &lvl, &num) != 2) {
    scanf("%c", &trash);
    sh_next();
  } else {
    select_lvl(lvl, num);
  }
}
void def_next() {
  printf("\nНапишите id модуля, который хотите перевести в защитный режим\n");
  int id;
  char trash;
  if (scanf("%d", &id) == 0) {
    scanf("%c", &trash);
    def_next();
  }
  insert_status_events(id, id, 0, "data", "time");
  insert_status_events(id, id, 1, "data", "time");
  insert_status_events(id, id, 20, "data", "time");
}
