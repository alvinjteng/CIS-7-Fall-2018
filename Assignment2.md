P -> Q <=> Q' -> P'\
P' v Q <=> Q'' v P'    <p align="right">IMPLICATION x2</p>\
P' v Q <=> Q v P'      <p align="right">DOUBLE NEGATION</p>\
P' v Q <=> P' v Q      <p align="right">COMMUTATIVE</p>

(P -> R) ^ (Q -> R) <=> (P v Q) -> R\
(P' v R) ^ (Q' v R) <=> (P v Q)' v R                      <p align="right">IMPLICATION x3</p>\
((P' v R) ^ Q') v ((P' v R) ^ R) <=> (P v Q)' v R         <p align="right">DISTRIBUTIVE</p>\
((P' v R) ^ Q') v R <=> (P v Q)' v R                      <p align="right">ABSORPTION</p>\
(Q' ^ P') v (Q' ^ R) v R <=> (P v Q)' v R                 <p align="right">DISTRIBUTIVE</p>\
(P v Q)' v (Q' ^ R) v R <=> (P v Q)' v R                  <p align="right">DEMORGANS/COMMUNTATIVE</p>\
(P v Q)' v R <=> (P v Q)' v R                             <p align="right">ABSORPTION</p>\

(Ǝx)A(x) ^ (Ǝx)B(x) -> (Ǝx)(A(x) ^ B(x))\
x = cat\
A(x) = x can talk\
B(x) = x cannot talk\
"If some cats can talk and some cats cannot talk, then some cats can talk and cannot talk."
