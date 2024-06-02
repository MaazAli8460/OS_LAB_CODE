# include <stdio.h>
# include <stdlib.h>
# include &lt;pthread . h&gt;
/ * t h i s f u n c t i o n i s run by t h e s e cond
t h r e a d

/ i ncre me nt x t o * /
p r i n t f ( &quot; Thread : Process Id i s %d and Thread Id i s %ld\n&quot; , getpid ( )
, pt hr e a d_s e l f ( ) ) ;

i n t * input ;
input =( i n t * ) arg ;
while ( ++(* input ) &lt; 1 0 0 ) ;
p r i n t f ( &quot; x increment f i n i s h e d\n&quot; ) ;
/ * t h e f u n c t i o n must r e turn something − NULL w i l l do
pthread_exit (NULL) ;
}
void main ( ) { / / main Thread
i n t x = 0 , y = 0 ;
/ * show t h e i n i t i a l v a l u e s o f x and y * /
p r i n t f ( &quot; x : %d , y : %d\n &quot; , x , y ) ;
p r i n t f ( &quot; main : Process Id i s %d and Thread Id i s %ld\n&quot; , getpid ( )
, pt hr e a d_s e l f ( ) ) ;

/ * t h i s v a r i a b l e i s our r e f e r e n c e t o t h e s e cond t
pthread_t thread_2 ;
/ * c r e a t e a s e co nd
( pthread_create (&amp; thread_2 , NULL, inc_x , &amp;x ) )
/ * i nc r e m e nt y t o 100 in t h e f i r s t t h
r e a d * /
while (++y &lt; 1 0 0 ) ;
/ * w ai t f o r t h e s e co nd t h r e a d t o f i n
( pthread_join ( thread_2 , NULL) ) ;

t

/ * show t h e r e s u l t s − x i s now 100 t h an k s
p r i n t f ( &quot; x : %d , y : %d\n &quot; , x

t o t h e

pthread_exit (NULL) ;
}
