#include "unit_tests.h"

TestSuite(student_tests, .timeout = TEST_TIMEOUT);

/*  ADD (10)  */

Test(student_tests, add1){
    int a[]={1,2,3,4}, b[]={5,6,7,8};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[0],6);
    free(A);free(B);free(R);
}

Test(student_tests, add2){
    int a[]={0,0,0,0}, b[]={1,1,1,1};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[3],1);
    free(A); free(B); free(R);
}

Test(student_tests, add3){
    int a[]={-1,-2,-3,-4}, b[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[2],0);
    free(A);free(B);free(R);
}

Test(student_tests, add4){
    int a[]={1}, b[]={2};
    matrix_sf*A=copy_matrix(1,1,a);
    matrix_sf*B=copy_matrix(1,1,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[0],3);
    free(A);free(B);free(R);
}

Test(student_tests, add5){
    int a[]={10,20}, b[]={30,40};
    matrix_sf*A=copy_matrix(1,2,a);
    matrix_sf*B=copy_matrix(1,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[1],60);
    free(A);free(B);free(R);
}

Test(student_tests, add6){
    int a[]={5,5,5,5}, b[]={5,5,5,5};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[0],10);
    free(A);free(B);free(R);
}

Test(student_tests, add7){
    int a[]={1,1,1,1}, b[]={-1,-1,-1,-1};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[1],0);
    free(A);free(B);free(R);
}

Test(student_tests, add8){
    int a[]={2,4,6,8}, b[]={1,3,5,7};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[3],15);
    free(A);free(B);free(R);
}

Test(student_tests, add9){
    int a[]={100}, b[]={200};
    matrix_sf*A=copy_matrix(1,1,a);
    matrix_sf*B=copy_matrix(1,1,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[0],300);
    free(A);free(B);free(R);
}

Test(student_tests, add10){
    int a[]={9,9,9,9}, b[]={1,1,1,1};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=add_mats_sf(A,B);
    cr_assert_eq(R->values[2],10);
    free(A);free(B);free(R);
}

/* MULT (10)  */

Test(student_tests, mult1){
    int a[]={1,2,3,4}, b[]={5,6,7,8};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],19);
    free(A);free(B);free(R);
}

Test(student_tests, mult2){
    int a[]={1,0,0,1}, b[]={2,2,2,2};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[3],2);
    free(A);free(B);free(R);
}

Test(student_tests, mult3){
    int a[]={2}, b[]={3};
    matrix_sf*A=copy_matrix(1,1,a);
    matrix_sf*B=copy_matrix(1,1,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],6);
    free(A);free(B);free(R);
}

Test(student_tests, mult4){
    int a[]={1,2}, b[]={3,4};
    matrix_sf*A=copy_matrix(1,2,a);
    matrix_sf*B=copy_matrix(2,1,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],11);
    free(A);free(B);free(R);
}

Test(student_tests, mult5){
    int a[]={0,0,0,0}, b[]={5,6,7,8};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],0);
    free(A);free(B);free(R);
}

Test(student_tests, mult6){
    int a[]={2,2,2,2}, b[]={2,2,2,2};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],8);
    free(A);free(B);free(R);
}

Test(student_tests, mult7){
    int a[]={3,3,3,3}, b[]={1,1,1,1};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[3],6);
    free(A);free(B);free(R);
}

Test(student_tests, mult8){
    int a[]={5}, b[]={5};
    matrix_sf*A=copy_matrix(1,1,a);
    matrix_sf*B=copy_matrix(1,1,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],25);
    free(A);free(B);free(R);
}

Test(student_tests, mult9){
    int a[]={1,2,3,4}, b[]={0,1,1,0};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[1],1);
    free(A);free(B);free(R);
}

Test(student_tests, mult10){
    int a[]={2,0,0,2}, b[]={2,0,0,2};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*B=copy_matrix(2,2,b);
    matrix_sf*R=mult_mats_sf(A,B);
    cr_assert_eq(R->values[0],4);
    free(A);free(B);free(R);
}

/* TRANSPOSE (10)  */

Test(student_tests, t1){
    int a[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[1],3);
    free(A);free(T);
}

Test(student_tests, t2){
    int a[]={1,2,3,4,5,6};
    matrix_sf*A=copy_matrix(2,3,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->num_rows,3);
    free(A);free(T);
}

Test(student_tests, t3){
    int a[]={5};
    matrix_sf*A=copy_matrix(1,1,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[0],5);
    free(A);free(T);
}

Test(student_tests, t4){
    int a[]={1,2};
    matrix_sf*A=copy_matrix(1,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->num_rows,2);
    free(A);free(T);
}

Test(student_tests, t5){
    int a[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[2],2);
    free(A);free(T);
}

Test(student_tests, t6){
    int a[]={9,8,7,6};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[1],7);
    free(A);free(T);
}

Test(student_tests, t7){
    int a[]={1,0,0,1};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[3],1);
    free(A);free(T);
}

Test(student_tests, t8){
    int a[]={2,3,4,5};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[0],2);
    free(A);free(T);
}

Test(student_tests, t9){
    int a[]={6,7,8,9};
    matrix_sf*A=copy_matrix(2,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->values[3],9);
    free(A);free(T);
}

Test(student_tests, t10){
    int a[]={1,2,3,4,5,6};
    matrix_sf*A=copy_matrix(3,2,a);
    matrix_sf*T=transpose_mat_sf(A);
    cr_assert_eq(T->num_cols,3);
    free(A);free(T);
}

/* CREATE (10) */

Test(student_tests, c1){
    matrix_sf*m=create_matrix_sf('A',"2 2 [1 2;3 4;]");
    cr_assert_eq(m->values[3],4);
    free(m);
}

Test(student_tests, c2){
    matrix_sf*m=create_matrix_sf('B',"1 1 [5;]");
    cr_assert_eq(m->values[0],5);
    free(m);
}

Test(student_tests, c3){
    matrix_sf*m=create_matrix_sf('C',"2 1 [3;4;]");
    cr_assert_eq(m->num_rows,2);
    free(m);
}

Test(student_tests, c4){
    matrix_sf*m=create_matrix_sf('D',"1 3 [1 2 3;]");
    cr_assert_eq(m->num_cols,3);
    free(m);
}

Test(student_tests, c5){
    matrix_sf*m=create_matrix_sf('E',"2 2 [0 0;0 0;]");
    cr_assert_eq(m->values[2],0);
    free(m);
}

Test(student_tests, c6){
    matrix_sf*m=create_matrix_sf('F',"2 2 [9 8;7 6;]");
    cr_assert_eq(m->values[1],8);
    free(m);
}

Test(student_tests, c7){
    matrix_sf*m=create_matrix_sf('G',"3 1 [1;2;3;]");
    cr_assert_eq(m->values[2],3);
    free(m);
}

Test(student_tests, c8){
    matrix_sf*m=create_matrix_sf('H',"1 2 [4 5;]");
    cr_assert_eq(m->values[1],5);
    free(m);
}

Test(student_tests, c9){
    matrix_sf*m=create_matrix_sf('I',"2 2 [2 2;2 2;]");
    cr_assert_eq(m->values[0],2);
    free(m);
}

Test(student_tests, c10){
    matrix_sf*m=create_matrix_sf('J',"2 2 [1 0;0 1;]");
    cr_assert_eq(m->values[3],1);
    free(m);
}

/* BST (10) */

Test(student_tests, b1){
    int a[]={1};
    matrix_sf*A=copy_matrix(1,1,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('A',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b2){
    int a[]={2};
    matrix_sf*A=copy_matrix(1,1,a); A->name='B';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('B',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b3){
    int a[]={3};
    matrix_sf*A=copy_matrix(1,1,a); A->name='C';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('X',root)==NULL);
    free_bst_sf(root);
}

Test(student_tests, b4){
    int a[]={1},b[]={2};
    matrix_sf*A=copy_matrix(1,1,a); A->name='A';
    matrix_sf*B=copy_matrix(1,1,b); B->name='B';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    root=insert_bst_sf(B,root);
    cr_assert(find_bst_sf('B',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b5){
    int a[]={1},b[]={2},c[]={3};
    matrix_sf*A=copy_matrix(1,1,a); A->name='A';
    matrix_sf*B=copy_matrix(1,1,b); B->name='B';
    matrix_sf*C=copy_matrix(1,1,c); C->name='C';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    root=insert_bst_sf(B,root);
    root=insert_bst_sf(C,root);
    cr_assert(find_bst_sf('C',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b6){
    bst_sf*root=NULL;
    cr_assert(find_bst_sf('A',root)==NULL);
}

Test(student_tests, b7){
    int a[]={5};
    matrix_sf*A=copy_matrix(1,1,a); A->name='Z';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('Z',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b8){
    int a[]={1};
    matrix_sf*A=copy_matrix(1,1,a); A->name='M';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    free_bst_sf(root);
    cr_assert(1);
}

Test(student_tests, b9){
    int a[]={7};
    matrix_sf*A=copy_matrix(1,1,a); A->name='Q';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('Q',root)!=NULL);
    free_bst_sf(root);
}

Test(student_tests, b10){
    int a[]={8};
    matrix_sf*A=copy_matrix(1,1,a); A->name='R';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    cr_assert(find_bst_sf('R',root)!=NULL);
    free_bst_sf(root);
}

/* POSTFIX (10) */

Test(student_tests, p1){
    char *p=infix2postfix_sf("A+B");
    cr_assert_str_eq(p,"AB+");
    free(p);
}

Test(student_tests, p2){
    char *p=infix2postfix_sf("A*B");
    cr_assert_str_eq(p,"AB*");
    free(p);
}

Test(student_tests, p3){
    char *p=infix2postfix_sf("A+B*C");
    cr_assert_str_eq(p,"ABC*+");
    free(p);
}

Test(student_tests, p4){
    char *p=infix2postfix_sf("(A+B)*C");
    cr_assert_str_eq(p,"AB+C*");
    free(p);
}

Test(student_tests, p5){
    char *p=infix2postfix_sf("A'");
    cr_assert_str_eq(p,"A'");
    free(p);
}

Test(student_tests, p6){
    char *p=infix2postfix_sf("A*B+C");
    cr_assert_str_eq(p,"AB*C+");
    free(p);
}

Test(student_tests, p7){
    char *p=infix2postfix_sf("A+B+C");
    cr_assert_str_eq(p,"AB+C+");
    free(p);
}

Test(student_tests, p8){
    char *p=infix2postfix_sf("(A+B)*(C+D)");
    cr_assert_str_eq(p,"AB+CD+*");
    free(p);
}

Test(student_tests, p9){
    char *p=infix2postfix_sf("A*(B+C)");
    cr_assert_str_eq(p,"ABC+*");
    free(p);
}

Test(student_tests, p10){
    char *p=infix2postfix_sf("A+B'");
    cr_assert_str_eq(p,"AB'+");
    free(p);
}

/* EVALUATE (10) */

Test(student_tests, e1){
    int a[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A+A",root);
    cr_assert_eq(R->values[0],2);
    free(R); free_bst_sf(root);
}

Test(student_tests, e2){
    int a[]={1,0,0,1};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A*A",root);
    cr_assert_eq(R->values[3],1);
    free(R); free_bst_sf(root);
}

Test(student_tests, e3){
    int a[]={2,2,2,2};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A+A",root);
    cr_assert_eq(R->values[0],4);
    free(R); free_bst_sf(root);
}

Test(student_tests, e4){
    int a[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A*A",root);
    cr_assert_eq(R->values[0],7);
    free(R); free_bst_sf(root);
}

Test(student_tests, e5){
    int a[]={3};
    matrix_sf*A=copy_matrix(1,1,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A+A",root);
    cr_assert_eq(R->values[0],6);
    free(R); free_bst_sf(root);
}

Test(student_tests, e6){
    int a[]={4};
    matrix_sf*A=copy_matrix(1,1,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A*A",root);
    cr_assert_eq(R->values[0],16);
    free(R); free_bst_sf(root);
}

Test(student_tests, e7){
    int a[]={1,2,3,4};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A'",root);
    cr_assert_eq(R->values[1],3);
    free(R); free_bst_sf(root);
}

Test(student_tests, e8){
    int a[]={1,1,1,1};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A+A",root);
    cr_assert_eq(R->values[2],2);
    free(R); free_bst_sf(root);
}

Test(student_tests, e9){
    int a[]={2,3,4,5};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A+A",root);
    cr_assert_eq(R->values[3],10);
    free(R); free_bst_sf(root);
}

Test(student_tests, e10){
    int a[]={2,0,0,2};
    matrix_sf*A=copy_matrix(2,2,a); A->name='A';
    bst_sf*root=NULL;
    root=insert_bst_sf(A,root);
    matrix_sf*R=evaluate_expr_sf('B',"A*A",root);
    cr_assert_eq(R->values[0],4);
    free(R); free_bst_sf(root);
}

/* EXECUTE SCRIPT (10) */

Test(student_tests, s1){
    FILE*f=fopen("t1.txt","w");
    fprintf(f,"A = 2 2 [1 2;3 4;]\nB = A + A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t1.txt");
    cr_assert_eq(R->values[0],2);
    free(R);
}

Test(student_tests, s2){
    FILE*f=fopen("t2.txt","w");
    fprintf(f,"A = 2 2 [1 0;0 1;]\nB = A * A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t2.txt");
    cr_assert_eq(R->values[3],1);
    free(R);
}

Test(student_tests, s3){
    FILE*f=fopen("t3.txt","w");
    fprintf(f,"A = 1 1 [2;]\nB = A + A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t3.txt");
    cr_assert_eq(R->values[0],4);
    free(R);
}

Test(student_tests, s4){
    FILE*f=fopen("t4.txt","w");
    fprintf(f,"A = 1 1 [3;]\nB = A * A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t4.txt");
    cr_assert_eq(R->values[0],9);
    free(R);
}

Test(student_tests, s5){
    FILE*f=fopen("t5.txt","w");
    fprintf(f,"A = 2 2 [1 1;1 1;]\nB = A + A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t5.txt");
    cr_assert_eq(R->values[0],2);
    free(R);
}

Test(student_tests, s6){
    FILE*f=fopen("t6.txt","w");
    fprintf(f,"A = 2 2 [2 2;2 2;]\nB = A * A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t6.txt");
    cr_assert_eq(R->values[0],8);
    free(R);
}

Test(student_tests, s7){
    FILE*f=fopen("t7.txt","w");
    fprintf(f,"A = 2 2 [1 2;3 4;]\nB = A'\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t7.txt");
    cr_assert_eq(R->values[1],3);
    free(R);
}

Test(student_tests, s8){
    FILE*f=fopen("t8.txt","w");
    fprintf(f,"A = 1 1 [5;]\nB = A + A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t8.txt");
    cr_assert_eq(R->values[0],10);
    free(R);
}

Test(student_tests, s9){
    FILE*f=fopen("t9.txt","w");
    fprintf(f,"A = 1 1 [6;]\nB = A * A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t9.txt");
    cr_assert_eq(R->values[0],36);
    free(R);
}

Test(student_tests, s10){
    FILE*f=fopen("t10.txt","w");
    fprintf(f,"A = 2 2 [1 0;0 1;]\nB = A + A\n");
    fclose(f);
    matrix_sf*R=execute_script_sf("t10.txt");
    cr_assert_eq(R->values[3],2);
    free(R);
}