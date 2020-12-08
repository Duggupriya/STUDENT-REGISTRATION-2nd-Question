#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include "slist.h"

void test_slist_new(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    assert(slist_length(list)==0);
}

void test_blist_new(){
    Bda b1 = bda_new();
    Bda *blist = &b1;
    assert(blist_length(blist)==0);
}

void test_mlist_new(){
    Ml m1 = ml_new();
    Ml *mlist = &m1;
    assert(mlist_length(mlist)==0);
}

void test_add(){
    Slist s1 = slist_new();
    Slist *list = &s1;
    Bda b1 = bda_new();
    Bda *blist = &b1;
    Ml m1 = ml_new();
    Ml *mlist = &m1;
    list=add_pgms(list,blist,mlist);
    assert(slist_length(list)==2);
    blist=add_node(list,blist,mlist,"priyanshu",23,1,1,18);
    assert(list->max==18);
    assert(blist_length(blist)==1);
    mlist=add_node(list,blist,mlist,"dugaya",55,2,2,12);
    assert(list->max==18);
    assert(maximum_marks(list)=="priyanshu");
    assert(mlist_length(mlist)==1);
}
int main()
{
    test_slist_new();
    test_mlist_new();
    test_blist_new();
    test_add();
    return 0;
}
