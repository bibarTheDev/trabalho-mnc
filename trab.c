#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 100

float coeficiente[MAXSIZE][MAXSIZE];
float Dinv[MAXSIZE][MAXSIZE];
float approx[MAXSIZE][1];
float R[MAXSIZE][MAXSIZE];
float matrizRes[MAXSIZE][1];
float b[MAXSIZE][1];
float temp[MAXSIZE][1];
int linha,coluna,size,navigate;


// = funcoes de calculo = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

int checarFloatZero(float f)
{
    return (abs(f) < 0.00001) ? 1 : 0;
}

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

void calcularInversa(float mat[MAXSIZE][MAXSIZE], int size, float s[MAXSIZE][MAXSIZE]) {
	int i, j, k = 0;
	float ident[i][j], pivo = 0, p = 0, m = 0;
	for(i = 0; i != size; i++) {
		for(j = 0; j != size; j++) {
			if(i == j) {
				ident[i][j] = 1;
			}
			else {
				ident[i][j] = 0;
			}
		}
	}
	for(j = 0; j != size; j++) {
		pivo = mat[i][j];
		p = pivo/pivo;
		for(k = j; k != size; k++) {
			mat[j][k] = (mat[j][k])/(pivo);
			ident[j][k] = (ident[j][k])/(pivo);
		}
		for(i = 0; i != size; i++) {
			if(i != j) {
				m = mat[i][j]/p;
				for( k = 0; k != size; k++) {
					mat[i][k] = (mat[i][k]) - (m * ident[j][k]);
				}
			}
		}
	}
}

int checarTriangularInferior(float mat[MAXSIZE][MAXSIZE], int size)
{
    int i, j;

    // itera sobre a matriz
    for(i = 0; i != size; i++){
        for(j = 0; j != size; j++){
            // se algum elemento acima da diagonal for diferente de zero, retorna falso
            if(j > i && checarFloatZero(mat[i][j]) == 0){
                return 0;
            }
            // se algum elemento da diagoal eh zero
            else if(j == i && checarFloatZero(mat[i][j]) == 1){
                return 0;
            }
        }
    }
    
    return 1;
}

int checarTriangularSuperior(float mat[MAXSIZE][MAXSIZE], int size)
{
    int i, j;

    // itera sobre a matriz
    for(i = 0; i != size; i++){
        for(j = 0; j != size; j++){
            // se algum elemento acima da diagonal for diferente de zero, retorna falso
            if(j < i && checarFloatZero(mat[i][j]) == 0){
                return 0;
            }
            // se algum elemento da diagoal eh zero
            else if(j == i && checarFloatZero(mat[i][j]) == 1){
                return 0;
            }
        }
    }
    
    return 1;
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

void triangularInferior(float mat[MAXSIZE][MAXSIZE], int size, float termos[MAXSIZE], float s[MAXSIZE])
{
    int i, j;

    for(i = 0; i != size; i++){
        s[i] = termos[i];
        for(j = 0; j != i; j++){
            s[i] -= mat[i][j] * s[j];
        }
        s[i] /= mat[i][i];
    }    
}

void triangularSuperior(float mat[MAXSIZE][MAXSIZE], int size, float termos[MAXSIZE], float s[MAXSIZE])
{
    int i, j;

    for(i = (size - 1); i != -1; i--){
        s[i] = termos[i];
        for(j = (size - 1); j != i; j--){
            s[i] -= mat[i][j] * s[j];
        }
        s[i] /= mat[i][i];
    }    
}

void multiply(float matrizA[][MAXSIZE],float matrizB[][1]){
    int ctr,ictr;

    for(ctr=0;ctr<size;ctr++){
        matrizRes[ctr][0]=0;
            for(navigate=0;navigate<size;navigate++)
                matrizRes[ctr][0]=matrizRes[ctr][0]+matrizA[ctr][navigate]*matrizB[navigate][0];
    }

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
    float termos[MAXSIZE], s[MAXSIZE];
    float mat[MAXSIZE][MAXSIZE];

    printf("insira a ordem da matriz: ");
    scanf("%d", &size);
    
    printf("insira a matriz: \n");
    leMatriz(mat, size);
    printf("\n");

    if(checarTriangularInferior(mat, size) != 1){
        printf("esta matriz nao eh triangular inferior\n");
        printf("pressione qualquer tecla para continuar...\n");
        getch();

        return;
    }

    printf("insira o vetor de termos independentes: \n");
    leVetor(termos, size);
    printf("\n");

    triangularInferior(mat, size, termos, s);
    printf("o vetor solucao da matriz eh: \n");
    imprimeVetor(s, size);

    printf("pressione qualquer tecla para continuar...\n");
    getch();
}

void rotinaSistemaTriangularSuperior() 
{
	system("cls");
    int size;
    float termos[MAXSIZE], s[MAXSIZE];
    float mat[MAXSIZE][MAXSIZE];

    printf("insira a ordem da matriz: ");
    scanf("%d", &size);
    
    printf("insira a matriz: \n");
    leMatriz(mat, size);
    printf("\n");

    if(checarTriangularSuperior(mat, size) != 1){
        printf("esta matriz nao eh triangular superior\n");
        printf("pressione qualquer tecla para continuar...\n");
        getch();

        return;
    }

    printf("insira o vetor de termos independentes: \n");
    leVetor(termos, size);
    printf("\n");

    triangularSuperior(mat, size, termos, s);
    printf("o vetor solucao da matriz eh: \n");
    imprimeVetor(s, size);

    printf("pressione qualquer tecla para continuar...\n");
    getch();
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
    int i, j, k, n, l;
    float A[MAXSIZE][MAXSIZE], c, x[MAXSIZE];

    printf("\nDigite o tamanho da matriz: ");
    scanf_s("%d", &n);

    printf("\nDigite os elementos da matriz:\n");
    for(i=1; i<=n; i++){
        for(j=1; j<=(n+1); j++){
            scanf_s("%f", &A[i][j]);
        }
    }

    printf("\nDigite o valor do vetor dos termos independentes: ");
    scanf_s("%d", &l);

    for(j=1; j<=n; j++){
        for(i=1; i<=n; i++){
            if(i!=j){
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++){
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    printf("\nA solucao eh:\n");
    for(i=1; i<=n; i++){
        x[i] = A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n", i, x[i]);
    }
}

void rotinaJacobi()
{

    printf("Digite o numero desconhecido\n");
    scanf("%d",&size);

    printf("Digite o coeficiente da matriz\n");
    for(linha=0;linha<size;linha++)
        for(coluna=0;coluna<size;coluna++)
            scanf("%f",&coeficiente[linha][coluna]);

    printf("Digite a primeira aproximacao\n");
    for(linha=0;linha<size;linha++)
    scanf("%f",&approx[linha][0]);
    
    printf("Digite o coeficiente RHS\n");
    for(linha=0;linha<size;linha++)
    scanf("%f",&b[linha][0]);

    for(linha=0;linha<size;linha++)
        for(coluna=0;coluna<size;coluna++){
            if(linha==coluna)
            Dinv[linha][coluna]=1/coeficiente[linha][coluna];
            else
            Dinv[linha][coluna]=0;
        }

    for(linha=0;linha<size;linha++)
        for(coluna=0;coluna<size;coluna++){
            if(linha==coluna)
            R[linha][coluna]=0;
            else
            if(linha!=coluna)
            R[linha][coluna]=coeficiente[linha][coluna];
        }

    int iter;
    printf("Digite o numero de iteracoes:\n");
    scanf("%d",&iter);

    int ctr=1;
    int octr;

    while(ctr<=iter){
        multiply(R,approx);
        for(linha=0;linha<size;linha++)
        temp[linha][0]=b[linha][0]-matrizRes[linha][0];
        multiply(Dinv,temp);
        for(octr=0;octr<size;octr++)
        approx[octr][0]=matrizRes[octr][0];
        printf("O valor apos a iteracao %d eh\n",ctr);
        for(linha=0;linha<size;linha++)
        printf("%.3f\n",approx[linha][0]);
        ctr++;
    }
    getch();

}

void rotinaGaussSeidel() 
{
	
}

void rotinaMatrizInversa() 
{
	system("cls");
    int size;
    float mat[MAXSIZE][MAXSIZE], s[MAXSIZE][MAXSIZE];

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
	printf("Matriz inversa: \n");
    calcularInversa(mat, size, s);
    imprimeMatriz(s, size);
    
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
