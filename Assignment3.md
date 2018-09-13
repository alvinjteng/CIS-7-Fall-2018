---Part 1:---\
(M -> H) ^ (S -> C)
<pre>
If math is easy then the homework is done and if it is sunny then camping is fun.
</pre>

“Mathematics is easy or camping is fun, as long as it is sunny and the homework is done.”
<pre>
(M v C) -> (S ^ H)
</pre>
---Part 2:---\
(¬B → ¬A) → ((¬B → A) → B)
<pre>
A   B   ('B -> 'A) = S    ('B -> A) = P   (S -> P) = Q    (Q -> B)
T   T       T                   T               T             T
T   F       F                   T               T             F
F   T       T                   T               T             T
F   F       T                   F               F             T
</pre>
**NEITHER**

((A → B)∧(B → ¬A)) → A
<pre>
A   B   (A -> B) = S    (B -> 'A) = P   (S ^ P) = Q   (Q -> A)
T   T        T                 F              F          T
T   F        F                 T              F          T
F   T        T                 T              T          F
F   F        T                 T              T          F
</pre>
**NEITHER**

---Part 3:---\
(p ∧ q) → r <=> p → (q → r )
<pre>
(P ^ Q)' v R <=> P' v (Q' v R)      IMPLICATION x3
('P v 'Q) v R <=> P' v (Q' v R)     DEMORGAN'S LAW
('P v 'Q) v R <=> (P' v Q') v R     ASSOCIATIVE
</pre>
(q ∨ r ) → p <=> (q → p)∧(r → p)
<pre>
(Q v R)' v P <=> (Q' v P) ^ (R' v P)           IMPLICATION x3
(Q' ^ R') v P <=> (Q' v P) ^ (R' v P)          DEMORGAN'S LAW
(Q' v P) ^ (R' v P) <=> (Q' v P) ^ (R' v P)    DISTRIBUTIVE
</pre>

---Part 4:---\
∃x∀y∀z(City(x) ∧ Traveler(y) ∧ Lives(z,x)) → (Loves(y,x) ∧ ¬Loves(z,x))
<pre>
For some cities, all people who live in the city don't love the city, but all travelers love the city.
</pre>

“No traveler loves the city they live in.”
<pre>
∀x∀y(Traveler(x) ^ City(y) ^ Lives(x,y) -> 'Loves(x,y))
</pre>
