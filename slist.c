#include "slist.h"
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


Slist slist_new(){
    Slist s1 = {NULL,NULL,0,0};
    return s1;
}

Bda bda_new(){
    Bda b1 = {NULL,NULL,0};
    return b1;
}

Ml ml_new(){
    Ml m1 = {NULL,NULL,0};
    return m1;
}

static Node* _get_new_node(char *name,int32_t regno,int32_t grade,int8_t pgm,float marks){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->name=name;
    newnode->regno=regno;
    newnode->marks=marks;
    newnode->pgm=pgm;
    newnode->grade=grade;
    newnode->next=NULL;
    return newnode;
}

Slist *add_pgms(Slist *list,Bda *blist,Ml *mlist){
    assert(list!=NULL && blist!=NULL && mlist!=NULL);
    list->head=blist;
    ++list->count;
    list->tail=mlist;
    ++list->count;

    return list;
}

Bda* add_node(Slist *list,Bda *blist,Ml *mlist,char* name,int32_t regno, int32_t grade, int8_t pgm, float marks){
    assert(list!=NULL && blist!=NULL);
    Node *newnode = _get_new_node(name,regno,grade,pgm,marks);
    if (newnode->pgm == 1){
        if(newnode->marks>list->max){
            list->max=newnode->marks;
            list->name=newnode->name;
        }

        newnode->next=blist->head;
        if(blist->head == NULL){
            blist->head=newnode;
            blist->tail=newnode;
        }else{
            blist->head=newnode;
        }
        ++ blist->length;
        ++list->count;
        assert(blist->length == 1 && blist->head==blist->tail || blist->length>1 && blist->head!=blist->tail);
        return blist;
        }
     else if(newnode->pgm==2){
            if(newnode->marks>list->max){
            list->max=newnode->marks;
        }

        newnode->next=mlist->head;
        if(mlist->head == NULL){
            mlist->head=newnode;
            mlist->tail=newnode;
        }else{
            mlist->head=newnode;
        }
        ++mlist->length;
        ++list->count;
        assert(mlist->length == 1 && mlist->head==mlist->tail || mlist->length>1 && mlist->head!=mlist->tail);
        return mlist;
        }

     }

uint32_t slist_length(Slist *list){
    assert(list!=NULL);
    return list->count;
}
uint32_t blist_length(Bda *blist){
    assert(blist!=NULL);
    return blist->length;
}
uint32_t mlist_length(Ml *mlist){
    assert(mlist!=NULL);
    return mlist->length;
}
char* maximum_marks(Slist *list){
    assert(list!=NULL);
    return list->name;
}



