#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED
#include <stdint.h>
#include "appconst.h"

typedef struct _slist_ Slist;
struct _slist_{
    Slist *head;
    Slist *tail;
    int32_t count;
    int32_t max;
    char* name;
};

typedef struct _slist_bda_ Bda;
struct _slist_bda_{
    Bda *head;
    Bda *tail;
    int32_t length;
};

typedef struct _slist_ml_ Ml;
struct _slist_ml_{
    Ml *head;
    Ml *tail;
    int32_t length;
};

typedef struct _node_ Node;
struct _node_{
    char* name;
    int32_t regno;
    int32_t grade;
    int8_t pgm;
    float marks;
    Node *next;
};

Slist slist_new();
Bda bda_new();
Ml ml_new();
Slist *add_pgms(Slist *list,Bda *blist,Ml *mlist);
Bda* add_node(Slist *list,Bda *blist,Ml *mlist,char* name,int32_t regno, int32_t grade, int8_t pgm, float marks);
uint32_t slist_length(Slist *list);
uint32_t blist_length(Bda *blist);
uint32_t mlist_length(Ml *mlist);
char* maximum_marks(Slist *list);


#endif // SLIST_H_INCLUDED
