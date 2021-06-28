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
        printf("02 - \n");
        printf("03 - \n");
        printf("04 - \n");
        printf("05 - \n");
        printf("06 - \n");
        printf("07 - \n");
        printf("08 - \n");
        printf("09 - \n");
        printf("10 - \n");
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
