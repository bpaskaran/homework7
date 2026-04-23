#include "hw7.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/* BST  */

bst_sf* insert_bst_sf(matrix_sf *mat, bst_sf *root){

    if(root==NULL){
        bst_sf *n = malloc(sizeof(bst_sf));
        n->mat = mat;
        n->left_child = NULL;
        n->right_child = NULL;
        return n;
    }

    if(mat->name < root->mat->name){
        root->left_child = insert_bst_sf(mat, root->left_child);
    } else {
        root->right_child = insert_bst_sf(mat, root->right_child);
    }

    return root;
}

matrix_sf* find_bst_sf(char name, bst_sf *root){

    if(root==NULL) return NULL;

    if(root->mat->name == name) return root->mat;

    if(name < root->mat->name){
        return find_bst_sf(name, root->left_child);
    } else {
        return find_bst_sf(name, root->right_child);
    }
}

void free_bst_sf(bst_sf *root){

    if(root==NULL) return;

    free_bst_sf(root->left_child);
    free_bst_sf(root->right_child);

    free(root->mat);
    free(root);
}


/*  MATRIX OPS  */

matrix_sf* add_mats_sf(const matrix_sf *a, const matrix_sf *b){

    if(a==NULL || b==NULL) return NULL;

    if(a->num_rows != b->num_rows || a->num_cols != b->num_cols){
        return NULL;
    }

    int r = a->num_rows;
    int c = a->num_cols;

    matrix_sf *res = malloc(sizeof(matrix_sf) + r*c*sizeof(int));
    res->name='?';
    res->num_rows = r;
    res->num_cols = c;

    int i;
    for(i=0;i<r*c;i++){
        res->values[i] = a->values[i] + b->values[i];
    }

    return res;
}

matrix_sf* mult_mats_sf(const matrix_sf *a, const matrix_sf *b){

    if(a==NULL || b==NULL) return NULL;
    if(a->num_cols != b->num_rows) return NULL;

    int r = a->num_rows;
    int c = a->num_cols;
    int c2 = b->num_cols;

    matrix_sf *res = malloc(sizeof(matrix_sf) + r*c2*sizeof(int));
    res->name='?';
    res->num_rows = r;
    res->num_cols = c2;

    int i,j,k;

    for(i=0;i<r;i++){
        for(j=0;j<c2;j++){

            int sum = 0;

            for(k=0;k<c;k++){
                sum += a->values[i*c + k] * b->values[k*c2 + j];
            }

            res->values[i*c2 + j] = sum;
        }
    }

    return res;
}

matrix_sf* transpose_mat_sf(const matrix_sf *m){

    int r = m->num_rows;
    int c = m->num_cols;

    matrix_sf *res = malloc(sizeof(matrix_sf) + r*c*sizeof(int));
    res->name='?';
    res->num_rows = c;
    res->num_cols = r;

    int i,j;

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            res->values[j*r + i] = m->values[i*c + j];
        }
    }

    return res;
}


/* CREATE MATRIX */

matrix_sf* create_matrix_sf(char name, const char *expr){

    int rows,cols;
    const char *p = expr;

    while(*p && isspace(*p)) p++;
    rows = atoi(p);

    while(*p && !isspace(*p)) p++;
    while(*p && isspace(*p)) p++;
    cols = atoi(p);

    while(*p && *p!='[') p++;
    p++;

    matrix_sf *m = malloc(sizeof(matrix_sf) + rows*cols*sizeof(int));

    m->name = name;
    m->num_rows = rows;
    m->num_cols = cols;

    int i = 0;

    while(*p && *p!=']'){

        if(*p==';'){
            p++;
            continue;
        }

        if(!isspace(*p)){
            m->values[i] = strtol(p,(char**)&p,10);
            i++;
        } else {
            p++;
        }
    }

    return m;
}


/* INFIX TO POSTFIX  */

int prec(char c){
    if(c=='*') return 2;
    if(c=='+') return 1;
    return 0;
}

char* infix2postfix_sf(char *infix){

    char *out = malloc(strlen(infix)+1);
    char stack[256];

    int top=-1;
    int j=0;

    int i;
    for(i=0;infix[i];i++){

        char c = infix[i];

        if(isspace(c)) continue;

        if(isalpha(c)){
            out[j++] = c;
        }
        else if(c=='\''){
            out[j++] = c;
        }
        else if(c=='('){
            stack[++top] = c;
        }
        else if(c==')'){
            while(top>=0 && stack[top]!='('){
                out[j++] = stack[top--];
            }
            top--;
        }
        else if(c=='+' || c=='*'){

            while(top>=0 && prec(stack[top]) >= prec(c)){
                out[j++] = stack[top--];
            }

            stack[++top] = c;
        }
    }

    while(top>=0){
        out[j++] = stack[top--];
    }

    out[j] = '\0';
    return out;
}


/* EVALUATE */

matrix_sf* evaluate_expr_sf(char name, char *expr, bst_sf *root){

    char *post = infix2postfix_sf(expr);

    matrix_sf *stack[256];
    int top=-1;

    int i;
    for(i=0;post[i];i++){

        char c = post[i];

        if(isalpha(c)){
            stack[++top] = find_bst_sf(c, root);
        }
        else if(c=='\''){

            matrix_sf *a = stack[top--];
            matrix_sf *tmp = transpose_mat_sf(a);

            if(!isalpha(a->name)){
                free(a);
            }

            stack[++top] = tmp;
        }
        else if(c=='+' || c=='*'){

            matrix_sf *b = stack[top--];
            matrix_sf *a = stack[top--];

            matrix_sf *tmp;

            if(c=='+'){
                tmp = add_mats_sf(a,b);
            } else {
                tmp = mult_mats_sf(a,b);
            }

            if(!isalpha(a->name)) free(a);
            if(!isalpha(b->name)) free(b);

            stack[++top] = tmp;
        }
    }

    matrix_sf *res = stack[top];
    res->name = name;

    free(post);
    return res;
}


/* SCRIPT */

matrix_sf* execute_script_sf(char *filename){

    FILE *f = fopen(filename,"r");

    char *line=NULL;
    size_t len=0;

    bst_sf *root=NULL;
    matrix_sf *last=NULL;

    while(getline(&line,&len,f)!=-1){

        char name = line[0];

        char *eq = strchr(line,'=');
        eq++;

        if(strchr(eq,'[')){
            matrix_sf *m = create_matrix_sf(name,eq);
            root = insert_bst_sf(m,root);
            last = m;
        } else {
            matrix_sf *m = evaluate_expr_sf(name,eq,root);
            root = insert_bst_sf(m,root);
            last = m;
        }
    }

    matrix_sf *final = copy_matrix(last->num_rows,last->num_cols,last->values);
    final->name = last->name;

    free_bst_sf(root);
    free(line);
    fclose(f);

    return final;
}


/* REQUIRED */

matrix_sf* copy_matrix(unsigned int r,unsigned int c,int values[]){

    matrix_sf *m = malloc(sizeof(matrix_sf)+r*c*sizeof(int));

    m->name='?';
    m->num_rows=r;
    m->num_cols=c;

    memcpy(m->values,values,r*c*sizeof(int));

    return m;
}

void print_matrix_sf(matrix_sf *mat){

    assert(mat!=NULL);

    printf("%d %d ",mat->num_rows,mat->num_cols);

    unsigned int i;
    for(i=0;i<mat->num_rows * mat->num_cols;i++){
        printf("%d",mat->values[i]);
        if(i < mat->num_rows * mat->num_cols - 1){
            printf(" ");
        }
    }

    printf("\n");
}