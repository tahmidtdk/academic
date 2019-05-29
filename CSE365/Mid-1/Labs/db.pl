loves(romeo, juliet).
loves(juliet, romeo) :- loves(romeo, juliet).

male(albert).
male(bob).
male(bill).
male(carl).
male(charlie).
male(dan).
male(edward).

female(alice).
female(betsy).
female(diana).


happy(albert).
happy(alice).
happy(bob).
happy(bill).
with_albert(alice).
near_water(bob).


runs(albert) :-
	happy(albert).

dances(alice) :-
	happy(alice),
	with_albert(alice).

does_albert_runs(albert) :-
	runs(albert),
	write('Albert is running').

does_alice_dances(alice) :-
	dances(alice),
	write('When Alice is happy and with Albert she dances').


swims(bob) :-
	happy(bob),
	near_water(bob),
	write('Bob is swimming.\n').

parent(albert, bob).
parent(albert, betsy).
parent(albert, bill).

parent(alice, bob).
parent(alice, betsy).
parent(alice, bill).

parent(bob, carl).
parent(bob, charlie).

cls :- write('\e[2J').



get_grandchild :-
	parent(albert, X),
	parent(X, Y),
	write('Alberts grandchild is '),
	write(Y), nl.


get_parent :-
	parent(X, carl),
	parent(X, charlie),
	format('~w ~s parent ~n', [X, "is the"]).


brother(bob, bill).


get_grandparent(X) :-
	parent(Y, X), parent(Z, Y),
	format('~w\'s grand_parent is ~w ~n', [X, Z]).


get_class(5) :-
	write('Go to kindergarden\n').
get_class(6) :-
	write('Go to first grade\n').
get_class(Other) :-
	Grade is Other - 5,
	format('Go to grade ~w ~n', [Grade]).

say_hi :-
	write('Enter your name: '),
	read(X),
	format('Hi, ~w~n', [X]).
