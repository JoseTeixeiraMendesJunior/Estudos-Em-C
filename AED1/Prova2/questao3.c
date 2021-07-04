#include<stdio.h>
#include<stdlib.h>
 
// cada paciente passa pela triagem, na qual sao registrados o horario de entrada e quantos minutos para que 
// seu quadro de saude fique critico. O ENFERMEIRO NUNCA ERRA..
 
// OS pacientes sao atendidos de 30 em 30 mimnutos.
// atendimentos sao inciados em horas cheias ou meia-horas
// incio 7:00
// ate o ultimo paciente da fila.
 
typedef struct FilaDoSUS
{
    unsigned int h; 
    unsigned int m;
    unsigned int c;
}filas;
 
int estado_critico(unsigned int h, unsigned int m, unsigned int c, filas * atend)
{

    if(atend->m == 30)
    {
        atend->m = 0;
        atend->h += 1;
    }else{
        atend->m = 30;
    }


    if(h >= atend->h)
    {
        if(h > atend->h)
        {
            atend->h = h;
            if(m < 30)
            {
                atend->m = 0;
            }else {
                atend->m = 30;
            }
            return(0);
        }
        else {
            if(m >= atend->h)
            {
                atend->h = h;
                if(m < 30)
                {
                    atend->m = 0;
                }else {
                    atend->m = 30;
                }
                return(0);  
            }
        }
    }
 
    
 
    m += c;
    
    if(m >= 60)
    {
        h += m/60;
        m = m%60;
    }
 
    if(h < atend->h)
    {
        return(1);
    }else if((h == atend->h) && (m < atend->m))
    {
        return(1);
    }
    
    return (0);
}
 
 
int main()
{
 
unsigned int N, i, cont = 0;

scanf("%u",&N);
 
filas fila[N];
filas atend;
atend.h = 6;
atend.m = 30;
atend.c = 0;
 
for(i = 0; i < N; i++)
{
    scanf("%u %u %u",&fila[i].h, &fila[i].m, &fila[i].c);
}
 
for(i = 0; i < N; i++)
{
    cont += estado_critico(fila[i].h, fila[i].m, fila[i].c, &atend);
}
printf("%u\n",cont);
 
    return(0);
}