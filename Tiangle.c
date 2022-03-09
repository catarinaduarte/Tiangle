#include <stdio.h>

void desenhaLinha(int linha, int nivel, int totalNiveis )
{
    // 0, 2, 5
    for(int i = 0; i != totalNiveis - linha - 1; ++i)
        printf( "%c", '.' );
    for(int i = 0; i != 2 * linha + 1; ++i)
        printf( "%c", '*' );

    printf( "\n" );
}

void desenhaNivel( int n, int totalNiveis, int ord )
{
    if( !ord ) // ( ord == 0 )
        for(int i = 0; i != n; ++i)
            desenhaLinha( i, n, totalNiveis );
   else
        for(int i = n - 1; i >= 0; --i)
            desenhaLinha( i, n, totalNiveis );
}

void desenhaArvore( int n, int ord )
{
    if( !ord ) // ( ord== 0 )
        for(int i = 1; i <= n; ++i)
            desenhaNivel( i, n, ord );
    else
        for(int i = n; i >= 1; --i)
            desenhaNivel( i, n, ord );
}

int main()
{
    printf( "Quantos niveis? " );
    int n;
    scanf( "%d", &n );

    printf( "Ordem (0=direta, 1=inversa) ? " );
    int ordem;
    scanf( "%d", &ordem );

    if( ( n <= 0 ) || ( ordem != 0 && ordem != 1 ) ) 
        printf( "Nivel ou ordem inválidos!\n" );
    else
        desenhaArvore( n, ordem );

    return 0;
}
