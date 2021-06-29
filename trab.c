#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100


// = funcoes de calculo = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

void leMatriz(float mat[MAXSIZE][MAXSIZE], int size)
{
	int i, j;
	
    for(i = 0; i != size; i++){
        for(j = 0; j != size; j++){
            scanf("%f", &mat[i][j]);
        }   
    }
}

void leVetor(float vet[MAXSIZE], int size)
{
	int i;
	
    for(i = 0; i != size; i++){
        scanf("%f", &vet[i]);
    }
}

void imprimeMatriz(float mat[MAXSIZE][MAXSIZE], int size)
{
    int i, j;
	
    printf("s: %d\n", size);
    for(i = 0; i != size; i++){
        printf("[");
        for(j = 0; j != size; j++){
            printf(" %5.2f", mat[i][j]);
        }   
        printf(" ]\n");
    }
    printf("\n");
}

void imprimeVetor(float vet[MAXSIZE], int size)
{
    int i;
	
    printf("s: %d\n", size);
    printf("[");
    for(i = 0; i != size; i++){
        printf(" %5.2f", vet[i]);   
    }
    printf(" ]\n");
}

void imprimeInversa(float mat[MAXSIZE][MAXSIZE], int size) { //Se determinante = 0 então ão inversível
	int i, j;
	
    printf("s: %d\n", size);
    for(i = size; i >= 0; i--){
        printf("[");
        for(j = size; j >= 0; j--){
            printf(" %5.2f", mat[i][j]);
        }   
        printf(" ]\n");
    }
    printf("\n");
}

float determinante(float mat[MAXSIZE][MAXSIZE], int size)
{   
    // condicao de saida
    if(size == 1){
        return mat[0][0];
    }

	int i, j, k;
    float det = 0;
    float matAux[MAXSIZE][MAXSIZE];
    int pulouCol = 0;

    // calcula o determinante, utlizando a linha 1 pra multiplicar seus elementos por seus cofatores e soma-los
    for(i = 0; i != size; i++){
        pulouCol = 0;
        //gera matriz auxiliar pra obter o determinante
        for(j = 0; j != size; j++){
            if(i == j){
                pulouCol = 1;
                continue;
            }

            for(k = 1; k != size; k++){
                matAux[k - 1][j - pulouCol] = mat[k][j];
            } 
        }

        det += mat[0][i] * determinante(matAux, size - 1) * ((1 + (i + 1)) % 2 == 0 ? 1 : -1);
    }

    return det;
}

// = funcoes de rotinas = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

void rotinaDeterminante() 
{
    system("cls");
    int size;
    float mat[MAXSIZE][MAXSIZE];

    printf("insira a ordem da matriz: ");
    scanf("%d", &size);
    
    printf("insira a matriz: \n");
    leMatriz(mat, size);
    printf("\n");

    printf("o determinante da matriz eh: %f\n", determinante(mat, size));
    printf("pressione qualquer tecla para continuar...\n");
    getch();
}

void rotinaSistemaTriangularInferior()
{
	system("cls");
    int size;
    float mat[MAXSIZE][MAXSIZE];

    printf("insira a ordem da matriz: ");
    scanf("%d", &size);
    
    printf("insira a matriz: \n");
    leMatriz(mat, size);
    printf("\n");

    printf("insira o vetor de coeficientes: \n");
    leMatriz(mat, size);
    printf("\n");

    
    printf("pressione qualquer tecla para continuar...\n");
    getch();
}

void rotinaSistemaTriangularSuperior() 
{
	
}

void rotinaDecomposicaoLU() 
{
	
}

void rotinaCholesky()
{
	
}

void rotinaGaussCompacto() 
{
	
}

void rotinaGaussJordan() 
{
	
}

void rotinaJacobi() 
{
	
}

void rotinaGaussSeidel() 
{
	
}

void rotinaMatrizInversa() 
{
	system("cls");
    int size;
    float mat[MAXSIZE][MAXSIZE];

    printf("insira a ordem da matriz: ");
    scanf("%d", &size);
    
    printf("insira a matriz: \n");
    leMatriz(mat, size);
    printf("\n");
	
	determinante(mat, size);
	printf("Matriz normal: ");
	imprimeMatriz(mat, size);
	if(determinante(mat, size) == 0) {
		printf("Matriz nao inversivel\n");
	}
	else {
	printf("Matriz inversa: ");
	imprimeInversa(mat, size);
	}
	printf("\n");
	
	printf("pressione qualquer tecla para continuar...\n");
    getch();
}

// = main e funcoes gerais = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

int main()
{
    int op;
    do{
        system("cls");

        printf("selecione uma opcao:\n");
        printf("-------------------------\n");
        printf("\n");
        printf("01 - Calcular determinante\n");
        printf("02 - Calcular sistema triangular superior\n");
        printf("03 - Calcular sistema triangular inferior\n");
        printf("04 - Calcular decomposicao LU\n");
        printf("05 - Calcular rotina Cholesky\n");
        printf("06 - Calcular rotina Gauss Compacto\n");
        printf("07 - Calcular rotina Gauss Jordan\n");
        printf("08 - Calcular rotina Jacobi\n");
        printf("09 - Calcular rotina Gauss Seidel\n");
        printf("10 - Calcular matriz inversa\n");
        printf("11 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            rotinaDeterminante();
            break;
        
        case 2:
            rotinaSistemaTriangularInferior();
            break;

        case 3:
             rotinaSistemaTriangularSuperior();
            break;

        case 4:
            rotinaDecomposicaoLU();
            break;

        case 5:
            rotinaCholesky();
            break;

        case 6:
            rotinaGaussCompacto();
            break;

        case 7:
            rotinaGaussJordan();
            break;

        case 8:
            rotinaJacobi();
            break;

        case 9:
            rotinaGaussSeidel();
            break;

        case 10:
            rotinaMatrizInversa();
            break;
        default:
        	break;
        }
    }while(op != 11);
	return 0;
}
