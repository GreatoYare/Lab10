#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "file_manager.h"
#include "checks.h"

// For adaptive clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

WoWMounts *readItem(WoWMounts *wowMounts)
{
    wowMounts->cost = enterInt("Write cost of mount: ");
    wowMounts->name = enterString("Write name of mount: ");
    wowMounts->quest = enterString("Write quest where you can earn mount: ");
    wowMounts->achieve = enterString("Write achievement where you can earn mount: ");
    wowMounts->drop = enterString("Write from who you can earn mount: ");
    wowMounts->chance = enterDouble("Write chance of mount drop: ");
    wowMounts->addon = enterString("Write addition where mount stand: ");
    wowMounts->where = enterString("Write location where mount stand: ");
    wowMounts->holders = enterDouble("Write percent of mount holders: ");
    wowMounts->rate = enterInt("Write your rate of mount: ");
    return wowMounts;
}

void showAbout()
{
    system(CLEAR);
    puts("================= [About] ===================");
    puts("Title: \"Labwork 10\"");
    puts("Author: Spiridonov Leonid 8307");
    puts("=============================================");
    printf("Press anything to continue: ");
    getch();
}

void showDelete(List *list)
{

    system(CLEAR);
    puts("================== [Delete] ====================");
    puts("At this point you can delete a mount\nfrom the library. Follow the instructions.");
    puts("=============================================");

    int id;
    printf("Enter the mount id before which you want to delete:");
    scanf("%d", &id);
    id--;
    DeletePrevious(id, list);
    puts("Item was deleted from library");
    printf("Write anything to continue: ");
    getch();
}

void showAdd(List *list)
{
    WoWMounts *wowMounts = malloc(sizeof(WoWMounts));

    system(CLEAR);
    puts("================== [Add] ====================");
    puts("At this point you can add a new mount\nto the library. Follow the instructions.");
    puts("=============================================");

    readItem(wowMounts);

    addToPreLast(wowMounts, list);
    puts("Mount was added to library");
    printf("Write anything to continue: ");
    getch();
}

void showList(List *list)
{
    system(CLEAR);
    puts("================= [List] ====================");
    display(list);
    puts("=============================================");
    printf("Write anything to continue: ");
    getch();
}

void showMenu(List *list)
{
    int menu = 0;
    while (menu != 4)
    {
        system(CLEAR);
        puts("================= [MENU] ===================");
        puts("0. Abouts");
        puts("1. Add new note");
        puts("2. Print list");
        puts("3. Delete previous element");
        puts("4. Exit");
        puts("============================================");
        menu = enterInt("Write your command: ");

        if (menu == 0)
        {
            showAbout();
        }
        else if (menu == 1)
        {
            showAdd(list);
        }
        else if (menu == 2)
        {
            showList(list);
        }
        else if (menu == 3)
        {
            showDelete(list);
        }
    }
}
