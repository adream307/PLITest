#include"veriuser.h"
#include"acc_user.h"

int test(int,int);

int test_sizetf()
{
    return 8;
}

int test_calltf()
{
    int x,y,r;
    x=tf_getp(1);
    y=tf_getp(2);
    r=test(x,y);
    tf_putp(0,r);
    return 0;
}

int test_checktf()
{
    bool err=FALSE;
    if(tf_nump()!=2){
        tf_error("$test requires exactly 2 arguments.\n");
        err=TRUE;
    }
    if(tf_typep(1) == tf_nullparam){
        tf_error("$test's first argument can't be null");
        err=TRUE;
    }
    if(tf_typep(2) == tf_nullparam){
        tf_error("$test's second argument can't be null");
        err=TRUE;
    }
    if(tf_sizep(1)>8){
        tf_error("$test's first argument can't longer than 8 bits");
        err=TRUE;
    }
    if(tf_sizep(2)>8){
        tf_error("$test's second argument can't longer than 8 bits");
        err=TRUE;
    }
    if (err) {
        tf_message(ERR_ERROR, "", "", "");
    }
    return(0);
}

int test(int x,int y)
{
    return x+y;
}

s_tfcell veriusertfs[] =
{
    {userfunction,      // type of PLI routine - usertask or userfunction
     0,                 // user_data value
     test_checktf,      // checktf() routine
     test_sizetf,       // sizetf() routine
     test_calltf,       // calltf() routine
     0,                 // misctf() routine
     "$test"       // "$tfname" system task/function name
    },
    {0}                 // final entry must be 0
};
