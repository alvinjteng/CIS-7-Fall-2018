P -> Q <=> Q' -> P'
P' v Q <=> Q'' v P'    IMPLICATION x2
P' v Q <=> Q v P'      DOUBLE NEGATION
P' v Q <=> P' v Q      COMMUTATIVE

(P -> R) ^ (Q -> R) <=> (P v Q) -> R
(P' v R) ^ (Q' v R) <=> (P v Q)' v R                      IMPLICATION x3
((P' v R) ^ Q') v ((P' v R) ^ R) <=> (P v Q)' v R         DISTRIBUTIVE
((P' v R) ^ Q') v R <=> (P v Q)' v R                      ABSORPTION
(Q' ^ P') v (Q' ^ R) v R <=> (P v Q)' v R                 DISTRIBUTIVE
(P v Q)' v (Q' ^ R) v R <=> (P v Q)' v R                  DEMORGANS/COMMUNTATIVE
(P v Q)' v R <=> (P v Q)' v R                             ABSORPTION

(Ǝx)A(x) ^ (Ǝx)B(x) -> (Ǝx)(A(x) ^ B(x))
x = cat
A(x) = x can talk
B(x) = x cannot talk
"If some cats can talk and some cats cannot talk, then some cats can talk and cannot talk."
