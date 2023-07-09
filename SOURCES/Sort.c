#include <stdio.h>
#include <stdlib.h>
#include "..\INCLUDE\Strcuts.h"

int compareProjects_bsbfr1(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their best_before in ascending order
    if (projA->best_bfor > projB->best_bfor) {
        return 1;
    }
    else{
        return -1;
    }
}

int compareProjects_bsbfr2(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their best_before in descending order
    if (projA->best_bfor > projB->best_bfor) {
        return -1;
    }
    else{
        return 1;
    }
}

int compareProjects_score1(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in ascending order
    if (projA->score > projB->score) {
        return 1;
    }
    else{
        return -1;
    }
}

int compareProjects_score2(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in descending order
    if (projA->score > projB->score) {
        return -1;
    }
    else{
        return 1;
    }
}

int compareProjects_days1(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in ascending order
    if (projA->req_days > projB->req_days) {
        return 1;
    }
    else{
        return -1;
    }
}

int compareProjects_days2(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in ascending order
    if (projA->req_days > projB->req_days) {
        return -1;
    }
    else{
        return 1;
    }
}

int compareProjects_roles1(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in ascending order
    if (projA->roles > projB->roles) {
        return 1;
    }
    else{
        return -1;
    }
}

int compareProjects_roles2(const void* a, const void* b) {
    const Project* projA = (const Project*)a;
    const Project* projB = (const Project*)b;

    // we Sort the projects by their score in ascending order
    if (projA->roles > projB->roles) {
        return -1;
    }
    else{
        return 1;
    }
}

void sort_projs(Project *projects,int p, int n)
{
    if(n == 0)
        qsort(projects, p, sizeof(Project), compareProjects_bsbfr1);
    else if (n == 1)
        qsort(projects, p, sizeof(Project), compareProjects_bsbfr2);
    else if (n == 2)
        qsort(projects, p, sizeof(Project), compareProjects_days1);
    else if (n == 3)
        qsort(projects, p, sizeof(Project), compareProjects_days2);
    else if (n == 4)
        qsort(projects, p, sizeof(Project), compareProjects_roles1);
    else if (n == 5)
        qsort(projects, p, sizeof(Project), compareProjects_roles2);
    else if (n == 6)
        qsort(projects, p, sizeof(Project), compareProjects_score1);
    else if (n == 7)
        qsort(projects, p, sizeof(Project), compareProjects_score2);
}