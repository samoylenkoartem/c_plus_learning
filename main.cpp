#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>  // Windows-only
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct town {
    struct town* pNext;
    struct town* pPrev;
    char Name[];
};
typedef struct town Town;
Town* pFirst = 0, * pLast = 0;

Town* Create(const char* name) {
    size_t len = strlen(name);
    Town* po = (Town*)malloc(sizeof(Town) + len + 1);
    if (po == 0) return 0;
    strncpy(po->Name, name, len);
    po->Name[len] = '\0';  // обязательно для strncpy!
    
    return po;
}

void AddToList(Town* po) {
    if (pLast) pLast->pNext = po;
    po->pPrev = pLast;
    pLast = po;
    po->pNext = 0;
    if (pFirst == 0) pFirst = po;
}

void DeleteTown(Town* po) {
    if (!po) return;

    if (po->pPrev) 
        po->pPrev->pNext = po->pNext; 
    else 
        pFirst = po->pNext;
        
    if (po->pNext) 
        po->pNext->pPrev = po->pPrev; 
    else 
        pLast = po->pPrev;

    free(po);
}

Town* SearchTown(const char* name) {
    Town* current = pFirst;
    while (current) {
        if (strcmp(current->Name, name) == 0) {
            return current;
        }
        current = current->pNext;
    }
    return 0;
}

void PrintAllTowns(void) {
    printf("All town list:");
    Town* po = pFirst;
    while (po) {
        printf("\n %s", po->Name);
        po = po->pNext;
    }
    printf("\n");
}

void SortTowns(void) {
    if (!pFirst || !pFirst->pNext) return;

    int flag;
    do {
        flag = 0;
        Town* current = pFirst;
        while (current->pNext) {
            if (strcmp(current->Name, current->pNext->Name) > 0) {
                // Обмен узлов
                Town* xNext = current->pNext;
                Town* xPrev = current->pPrev;
                Town* xxNext = xNext->pNext;
                
                if (xPrev) 
                    xPrev->pNext = xNext; 
                else 
                    pFirst = xNext;
                    
                if (xxNext) 
                    xxNext->pPrev = current;

                xNext->pPrev = xPrev;
                current->pNext = xxNext;

                xNext->pNext = current;
                current->pPrev = xNext;

                flag = 1;
            }
            else {
                current = current->pNext;
            }
        }
    } while (flag);
}

int main(void) {
    // _CrtSetDbgFlag(...) - Windows-only
    
    Town* po;
    
    po = Create("Saint Petersburg"); if (po == 0) return -1; AddToList(po);
    po = Create("Nice"); if (po == 0) return -1; AddToList(po);
    po = Create("Rome"); if (po == 0) return -1; AddToList(po);
    po = Create("Astana"); if (po == 0) return -1; AddToList(po);
    po = Create("Lima"); if (po == 0) return -1; AddToList(po);
    po = Create("Beijing"); if (po == 0) return -1; AddToList(po);
    po = Create("Paris"); if (po == 0) return -1; AddToList(po);

    PrintAllTowns();
    
    po = SearchTown("Paris"); 
    DeleteTown(po);
    
    printf("\n\n");
    PrintAllTowns();
    printf("\n\n");
    
    SortTowns();
    PrintAllTowns();

    return 0;
}