% test family


:- set(i,2).
:- set(verbose,1).

:- modeh(1,fillede(+pers,+pers)).
:- modeb(1,pere(+pers,+pers)).
:- modeb(*,pere(+pers,-pers)).
:- modeb(1,pere(-pers,+pers)).
:- modeb(*,pere(-pers,-pers)).
:- modeb(1,mere(+pers,+pers)).
:- modeb(*,mere(+pers,-pers)).
:- modeb(1,mere(-pers,+pers)).
:- modeb(*,mere(-pers,-pers)).
:- modeb(1,femme(+pers)).
:- modeb(*,femme(-pers)).
:- modeb(1,homme(+pers)).
:- modeb(*,homme(-pers)).

:- determination(fillede/2,pere/2).
:- determination(fillede/2,mere/2).
:- determination(fillede/2,femme/1).
:- determination(fillede/2,homme/1).

% type definitions


%Relations

femme(ann).
femme(mary).
femme(rosy).
femme(eve).
femme(lisa).
homme(tom).
homme(bob).

mere(ann,mary).
mere(ann,tom).
mere(mary,rosy).
pere(tom,eve).
pere(tom,lisa).
pere(tom,bob).
