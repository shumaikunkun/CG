   # i n c l u d e   " s t d a f x . h "  

 # i n c l u d e   < c s t d l i b >  
 # i n c l u d e   < G L / g l u t . h >  
 # d e f i n e   _ U S E _ M A T H _ D E F I N E S 	 / /   V i s u a l   S t u d i o   g0  �QhT�sh0W0f0�[pe  M _ P I   �0O(uY0�0_0�0 
 # i n c l u d e   < c m a t h >  
  
 # d e f i n e   M _ P I   3 . 1 4 1 5 9 2 6 5  
  
 / /   r�n0�`1X�0<h}Y0�0qQ(uSO 
 u n i o n   c o l o r   {  
 	 s t r u c t   {   f l o a t   r ,   g ,   b ,   a ;   } ;  
 	 f l o a t   c o l o r s [ 4 ] ;  
 } ;  
  
 / /   P0n0�0�0�0�0�0�0n0r��00�PM0҉�^k0��Y0�0�`1X�0�OcY0�0_0�0n0�i �SO 
 s t r u c t   T e a p o t D a t a   {  
 	 c o l o r   a m b i e n t ,   d i f f u s e ,   s p e c u l a r ;  
 	 f l o a t   s h i n i n e s s ,   a n g l e ;  
 } ;  
  
 / /   �0�0�0�0�0	Ype��0�0�0�0�0-Nn0i0S0K0�0g0�0�0�0�0�0g0M0�0	Ype	�k0o0  g _   �0�NQ0f0D0�0 
 c o n s t   i n t   g _ N u m T e a p o t s   =   8 ;     / / �0�0�0�0�0�0n0pe 
 T e a p o t D a t a   g _ T e a p o t s [ g _ N u m T e a p o t s ] ;  
  
 / /   f l o a t �Wn0$Po00peW[n0�_�0k0f �0�NQ0�00+g>\n0�0�0o0weug0M0�0 
 c o n s t   f l o a t   g _ T e a p o t S i z e   =   1 . f ;  
 c o n s t   f l o a t   g _ I n n e r R a d i u s   =   6 . f ;  
 c o n s t   f l o a t   g _ O u t e r R a d i u s   =   7 . 5 f ;  
 c o n s t   f l o a t   g _ H e i g h t A m p l i t u d e   =   0 . 8 f ;  
 c o n s t   f l o a t   g _ H e i g h t O f f s e t   =   0 . 2 f ;     / / �0�0�0�0�0�0n0ؚU0 
  
 c o n s t   f l o a t   g _ E y e C e n t e r Y   =   1 0 . f ;     / / 'YM0Q0�0p0���pL0ؚO0j0�0 
 c o n s t   f l o a t   g _ E y e C e n t e r Z   =   3 0 . f ;     / / 'YM0Q0�0p0���pL0`�O0j0�0 
 c o n s t   f l o a t   g _ E y e R a d i u s   =   8 . f ;  
 f l o a t   g _ E y e Y ,   g _ E y e Z ;  
  
 c o n s t   i n t   g _ A n i m a t i o n I n t e r v a l M s e c   =   1 0 ;  
  
 f l o a t   g _ R o t a t i o n D e g r e e   =   0 . f ;     / / �RD0_0҉�^�0�OX[  0 . 0   0 . 3   0 . 6   0 . 9   1 . 2 . . .  
 c o n s t   f l o a t   g _ D e l t a R o t a t i o n D e g r e e   =   0 . 3 ;     / / ���RW0f0D0O0$P 
  
 i n t   g _ W i n d o w W i d t h   =   5 1 2 ;  
 i n t   g _ W i n d o w H e i g h t   =   5 1 2 ;  
  
 / /   �QR{�0�c;u& _peo0�Qn0JS�_0ؚU00�Qn0RrRpe 
 / /   g l u t k0o0�QR{�0�c;uY0�0_0�0n0��peL0!qD0n0g00�r��k0�n�P 
 v o i d   d i s p l a y C y l i n d e r ( f l o a t   r a d i u s ,   f l o a t   h e i g h t ,   i n t   n S l i c e s )   {  
 	 / /   )Y�b� 
 	 c o n s t   f l o a t   d e l t a T h e t a   =   2   *   M _ P I   /   ( f l o a t ) n S l i c e s ;  
  
 	 g l N o r m a l 3 f ( 0 ,   1 ,   0 ) ;  
 	 g l B e g i n ( G L _ T R I A N G L E _ F A N ) ;  
 	 g l V e r t e x 3 f ( 0 ,   h e i g h t ,   0 ) ;  
 	 f o r   ( i n t   i   =   0 ;   i   < =   n S l i c e s ;   i + + )   {  
 	 	 c o n s t   f l o a t   t h e t a   =   d e l t a T h e t a   *   i ;  
 	 	 g l V e r t e x 3 f ( r a d i u s   *   c o s f ( t h e t a ) ,   h e i g h t ,   r a d i u s   *   s i n f ( t h e t a ) ) ;  
 	 }  
 	 g l E n d ( ) ;  
  
 	 / /   �^b� 
 	 g l N o r m a l 3 f ( 0 ,   - 1 ,   0 ) ;  
 	 g l B e g i n ( G L _ T R I A N G L E _ F A N ) ;  
 	 g l V e r t e x 3 f ( 0 ,   0 ,   0 ) ;  
 	 f o r   ( i n t   i   =   0 ;   i   < =   n S l i c e s ;   i + + )   {  
 	 	 c o n s t   f l o a t   t h e t a   =   d e l t a T h e t a   *   i ;  
 	 	 g l V e r t e x 3 f ( r a d i u s   *   c o s f ( t h e t a ) ,   0 ,   r a d i u s   *   s i n f ( t h e t a ) ) ;  
 	 }  
 	 g l E n d ( ) ;  
  
 	 / /   tPb� 
 	 g l B e g i n ( G L _ T R I A N G L E _ S T R I P ) ;  
 	 f o r   ( i n t   i   =   0 ;   i   < =   n S l i c e s ;   i + + )   {  
 	 	 c o n s t   f l o a t   t h e t a   =   d e l t a T h e t a   *   i ;  
 	 	 c o n s t   f l o a t   c o s T h e t a   =   c o s f ( t h e t a ) ;  
 	 	 c o n s t   f l o a t   s i n T h e t a   =   s i n f ( t h e t a ) ;  
 	 	 g l N o r m a l 3 f ( c o s T h e t a ,   0 ,   s i n T h e t a ) ;  
 	 	 g l V e r t e x 3 f ( r a d i u s   *   c o s T h e t a ,   h e i g h t ,   r a d i u s   *   s i n T h e t a ) ;  
 	 	 g l V e r t e x 3 f ( r a d i u s   *   c o s T h e t a ,   0 ,   r a d i u s   *   s i n T h e t a ) ;  
 	 }  
 	 g l E n d ( ) ;  
 }  
  
 v o i d   d i s p l a y ( )   {  
 	 g l C l e a r ( G L _ C O L O R _ B U F F E R _ B I T   |   G L _ D E P T H _ B U F F E R _ B I T ) ;  
  
 	 / /   ����bq_	Y�cn0-��[ 
 	 g l M a t r i x M o d e ( G L _ P R O J E C T I O N ) ;  
 	 g l L o a d I d e n t i t y ( ) ;  
 	 g l u P e r s p e c t i v e ( 3 0 . 0 ,   g _ W i n d o w W i d t h   /   ( d o u b l e ) g _ W i n d o w H e i g h t ,   1 ,   1 0 0 . 0 ) ;  
  
 	 / /   �0�0�0�^jn0�d\Ox0�0�0�0R�0�fH0 
 	 g l M a t r i x M o d e ( G L _ M O D E L V I E W ) ;  
 	 g l L o a d I d e n t i t y ( ) ;  
 	 g l u L o o k A t ( 0 . 0 ,   g _ E y e Y ,   g _ E y e Z ,   0 . 0 ,   0 . 0 ,   0 . 0 ,   0 . 0 ,   1 . 0 ,   0 . 0 ) ;  
  
 	 f l o a t   a m b i e n t C o l o r [ ]   =   {   0 . 4 f ,   0 . 2 f ,   0 . 2 f ,   1 . 0 f   } ;  
 	 f l o a t   d i f f u s e C o l o r [ ]   =   {   1 . f ,   0 . 8 f ,   0 . 8 f ,   1 . 0 f   } ;  
 	 f l o a t   s p e c u l a r C o l o r [ ]   =   {   0 . 4 f ,   0 . 3 f ,   0 . 3 f ,   1 . 0 f   } ;  
 	 f l o a t   s h i n i n e s s   =   5 . f ;  
  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ A M B I E N T ,   a m b i e n t C o l o r ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ D I F F U S E ,   d i f f u s e C o l o r ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S P E C U L A R ,   s p e c u l a r C o l o r ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S H I N I N E S S ,   & s h i n i n e s s ) ;  
  
  
  
 	 / /   K\9h 
 	 g l P u s h M a t r i x ( ) ;  
 	 g l T r a n s l a t e f ( 0 ,   g _ H e i g h t A m p l i t u d e   +   g _ H e i g h t O f f s e t   +   3 . f ,   0 ) ;  
 	 g l R o t a t e f ( - 9 0 ,   1 ,   0 ,   0 ) ;  
 	 g l u t S o l i d C o n e ( g _ O u t e r R a d i u s ,   2 . f ,   3 2 ,   3 2 ) ;  
 	 g l P o p M a t r i x ( ) ;  
  
 	 / /   -N�_n0�g 
 	 g l P u s h M a t r i x ( ) ;  
 	 g l T r a n s l a t e f ( 0 ,   - 1 . f ,   0 ) ;  
 	 d i s p l a y C y l i n d e r ( 0 . 5 f ,   g _ H e i g h t A m p l i t u d e   +   g _ H e i g h t O f f s e t   +   6 . 5 f ,   3 2 ) ;  
 	 g l P o p M a t r i x ( ) ;  
  
 	 / /   W�S 
 	 g l P u s h M a t r i x ( ) ;  
 	 g l T r a n s l a t e f ( 0 ,   - 2 . f ,   0 ) ;  
 	 d i s p l a y C y l i n d e r ( g _ O u t e r R a d i u s ,   0 . 7 f ,   6 4 ) ;  
 	 g l P o p M a t r i x ( ) ;  
  
 	 / /   K\9hn0
Nn0�0�0�0�0�0�0 
 	 g l P u s h M a t r i x ( ) ;  
 	 g l T r a n s l a t e f ( 0 ,   g _ H e i g h t A m p l i t u d e   +   g _ H e i g h t O f f s e t   +   5 . 5 f ,   0 ) ;  
 	 g l R o t a t e f ( g _ R o t a t i o n D e g r e e ,   0 ,   1 ,   0 ) ;   / /   �V��U0[0f0D0�0 
 	 g l u t S o l i d T e a p o t ( g _ T e a p o t S i z e ) ;  
 	 g l P o p M a t r i x ( ) ;  
  
 	 g l R o t a t e f ( g _ R o t a t i o n D e g r e e   *   1 0 ,   0 ,   1 ,   0 ) ;  
  
 	 c o n s t   f l o a t   d e l t a T h e t a   =   3 6 0   /   ( f l o a t ) g _ N u m T e a p o t s ;  
  
 	 / /   �0�0�0�0�0�0h0�g�01 d0Z0d0�c;uY0�0 
 	 / /   &N�n0�0�0�0g0o008^k0TX0MOnk0�c;uU0�0�0n0g00hQSOL0�V��Y0�0�0F0k0	Y�fY0�0 
 	 f o r   ( i n t   i   =   0 ;   i   <   g _ N u m T e a p o t s ;   i + + )   {  
 	 	 c o n s t   f l o a t   t h e t a D e g r e e   =   d e l t a T h e t a   *   i ;   / /   �0�0�0�0�0�0n0MOn�0zl�0�0_0�0n0҉�^ 
  
 	 	 c o n s t   f l o a t   t h e t a R a d   =   t h e t a D e g r e e   *   M _ P I   /   1 8 0 . f ;  
 	 	 c o n s t   f l o a t   x P o s   =   g _ I n n e r R a d i u s   *   s i n f ( t h e t a R a d ) ;  
 	 	 c o n s t   f l o a t   z P o s   =   g _ I n n e r R a d i u s   *   c o s f ( t h e t a R a d ) ;  
  
 	 	 / /   �0�0�0�0�0�0n0ؚU0�eTn0$P 
 	 	 c o n s t   f l o a t   y P o s   =   s i n ( 2 * M _ P I * ( i +   g _ R o t a t i o n D e g r e e / 3 ) / 4 ) + 1 . 2 ;   / /   &S0n0$P�0\W0Z0d0	YSU0[0�0S0h0g0�0�0�0�0�0�0L0
NNk0�y�RY0�0 
  
 	 	 	 	 	 	 	 	 	 	       / /   �0�0�0�0�0�0n0r�n0c�[ 
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ A M B I E N T ,   g _ T e a p o t s [ i ] . a m b i e n t . c o l o r s ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ D I F F U S E ,   g _ T e a p o t s [ i ] . d i f f u s e . c o l o r s ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S P E C U L A R ,   g _ T e a p o t s [ i ] . s p e c u l a r . c o l o r s ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S H I N I N E S S ,   & g _ T e a p o t s [ i ] . s h i n i n e s s ) ;  
  
 	 	 / /   �0�0�0�0�0�0n0�c;u 
 	 	 g l P u s h M a t r i x ( ) ;  
 	 	 g l T r a n s l a t e f ( x P o s ,   y P o s ,   z P o s ) ;  
 	 	 g l R o t a t e f ( t h e t a D e g r e e ,   0 ,   1 ,   0 ) ;  
 	 	 g l R o t a t e f ( g _ T e a p o t s [ i ] . a n g l e ,   0 ,   0 ,   1 ) ;  
 	 	 g l u t S o l i d T e a p o t ( 1 . 2 f   *   g _ T e a p o t S i z e ) ;  
 	 	 g l P o p M a t r i x ( ) ;  
  
 	 	 / /   �0�0�0�0�0�0�0/eH0�0�gn0r�n0c�[   
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ A M B I E N T ,   a m b i e n t C o l o r ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ D I F F U S E ,   d i f f u s e C o l o r ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S P E C U L A R ,   s p e c u l a r C o l o r ) ;  
 	 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S H I N I N E S S ,   & s h i n i n e s s ) ;  
  
 	 	 / /   �0�0�0�0�0�0�0/eH0�0�gn0�c;u 
 	 	 g l P u s h M a t r i x ( ) ;  
 	 	 g l T r a n s l a t e f ( x P o s ,   - 1 . f ,   z P o s ) ;  
 	 	 d i s p l a y C y l i n d e r ( 0 . 3 f ,   y P o s   +   1 . f ,   3 2 ) ;  
 	 	 g l P o p M a t r i x ( ) ;  
 	 }  
  
 	 g l u t S w a p B u f f e r s ( ) ;  
 }  
  
 f l o a t   f r a n d ( )   {   r e t u r n   r a n d ( )   /   ( f l o a t ) R A N D _ M A X ;   }  
  
 / /   Rg-��[�0L�F0��pe 
 v o i d   i n i t ( )   {  
 	 g l C l e a r C o l o r ( 1 ,   1 ,   1 ,   1 ) ;  
 	 g l C l e a r D e p t h ( 1 0 0 . f ) ;  
  
 	 f l o a t   l i g h t A m b i e n t C o l o r 0 [ ]   =   {   0 . 2 f ,   0 . 2 f ,   0 . 2 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t D i f f u s e C o l o r 0 [ ]   =   {   0 . 4 f ,   0 . 4 f ,   0 . 4 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t S p e c u l a r C o l o r 0 [ ]   =   {   0 . 8 f ,   0 . 8 f ,   0 . 8 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t P o s i t i o n 0 [ ]   =   {   5 . 0 f ,   5 . 0 f ,   8 . 0 f ,   0 . 0 f   } ;  
  
 	 f l o a t   l i g h t A m b i e n t C o l o r 1 [ ]   =   {   0 . 2 f ,   0 . 2 f ,   0 . 2 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t D i f f u s e C o l o r 1 [ ]   =   {   0 . 4 f ,   0 . 4 f ,   0 . 4 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t S p e c u l a r C o l o r 1 [ ]   =   {   0 . 8 f ,   0 . 8 f ,   0 . 8 f ,   0 . 0 f   } ;  
 	 f l o a t   l i g h t P o s i t i o n 1 [ ]   =   {   - 5 . 0 f ,   2 . 0 f ,   3 . 0 f ,   0 . 0 f   } ;  
  
 	 g l E n a b l e ( G L _ L I G H T I N G ) ;  
  
 	 g l E n a b l e ( G L _ L I G H T 0 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ A M B I E N T ,   l i g h t A m b i e n t C o l o r 0 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ D I F F U S E ,   l i g h t D i f f u s e C o l o r 0 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ S P E C U L A R ,   l i g h t S p e c u l a r C o l o r 0 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ P O S I T I O N ,   l i g h t P o s i t i o n 0 ) ;  
  
 	 g l E n a b l e ( G L _ L I G H T 1 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ A M B I E N T ,   l i g h t A m b i e n t C o l o r 1 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ D I F F U S E ,   l i g h t D i f f u s e C o l o r 1 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ S P E C U L A R ,   l i g h t S p e c u l a r C o l o r 1 ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ P O S I T I O N ,   l i g h t P o s i t i o n 1 ) ;  
  
 	 s r a n d ( 0 ) ;  
  
 	 / /   P0n0�0�0�0�0�0�0n0r��0-��[Y0�0�Qt  qNpeg0zl�0f0D0�0 
 	 f o r   ( i n t   i   =   0 ;   i   <   g _ N u m T e a p o t s ;   i + + )   {  
 	 	 g _ T e a p o t s [ i ] . a m b i e n t . r   =   0 . 2 f   *   f r a n d ( ) ;  
 	 	 g _ T e a p o t s [ i ] . a m b i e n t . g   =   0 . 2 f   *   f r a n d ( ) ;  
 	 	 g _ T e a p o t s [ i ] . a m b i e n t . b   =   0 . 2 f   *   f r a n d ( ) ;  
 	 	 g _ T e a p o t s [ i ] . a m b i e n t . a   =   1 . f ;  
  
 	 	 g _ T e a p o t s [ i ] . d i f f u s e . r   =   0 . 2 f   *   f r a n d ( )   +   0 . 8 f ;  
 	 	 g _ T e a p o t s [ i ] . d i f f u s e . g   =   0 . 2 f   *   f r a n d ( )   +   0 . 8 f ;  
 	 	 g _ T e a p o t s [ i ] . d i f f u s e . b   =   0 . 2 f   *   f r a n d ( )   +   0 . 8 f ;  
 	 	 g _ T e a p o t s [ i ] . d i f f u s e . a   =   1 . f ;  
  
 	 	 g _ T e a p o t s [ i ] . s p e c u l a r . r   =   0 . 3 f   *   f r a n d ( )   +   0 . 2 f ;  
 	 	 g _ T e a p o t s [ i ] . s p e c u l a r . g   =   0 . 3 f   *   f r a n d ( )   +   0 . 2 f ;  
 	 	 g _ T e a p o t s [ i ] . s p e c u l a r . b   =   0 . 3 f   *   f r a n d ( )   +   0 . 2 f ;  
 	 	 g _ T e a p o t s [ i ] . s p e c u l a r . a   =   1 . f ;  
  
 	 	 g _ T e a p o t s [ i ] . s h i n i n e s s   =   2 . f   +   3 0   *   f r a n d ( ) ;  
  
 	 	 g _ T e a p o t s [ i ] . a n g l e   =   1 5   *   ( 2 . f   *   f r a n d ( )   -   1 . f ) ;  
 	 }  
  
 	 g l E n a b l e ( G L _ D E P T H _ T E S T ) ;  
 }  
  
 / /    N�[Bf��T0h0k0�[L�U0�0�0��pe 
 v o i d   t i m e r ( i n t   v a l )   {  
 	 / /   �V��҉�^n0�f�e 
 	 g _ R o t a t i o n D e g r e e   + =   g _ D e l t a R o t a t i o n D e g r e e ;  
  
 	 c o n s t   f l o a t   r o t a t i o n R a d   =   2 . f   *   g _ R o t a t i o n D e g r e e   *   M _ P I   /   1 8 0 . f ;  
  
 	 / /   &  Nn0�0�0�0g0o0���pL0�V�[`0Q0i0 
 	 / /   S0S0g0    g _ E y e Y   h0  g _ E y e Z   n0$P�0	YH0�0S0h0g0���pMOn�0	YSU0[0�0S0h0L0g0M0�0 
 	 g _ E y e Y   =   ( s i n ( g _ R o t a t i o n D e g r e e   /   1 0 )   +   1 )   *   1 0   -   5 ;     / / �0�0�0n0y �^jo0- 5 . f - 1 5 . f  
 	 g _ E y e Z   =   ( c o s ( g _ R o t a t i o n D e g r e e   /   1 0 )   +   1 )   *   1 0   +   3 0 ;     / / �0�0�0n0z �^jo03 0 . f - 5 0 . f  
  
 	 g l u t P o s t R e d i s p l a y ( ) ;  
  
 	 g l u t T i m e r F u n c ( g _ A n i m a t i o n I n t e r v a l M s e c ,   t i m e r ,   v a l ) ;  
 }  
  
 / /   �0�0�0�0�0�0�0�0L0	Y�fU0�0_0h0M0n0�Qt 
 v o i d   r e s h a p e ( i n t   w ,   i n t   h )   {  
 	 i f   ( h   <   1 )   r e t u r n ;  
  
 	 / /   �0�0�0�0�0�0�0�0�0�0�0�0�0�0�0k0	Y�f 
 	 g l V i e w p o r t ( 0 ,   0 ,   w ,   h ) ;  
 	 g _ W i n d o w W i d t h   =   w ;  
 	 g _ W i n d o w H e i g h t   =   h ;  
 }  
  
 i n t   m a i n ( i n t   a r g c ,   c h a r   * * a r g v )   {  
 	 g l u t I n i t ( & a r g c ,   a r g v ) ;  
 	 g l u t I n i t D i s p l a y M o d e ( G L U T _ D O U B L E   |   G L U T _ R G B   |   G L U T _ D E P T H ) ;  
 	 g l u t I n i t W i n d o w S i z e ( g _ W i n d o w W i d t h ,   g _ W i n d o w H e i g h t ) ;  
  
 	 / /   �0�0�0�0�0�0�0�0�0k0h�:yY0�0�eW[R�0c�[Y0�04XT 
 	 g l u t C r e a t e W i n d o w ( " T e a p o t   M e r r y - G o - R o u n d " ) ;  
  
 	 g l u t D i s p l a y F u n c ( d i s p l a y ) ;  
 	 g l u t R e s h a p e F u n c ( r e s h a p e ) ;   / /   �0�0�0�0�0�0�0�0L0	Y�fU0�0_0h0M0k0�[L�U0�0�0��pe�0c�[ 
 	 g l u t T i m e r F u n c ( g _ A n i m a t i o n I n t e r v a l M s e c ,   t i m e r ,   0 ) ;  
  
 	 / /   Rg-��[�0L�F0 
 	 i n i t ( ) ;  
  
 	 g l u t M a i n L o o p ( ) ;  
  
 	 r e t u r n   0 ;  
 } 
